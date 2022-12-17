import random
import string

data, files = [], ["D:/pajton/2/imiona.csv", "D:/pajton/2/nazwiska.csv", "D:/pajton/2/ulice.csv", "D:/pajton/2/miasta.csv", "D:/pajton/2/kraje.csv"]

for path in files:
	file = open(path, "r", encoding="utf-8")
	data.append(file.readlines())

data.insert(2, 0)
data.insert(4, 0)
count, file = int(input("Ilosc: ")), open("D:/pajton/2/output.csv", "w", encoding="utf-8")

mapa = dict()
for n in range(0, count):
	str = ""
	pesel = "".join(random.choices(string.digits, k=11))
	data[4] = ["{}".format(random.randint(1, 50))]

	imie = random.choice(data[0]).strip()
	if(imie[-1] == 'a' and int(pesel[-1])%2 == 0):
		pesel = pesel[:-1]+random.choice(['1', '3', '5', '7', '9'])
	elif(imie[-1] != 'a' and int(pesel[-1])%2 != 0):
		pesel = pesel[:-1]+random.choice(['2', '4', '6', '8', '0'])

	data[2] = [pesel]
	str = imie+";"



	for x in range(1, len(data)):
		str += random.choice(data[x]).strip()+";"

	mapa[str[:-1]+"\n"] = 1
	

for str,x in mapa.items():
	file.writelines(str)
file.close()