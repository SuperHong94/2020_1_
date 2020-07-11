T=eval(input())

for i in range(T):
    A = input().split(' ')

    trueNum=0
    if A[1]=="*":
        trueNum=int(A[0])*int(A[2])
    elif A[1]=="+":
        trueNum = int(A[0])+int(A[2])
    elif A[1] == "-":
        trueNum =int(A[0])-int(A[2])
    elif A[1] == "/":
        trueNum = int(A[0])/int(A[2])

    if int(A[4])==trueNum:
        print("correct")
    else:
        print("wrong answer")