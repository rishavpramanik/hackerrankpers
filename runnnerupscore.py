if __name__ == '__main__':
    n = int(input())
    arr = (input().split())
    for i in range(n):
        arr[i]=int(arr[i])
    arr.sort(reverse=False)
    k=arr.count(arr[-1])
    print(arr[-k-1])
