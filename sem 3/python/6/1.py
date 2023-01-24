from tkinter import *

root = Tk()

turn = 'X'
buttons = []
size = 5
count = 3
empty = 0

boxSize = Entry(root, width=4)
label = Label(root, text="Player: X", font=("Arial", 25))

def clickReset():
	global turn
	global size
	global empty
	global buttons
	global count
	turn = "X"
	label.configure(text="Player: "+turn)
	for b in buttons:
		b.destroy()
	buttons.clear()
	size = int(boxSize.get())
	empty = size*size
	count = size-2
	if(count <= 1):
		count = 3
	for n in range(0, size*size):
		buttons.append(MyButton(n))
		buttons[n].configure(text=" ")
		buttons[n].grid(row=int(n/size)+2, column=n%size)

reset = Button(root, text="Reset", command=clickReset)
reset.grid(row=1, column=1, columnspan=999)
label.grid(row=0, column=0, columnspan=999)
boxSize.insert(0, "{}".format(size))
boxSize.grid(row=1, column=0)

class MyButton(Button):
	def __init__(self, id):
		super().__init__(root, text=" ", font=("Arial", 25), width=1, command=self.click)
		self.id = id

	def click(self):
		global empty
		if buttons[self.id].cget("text") == " " and empty > 0:
			global turn
			empty -= 1
			buttons[self.id].configure(text=turn)

			win = False

			x = self.id%size
			y = int(self.id/size)

			sum = 0
			for n in range(x, x+count):
				if(n < size and buttons[n+y*size].cget("text") == turn):
					sum += 1
				else:
					break

			for n in range(x-1, x-count, -1):
				if(n >= 0 and buttons[n+y*size].cget("text") == turn):
					sum += 1
				else:
					break

			if(sum >= count):
				win = True

			sum = 0
			for n in range(y, y+count):
				if(n < size and buttons[x+n*size].cget("text") == turn):
					sum += 1
				else:
					break

			for n in range(y-1, y-count, -1):
				if(n >= 0 and buttons[x+n*size].cget("text") == turn):
					sum += 1
				else:
					break

			if(sum >= count):
				win = True

			sum = 0
			for n in range(0, count):
				if(n+x < size and n+y < size and buttons[(x+n)+(y+n)*size].cget("text") == turn):
					sum += 1
				else:
					break

			for n in range(-1, -count, -1):
				if(n+x >= 0 and n+y >= 0 and buttons[(x+n)+(y+n)*size].cget("text") == turn):
					sum += 1
				else:
					break

			if(sum >= count):
				win = True

			sum = 0
			for n in range(0, count):
				if(x-n >= 0 and n+y < size and buttons[(x-n)+(y+n)*size].cget("text") == turn):
					sum += 1
				else:
					break

			for n in range(-1, -count, -1):
				if(x-n < size and n+y >= 0 and buttons[(x-n)+(y+n)*size].cget("text") == turn):
					sum += 1
				else:
					break

			if(sum >= count):
				win = True

			if(win):
				label.configure(text="Player "+turn+" won!")
				empty = -1
			else:
				if turn == "X":
					turn = "O"
				else:
					turn = "X"
				label.configure(text="Player: "+turn)

			draw = True

			if(empty == 0 and ~win):
				label.configure(text="It's draw!")

clickReset()
root.mainloop()
