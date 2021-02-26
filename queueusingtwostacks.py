a=[]
for i in range(int(input())):
    b=input().split()
    if b[0]=='2':
        a.pop()
    if b[0]=='1':
        a.insert(0,b[-1])
    if b[0]=='3':
        print(a[-1])
