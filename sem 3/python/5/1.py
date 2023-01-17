from tkinter import *
import requests as req
from bs4 import BeautifulSoup

root = Tk()

url = Entry(root, width=32)
url.pack()
url.insert(0, "https://www.pans.nysa.pl/")

OPTIONS = [
    ("h1", "h1"),
    ("h2", "h2"),
    ("p", "p"),
    ("ol", "ol")
]

option=StringVar()
option.set("<h1>")

def click():
    words = dict()
    page = req.get(url.get())
    page.encoding = 'utf-8'
    parser = BeautifulSoup(page.text, 'html.parser')
    
    links = [url.get()]
    for a in parser.find_all('a'):
        if a.attrs['href'][0] == 'h':
            links.append(url.get()+a.attrs['href'])
    
    for link in links:
        try:
            page = req.get(link)
            page.encoding = 'utf-8'
            parser = BeautifulSoup(page.text, 'html.parser')
            
            for a in parser.find_all(option.get()):
                if a.string == None:
                    continue
                for word in a.string.split():
                    if len(word) > 1:
                        if word in words:
                            words[word] += 1
                        else:
                            words[word] = 1
        except:
            pass
    
    word = ""
    oldWord = ""
    count = 0
    oldCount = 0;
    for w, v in words.items():
        if v > count:
            oldCount = count;
            count = v
            oldWord = word
            word = [w];
        elif v == count:
            word.append(w)
    
    label.config(text="{} - {}\n{} - {}".format(word, count, oldWord, oldCount))
    

for a,b in OPTIONS:
    Radiobutton(root, text=a, variable=option, value=b).pack(anchor=W)

button = Button(root, text="go", command=click)
button.pack()

label = Label(root, text="")
label.pack()

root.mainloop()
