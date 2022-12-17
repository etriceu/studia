text = " * "+input("text: ")
l = len(text)+3
if l % 2 == 0:
	text += " "
	l += 1
text += " *"
lh = int(l/2)
for y in range(lh+1, -1, -1):
	if y == lh-1:
		print(text)
	else:
		for x in range(0, l):
			if x == lh-y or x == lh+y or y == lh:
				print("*", end="")
			else:
				print(" ", end="")
		print()