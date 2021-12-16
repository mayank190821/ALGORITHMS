def bubbleSort(arr):
    n = len(arr)
    k=0
    for i in range(n):
        for j in range(n-i-1):
            k+=1
            if arr[j+1]<arr[j]:
                arr[j],arr[j+1] = arr[j+1],arr[j]
            print("Step:",k,arr)

arr =[4,6,5,8,1,2,3]
bubbleSort(arr)
print("Ans",arr)