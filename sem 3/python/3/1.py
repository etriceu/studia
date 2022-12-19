import random
import os
from abc import ABC, abstractmethod
import pickle

START = 0
PROPERTY = 1
RAILWAY = 2
TAX = 3
COMPANY = 4

class Base:
    def __init__(self, id, name, type):
        self.name = name
        self.id = id
        self.type = type
    
    def __str__(self):
        return "{} {}".format(self.id, self.name)

class Payable(Base, ABC):
    def __init__(self, id, name, type, rent):
        self.rent = rent
        super().__init__(id, name, type)

    @abstractmethod
    def getRent(self):
        pass
    
    def __str__(self):
        return super().__str__() + "\t\tRent: {}$".format(self.getRent())

class Tax(Payable):
    def __init__(self, id, name, type, rent):
        super().__init__(id, name, type, rent)

    def getRent(self):
        return self.rent

class Buyable(Payable):
    def __init__(self, id, name, type, rent, price):
        self.owner = -1
        self.price = price
        self.multiplier = 1
        super().__init__(id, name, type, rent)
        
    def getRent(self):
        return self.rent*self.multiplier
    
    def getPrice(self):
        if self.type == PROPERTY:
            return self.price*self.multiplier
        return self.price
    
    def __str__(self):
        return super().__str__() + "\tPrice: {}$\towner: {}".format(self.getPrice(), self.owner)

class Player:
    def __init__(self, id, name, isAI):
        self.id = id
        self.name = name
        self.position = 0
        self.money = 100000
        self.companies = 0
        self.railways = 0
        self.isAI = isAI

class Game:
    def __init__(self):
        self.players = []
        self.players.append(Player(0, "ai1", True))
        self.players.append(Player(1, "ai2", True))
        self.players.append(Player(2, "player", False))
        self.board = []
        self.board.append(Base(0, "START", START))
        self.board.append(Buyable(1, "Water Works\t", COMPANY, 100, 100))
        self.board.append(Buyable(2, "Baltic Avenue\t", PROPERTY, 25, 100))
        self.board.append(Tax(3, "Income Tax\t", TAX, 100))
        self.board.append(Buyable(4, "Oriental Avenue", PROPERTY, 30, 150))
        self.board.append(Buyable(5, "Reading Railload", RAILWAY, 25, 200))
        self.board.append(Buyable(6, "Virginia Avenue", PROPERTY, 50, 200))
        self.board.append(Buyable(7, "New York Avenue", PROPERTY, 75, 250))
        self.board.append(Buyable(8, "R. & Q. Railload", RAILWAY, 25, 200))
        self.board.append(Buyable(9, "Indiana Avenue", PROPERTY, 100, 300))
        self.board.append(Buyable(10, "Atlantic Avenue", PROPERTY, 125, 350))
        self.board.append(Buyable(11, "Electric Company", COMPANY, 100, 100))
        self.board.append(Buyable(12, "Short Line\t", RAILWAY, 25, 200))
        self.board.append(Buyable(13, "Pacific Avenue", PROPERTY, 150, 400))
        self.board.append(Tax(14, "Income Tax\t", TAX, 100))
        self.board.append(Buyable(15, "Pennsylvania Avenue", PROPERTY, 175, 450))
    
    def findPlayer(self, id):
        for x in range(0, len(self.players)):
            if self.players[x].id == id:
                return x
    
    def movePlayer(self, id):
        remove = id
        id = self.findPlayer(id)
        
        if self.players[id].money < 0:
            for x in range(0, len(self.board)):
                if self.board[x].owner == id:
                    self.board[x].owner = -1
            
            if self.players[id].isAI == False:
                print("You lost! Money: " + self.players[id].money)
            del self.players[remove]
            return
        
        if self.players[id].isAI == False:
            print("1. move")
            print("2. buy house")
            print("3. sell field")
            while True:
                print("money: {}".format(self.players[id].money))
                a = int(input())
                if a == 1:
                    break
                elif a == 2:
                    b = int(input("id: "))
                    self.players[id].money -= self.board[b].price
                    self.board[b].multiplier += 1
                elif a == 3:
                    b = int(input("id: "))
                    if self.board[b].owner == id:
                        self.board[b].owner = -1
                        self.players[id].money += self.board[b].getPrice()
                        if self.board[b].type == COMPANY:
                            self.players[id].companies -= 1
                            for x in range(0, len(self.board)):
                                if self.board[x].type == COMPANY:
                                    self.board[x].multiplier = 1
                        elif self.board[b].type == RAILWAY:
                            self.players[id].railways -= 1
                            for x in range(0, len(self.board)):
                                if self.board[x].type == RAILWAY and self.board[x].owner == id:
                                    self.board[x].multiplier = self.players[id].railways
        
        what = ""
        self.players[id].position = self.players[id].position + random.randint(1, 6)
        if self.players[id].position >= len(self.board):
            self.players[id].money += 200
            what = "You have got 200$. "
        
        self.players[id].position %= len(self.board)
        pos = self.players[id].position
        field = self.board[pos]
        
        isAI = self.players[id].isAI
        
        if isAI == False:
            print("You are on " + field.name)
            
        if field.type == TAX:
            self.players[id].money -= field.getRent()
            what += "You must pay: {}".format(field.getRent())
        elif (field.type == COMPANY or field.type == PROPERTY or field.type == RAILWAY):
            if field.owner == -1:
                if isAI or input("Do you want to buy {} for {}$? [y/n]".format(field.name, field.getPrice())) == 'y':
                    self.players[id].money -= field.getPrice()
                    self.board[pos].owner = id
                    if field.type == COMPANY:
                        self.players[id].companies += 1
                        if self.players[id].companies == 2:
                            for x in range(0, len(self.board)):
                                if self.board[x].type == COMPANY:
                                    self.board[x].multiplier = 6
                    elif field.type == RAILWAY:
                        self.players[id].railways += 1
                        for x in range(0, len(self.board)):
                            if self.board[x].type == RAILWAY and self.board[x].owner == id:
                                self.board[x].multiplier = self.players[id].railways
            elif field.owner != id:
                self.players[id].money -= field.getRent()
                what += "You must pay: {}".format(field.getRent())
                owner = self.findPlayer(field.owner)
                self.players[owner].money += field.getRent()
                if self.players[owner].isAI == False:
                    print("You have got {}$".format(field.getRent()))
        
        if isAI == False:
            print(what)
    
    def mainLoop(self):
        for x in range(0, len(self.board)):
            print(self.board[x])
        
        for x in range(0, len(self.players)):
            self.movePlayer(x)

game = Game()

while True:
    a = int(input("1. Continue, 2. Exit, 3. Save, 4. Load"))
    if a == 2:
        break
    elif a == 3:
        with open("game.dat", "wb") as file:
            pickle.dump(game, file)
    elif a == 4:
        with open("game.dat", "rb") as file:
            game = pickle.load(file)
    os.system("clear")
    game.mainLoop()
    
