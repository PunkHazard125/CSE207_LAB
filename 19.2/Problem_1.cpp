#include <bits/stdc++.h>

using namespace std;

const string nl = "\n";

int binarySearchNext(int array[], int size, int key) {

    if (array[size - 1] <= key)
    {
        return -1;
    }

    int i = 0, j = size - 1, m;

    while (i <= j)
    {
        m = (i + j) / 2;
        
        if (array[m] <= key)
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

int binarySearchPrevious(int array[], int size, int key) {

    if (array[0] >= key)
    {
        return -1;
    }

    int i = 0, j = size - 1, m;

    while (i <= j)
    {
        m = (i + j) / 2;
        
        if (array[m] < key)
        {
            i = m + 1;
        }
        else
        {
            j = m - 1;
        }
    }

    return j;

}

int main(void) {

    int n, q;

    cin >> n;
    int chimps[n];
    for (int i = 0; i < n; i++)
    {
        cin >> chimps[i];
    }

    cin >> q;
    int ziggy[q];
    for (int i = 0; i < q; i++)
    {
        cin >> ziggy[i];
    }

    for (int i = 0; i < q; i++)
    {
        int previous = binarySearchPrevious(chimps, n, ziggy[i]);
        int next = binarySearchNext(chimps, n, ziggy[i]);

        if (previous != -1)
        {
            cout << chimps[previous] << " ";
        }
        else
        {
            cout << "X" << " ";
        }
        
        if (next != -1)
        {
            cout << chimps[next] << nl;
        }
        else
        {
            cout << "X" << nl;
        }
    }

    return 0;
}
