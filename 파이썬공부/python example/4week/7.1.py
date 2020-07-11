class Rectangle:
    def __init__(self,width=1,height=1):
        self.width=width
        self.height=height
    def getArea(self):
        return self.width*self.height
    def getPerimeter(self):
        return (self.width+self.height)*2
    def info(self):
        print("width:{0},height:{1},grea:{2},perimeter{3}".format(self.width,
            self.height,self.getArea(),self.getPerimeter()))


r1=Rectangle(4,10)
r1.info()
r2=Rectangle(3.5,35.7)
r2.info()