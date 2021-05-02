N = int(input())
A = list(map(int,input().split()))
A.sort()
M = int(input())
li_M = list(map(int,input().split()))
for i in li_M:
    a = 1
    lower = 0
    upper = len(A)-1
    while lower <= upper:
        middle = (lower+upper)//2
        if A[middle] == i:
            print(1)
            a = 0
            break
        elif A[middle] < i :
            lower = middle + 1
        elif A[middle] > i :
            upper = middle - 1
    if a :
        print(0)
