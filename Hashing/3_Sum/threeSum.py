'''
Author: Tushar Nitave
'''

nums = [-1, 0, 1, 2, -1, -4]

hashTable = []
result = []  # result containing duplicate values
finalresult = []  # stores final result without duplicate values

for i in range(0, len(nums) - 2):

    for j in range(i + 1, len(nums) - 1):
        x = -(nums[i] + nums[j])
        if (x in hashTable):
            result.append([])
            result[len(result) - 1].append(x)
            result[len(result) - 1].append(nums[i])
            result[len(result) - 1].append(nums[j])
        else:
            hashTable.append(nums[j])

for i in range(len(result)):
    result[i].sort()
    if not result[i] in finalresult:
        finalresult.append(result[i])

print(finalresult)
