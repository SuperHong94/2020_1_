from functools import *
def intersect(*ar):  #함수인자이름앞에*은 가변인자리스트 (3장)
     return reduce(__intersectSC,ar)

def __intersectSC(listX,listY):
    setList=[]
    for x in listX:
        if x in listY:
            setList.append(x)
    return setList

def difference(*ar):
    setList=[]
    intersectSet=intersect(*ar) #여기 *은 듀플로받은것을 풀어 해친다.
    unionSet=union(*ar)
    for x in unionSet:
        if not x in intersectSet:
            setList.append(x)
    return setList
def union(*ar):
    setList=[]
    for item in ar:
        for x in item:
            if not x in setList:
                setList.append(x)
    return setList