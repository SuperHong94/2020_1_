T=eval(input())


while T!=0:
    N=eval(input())
    line1=list(input())
    line2=list(input())
    num1=0
    num2=0
    for i in range(N):
        if line1[i]=='W' and line2[i]=='B':
            num1+=1
        elif line1[i]=='B' and line2[i]=='W':
            num2+=1

    result=0
    if num1>num2:
        result=num1
    else:
        result=num2
    print(result)
    T-=1
