from tkinter import*
class Card:
    def __init__(self,value):
        self.type=(value//4)+1 # 1월~10월
        self.num=(value%4)+1 #광인지 판별하고 이미지파일 읽기
        self.cImage=PhotoImage(file='Resource/GodoriCards/'+str(self.type)+'.'+str(self.num)+'.gif')