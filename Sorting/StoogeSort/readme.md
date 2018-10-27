#STOOGE SORT

>Input :   2 4 5 3 1

>Output : 1 2 3 4 5

>Explanation:

Initially, swap 2 and 1 following above step 1.
          1 4 5 3 2
          Now, recursively sort initial 2/3rd of the elements.
          1 4 5 3 2
          1 3 4 5 2 
          Then, recursively sort last 2/3rd of the elements.
          1 3 4 5 2
          1 2 3 4 5
          Again, sort the initial 2/3rd of the elements to confirm final data is sorted.
          1 2 3 4 5