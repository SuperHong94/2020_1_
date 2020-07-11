
matrix=[] # 전역변수 :3X3틱택토 보드 자료구조
def check(): #3개 연속인것을 찾으면 O/x를 반환하고 아니면 빈문자열 반환
    for i in range(3): #행과 열 가로/세로에 대해서 3개 연속 검사
        player=matrix[i][0] #i행의 3개 열이 3개 연속인지 검사 (가로 검사)
        if player !=' 'and player==matrix[i][1]and player==matrix[i][2]:
            return player
        player = matrix[0][i]  # i열의 3개 행이 3개 연속인지 검사 (세로 검사)
        if player != ' ' and player == matrix[1][i] and player == matrix[2][i]:
            return player
    # 대각선검사
    player=matrix[0][0]
    if player != ' ' and player == matrix[1][1] and player == matrix[2][2]:
        return player
    player = matrix[0][2]
    if player != ' ' and player == matrix[1][1] and player == matrix[2][0]:
        return player
    return ' '
def drawBoard():
    for i in range(3):
        print('----------------')
        for j in range(3):
            print('|',matrix[i][j]," ",end='')
        print('|')
    print('----------------')
def main():
    for i in range(3):
        matrix.append([])
        for j in range(3):
            matrix[i].append(' ') # 공란 문자열 삽입

    drawBoard()
    turn=True   #부울 변수 번갈아가면서 x, O 플레이어 차례를 나타냄
    for i in range(9):
        if turn:#x 플레이어 차례
            row=eval(input('플레이어 x의 행(0,1, 또는 2)입력:'))
            col=eval(input('플레이어 x의 열(0,1, 또는 2)입력:'))
            if matrix[row][col]==' ':
                matrix[row][col]='X'
                turn = not turn
            else:
                print("이미 있습니다. 다시 입력 해주세요")
        else: #o플레이어 차례
            row = eval(input('플레이어 o의 행(0,1, 또는 2)입력:'))
            col = eval(input('플레이어 o의 열(0,1, 또는 2)입력:'))
            if matrix[row][col] == ' ':
                matrix[row][col] = 'O'
                turn=not turn
            else:
                print("이미 있습니다. 다시 입력 해주세요")

        drawBoard()
        player=check()
        if player !=' ':
            print('플레이어',player,'가 이겼습니다.')
            break
    if i==8:
        print('비겼습니다.')


main()