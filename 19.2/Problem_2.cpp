#include <bits/stdc++.h>

using namespace std;

const string nl = "\n";

int binarySearch(int array[], int size, int key) {

    int i = 0, j = size - 1, m;

    while (i <= j)
    {
        m = (i + j) / 2;

        if (array[m] == key)
        {
            return m + 1;
        }
        
        if (key > array[m])
        {
            i = m + 1;
        }
        else
        {
            j = m - 1;
        }
    }

    return i;

}

int main(void) {

    int size, target;

    cout << "Enter size of array: ";
    cin >> size;

    int array[size];

    cout << "Enter elements of array: ";

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    cout << "Enter target element: ";
    cin >> target;

    int index = binarySearch(array, 4, target);
    size++;

    int new_array[size];
    
    for (int i = 0; i < size; i++)
    {
        if (i == index)
        {
            new_array[i] = target;
        }
        else if (i > index)
        {
            new_array[i] = array[i - 1];
        }
        else
        {
            new_array[i] = array[i];
        }
    }

    cout << "New Array: ";
    
    for (int i = 0; i < size; i++)
    {
        cout << new_array[i] << " ";
    }

    cout << nl;

    return 0;
}
