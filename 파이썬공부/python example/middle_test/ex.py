N=eval(input())  #N값

def IsPalindrome(num):
    s=str(num)
    for i in range(len(s)//2):
        if s[i]!=s[-(i+1)]:
            return False
    return True

def IsPrime(num) :
    for i in range(2,num):
        if num%i==0:
            return False
    return True

initNum=N
while True:
    if IsPalindrome(initNum) and IsPrime(initNum):
        print(initNum)
        break
    else:
        initNum+=1