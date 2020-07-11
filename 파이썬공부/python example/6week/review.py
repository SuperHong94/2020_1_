'''from tkinter import *
WIDTH=300
HEIGHT=300
window=Tk()
canvas=Canvas(window,bg="white",width=WIDTH,height=HEIGHT)
canvas.create_rectangle(WIDTH/2-WIDTH*0.4,HEIGHT/2-HEIGHT*0.4,WIDTH/2+WIDTH*0.4,HEIGHT/2+HEIGHT*0.4,tags="shape")
canvas.pack()
v=IntVar()
def display():
    print(v.get())
    canvas.delete('shape')
    if v.get()==1:
        canvas.create_rectangle(WIDTH / 2 - WIDTH * 0.4, HEIGHT / 2 - HEIGHT * 0.4, WIDTH / 2 + WIDTH * 0.4,
                                HEIGHT / 2 + HEIGHT * 0.4, tags="shape")
    else:
        canvas.create_oval(WIDTH / 2 - WIDTH * 0.4, HEIGHT / 2 - HEIGHT * 0.4, WIDTH / 2 + WIDTH * 0.4,
                                HEIGHT / 2 + HEIGHT * 0.4, tags="shape")


Radiobutton(window,text="직사각형",variable=v,value=1,command=display).pack()
Radiobutton(window,text="타원",variable=v,value=2,command=display).pack()
f=IntVar()
Checkbutton(window,text="타원",variable=f).pack()
window.mainloop()'''

'''f=open("abc.txt","r")
s=f.read()
removeString=input("제거할 문자열을 입력하세용: ")
newString=s.replace(removeString,' ')
f.close()
outfile=open("abc.txt","w")
print(newString,file=outfile,end=' ')
outfile.close()
'''
from tkinter import *
import  tkinter.messagebox #에러메시지를 출력하는 모듈
from tkinter.filedialog import askopenfilename #파일 오픈 대화상자
def openFile():
    fn=askopenfilename()
    filename.set(fn)

def result():
    fn=filename.get()
    try:
        infile=open(fn,"r")
        counts=[0]*26
        for line in infile:
            lowerline=line.lower()
            for ch in lowerline:
                if ch.isalpha():
                    counts[ord(ch)-ord('a')]+=1
        maxCounts = max(counts)
        width=int(canvas['width'])/26
        height=int(canvas['height'])
        heightBar = height * 0.75
        widthBar = width - 20
        for i in range(26):
            canvas.create_rectangle(i*widthBar/26+10,height-heightBar*counts[i]/maxCounts-20,(i+1)*widthBar/26,height-20)
            canvas.create_text(i * widthBar / 26 + 5 + 0.5 * widthBar / 26, height - 10, text=chr(i + ord('a')))




        infile.close()
    except IOError:
        tkinter.messagebox.showwarning(fn + "파일이 존재하지 않습니다.")
    pass
f="abc.txt"
infile=open(f,"r")
s=infile.read()
window=Tk()
frame1=Frame(window)
canvas=Canvas(frame1,bg="white",width=500,height=200)
canvas.pack()
frame1.pack()


frame2=Frame(window)
frame2.pack()
Label(frame2,text="파일명을 입력하세요:").pack(side=LEFT)
filename=StringVar()
Entry(frame2,width=20,textvariable=filename).pack(side=LEFT)
Button(frame2,text="열기",command=openFile).pack(side=LEFT)
Button(frame2,text="결과보기",command=result).pack(side=LEFT)
window.mainloop()


