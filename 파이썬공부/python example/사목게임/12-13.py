#12.5

from tkinter import *

class MainGUI:
    def check(self):  # 4개 연속인것을 찾으면 R/Y를 반환하고 아니면 빈문자열 반환
        # 가로 4개 체크
        for i in range(6):  # 행과 열 가로/세로에 대해서 3개 연속 검사
            for j in range(4):  # col=0,1,2,3
                player = self.matrix[i][j]['text']  # i행의 4개열 연속인지 검사 (가로 검사)
                if player != ' ' and player == self.matrix[i][j + 1]['text']   and player == self.matrix[i][j + 2]['text']   and player == self.matrix[i][
                    j + 3]['text']  :
                    return player

        # 세로 4개 체크
        for i in range(3):  # row 0,1,2
            for j in range(7):  # col=0,1,2,3,4,5,6,7
                player = self.matrix[i][j]['text']  # i행의 4개열 연속인지 검사 (가로 검사)
                if player != ' ' and player == self.matrix[i + 1][j]['text'] and player == self.matrix[i + 2][j]['text'] and player == \
                        self.matrix[i + 3][j]['text']:
                    return player
        # 대각선검사 좌에서 우로
        for i in range(3):  # row=0,1,2
            for j in range(4):  # col=0,1,2,3
                player = self.matrix[i][j]['text']
                if player != ' ' and player == self.matrix[i + 1][j + 1]['text'] and player == self.matrix[i + 2][j + 2]['text'] and player == \
                        self.matrix[i + 3][j + 3]['text']:
                    return player
        # 대각선검사 dn에서 우로
        for i in range(3):  # row=0,1,2
            for j in range(3,7):  # col=3,4,5,6
                player = self.matrix[i][j]['text']
                if player != ' ' and player == self.matrix[i + 1][j - 1]['text'] and player == self.matrix[i + 2][j - 2]['text'] and player == \
                        self.matrix[i + 3][j - 3]['text']:
                    return player
        return ' '

    def findRow(self,col):
        for row in range(5, -1, -1):  # row 5,4,3,2,1,0
            if self.matrix[row][col]['text'] == ' ':
                return row
    def pressed(self,col):
        row=self.findRow(col)
        if not self.done and self.matrix[row][col]['text']==' ':
            if self.turn: #x 차례
                self.matrix[row][col]['image']=self.imageX
                self.matrix[row][col]['text']='X'
            else:
                self.matrix[row][col]['image'] = self.imageO
                self.matrix[row][col]['text'] = 'O'
            self.turn=not self.turn


            if self.check()!=' ':
                self.done=True
                self.explain.set('플레이어'+self.check()+'이겼습니다.')
            elif self.turn:
                self.explain.set('플레이어 X 차례')
            else:
                self.explain.set('플레이어 O 차례')
            if self.count==9:
                self.explain.set('비겼습니다.')
    def refresh(self):
        for i in range(6):
            for j in range(7):
                self.matrix[i][j]['image']=self.imageE
                self.matrix[i][j]['text']=' '
        self.done=False
        self.explain.set('플레이어 X 차례')
        self.turn=True
        self.count=0
    def __init__(self):
        window=Tk()
        window.title("사목게임")
        frame=Frame(window)
        frame.pack()
        self.count=0
        self.matrix=[]
        self.imageX=PhotoImage(file='cross.gif')
        self.imageO=PhotoImage(file='circle.gif')
        self.imageE=PhotoImage(file='empty.gif')
        self.turn=True
        self.done=False
        for i in range(6):
            self.matrix.append([])
            for j in range(7):
                self.matrix[i].append(Button(frame,image=self.imageE,text=' ',\
                                             command=lambda col=j:self.pressed(col)))
                self.matrix[i][j].grid(row=i,column=j)
        frame1=Frame(window)
        frame1.pack()
        self.explain=StringVar()
        self.explain.set("플레이어 X 차례")
        self.label=Label(frame1,textvariable=self.explain)
        self.label.pack(side=LEFT)
        Button(frame1,text='다시 실행',command=self.refresh).pack(side=LEFT)
        window.mainloop()



MainGUI()