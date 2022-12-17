import mylib

numbers = []
while len(numbers) < 15:
	numbers.extend(input("Podaj {} liczb: ".format(15-len(numbers))).split(" "))
numbers = [int(x) for x in numbers]

print("szukana: ", mylib.find(numbers, int(input("Podaj liczbe do znalezienia: "))))
i = mylib.min(numbers)
print("min index: ", i)
print("min: ", numbers[i])
i = mylib.max(numbers)
print("max index: ", i)
print("max: ", numbers[i])
print("srednia: ", mylib.avg(numbers))
print("srednia geometryczna: ", mylib.avg2(numbers))