import time
class StopWatch:
    def __init__(self):
        self.__startTime=time.time()
    def getStartTime(self):
        return self.__startTime
    def getEndTime(self):
        return self.__endTime
    def start(self):
        self.__startTime=time.time()
    def stop(self):
        self.__endTime=time.time()
    def getElapsedTime(self):
        return int((self.__endTime-self.__startTime)*1000)
s=StopWatch()
sum=0
for i in range(1000000):
    sum+=i
s.stop()
print("1부터 1000000까지 더하는 데 걸리는 밀리초:",s.getElapsedTime())