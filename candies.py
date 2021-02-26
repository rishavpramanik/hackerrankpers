def optimalCandies(n,arr):
    candies = [1]*n
    for i in range(n-1):
        if arr[i+1]>arr[i]:
            candies[i+1] = candies[i]+1
    for i in range(n-1,0,-1):
        if arr[i-1]>arr[i] and candies[i-1]<=candies[i]:
            candies[i-1] = candies[i]+1
    return sum(candies)
n = int(input())
arr = [int(input()) for _ in range(n)]
print(optimalCandies(n,arr))
