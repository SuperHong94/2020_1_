from tkinter import *
from random import *
from tkinter.simpledialog import *

WIDTH=800
HEIGHT=600
barWidth=(WIDTH-20)/20 #1개 막대그래프의 너비
class MainGUI:
    def next(self):
        key=int(self.key.get())
        self.canvas.delete('current_bar')
        self.canvas.create_rectangle(10 + self.current * barWidth, HEIGHT - (HEIGHT - 20) * self.counts[self.current] /self.maxCount,
                                     10 + (self.current + 1) * barWidth, HEIGHT - 10,fill='red',tags='current_bar')
        if key==self.counts[self.current]:
            messagebox.showinfo("찾았다","{0}".format(key))
        else:
            self.current+=1


    def reGen(self):
        self.canvas.delete('histogram')
        self.counts=[x for x in range(1,21)] #[1,2,3,,,20]
        shuffle(self.counts)
        self.current=0

        self.maxCount=max(self.counts)
        for i in range(20):
            self.canvas.create_rectangle(10+i*barWidth,HEIGHT-(HEIGHT-20)*self.counts[i]/ self.maxCount,
                                         10+(i+1)*barWidth,HEIGHT-10,tags='histogram')
            self.canvas.create_text(25+i*barWidth,HEIGHT-(HEIGHT-20)*self.counts[i]/ self.maxCount-5,
                                    text=str(self.counts[i]),tags='histogram')


    def __init__(self):
        window=Tk()
        window.title('선형 검색 애니메이션')
        self.canvas=Canvas(window,width=WIDTH,height=HEIGHT,bg="white")
        self.canvas.pack()
        frame=Frame(window)
        frame.pack()
        Label(frame,text="키를 입력하세요: ").pack(side=LEFT)
        self.key=IntVar()
        Entry(frame,textvariable=self.key,justify=RIGHT,width=3).pack(side=LEFT)
        Button(frame,text='다음단게',command=self.next).pack(side=LEFT)
        Button(frame,text='재설정',command=self.reGen).pack(side=LEFT)
        window.mainloop()

MainGUI()