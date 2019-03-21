 /* function to check whether two strings are
    anagram of each other */
    fun areAnagram(str1: CharArray, str2: CharArray): Boolean {
        // Get lenghts of both strings
        val n1 = str1.size
        val n2 = str2.size

        // If length of both strings is not same,
        // then they cannot be anagram
        if (n1 != n2)
            return false

        // Sort both strings
        quickSort(str1, 0, n1 - 1)
        quickSort(str2, 0, n2 - 1)

        // Compare sorted strings
        for (i in 0 until n1)
            if (str1[i] != str2[i])
                return false

        return true
    }

    /* Implementation of Quick Sort
    A[] --> Array to be sorted
    si  --> Starting index
    ei  --> Ending index
    */
    fun quickSort(A: CharArray, si: Int, ei: Int) {
        val pi: Int    /* Partitioning index */
        if (si < ei) {
            pi = partition(A, si, ei)
            quickSort(A, si, pi - 1)
            quickSort(A, pi + 1, ei)
        }
    }

    // Following functions (exchange and partition
    // are needed for quickSort)
    fun exchange(A: CharArray, a: Int, b: Int) {
        val temp: Char
        temp = A[a]
        A[a] = A[b]
        A[b] = temp
    }

    fun partition(A: CharArray, si: Int, ei: Int): Int {
        val x = A[ei]
        var i = si - 1
        var j: Int

        j = si
        while (j <= ei - 1) {
            if (A[j] <= x) {
                i++
                exchange(A, i, j)
            }
            j++
        }
        exchange(A, i + 1, ei)
        return i + 1
    }