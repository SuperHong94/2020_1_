SLOW =1
MEDIUM=2
FAST=3

class Fan:
    def __init__(self, speed=SLOW, radius=5, color="blue", on=False):
        self.__speed= speed
        self.__radius = radius
        self.__color = color
        self.__on = on

    def getSpeed(self):
        return self.__speed
    def setSpeed(self, value):
        self.__speed = value

    def getRadius(self):
        return self.__radius
    def setRadius(self,value):
        self.__radius=value

    def getColor(self):
        return self.__color

    def setColor(self, value):
        self.__color = value

    def getOn(self):
        return self.__on

    def setOn(self, value):
        self.__on= value

def displayFan(fan):
    print("speed:{0},color:{1},radius:{2},on:{3}".format(\
        fan.getSpeed(),fan.getColor(),fan.getRadius(),fan.getOn()))

fan1=Fan(FAST,10,"yellow",True)
fan2=Fan(MEDIUM,5,"blue",False)
displayFan(fan1)
displayFan(fan2)