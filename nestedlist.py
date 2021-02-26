a=[]
b=[]
for i in range(int(input())):
    name=str(input())
    score=float(input())
    a.append([name,score])
    if score not in b:
        b.append(score)
b.sort()
c=[]
for j in a:
    if j[-1]==b[1]:
        c.append(j[0])
c.sort()
for i in c:
    print(i)
