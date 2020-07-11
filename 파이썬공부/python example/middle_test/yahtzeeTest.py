

N=[eval(x) for x in input().split()]

if len(set(N))>3:
    N.sort()
    s=0
    count=0
    for i in range(3):
         if abs(N[i]-N[i+1])>1:
                    count+=1
    for i in range(1,4):
        if abs(N[i] - N[i + 1]) >1:
                    count += 1

    if count>=2:
        print("NO")
    else:
        print("YES")
else:
    print("NO")