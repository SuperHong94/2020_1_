N,M=input().split()

nums=[eval(x) for x in input().split()]
copyNum=[]
for p in range(len(nums)):
    copyNum.append(nums[p])

reLst=[]
for i in range(int(M)):
    r=0
    reLst.clear()
    d1,d2=input().split()

    nums[int(d1)-1]=0
    nums[int(d2)-1]=0
    for j in range(2):
        r+=max(nums)
        inx=nums.index(max(nums))
        reLst.append(inx)
        nums[inx]=0

    print(r)
    for z in range(len(reLst)):
        nums[reLst[z]]=copyNum[reLst[z]]

