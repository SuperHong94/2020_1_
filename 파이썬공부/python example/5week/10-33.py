from tkinter import *
from random import *

WIDTH=800
HEIGHT=600
class MainGUI:
    def display(self):
        self.canvas.delete('histogram')
        counts=[0]*26
        for i in range(1000):
            ch=randint(0,25) #0~25사이 수
            counts[ch]+=1
        barWidth=(WIDTH-20)/26 #1개 막대그래프의 너비
        maxCount=max(counts)
        for i in range(26):
            self.canvas.create_rectangle(10+i*barWidth,HEIGHT-(HEIGHT-20)*counts[i]/maxCount,
                                         10+(i+1)*barWidth,HEIGHT-10,tags='histogram')
            self.canvas.create_text(25+i*barWidth,HEIGHT-5,text=chr(i+ord('a')),tags='histogram')
            self.canvas.create_text(25+i*barWidth,HEIGHT-(HEIGHT-20)*counts[i]/maxCount-5,text=str(counts[i]),tags='histogram')

    def __init__(self):
        window=Tk()
        window.title('문자의 개수 세기')
        self.canvas=Canvas(window,width=WIDTH,height=HEIGHT,bg="white")
        self.canvas.pack()
        Button(window,text='히스토그램 출력',command=self.display).pack()
        window.mainloop()

MainGUI()