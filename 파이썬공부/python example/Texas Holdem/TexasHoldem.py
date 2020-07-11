
from tkinter import *
from tkinter import font
from winsound import *
from Card import *
from Player import *
import random
def soundDing():
    PlaySound('sounds/ding.wav', SND_FILENAME)
def soundchip():
    PlaySound('sounds/chip.wav', SND_FILENAME)

class BlackJack:
    def __init__(self):
        self.window = Tk()
        self.window.title("TexasHoldem")
        self.window.geometry("800x600")
        #self.window.configure(bg="green")
        self.fontstyle = font.Font(self.window, size=24, weight='bold', family='Consolas')
        self.fontstyle2 = font.Font(self.window, size=16, weight='bold', family='Consolas')
        self.back = PhotoImage(file="cards/table.gif")
        self.imageLabel = Label(self.window, image=self.back)
        self.imageLabel.place(x=0,y=0)
        self.setupButton()
        self.setupLabel()
        self.turn=0
        self.player = Player("player")
        self.dealer = Player("dealer")
        self.Board  = Player("board")
        self.betMoney = 10
        self.playerMoney = 990
        self.nCardsDealer = 0
        self.nCardsPlayer = 0
        self.nCardsBoard = 0
        self.LcardsPlayer = []
        self.LcardsDealer = []
        self.LcardsBoard = []
        self.deckN = 0
        self.window.mainloop()

    def setupButton(self):
        self.Check = Button(self.window, text="Check", width=6, height=1, font=self.fontstyle2, command=self.pressedCheck)
        self.Check.place(x=50, y=500)
        self.B1 = Button(self.window, text="Bet x1", width=6, height=1, font=self.fontstyle2, command=self.pressedB1)
        self.B1.place(x=150, y=500)
        self.B2 = Button(self.window, text="Bet x2", width=6, height=1, font=self.fontstyle2, command=self.pressedB2)
        self.B2.place(x=250, y=500)

        self.Deal = Button(self.window, text="Deal", width=6, height=1, font=self.fontstyle2, command=self.pressedDeal)
        self.Deal.place(x=600, y=500)
        self.Again = Button(self.window, text="Again", width=6, height=1, font=self.fontstyle2, command=self.pressedAgain)
        self.Again.place(x=700, y=500)

        self.Deal['state'] = 'disabled'
        self.Deal['bg'] = 'gray'
        self.Again['state'] = 'disabled'
        self.Again['bg'] = 'gray'

    def setupLabel(self):
        self.LbetMoney = Label(text="$10", width=4, height=1, font=self.fontstyle, bg="green", fg="cyan")
        self.LbetMoney.place(x=200, y=450)
        self.LplayerMoney = Label(text="You have $990", width=15, height=1, font=self.fontstyle, bg="green", fg="cyan")
        self.LplayerMoney.place(x=500, y=450)
        self.LplayerPts = Label(text="", width=20, height=1, font=self.fontstyle2, bg="green", fg="white")
        self.LplayerPts.place(x=300, y=400)
        self.LdealerPts = Label(text="", width=20, height=1, font=self.fontstyle2, bg="green", fg="white")
        self.LdealerPts.place(x=300, y=100)
        self.Lstatus = Label(text="", width=15, height=1, font=self.fontstyle, bg="green", fg="white")
        self.Lstatus.place(x=500, y=300)

    def pressedCheck(self):
        self.Check['state'] = 'disabled'
        self.Check['bg'] = 'gray'
        self.B1['state'] = 'disabled'
        self.B1['bg'] = 'gray'
        self.B2['state'] = 'disabled'
        self.B2['bg'] = 'gray'
        self.Deal["state"] = "active"
        self.Deal["bg"] = "white"
        PlaySound('sounds/chip.wav', SND_FILENAME)


    def pressedB1(self):
        self.betMoney *=2
        if self.betMoney <= self.playerMoney:
            self.LbetMoney.configure(text="$" + str(self.betMoney))
            self.playerMoney -= self.betMoney
            self.LplayerMoney.configure(text="You have $" + str(self.playerMoney))
            self.Check['state'] = 'disabled'
            self.Check['bg'] = 'gray'
            self.B1['state'] = 'disabled'
            self.B1['bg'] = 'gray'
            self.B2['state'] = 'disabled'
            self.B2['bg'] = 'gray'
            self.Deal["state"] = "active"
            self.Deal["bg"] = "white"
            PlaySound('sounds/chip.wav', SND_FILENAME)
        else:
            self.betMoney /=2

    def pressedB2(self):
        self.betMoney *= 3
        if self.betMoney <= self.playerMoney:
            self.LbetMoney.configure(text="$" + str(self.betMoney))
            self.playerMoney -= self.betMoney
            self.LplayerMoney.configure(text="You have $" + str(self.playerMoney))
            self.Check['state'] = 'disabled'
            self.Check['bg'] = 'gray'
            self.B1['state'] = 'disabled'
            self.B1['bg'] = 'gray'
            self.B2['state'] = 'disabled'
            self.B2['bg'] = 'gray'
            self.Deal["state"] = "active"
            self.Deal["bg"] = "white"
            PlaySound('sounds/chip.wav', SND_FILENAME)
        else:
            self.betMoney /=3



    def pressedAgain(self):
        for i in range(self.dealer.inHand()):
            self.LcardsDealer[i].image= ""
            self.LcardsDealer[i].place(x=250 + i * 30, y=1350)

        for i in range(self.player.inHand()):
            self.LcardsPlayer[i].image = ""
            self.LcardsPlayer[i].place(x=250 + i* 30, y=3150)

        for i in range(self.Board.inHand()):
            self.LcardsBoard[i].image = ""
            self.LcardsBoard[i].place(x=250 + i* 30, y=3150)
        self.betMoney = 10
        self.turn = 0
        self.player.reset()
        self.dealer.reset()
        self.Board.reset()
        self.betMoney = 0
        self.nCardsDealer = 0
        self.nCardsPlayer = 0
        self.LcardsPlayer=[]
        self.LcardsDealer=[]
        self.LcardsBoard=[]
        self.deckN = 0
        self.Check['state']='active'
        self.Check['bg']='white'
        self.B1['state']= 'active'
        self.B1['bg'] = 'white'
        self.B2['state']='active'
        self.B2['bg'] = 'white'
        self.Deal['state'] = 'disabled'
        self.Deal['bg'] = 'gray'
        self.Again['state'] = 'disabled'
        self.Again['bg'] = 'gray'
        self.LdealerPts.configure(text="")
        self.LplayerPts.configure(text="")
        self.Lstatus.configure(text="")

    def deal(self):
        if self.turn==0:  #첫번째 턴일때
            self.player.reset()
            self.dealer.reset()
            self.cardDeck = [i for i in range(52)]# 카드 덱 52장 셔플링 0,1,,.51
            random.shuffle(self.cardDeck)
            self.deckN =0
            self.hitPlayer( 0 )
            self.hitDealer(0)
            self.hitPlayer(1)
            self.hitDealer(1)
            self.nCardsPlayer =2
            self.nCardsDealer =2
            self.turn += 1
        elif self.turn==1: #두번째 턴
            self.drawBoard(0)
            self.drawBoard(1)
            self.drawBoard(2)
            self.turn += 1
        elif self.turn==2:
            self.drawBoard(3)
            self.turn += 1
        elif self.turn==3:
            self.drawBoard(4)
            self.turn += 1
            self.checkWinner()


        self.Deal['state'] = 'disabled'
        self.Deal['bg'] = 'gray'


    def pressedDeal(self):
        self.Check['state'] = 'active'
        self.Check['bg'] = 'gray'
        self.B1['state'] = 'active'
        self.B1['bg'] = 'gray'
        self.B2['state'] = 'active'
        self.B2['bg'] = 'gray'
        self.Deal['state'] = 'disabled'
        self.Deal['bg'] = 'gray'

        self.deal()
    def hitPlayer(self, n):#플레이어 카드뽑기
        newCard = Card(self.cardDeck[self.deckN])
        self.deckN += 1
        self.player.addCard(newCard)
        p = PhotoImage(file="cards/" + newCard.filename())
        self.LcardsPlayer.append(Label(self.window, image=p))
        # 파이썬은 라벨 이미지 레퍼런스를 갖고 있어야 이미지가 보임
        self.LcardsPlayer[self.player.inHand() - 1].image = p
        self.LcardsPlayer[self.player.inHand() - 1].place(x=50 + n * 80, y=350)

        #PlaySound('sounds/cardFlip1.wav', SND_FILENAME)

    def drawBoard(self, n):#플레이어 카드뽑기
        newCard = Card(self.cardDeck[self.deckN])
        self.deckN += 1
        self.Board.addCard(newCard)
        p = PhotoImage(file="cards/" + newCard.filename())
        self.LcardsBoard.append(Label(self.window, image=p))
        # 파이썬은 라벨 이미지 레퍼런스를 갖고 있어야 이미지가 보임
        self.LcardsBoard[self.Board.inHand() - 1].image = p
        self.LcardsBoard[self.Board.inHand() - 1].place(x=150 + n * 80, y=200)
        #PlaySound('sounds/cardFlip1.wav', SND_FILENAME)

    def hitDealer(self,n): #딜러 카드뽑기
        newCard = Card(self.cardDeck[self.deckN])
        self.deckN += 1
        self.dealer.addCard(newCard)
        p = PhotoImage(file="cards/b2fv.png")
        self.LcardsDealer.append(Label(self.window, image=p))
        # 파이썬은 라벨 이미지 레퍼런스를 갖고 있어야 이미지가 보임
        self.LcardsDealer[self.dealer.inHand() - 1].image = p
        self.LcardsDealer[self.dealer.inHand() - 1].place(x=50 + n * 80, y=50)
        #self.LdealerPts.configure(text=str(self.dealer.value()))
        #PlaySound('sounds/cardFlip1.wav', SND_FILENAME)


    def pressedHit(self):
        self.nCardsPlayer += 1
        self.hitPlayer(self.nCardsPlayer)

    def score(self, i):

        print(i)
        if i==100:
            return "포카드"
        elif i==90:
            return "풀하우스"
        elif i==80:
            return "플러쉬"
        elif i==70:
            return "스트레이트"
        elif i==60:
            return "트리플"
        elif i==50:
            return "투페어"
        elif i==40:
            return "원페어"
        else:
            return "족보없음 최대값:"+str(i)
    def checkWinner(self):
        # 뒤집힌 카드를 다시 그린다.
        print("되나?")
        for i in range(self.nCardsDealer):
            p = PhotoImage(file="cards/" + self.dealer.cards[i].filename())
            self.LcardsDealer[i].configure(image=p)  # 이미지 레퍼런스 변경
            self.LcardsDealer[i].image = p  # 파이썬은 라벨 이미지 레퍼런스를 갖고 있어야 이미지가 보임
        self.LdealerPts.configure(text=self.score(self.dealer.judgemuent(self.Board.cards)))
        self.LplayerPts.configure(text=self.score(self.player.judgemuent(self.Board.cards)))

        if self.dealer.judgemuent(self.Board.cards)<self.player.judgemuent(self.Board.cards):
            self.Lstatus.configure(text="You won!!")
            self.playerMoney += self.betMoney*2
        elif self.dealer.judgemuent(self.Board.cards)>self.player.judgemuent(self.Board.cards):
            self.Lstatus.configure(text="Sorry you lost!")
        else:
            self.Lstatus.configure(text="비겼어요")
            self.playerMoney += self.betMoney



        self.betMoney = 10
        self.LplayerMoney.configure(text="You have $" + str(self.playerMoney))
        self.LbetMoney.configure(text="$" + str(self.betMoney))
        self.Check['state'] = 'disabled'
        self.Check['bg'] = 'gray'
        self.B1['state'] = 'disabled'
        self.B1['bg'] = 'gray'
        self.B2['state'] = 'disabled'
        self.B2['bg'] = 'gray'
        self.Deal['state'] = 'disabled'
        self.Deal['bg'] = 'gray'
        self.Again['state'] = 'active'
        self.Again['bg'] = 'white'

    def hitDealerDown(self):
        pass



BlackJack()
