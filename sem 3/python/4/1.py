import requests as req

city = input("Miasto: ")

data = req.get("https://api.openweathermap.org/data/2.5/weather?q="+city+"&lang=pl&units=metric&APPID=be310ee45086594734fc545b3b452573").json()


print("Niebo: " + data["weather"][0]["description"])
print("Temperatura: {}C".format(data["main"]["temp"]))
print("Cisnienie: {}hPa".format(data["main"]["pressure"]))
print("Wilgotnosc: {}%".format(data["main"]["humidity"]))
print("Wiatr: {}".format(data["wind"]["speed"]))
