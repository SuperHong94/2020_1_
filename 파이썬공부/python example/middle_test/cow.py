
N=eval(input())

cowLst=[eval(x) for x in input().split()]




sortLst=[]
for i in range(len(cowLst)):
    sortLst.append(cowLst[i])
sortLst.sort()

cnt=0


for i in range(N):
    if sortLst[i]==cowLst[i]:
        cnt+=1
    else:
        temp=cowLst[i]
        for k in range(i,N-1):
            cowLst[k]=cowLst[k+1]
        for j in range(len(sortLst)):
            if(sortLst[j]==temp):
                cowLst[j]=sortLst[j]



print(cnt)
