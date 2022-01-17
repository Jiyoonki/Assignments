def insertion_sort(num):

    for i in range(1, len(num)):
        k = num[i]
        j = i-1
        while j >= 0 and k < num[j] :
                num[j + 1] = num[j]
                j -= 1
        num[j + 1] = k


num = list(map(int, input("input numbers:").split()))

insertion_sort(num)

print ("Sorted:", end="")
for i in range(len(num)):
    print ("% d" % num[i], end="")