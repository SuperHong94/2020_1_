from tkinter import *

class MainGUI:
    def up(self):
        if self.canvas.coords('ball')[1]>5:
            self.canvas.move('ball',0,-5)

    def down(self):
        print(self.canvas.coords('ball'))
        if self.canvas.coords('ball')[3] < self.canvas.winfo_height()-5:
            self.canvas.move('ball', 0, 5)

    def left(self):
        if self.canvas.coords('ball')[0] > 5:
            self.canvas.move('ball', -5, 0)

    def right(self):
        if self.canvas.coords('ball')[2] <self.canvas.winfo_width()-5:
            self.canvas.move('ball', 5, 0)
    def __init__(self):
        window=Tk()
        window.title("공 옮기기")
        width=200
        height=100
        self.x,self.y=50,50
        self.w=20
        self.canvas=Canvas(window,bg="white",width=width,height=height)
        self.canvas.pack()
        self.canvas.create_oval(self.x,self.y,self.x+self.w,self.y+self.w,fill='red',tags='ball')

        frame=Frame(window)
        frame.pack()
        Button(frame,text='상',command=self.up).pack(side=LEFT)
        Button(frame,text='하',command=self.down).pack(side=LEFT)
        Button(frame,text='좌',command=self.left).pack(side=LEFT)
        Button(frame,text='우',command=self.right).pack(side=LEFT)
        window.mainloop()

MainGUI()
