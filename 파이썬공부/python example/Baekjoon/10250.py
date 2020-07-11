T=int(input()) #테스트 데이터 입력
H=[]
W=[]
N=[]
for i in range(T):
    a, b, c=input().split(" ")
    H.append(int(a))
    W.append(int(b))
    N.append(int(c))

floor=[0]*T
room=[0]*T
result=[0]*T
for i in range(T):
    if N[i]%H[i]==0:
        floor[i]=H[i]*100
        room[i]=N[i]//H[i]
        result[i]=floor[i]+room[i]
    else:
        floor[i]=N[i]%H[i]
        floor[i]*=100
        room[i] = N[i] // H[i]
        result[i] = floor[i] + room[i]+1


for i in range(T):
    print(result[i])