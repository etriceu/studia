from tkinter import *

root = Tk()

turn = 'X'
label = Label(root, text="Player: X")
label.grid(row=0, column=0, columnspan=3)

buttons = []

def click(id):
    if buttons[id].cget("text") == " ":
        global turn
        buttons[id].configure(text=turn)
        if turn == "X":
            turn = "O"
        else:
            turn = "X"
        
        label.configure(text="Player: "+turn)
        
        t = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 4, 8], [2, 4, 6], [0, 3, 6], [1, 4, 7], [2, 5, 8]]
        
        for a in t:
            if(buttons[a[0]].cget("text") != " "):
                win = True
                for b in a:
                    if buttons[b].cget("text") != buttons[a[0]].cget("text"):
                        win = False
                
                if(win):
                    label.configure(text="Player "+buttons[a[0]].cget("text")+" won!")
        
        draw = True
        
        for i in range(0, 9):
            if(buttons[i].cget("text") == " "):
                draw = False
                
        if(draw and ~win):
            label.configure(text="It's draw!")
            

buttons.append(Button(root, text=" ", font=("Arial", 25), width=1, command=lambda: click(0)))
buttons.append(Button(root, text=" ", font=("Arial", 25), width=1, command=lambda: click(1)))
buttons.append(Button(root, text=" ", font=("Arial", 25), width=1, command=lambda: click(2)))
buttons.append(Button(root, text=" ", font=("Arial", 25), width=1, command=lambda: click(3)))
buttons.append(Button(root, text=" ", font=("Arial", 25), width=1, command=lambda: click(4)))
buttons.append(Button(root, text=" ", font=("Arial", 25), width=1, command=lambda: click(5)))
buttons.append(Button(root, text=" ", font=("Arial", 25), width=1, command=lambda: click(6)))
buttons.append(Button(root, text=" ", font=("Arial", 25), width=1, command=lambda: click(7)))
buttons.append(Button(root, text=" ", font=("Arial", 25), width=1, command=lambda: click(8)))
    
for n in range(0, 9):
    buttons[n].grid(row=int(n/3)+1, column=n%3)
    
def clickReset():
    global turn
    turn = "X"
    label.configure(text="Player: "+turn)
    for n in range(0, 9):
        buttons[n].configure(text=" ")

reset = Button(root, text="Reset", command=clickReset)
reset.grid(row=4, column=0, columnspan=3)

root.mainloop()
