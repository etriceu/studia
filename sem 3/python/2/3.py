import random

class Matrix:
	def __init__(self, w = 0, h = 0):
		self.setSize(w, h)

	def setSize(self, w, h):
		self.m = [None]*(h*w)
		self.w = w
		self.h = h

	def getWidth(self):
		return self.w

	def getHeight(self):
		return self.h

	def get(self, x, y):
		return self.m[x+y*self.w]

	def set(self, x, y, v):
		self.m[x+y*self.w] = v

	def getMatrix(self):
		return self.m

	def __str__(self):
		str = ""
		for y in range(0, self.h):
			for x in range(0, self.w):
				str += "{}\t".format(self.m[x+y*self.w])
			str += "\n"
		return str

	def __add__(self, sec):
		tmp = Matrix(self.w, self.h)
		for y in range(0, self.h):
			for x in range(0, self.w):
				tmp.set(x, y, self.get(x, y)+sec.get(x, y))
		return tmp

	def __sub__(self, sec):
		tmp = Matrix(self.w, self.h)
		for y in range(0, self.h):
			for x in range(0, self.w):
				tmp.set(x, y, self.get(x, y)-sec.get(x, y))
		return tmp

	def __mul__(self, sec):
		tmp = Matrix(self.w, self.h)
		for y in range(0, self.h):
			for x in range(0, self.w):
				tmp.set(x, y, self.get(x, y)*sec.get(x, y))
		return tmp

	def __lt__(self, sec):
		s1 = 0
		s2 = 0
		for y in range(0, self.h):
			for x in range(0, self.w):
				s1 += self.get(x, y)
				s2 += sec.get(x, y)

		return s1 < s2

	m = []
	w = 0
	h = 0

w, h = int(input("szerokosc: ")), int(input("wysokosc: "))
rMin, rMax = int(input("zakres od: ")), int(input("zakres do: "))

neo = Matrix()
trinity = Matrix(w, h)

neo.setSize(w, h)


for y in range(0, h):
	for x in range(0, w):
		neo.set(x, y, random.randint(rMin, rMax))
		trinity.set(x, y, random.randint(rMin, rMax))

print("neo:\n", neo, "\n")
print("trinity:\n", trinity, "\n")
print("neo + trinity:\n", neo+trinity, "\n")
print("neo - trinity:\n", neo-trinity, "\n")
print("neo * trinity:\n", neo*trinity, "\n")
print("neo < trinity:\n", neo<trinity, "\n")
# mniejsza suma