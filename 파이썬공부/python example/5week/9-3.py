from tkinter import *
WIDTH=300
HEIGHT=50
class MainGUI:
    def display(self):
        print(self.v)
        print(self.filled)
        self.canvas.delete('shape')
        if self.filled.get()==1: #채워서그림
            if self.v.get()==1:# 직사각형
                self.canvas.create_rectangle(WIDTH / 2 - WIDTH * 0.4, HEIGHT / 2 - HEIGHT * 0.4,
                                             WIDTH / 2 + WIDTH * 0.4, HEIGHT / 2 + HEIGHT * 0.4,fill='red', tags='shape')
            else:
                self.canvas.create_oval(WIDTH / 2 - WIDTH * 0.4, HEIGHT / 2 - HEIGHT * 0.4,
                                             WIDTH / 2 + WIDTH * 0.4, HEIGHT / 2 + HEIGHT * 0.4, fill='red',tags='shape')
        else:
            if self.v.get() == 1:  # 직사각형
                self.canvas.create_rectangle(WIDTH / 2 - WIDTH * 0.4, HEIGHT / 2 - HEIGHT * 0.4,
                                             WIDTH / 2 + WIDTH * 0.4, HEIGHT / 2 + HEIGHT * 0.4,tags='shape')
            else:
                self.canvas.create_oval(WIDTH / 2 - WIDTH * 0.4, HEIGHT / 2 - HEIGHT * 0.4,
                                        WIDTH / 2 + WIDTH * 0.4, HEIGHT / 2 + HEIGHT * 0.4, tags='shape')
    def __init__(self):
        window=Tk()
        window.title('라디오버튼과 체크 버튼')
        self.canvas=Canvas(window,bg="white",width=WIDTH,height=HEIGHT)
        self.canvas.create_rectangle(WIDTH/2-WIDTH*0.4,HEIGHT/2-HEIGHT*0.4,
                                     WIDTH/2+WIDTH*0.4,HEIGHT/2+HEIGHT*0.4,tags='shape')
        self.canvas.pack()
        frame=Frame(window)
        frame.pack()
        self.v=IntVar()
        Radiobutton(frame,text="직사각형",variable=self.v,value=1,command=self.display).pack(side=LEFT)
        Radiobutton(frame,text="타원",variable=self.v,value=2,command=self.display).pack(side=LEFT)
        self.filled=IntVar()
        Checkbutton(frame,text='채우기',variable=self.filled,command=self.display).pack(side=LEFT)

        window.mainloop()



MainGUI()
