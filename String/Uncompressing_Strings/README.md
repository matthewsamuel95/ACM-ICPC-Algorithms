Arya has 2 strings, s and t. She has been given a task to uncompress the string s and verify if string t can be constructed. While uncompressing the string s, she can repeat each letter in s any non-zero number of times, i.e for s="aab", possible uncompressed forms can be "aabbb", "aaabb" etc.

Determine if she is able to perform the task.

### Input:

The first line contains an integer T, the number of test cases.
For each test case, the first line contains the string s and second line contains the string t.

Sample:
```sh
2
aaa
aa
aa
aaa
```

### Constraints:

1<=T<= 50,
1<=|s|<=200,
1<=|t|<=1000,

### Output:

For each test case, print "Yes" if Arya is able to perform the task, else print "No" in a new line.

Sample
```sh
NO
YES
```
