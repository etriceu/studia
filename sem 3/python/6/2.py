from tkinter import *
import sqlite3

main = Tk()
main.geometry("800x600")
db = sqlite3.connect("database.db")
cdb = db.cursor()
try:
	cdb.execute("CREATE TABLE studenci (id INTEGER PRIMARY KEY AUTOINCREMENT, imie text, nazwisko text, adres text, pesel text, album integer)")
	cdb.execute("INSERT INTO studenci (imie, nazwisko, adres, pesel, album) VALUES ('Bob', 'Tyranozaur', 'Zadupowice 666', '4752896341', 1)")
	cdb.execute("CREATE TABLE oceny (id INTEGER PRIMARY KEY AUTOINCREMENT, nazwa text, ocena text, id_s integer)")
	cdb.execute("INSERT INTO oceny (nazwa, ocena, id_s) VALUES ('fiza', '4,5', 1)")
	db.commit()
except:
	pass

labels = []
def mainClickSelect():
	for l in labels:
		l.destroy()
	labels.clear()
	cdb.execute("SELECT * FROM studenci")
	result = cdb.fetchall()
	y = 1
	n = 0
	for row in result:
		x = 0
		for col in row:
			labels.append(Label(main, text=col))
			labels[n].grid(row=y, column=x)
			x += 1
			n += 1
		y += 1

def mainClickInsert():
	child = Toplevel()
	Label(child, text="imie").grid(row=0, column=0)
	imie = Entry(child, width=20)
	imie.grid(row=0, column=1)
	Label(child, text="nazwisko").grid(row=1, column=0)
	nazwisko = Entry(child, width=20)
	nazwisko.grid(row=1, column=1)
	Label(child, text="adres").grid(row=2, column=0)
	adres = Entry(child, width=20)
	adres.grid(row=2, column=1)
	Label(child, text="pesel").grid(row=3, column=0)
	pesel = Entry(child, width=20)
	pesel.grid(row=3, column=1)
	Label(child, text="album").grid(row=4, column=0)
	album = Entry(child, width=20)
	album.grid(row=4, column=1)

	def studentInsert():
		try:
			cdb.execute("INSERT INTO studenci (imie, nazwisko, adres, pesel, album) VALUES ('{}', '{}', '{}', '{}', {})".format(imie.get(), nazwisko.get(), adres.get(), pesel.get(), album.get()))
			db.commit()
		except:
			pass
		child.destroy()
		mainClickSelect()

	Button(child, text="Insert", command=studentInsert).grid(row=5, column=0)

def mainClickUpdate():
	child = Toplevel()
	Label(child, text="id").grid(row=0, column=0)
	id = Entry(child, width=20)
	id.grid(row=0, column=1)
	Label(child, text="imie").grid(row=1, column=0)
	imie = Entry(child, width=20)
	imie.grid(row=1, column=1)
	Label(child, text="nazwisko").grid(row=2, column=0)
	nazwisko = Entry(child, width=20)
	nazwisko.grid(row=2, column=1)
	Label(child, text="adres").grid(row=3, column=0)
	adres = Entry(child, width=20)
	adres.grid(row=3, column=1)
	Label(child, text="pesel").grid(row=4, column=0)
	pesel = Entry(child, width=20)
	pesel.grid(row=4, column=1)
	Label(child, text="album").grid(row=5, column=0)
	album = Entry(child, width=20)
	album.grid(row=5, column=1)

	def studentUpdate():
		try:
			cdb.execute("UPDATE studenci SET imie = '{}', nazwisko = '{}', adres = '{}', pesel = '{}', album = {} WHERE id = {}".format(imie.get(), nazwisko.get(), adres.get(), pesel.get(), album.get(), id.get()))
			db.commit()
		except:
			pass
		child.destroy()
		mainClickSelect()

	Button(child, text="Update", command=studentUpdate).grid(row=6, column=0)

oceny = []
def mainClickOceny():
	child = Toplevel()
	child.geometry("600x400")
	Label(child, text="id studenta").grid(row=0, column=0)
	id = Entry(child, width=20)
	id.grid(row=0, column=1)
	def ocenySelect():
		try:
			cdb.execute("SELECT nazwa, ocena FROM oceny WHERE id_s = {}".format(id.get()))
			for l in oceny:
				l.destroy()
			oceny.clear()
			result = cdb.fetchall()
			y = 1
			n = 0
			for row in result:
				x = 0
				for col in row:
					oceny.append(Label(child, text=col))
					oceny[n].grid(row=y, column=x)
					x += 1
					n += 1
				y += 1
		except:
			pass

	def ocenyInsert():
		child2 = Toplevel()
		Label(child2, text="nazwa").grid(row=0, column=0)
		nazwa = Entry(child2, width=20)
		nazwa.grid(row=0, column=1)
		Label(child2, text="ocena").grid(row=1, column=0)
		ocena = Entry(child2, width=20)
		ocena.grid(row=1, column=1)

		def nowaOcena():
			try:
				cdb.execute("INSERT INTO oceny (nazwa, ocena, id_s) VALUES ('{}', '{}', {})".format(nazwa.get(), ocena.get(), id.get()))
				db.commit()
			except:
				pass
			child2.destroy()
			ocenySelect()

		Button(child2, text="Insert", command=nowaOcena).grid(row=2, column=0)

	Button(child, text="Select", command=ocenySelect).grid(row=0, column=2)
	Button(child, text="Insert", command=ocenyInsert).grid(row=0, column=3)

Label(main, text="ilosc csv").grid(row=0, column=3)
count = Entry(main, width=5)
count.grid(row=0, column=4)

def clickCSV():
	file = open("output.csv", "w")
	c = int(count.get())
	if(c > 0):
		try:
			cdb.execute("SELECT imie, nazwisko FROM studenci")
			result = cdb.fetchall()
			for row in result:
				file.writelines([row[0] + ";" + row[1] + "\n"])
				c -= 1
				if(c <= 0):
					break

		except:
			pass
	file.close()

Button(main, text="Insert\nStudent", command=mainClickInsert).grid(row=0, column=0)
Button(main, text="Update", command=mainClickUpdate).grid(row=0, column=1)
Button(main, text="Oceny", command=mainClickOceny).grid(row=0, column=2)
Button(main, text="CSV", command=clickCSV).grid(row=0, column=5)

mainClickSelect()
main.mainloop()
