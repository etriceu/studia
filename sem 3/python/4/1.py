import requests as req

city = input("Miasto: ")
day = int(input("Kiedy (0 - dzis, 1 - jutro): "))

if day == 0:
	day = "weather"
else
	day = "forecast"

data = req.get("https://api.openweathermap.org/data/2.5/"+day+"?q="+city+"&lang=pl&units=metric&APPID=be310ee45086594734fc545b3b452573").json()

if day == "weather":
	print("Niebo: " + data["weather"][0]["description"])
	print("Temperatura: {}C".format(data["main"]["temp"]))
	print("Cisnienie: {}hPa".format(data["main"]["pressure"]))
	print("Wilgotnosc: {}%".format(data["main"]["humidity"]))
	print("Wiatr: {}".format(data["wind"]["speed"]))
else:
	print("Niebo: " + data["list"][0]["weather"][0]["description"])
	print("Temperatura: {}C".format(data["list"][0]["main"]["temp"]))
	print("Cisnienie: {}hPa".format(data["list"][0]["main"]["pressure"]))
	print("Wilgotnosc: {}%".format(data["list"][0]["main"]["humidity"]))
	print("Wiatr: {}".format(data["list"][0]["wind"]["speed"]))
