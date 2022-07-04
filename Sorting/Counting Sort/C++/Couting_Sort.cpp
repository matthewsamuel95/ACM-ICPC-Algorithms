#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Find the maximum element in the array.

int findMax(int arr[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = arr[i] > maxi ? arr[i] : maxi;
    }
    return maxi;
}

void countingSort(int arr[], int n)
{
    int range = findMax(arr, n) + 1;

    // Initialize an array to store the frequency of every element in the array.

    int count[range] = {0};

    // Counting the occurence of each element.

    for (int i = 0; i < n; ++i)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= range; i++)
    {
        count[i] += count[i - 1];
    }

    // Rotate the array left by one element.

    for (int i = range; i > 0; i--)
    {
        count[i] = count[i - 1];
    }
    count[0] = 0;

    // Declare an array to store the sorted elements.

    int output[n];

    for (int i = 0; i < n; i++)
    {
        output[count[arr[i]]] = arr[i];
        count[arr[i]]++;
    }

    // Arrage the output elements in original array.

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    countingSort(arr, n);
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}