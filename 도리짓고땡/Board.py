from tkinter import*
from tkinter import font
import Player
import Card
import random

class MainGUI:
    def SetupLabel(self):
        for i in range(len(self.players)):
            self.PlayerMoneyL.append(Label(text=str(self.players[i].money) + "만", width=4, height=1, font=self.fontstyle,
                                           bg="green", fg="yellow"))
            self.PlayerMoneyL[i].place(x=70+(i*215),y=500)


        self.totalMoneyL = Label(text=str(self.totalMoney) + "만", width=6, height=1, font=self.fontstyle,
                                  bg="green", fg="yellow")
        self.totalMoneyL.place(x=690, y=500)

    def BetMoney(self,num,value):
        if self.totalMoney>=1:
            if value==5 and self.totalMoney>=value:
                self.totalMoney-=value
                self.totalMoneyL.configure(text=str(self.totalMoney)+"만")
                self.players[num].money+=value
                self.PlayerMoneyL[num].configure(text=str(self.players[num].money) + "만")
            elif value==1:
                self.totalMoney -= value
                self.totalMoneyL.configure(text=str(self.totalMoney) + "만")
                self.players[num].money += value
                self.PlayerMoneyL[num].configure(text=str(self.players[num].money) + "만")
            self.DealButton['state'] = 'active'
            self.DealButton['bg']='white'

    def drawCards(self):
        if self.turn==1:
            self.LDealerCards[0].place(x=100,y=100)
            #플레이어 카드
            for i in range(len(self.players)):
                self.LPlayerCards[i][0].place(x=30+(i*215),y=380)

        elif self.turn==2:
            for i in range(1,4): #카드 3장 그리기
                self.LDealerCards[i].place(x=100+(i*30), y=100)
                for j in range(len(self.players)):
                    self.LPlayerCards[j][i].place(x=30+(j*215)+(i*30),y=380)

        elif self.turn==3:
            self.LDealerCards.append(Label(self.window, image=self.delarImage))
            self.LDealerCards[4].place(x=220, y=100)
            # 플레이어 카드
            for i in range(len(self.players)):
                self.LPlayerCards[i][4].place(x=30 + (i * 215)+120, y=380)



    def CheckWinnner(self):
        for i in range(len(self.players)):
            self.Button5[i]['state'] = 'disable'
            self.Button5[i]['bg'] = 'gray'
            self.Button1[i]['state'] = 'disable'
            self.Button1[i]['bg'] = 'gray'

    def GamePlay(self):
        if self.turn==1:  #첫번째턴
            self.initDeck()  # 카드 초기화
            for i in range(5):  # "카드 5장 뽑기" 처음부터 다뽑고 그릴때만 보여주면된다.
                self.dealer.cards.append(Card.Card(self.CardeDeck.pop()))  # 딜러 카드 한장받는다.
                for p in self.players:
                    p.cards.append(Card.Card(self.CardeDeck.pop()))  # 카드리스트에서 한장빼서 플레이어에게 준다.
            for i in range(5): #이미지 라벨 리스트에 카드 5장 채우기 반복문을 나눈것은 배치의 개념
                self.LDealerCards.append(Label(self.window, image=self.delarImage))
                for j in range(len(self.players)):
                    self.LPlayerCards[j].append(Label(self.window,image=self.players[j].cards[i].cImage))


        self.drawCards()



    def Deal(self):
        print(self.turn,"deal버튼")

        self.DealButton['state'] = 'disable'
        self.DealButton['bg'] = 'gray'
        self.AgainButton['state'] = 'active'
        self.AgainButton['bg']='white'
        self.turn += 1  # 턴증가
        self.GamePlay() #게임시작

        pass
    def Again(self):
        self.turn=0
        self.AgainButton['state'] = 'disable'
        self.AgainButton['bg'] = 'gray'
        for i in range(len(self.players)):
            self.Button5[i]['state']='active'
            self.Button5[i]['bg']='white'
            self.Button1[i]['state']='active'
            self.Button1[i]['bg']='white'
        pass
    def SetupButton(self):
        width=220
        for i in range(len(self.players)):
            self.Button5.append(Button(self.window, text="5만", font=self.fontstyle,command=lambda: self.BetMoney(i, 5)))
            self.Button1.append(Button(self.window, text="1만", font=self.fontstyle))
            self.Button5[i].place(x=30 + (i * width), y=550)
            self.Button1[i].place(x=90 + (i * width), y=550)

        self.Button5[0].configure(command=lambda: self.BetMoney(0, 5))
        self.Button1[0].configure(command=lambda: self.BetMoney(0, 1))

        self.Button5[1].configure(command=lambda: self.BetMoney(1, 5))
        self.Button1[1].configure(command=lambda: self.BetMoney(1, 1))

        self.Button5[2].configure(command=lambda: self.BetMoney(2, 5))
        self.Button1[2].configure(command=lambda: self.BetMoney(2, 1))


        #deal, again
        self.DealButton=Button(self.window, text="Deal", font=self.fontstyle,command=self.Deal)
        self.DealButton.place(x=650,y=550)
        self.DealButton['state'] = 'disable'
        self.DealButton['bg'] = 'gray'

        self.AgainButton = Button(self.window, text="Again", font=self.fontstyle,command=self.Again)
        self.AgainButton.place(x=720, y=550)
        self.AgainButton['state'] = 'disable'
        self.AgainButton['bg'] = 'gray'


    def initDeck(self):
        for i in range(40): #카드번호 추가
            self.CardeDeck.append(i)

        random.shuffle(self.CardeDeck) #카드리스트 섞기



    def __init__(self):
        self.window=Tk()
        self.window.title("도리짓고땡")
        self.window.geometry("800x600")
        self.fontstyle = font.Font(self.window, size=15, weight='bold', family='Consolas')

        #배경 만들기
        self.fileRoute = 'Resource/GodoriCards/'
        self.bgImg=PhotoImage(file=self.fileRoute+'table.gif')
        Label(self.window, image=self.bgImg).place(x=0, y=0)

        #각종변수

        self.players=[Player.Player(), Player.Player(), Player.Player()]
        self.dealer=Player.Player()
        self.totalMoney=1000
        self.Button5 = []
        self.Button1 = []
        self.PlayerMoneyL=[]
        self.turn=0
        self.CardeDeck=[]
        self.LPlayerCards=[[],[],[]]#플레이어 3명
        self.LDealerCards=[]
        self.delarImage=p=PhotoImage(file=self.fileRoute+"cardback.gif")
        #기본 라벨 셋업
        self.SetupLabel()
        self.SetupButton()


        self.window.mainloop()




if __name__=='__main__':
    MainGUI()