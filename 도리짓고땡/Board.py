from tkinter import*
from tkinter import font
import Player
import Card
import random
from winsound import *
class MainGUI:
    def SetupLabel(self):
        for i in range(len(self.players)):
            self.PlayerMoneyL.append(Label(text=str(self.players[i].money) + "만", width=4, height=1, font=self.fontstyle,
                                           bg="green", fg="yellow"))
            self.PlayerMoneyL[i].place(x=70+(i*215),y=500)


        self.totalMoneyL = Label(text=str(self.totalMoney) + "만", width=6, height=1, font=self.fontstyle,
                                  bg="green", fg="yellow")
        self.totalMoneyL.place(x=690, y=500)
        for i in range(7): #플레이어 하나당 7개의 라벨을 추가 마지막은 메이드와 족보 결과 마지막은 승리결과
            self.LDealerTypes.append(Label(self.window,bg='green',font=self.fontstyle,fg='white',
                      text="")) #딜러 라벨 추가
            for j in range(len(self.players)):
                self.LPlayerTypes[j].append( Label(self.window,bg='green',font=self.fontstyle,fg='white',
                      text=""))

         #이미지 리스트
        for i in range(5):  # 이미지 라벨 리스트에 카드 5장 채우기 반복문을 나눈것은 배치의 개념
            self.LDealerCards.append(Label(self.window, image=self.delarImage))
            for j in range(len(self.players)):
                self.LPlayerCards[j].append(Label(self.window, image=""))
    def BetMoney(self,num,value):
        PlaySound('Resource/sounds/chip.wav', SND_FILENAME)
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
            PlaySound('Resource/sounds/cardFlip1.wav', SND_FILENAME)
            self.LDealerCards[0].place(x=100,y=100)
            #플레이어 카드
            for i in range(len(self.players)):
                self.LPlayerCards[i][0].place(x=30+(i*215),y=380)
                self.LPlayerTypes[i][0]['text']=str(self.players[i].cards[0].type)
                self.LPlayerTypes[i][0].place(x=57+(i*215),y=350)

        elif self.turn==2:
            PlaySound('Resource/sounds/cardFlip1.wav', SND_FILENAME)
            for i in range(1,4): #카드 3장 그리기
                self.LDealerCards[i].place(x=100+(i*30), y=100)
                for j in range(len(self.players)):
                    self.LPlayerCards[j][i].place(x=30+(j*215)+(i*30),y=380)
                    self.LPlayerTypes[j][i]['text']=str(self.players[j].cards[i].type)
                    self.LPlayerTypes[j][i].place(x=57 + (j * 215)+(i*30), y=350)


        elif self.turn==3:
            PlaySound('Resource/sounds/cardFlip1.wav', SND_FILENAME)
            for i in range(len(self.LDealerCards)):
                self.LDealerCards[i]['image']= self.dealer.cards[i].cImage
                self.LDealerTypes[i]['text'] = str(self.dealer.cards[i].type)
                self.LDealerTypes[i].place(x=127+(i*30),y=70)
            self.LDealerCards[4].place(x=220, y=100)

            # 플레이어 카드
            for i in range(len(self.players)):
                self.LPlayerCards[i][4].place(x=30 + (i * 215)+120, y=380)
                self.LPlayerTypes[i][4]['text']=str(self.players[i].cards[4].type)
                self.LPlayerTypes[i][4].place(x=57+ (i * 215)+120, y=350)

            #승리자 체크
            self.CheckWinnner()







    def CheckWinnner(self):
        winCnt=0
        for i in range(len(self.players)):
            self.Button5[i]['state'] = 'disable'
            self.Button5[i]['bg'] = 'gray'
            self.Button1[i]['state'] = 'disable'
            self.Button1[i]['bg'] = 'gray'
        self.AgainButton['state']='active'
        self.AgainButton['bg']='white'

        #족보 결과 추가
            #메이드 결과
        self.dealer.judgement()
        if self.dealer.madeLst == None:
            self.LDealerTypes[5]['text'] = "노메이드"

            self.LDealerTypes[5]['fg'] = "blue"
            self.LDealerTypes[5].place(x=127, y=40)
        else:
            self.LDealerTypes[5]['text'] = self.dealer.madeLst[3]+" "+self.dealer.rScore[1]
            self.LDealerTypes[5]['fg'] = "blue"
            self.LDealerTypes[5].place(x=127, y=40)

            numLst = list(self.dealer.madeLst[:5]) #중복피하려고
            for i in range(5): #메이드된거 색깔바꾸기
                if (int(self.LDealerTypes[i]['text'])in self.dealer.madeLst) and (int(self.LDealerTypes[i]['text'])in numLst):
                    numLst.remove(int(self.LDealerTypes[i]['text']))
                    self.LDealerTypes[i]['fg']='yellow'
                    self.LDealerCards[i].place(x=100+(i*30), y=110)

        for i in range(len(self.players)): #"플레이어 족보결과"
            self.players[i].judgement()
            if self.players[i].madeLst==None:
                self.LPlayerTypes[i][5]['text']="노메이드"
                self.LPlayerTypes[i][5]['fg']="blue"
                self.LPlayerTypes[i][5].place(x=50+(i*215),y=320)
            else:
                self.LPlayerTypes[i][5]['text'] = self.players[i].madeLst[3]+" "+self.players[i].rScore[1]
                self.LPlayerTypes[i][5]['fg'] = "blue"
                self.LPlayerTypes[i][5].place(x=50 + (i * 215), y=320)

                numLst = list(self.players[i].madeLst[:5])
                for j in range(5):  # 메이드된거 색깔바꾸기
                    if (int(self.LPlayerTypes[i][j]['text']) in self.players[i].madeLst) \
                            and (int(self.LPlayerTypes[i][j]['text']) in numLst):
                        numLst.remove(int(self.LPlayerTypes[i][j]['text']))
                        self.LPlayerTypes[i][j]['fg'] = 'yellow'
                        self.LPlayerCards[i][j].place(x=30+(i*215)+(j*30),y=390)

        for i in range(len(self.players)):
            if self.dealer.madeLst==None:
                if self.players[i].madeLst!=None:
                    self.LPlayerTypes[i][6]['text']="승리"
                    self.LPlayerTypes[i][6]['fg']="red"
                    self.LPlayerTypes[i][6].place(x=50 + (i * 215), y=280)
                    self.totalMoney += self.players[i].money * 2
                    self.totalMoneyL['text']=str(self.totalMoney)+"만"
                    winCnt+=1

                else: #둘다 노메이드일때
                    self.LPlayerTypes[i][6]['text'] = "무승부"
                    self.LPlayerTypes[i][6]['fg'] = "red"
                    self.LPlayerTypes[i][6].place(x=50 + (i * 215), y=280)

            else:
                if self.players[i].madeLst == None:
                    self.LPlayerTypes[i][6]['text'] = "패배"
                    self.LPlayerTypes[i][6]['fg'] = "red"
                    self.LPlayerTypes[i][6].place(x=50 + (i * 215), y=280)

                else:
                    if self.dealer.rScore[0]>self.players[i].rScore[0]:
                        self.LPlayerTypes[i][6]['text'] = "패배"
                        self.LPlayerTypes[i][6]['fg'] = "red"
                        self.LPlayerTypes[i][6].place(x=50 + (i * 215), y=280)

                    elif self.dealer.rScore[0]<self.players[i].rScore[0]:
                        self.LPlayerTypes[i][6]['text'] = "승리"
                        self.LPlayerTypes[i][6]['fg'] = "red"
                        self.LPlayerTypes[i][6].place(x=50 + (i * 215), y=280)
                        self.totalMoney+=self.players[i].money*2
                        self.totalMoneyL['text']=str(self.totalMoney)+"만"
                        winCnt += 1

                    else:#둘다 메이드인데 점수같을때
                        if self.dealer.dan>self.players[i].dan: #단으로비교
                            self.LPlayerTypes[i][6]['text'] = "패배"
                            self.LPlayerTypes[i][6]['fg'] = "red"
                            self.LPlayerTypes[i][6].place(x=50 + (i * 215), y=280)
                        elif self.dealer.dan<self.players[i].dan:
                            self.LPlayerTypes[i][6]['text'] = "승리"
                            self.LPlayerTypes[i][6]['fg'] = "red"
                            self.LPlayerTypes[i][6].place(x=50 + (i * 215), y=280)
                            self.totalMoney += self.players[i].money * 2
                            self.totalMoneyL['text'] = str(self.totalMoney) + "만"
                            winCnt += 1
                        else:
                            self.LPlayerTypes[i][6]['text'] = "무승부"
                            self.LPlayerTypes[i][6]['fg'] = "red"
                            self.LPlayerTypes[i][6].place(x=50 + (i * 215), y=280)

        if winCnt>0:
            PlaySound('Resource/sounds/win.wav', SND_FILENAME)
        else:
            PlaySound('Resource/sounds/wrong.wav', SND_FILENAME)











    def GamePlay(self):
        if self.turn==1:  #첫번째턴
            self.initDeck()  # 카드 초기화
            for i in range(5):  # "카드 5장 뽑기" 처음부터 다뽑고 그릴때만 보여주면된다.
                self.dealer.cards.append(Card.Card(self.CardeDeck.pop()))  # 딜러 카드 한장받는다.
                for p in self.players:
                    p.cards.append(Card.Card(self.CardeDeck.pop()))  # 카드리스트에서 한장빼서 플레이어에게 준다.
            for i in range(5): #이미지 라벨 리스트에 카드 5장 채우기 반복문을 나눈것은 배치의 개념
                self.LDealerCards[i]['image']=self.delarImage
                for j in range(len(self.players)):
                    self.LPlayerCards[j][i]['image']=self.players[j].cards[i].cImage


        self.drawCards()



    def Deal(self):
        self.DealButton['state'] = 'disable'
        self.DealButton['bg'] = 'gray'
        self.turn += 1  # 턴증가
        self.GamePlay() #게임시작

        pass
    def Again(self):
        PlaySound('Resource/sounds/ding.wav', SND_FILENAME)
        self.turn=0
        self.AgainButton['state'] = 'disable'
        self.AgainButton['bg'] = 'gray'

        for i in range(7):  # 라벨들 안보이는곳으로 보내버리기
            self.LDealerTypes[i]['fg']='white'
            self.LDealerTypes[i].place(x=1000,y=1000)
            for j in range(len(self.players)):
                self.LPlayerTypes[j][i]['fg']='white'
                self.LPlayerTypes[j][i].place(x=1000,y=1000)

        for i in range(5):  # 이미지안보이는곳으로 보내버리기
            self.LDealerCards[i].place(x=1000,y=1000)
            for j in range(len(self.players)):
                self.LPlayerCards[j][i].place(x=1000,y=1000)
        #딜러 초기화
        self.dealer.cards.clear()
        if self.dealer.madeLst!=None:
            self.dealer.madeLst.clear()
        self.dealer.results.clear()
        self.dealer.typeLst.clear()
        self.dealer.rScore = None
        self.dealer.dan=0
        for i in range(len(self.players)):
            self.Button5[i]['state']='active'
            self.Button5[i]['bg']='white'
            self.Button1[i]['state']='active'
            self.Button1[i]['bg']='white'
            self.players[i].cards.clear()
            if self.players[i].madeLst!=None:
                self.players[i].madeLst.clear()
            self.players[i].results.clear()
            self.players[i].typeLst.clear()
            self.players[i].rScore=None
            self.players[i].money=0
            self.players[i].dan=0
            self.PlayerMoneyL[i]['text']=str(self.players[i].money)+"만"
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
        self.window.title("도리짓고땡_2018182041_홍순조")
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
        self.LPlayerCards=[[],[],[]]#플레이어 3명 이미지
        self.LDealerCards=[]
        self.delarImage=p=PhotoImage(file=self.fileRoute+"cardback.gif")
        self.LPlayerTypes=[[],[],[]] # 플레이어 타입리스트 [x][5]번째에 족보 결과 나타낼꺼임
        self.LDealerTypes=[] # 딜러 타입리스트 5번째에 족보결과
        #기본 라벨 셋업
        self.SetupLabel()
        self.SetupButton()


        self.window.mainloop()




if __name__=='__main__':
    MainGUI()