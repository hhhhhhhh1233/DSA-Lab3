# DSA-Lab3

## Python program that that'll generate the perfect tree
```
import random

def PerfectTree(arr):
    if len(arr) == 1:
        print(arr[0])
        return 
    if len(arr) == 2:
        print(arr[0])
        print(arr[1])
        return
    arr = sorted(arr)
    print(arr[(len(arr))//2])
    PerfectTree(arr[:(len(arr))//2])
    PerfectTree(arr[((len(arr))//2)+1:])

testArr = []
for i in range(15):
    num = random.randint(0,20)
    while num in testArr:
        num = random.randint(0,20)
    testArr.append(num)

PerfectTree(testArr)
```
