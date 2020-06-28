


class Player:
    def __init__(self):
        self.money=0
        self.cards=[]
        self.madeLst=[]
        self.typeLst=[] #플레이어 카드들의 타입(1월~12월)들을 넣어준다.
        self.results=[]# 족보비교 카드 인덱스 리스트
        self.rScore=None #튜플로 점수와하고 이름 넘겨주자.
        self.dan=0

    def IsMade(self):
        if (8 in self.typeLst) and(self.typeLst.count(1)>=2): #콩콩팔
            self.dan = 1
            return [1,1,8,"콩콩팔(1 1 8)"]
        elif (1 in self.typeLst) and (2 in self.typeLst) and (7 in self.typeLst) : #삐리칠
            self.dan = 1
            return [1,2,7,"삐리칠(1 2 7)"]
        elif (1 in self.typeLst) and (3 in self.typeLst) and (6 in self.typeLst) : #물삼육
            self.dan = 1
            return [1,3,6,"물삼육(1 3 6)"]
        elif (1 in self.typeLst) and (4 in self.typeLst) and (5 in self.typeLst): #빽새오
            self.dan = 1
            return [1, 4, 5,"빽새오(1 4 5)"]
        elif (1 in self.typeLst) and (9 in self.typeLst) and (10 in self.typeLst): #삥구장
            self.dan = 1
            return [1, 9, 10,"삥구장(1 9 10)"]
        elif(6 in self.typeLst) and (self.typeLst.count(2)>=2):  # 니니육
            self.dan = 2
            return [2, 2, 6,"니니육(2 2 6)"]
        elif (2 in self.typeLst) and (3 in self.typeLst) and (5 in self.typeLst):  # 이삼오
            self.dan = 2
            return [2, 3, 5,"이삼오(2 3 5)"]
        elif (2 in self.typeLst) and (8 in self.typeLst) and (10 in self.typeLst):  # 이판장
            self.dan = 2
            return [2, 8, 10,"이판장(2 8 10)"]
        elif  (self.typeLst.count(3)>=2)and (4 in self.typeLst):  # 심심새
            self.dan = 3
            return [3, 3, 4,"심심새(3 3 4)"]

        elif (3 in self.typeLst) and (7 in self.typeLst) and (10 in self.typeLst):  # 삼칠장
            self.dan = 3
            return [3, 7, 10,"삼칠장(3 7 10)"]
        elif (3 in self.typeLst) and (8 in self.typeLst) and (9 in self.typeLst):  # 삼빡구
            self.dan = 3
            return [3, 8, 9,"삼빡구(3 8 9)"]
        elif  (self.typeLst.count(4) >= 2)and (2 in self.typeLst):  # 살살이
            self.dan = 4
            return [4, 4, 2,"살살이(4 4 2)"]
        elif (4 in self.typeLst) and (6 in self.typeLst) and (10 in self.typeLst):  # 사륙장
            self.dan = 4
            return [4, 6, 10,"사륙장(4 6 10)"]
        elif (4 in self.typeLst) and (7 in self.typeLst) and (9 in self.typeLst):  # 사칠구
            self.dan = 4
            return [4, 7, 9,"사칠구(4 7 9)"]
        elif (self.typeLst.count(5) >= 2) and (10 in self.typeLst):  # 꼬꼬장
            self.dan = 5
            return [5, 5, 10,"꼬꼬장(5 5 10)"]
        elif (5 in self.typeLst) and (6 in self.typeLst) and (9 in self.typeLst):  # 오륙구
            self.dan = 5
            return [5, 6, 9,"오륙구(5 6 9)"]
        elif (5 in self.typeLst) and (7 in self.typeLst) and (8 in self.typeLst):  # 오리발
            self.dan = 5
            return [5, 7, 8,"오리발(5 8 8)"]
        elif (self.typeLst.count(6) >= 2) and (8 in self.typeLst):  # 쭉쭉팔
            self.dan = 6
            return [6, 6, 8,"쭉쭉팔(6 6 8)"]
        elif (self.typeLst.count(7) >= 2) and (6 in self.typeLst):  # 철철육
            self.dan = 7
            return [7, 7, 6,"철철육(7 7 6)"]
        elif (self.typeLst.count(8) >= 2) and (4 in self.typeLst):  # 팍팍싸
            self.dan = 8
            return [8, 8, 4,"팍팍싸(8 8 4)"]
        elif (self.typeLst.count(9) >= 2) and (2 in self.typeLst):  # 구구리
            self.dan = 9
            return [9, 9, 2,"구구리(9 9 2)"]
        else:
            return None


    def defineResult(self):
        if (300 in self.results) and (800 in self.results):
            return (3800,"삼팔광땡") #38광땡이 최고점수
        elif(100 in self.results) and (800 in self.results):
            return (1800,"일팔광땡") #18
        elif (100 in self.results) and (300 in self.results):
            return (1300,"일삼광땡")  # 13광땡이

        for i in range(2): #광땡아니면 광땡 점수 제거
            self.results[i]%=100

        if len(set(self.results))==1: #n땡
            if self.results[0]==1:
                return (self.results[0] * 100,"삥땡")  # 점수는 n*100점
            elif self.results[0]==10:
                return (self.results[0] * 100, "장땡")  # 점수는 n*100점
            else:
                return (self.results[0] * 100, str(self.results[0])+"땡")  # 점수는 n*100점

        else: #끗
            temp=self.results[0]+self.results[1]
            if temp%10==0:
                return (temp%10,"망통")
            else:
                return (temp%10,str(temp%10)+"끗")




    def judgement(self):
        for card in self.cards: #카드의 type을 type리스트에 추가
            self.typeLst.append(card.type)
        self.madeLst=self.IsMade()

        if self.madeLst!=None:
            tempLst=self.madeLst[:3]
            for i in range(5):
                if not(self.cards[i].type in tempLst):
                    if (self.cards[i].num==1)and(self.cards[i].type==1 or self.cards[i].type==3 or self.cards[i].type==8):
                        self.results.append(self.cards[i].type*100) #광이면 100 곱한다. ex) 1광==100 3광==300 8광==800
                    else:
                        self.results.append(self.cards[i].type)
                else: #중복해서 있지않게하기위해서 ex)
                    tempLst.remove(self.cards[i].type)

            self.rScore=self.defineResult()

