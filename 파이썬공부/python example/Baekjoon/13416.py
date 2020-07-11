
T=eval(input())
for i in range(T):
    N=eval(input())
    result=0
    for j in range(N):
        A=[eval(x) for x in input().split(' ')]
        if max(A)>0:
            result+=max(A)
    print(result)


