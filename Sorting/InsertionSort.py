def insertionSort(l):
    for i in range(1,len(l)):
        key = l[i]
        j=i-1
        while j>=0 and key <l[j]:
            l[j+1] =l[j]
            j-=1
        l[j+1] =key
        print("Step :",i," ",l)


l = [5,2,3,4,9]
insertionSort(l)
print("Ans ",l)