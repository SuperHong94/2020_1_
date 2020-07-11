class Player:
    def __init__(self, name):
        self.name = name
        self.cards = []
        self.N = 0
    def inHand(self):
        return self.N
    def addCard(self,c):
        self.cards.append(c)
        self.N += 1
    def reset(self):
        self.N = 0
        self.cards.clear()


    def loyalStrateF(self,cardLst,imgLst):
        truePoint=0
        imgSet=set(imgLst)
        img=None
        if len(imgSet)>3:
            return False
        for i in range(len(cardLst)):
            if 10==cardLst[i]:
                truePoint +=1
            if 11 ==cardLst[i]:
                truePoint += 1
            if 12==cardLst[i]:
                truePoint += 1
            if 13==cardLst[i]:
                truePoint += 1
            if 1 ==cardLst[i]:
                truePoint += 1
        if truePoint!=5:
            return False
        pass

    def fourCard(self,cardLst):
        lst=[]
        for i in cardLst:
            lst.append(i.getValue())

        lst.sort()
        for j in range(1,13+1):
            if lst.count(j)==4:
                return True
        return False

    def Triple(sef,cardLst):
        lst=[]
        for i in cardLst:
            lst.append(i.getValue())

        lst.sort()
        for j in range(1,13+1):
            if lst.count(j)==3:
                return True
        return False

    def TwoPair(sef,cardLst):
        lst=[]
        for i in cardLst:
            lst.append(i.getValue())

        truePoint=0
        lst.sort()
        for j in range(1,13+1):
            if lst.count(j)==2:
                truePoint+=1
        if truePoint>1:
            return True
        return False
    def onePair(sef,cardLst):
        lst=[]
        for i in cardLst:
            lst.append(i.getValue())

        lst.sort()
        for j in range(1,13+1):
            if lst.count(j)==2:
                return True
        return False

    def fullHouse(self,cardLst):
        lst=[]
        for i in cardLst:
            lst.append(i.getValue())
        lst.sort()
        for j in cardLst:
            if lst.count(j)==3:
                for k in cardLst:
                    if lst.count(k)==2:
                        return True
        return False

    def flush(self,cardLst):
        lst = []
        for i in cardLst:
            lst.append(i.getsuit())
        lst.sort()
        for j in range(1, 13 + 1):
            if lst.count(j) == 5:
                return True
        return False

    def Straight(self, cardLst):
        lst = []
        for i in cardLst:
            lst.append(i.getValue())

        lst.sort()
        truePoint=0
        for i in range(len(lst)-1):
            if truePoint==4:
                return True
            if lst[i+1]-lst[i]==1:
                truePoint+=1
            else:
                truePoint=0




    def judgemuent(self,boards): #스트링 반환
        cardLst=[]
        for i in self.cards:
            cardLst.append(i)

        for j in boards:
            cardLst.append(j)


        if self.fourCard(cardLst):
            return 100
        elif self.fullHouse(cardLst):
            return 90
        elif self.flush(cardLst):
            return 80
        elif self.Straight(cardLst):
            return 70
        elif self.Triple(cardLst):
            return 60
        elif self.TwoPair(cardLst):
            return 50
        elif self.onePair(cardLst):
            return 40
        else:
            lst=[]
            for k in cardLst:
                lst.append(k.getValue())

            return max(lst)





