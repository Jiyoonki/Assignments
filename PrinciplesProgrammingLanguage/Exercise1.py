def top_count(x):
    z = I.count(x)
    return z

def countall(x):
    z = 0
    for i in I:
        if type(i) == list:
            j = i.count(x)
            z = z + j
    z = z + top_count(x)
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

while True:
    x = input("please type an element to count:")
    print("count '"+ x +"' in %s -->" %I, top_count(x))
    print("countall '"+ x +"' in %s -->" %I, countall(x))