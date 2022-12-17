przedmioty = dict()
print("<przedmiot> <oceny>\nsrednia [przedmiot]\nsredniaOcen\nkoniec\n")
while True:
	odp = input("").split(" ")
	if odp[0] == "koniec":
		break
	elif odp[0] == "srednia":
		if len(odp) > 1:
			print(odp[1], ": ", sum(przedmioty[odp[1]])/len(przedmioty[odp[1]]))
		else:
			for przedmiot, oceny in przedmioty.items():
				print(przedmiot, ": ", sum(oceny)/len(oceny))
	elif odp[0] == "sredniaOcen":
		suma = 0
		size = 0
		for przedmiot, oceny in przedmioty.items():
			suma += sum(oceny)
			size += len(oceny)
		
		print("Srednia ocen: ", suma/size)
	else:
		if odp[0] not in przedmioty:
			przedmioty[odp[0]] = []
		przedmiot = odp[0]
		odp.pop(0)
		for ocena in odp:
			przedmioty[przedmiot].append(int(ocena))
