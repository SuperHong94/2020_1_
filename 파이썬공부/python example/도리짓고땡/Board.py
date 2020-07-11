from tkinter import*
from tkinter import font
import Player

class MainGUI:
    def SetupLabel(self):
        self.Player1Money = Label(text="5만", width=4, height=1, font=self.fontstyle, bg="green", fg="cyan")
        self.Player1Money.place(x=200, y=450)
    def __init__(self):
        window=Tk()
        window.title("도리짓고땡")
        window.geometry("800x600")
        self.fontstyle = font.Font(window, size=24, weight='bold', family='Consolas')

        #배경 만들기
        self.bgImg=PhotoImage(file='Resource/GodoriCards/table.gif')
        Label(window, image=self.bgImg).place(x=0, y=0)

        #각종변수
        self.player1=Player.Player()
        self.player2=Player.Player()
        self.player2=Player.Player()
        self.SetupLabel()


        window.mainloop()




if __name__=='__main__':
    MainGUI()