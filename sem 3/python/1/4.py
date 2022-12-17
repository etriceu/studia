text = input("text: ")
znak = input("znak do pominiecia: ")
print(text.replace(",", "").replace(".", ""), "\nilosc znakow: ", len(text), "\nbez spacji: ", len(text.replace(" ", "")), "\nbez podanego znaku: ", len(text.replace(znak, "")))
lista = text.split(znak)
for n in range(0, len(lista)):
	if n < len(lista)-1:
		lista[n] += znak
	print(lista[n])
