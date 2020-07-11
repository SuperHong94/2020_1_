users=[]


while True:
    user=input("이름을 입력해주요: ")

    if users.count(user)==0 and len(user)<6:
        users.append(user)
    else:
        print("이미 있습니다.")

    print("현재 사용자 목록: ")
    print(users)

