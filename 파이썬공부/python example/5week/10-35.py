from tkinter import *
from random import *
WIDTH=800
HEIGHT=600
class Ball:
    def toHexChar(self,value): #0~15->#0,1,2,3,,,9,A,B,C,D,E,F
        if 0<=value<=9:
            return chr(value+ord('0'))
        else: #10,11,12,13,14,15
            return chr(value-10+ord('A'))

    def getRandomColor(self): #RRGGBB 16진수로 색깔을 표현
        color='#'
        for i in range(6):
            color +=self.toHexChar(randint(0,15)) #0,1,2,3,,,9,A,B,C,D,E,F
        return color

    def __init__(self):
        self.x=0
        self.y=0
        self.dx=2
        self.dy=2
        self.color=self.getRandomColor()

class MainGUI:
    def stop(self):
        self.isStopped=True

    def resume(self):
        self.isStopped = False
        self.animate()

    def add(self):
        self.balllist.append(Ball())



    def remove(self):
        self.balllist.pop()

    def faster(self):
        if self.sleepTime>20:
            self.sleepTime-=20

    def slower(self):
        self.sleepTime+=20

    def animate(self):
        while not self.isStopped:
            self.canvas.after(self.sleepTime) # 일정시간뒤에 다시 animate 함수실행
            self.canvas.update() #다시그린다.
            self.canvas.delete('ball')
            for ball in self.balllist:
                self.displayBall(ball)

    def displayBall(self,ball):
        if ball.x >=WIDTH:
            ball.dx *=-1
        elif ball.x <0:
            ball.dx *=-1
        if ball.y>=HEIGHT:
            ball.dy *=-1
        elif ball.y<0:
            ball.dy *=-1
        ball.x+=ball.dx
        ball.y+=ball.dy
        self.canvas.create_oval(ball.x-3,ball.y-3,ball.x+3,ball.y+3, fill=ball.color,tags='ball')



    def __init__(self):
        window=Tk()
        window.title('공 튀기기')
        self.balllist=[]
        self.isStopped=False
        self.sleepTime=100
        self.canvas=Canvas(window,bg="white",width=WIDTH,height=HEIGHT)
        self.canvas.pack()
        frame=Frame(window)
        frame.pack()
        Button(frame,text="정지",command=self.stop).pack(side=LEFT)
        Button(frame,text="재시작",command=self.resume).pack(side=LEFT)
        Button(frame,text="+",command=self.add).pack(side=LEFT)
        Button(frame,text="-",command=self.remove).pack(side=LEFT)
        Button(frame,text="빠르게",command=self.faster).pack(side=LEFT)
        Button(frame,text="느리게",command=self.slower).pack(side=LEFT)
        self.animate()
        window.mainloop()


MainGUI()
