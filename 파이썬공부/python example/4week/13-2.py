f= input("파일 이름을 입력하세요: ")
infile=open(f,"r")

s=infile.read()#전체를 읽기
print('문자'+str(len(s)),'개')
print('단어'+str(len(s.split())),'개')
print('행'+str(len(s.split('\n'))),'개')