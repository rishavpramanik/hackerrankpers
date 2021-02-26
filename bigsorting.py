n = int(input())
u={}
for _ in range(n):
        x=input()
        try:
            u[len(x)].append(x)
        except KeyError:
            u[len(x)]=[x]
for i in sorted(u):
    for j in sorted(u[i]):
        print(j)
