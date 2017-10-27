# Problem Statement#1
You have a friend named Shivam and he is going to school from his house. He finds out that there are coins scattered on the roads and since he is greedy he wants to collect them all but since he doesn't want to be late for school, he decides to collect as many as he can on his way. He is a student and knows math so he figures he could travel the path in the form of a 2-D grid.

Assume the whole space to be a 2-D block of **MxN** boxes and in each box there are some or no coins, Shivam's house is on the **Top-Left corner** and school is at the **Bottom-Right corner**. Due to his shortage of time he can travel either one step(box) **Right** or **Down** towards the school and collect the coins he find on his way.

Since there are multiple paths possible, he can't figure out which path will yield him the most coins. Help him figure that out.

## Input

You will be given **_T_ Test Cases** and each test case will contain:
- **First line** will have the size of grid - **M N**
- Followed by a matrix of **M rows** and **N columns** of integers.

**Constraints**

- 0 < T <= 10
- 0 < M,N <= 10^3
- 0 <= Element <= 10^3

## Output

For each test case you will have to output one integer -> **Maximum No. of Coins**

## Example

- Input
```sh
4
2 3
1 2 0
3 1 1
4 3
4 2 1
3 5 2
3 2 4
4 5 1
3 3
6 2 3
3 7 5
3 3 1
4 6
2 9 4 3 2 5
1 3 5 2 4 1
6 2 3 3 5 2
7 1 8 1 3 6
```

- Output
```sh
6
20
22
41
```
