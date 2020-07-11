'''#9-1
from tkinter import*

class MainGUI:
    def UP(self):
        if self.canvas.coords("ball")[1]>5:
            self.canvas.move("ball",0,-5)
    def DOWN(self):
        if self.canvas.coords("ball")[3] < self.canvas.winfo_height()-5:
            self.canvas.move("ball",0,5)
    def LEFT(self):
        if self.canvas.coords("ball")[0] > 5:
            self.canvas.move("ball",-5,0)
    def RIGHT(self):
        if self.canvas.coords("ball")[2] < self.canvas.winfo_width() - 5:
            self.canvas.move("ball",5,0)
    def __init__(self):
        window=Tk()
        width=200
        height=200
        self.canvas=Canvas(window,bg="white",width=width,height=height)
        self.canvas.create_oval(50,50,70,70,fill="red",tag="ball")
        self.canvas.pack()
        frame=Frame(window)
        frame.pack()
        Button(frame,text="상",command=self.UP).pack(side=LEFT)
        Button(frame,text="하",command=self.DOWN).pack(side=LEFT)
        Button(frame,text="좌",command=self.LEFT).pack(side=LEFT)
        Button(frame,text="우",command=self.RIGHT).pack(side=LEFT)

        window.mainloop()'''
#9-2
'''from tkinter import*

class MainGUI:
    def RESULT(self):
        r=int(self.money.get()) * int(self.hour.get())*int(self.day.get())
        self.result.set(r)
    def __init__(self):
        window=Tk()
        Label(window,text="시급").grid(row=0,column=0)
        Label(window,text="시간").grid(row=1,column=0)
        Label(window,text="일수").grid(row=2,column=0)
        self.money = StringVar()
        Entry(window,textvariable=self.money,justify=RIGHT).grid(row=0,column=1)
        self.hour = StringVar()
        Entry(window, textvariable=self.hour, justify=RIGHT).grid(row=1, column=1)
        self.day = StringVar()
        Entry(window, textvariable=self.day, justify=RIGHT).grid(row=2, column=1)
        self.result=StringVar()
        Label(window,textvariable=self.result).grid(row=3,column=1)

        Button(window,text="계산하기",command=self.RESULT).grid(row=4,column=1)

        window.mainloop()

MainGUI()'''
#9-3
from tkinter import*
WIDHT=300
HEIGHT=100
class MainGUI:
    def __init__(self):
        window=Tk()
        window.title("라디오 버튼과 체크 버튼")
        canvas=Canvas(window,bg="white",width=WIDHT,height=HEIGHT)
        canvas.pack()
        Radiobutton(window,text="사각형").pack(side=LEFT)
        window.mainloop()

MainGUI()