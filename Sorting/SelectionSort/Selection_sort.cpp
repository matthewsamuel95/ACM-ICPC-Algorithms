#include <iostream>

using namespace std;

class SelectionSort
{
    int size;
    int *arr;
public:
    SelectionSort()
    {
        cout << "Enter the size: ";
        cin >> size;
        arr = new int [size];
    }
    void get()
    {
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
    void sort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            int min = arr[i];
            int k = i;
            for (int j = i + 1; j < size; j++)
            {
                if (min > arr[j])
                {
                    k = j;
                    min = arr[j];
                }
            }
            if (k != i)
            {
                int temp = arr[i];
                arr[i] = arr[k];
                arr[k] = temp;
            }
        }
    }
    void show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(void)
{
    SelectionSort i;
    i.get();
    i.sort();
    i.show();
}
