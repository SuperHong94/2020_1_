class Stock:
    def __init__(self,name,symbol,previousPrice,currentPrice):
        self.__name=name
        self.__symbol=symbol
        self.__previousPrice=previousPrice
        self.__currentPrice=currentPrice
    def getName(self):
        return self.__name
    def getSymbol(self):
        return self.__symbol
    def getPreviousPrice(self):
        return self.__previousPrice
    def setPreviousPrice(self,value):
        self.__previousPrice=value
    def getCurrentPrice(self):
        return self.__currentPrice
    def setCurrentPrice(self,value):
        self.__currentPrice=value
    def getChangePercent(self):
        return "{0:.2f}%".format(\
            100*(self.__currentPrice-self.__previousPrice)/self.__previousPrice)
stock=Stock("intel","INTC",20500,20350)

print("가격 변화%:",stock.getChangePercent())