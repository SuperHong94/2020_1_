chaseBoard=[
[],
[],
[],
[],
[],
[],
[],
[],
]

for i in range(0,8):
    temp=input()
    for j in temp:
        chaseBoard[i].append(j)
    temp=""


count=0

for i in range(0,8):
    for j in range(0,8):
        if i%2==0:
            if chaseBoard[i][j]=='F'and j%2==0:
                count+=1
        else:
            if chaseBoard[i][j]=='F'and j%2==1:
                count+=1

print(count)