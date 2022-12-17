import math

print("1) kula\n2) cegla\n3) stozek\n4) ostroslup")
odp = int(input("podaj figure: "))
if odp == 1 :
	r = float(input("r = "))
	print("V = ", 4/3*3.14*r*r*r, "\nP = ", 4*3.14*r*r)
elif odp == 2 :
	a = float(input("a = "))
	b = float(input("b = "))
	c = float(input("c = "))
	print("V = ", a*b*c, "\nP = ", 2*a*b+2*a*c+2*b*c)
elif odp == 3 :
	r = float(input("r = "))
	h = float(input("h = "))
	print("V = ", r*r*3.14*h/2, "\nP = ", 3.14*r*(r+math.sqrt(r*r+h*h)))
elif odp == 4 :
	a = float(input("a = "))
	h = float(input("h = "))
	print("V = ", a*a*h/3, "\nP = ", a*a+2*a*(math.sqrt(math.pow(a/2, 2)+h*h)))