import is_anagram

print("Enter the words followed by commas like this: ")
print("eat,tea,tan,ate,nat,bat")
input_user = input("Enter the words: ")

inp = []
input_user = input_user.split(",")

for x in input_user:
    inp.append(x)

arrFinal = []
i = 0
for x in inp:
    arrPrint = []
    for b in inp:
        if (is_anagram.is_anagram(str(x), str(b))):
            arrPrint.append(b)
    arrFinal.append(arrPrint)
    i = i + 1

aux = arrFinal[0][0]
for i, j in enumerate(arrFinal[:-1]):
    try:
        compOne = j[0]
        compTwo = arrFinal[i + 1][0]
        if (is_anagram.is_anagram(compOne, compTwo)):
            arrFinal.remove(j)
    except Exception:
        pass
arrFinal.remove(arrFinal[0])
print(arrFinal)
