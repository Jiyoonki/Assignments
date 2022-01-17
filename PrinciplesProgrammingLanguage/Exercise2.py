def reverse(x):
    z = x[::-1]

    return z

def twist(x):
    z=[]
    j = reverse(x)

    for i in j:
        if type(i) == list:
            i = reverse(i)
        z.append(i)

    return z

I = []
print("Instruction:\n 1.Type \"1\" to add a top level element\n 2.Type \"2\" to add a 2nd level element\n 3.Type \"done\" to finish insertion")
while True:
    a = input()

    if a == "1":
        top = input("add one top level element:")
        top = top.split(" ")
        for i in top:
            I.append(i)
        print(I)

    elif a == "2":
        second = input("add one 2nd level element:")
        second = second.split(" ")
        I.append(second)
        print(I)

    elif a == "done":
        break

    else:
        print("please follow the instruction")


print("reverse %s -->" %I, reverse(I))
print("twist %s -->" %I, twist(I))