#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vp;
typedef complex<double> point;

#define ln "\n"
#define RESULT cout << "Result: "
#define FIXED(x) cout << fixed << setprecision(x)

const int64_t LIMIT = 1e6;

void reverse_array(int *array, int size) {

    int left = 0, right = size - 1;

    while (left <= right)
    {
        swap(array[left], array[right]);
        left++;
        right--;
    }

}

void reverse_array_hybrid(int **array, int size) {

    int *new_array = new int[size];

    for (int i = 9; i >= 0; i--)
    {
        new_array[i] = (*array)[size - 1 - i];
    }

    delete[] *array;
    *array = new_array;

}

int main(void) {
    
    int size;
    cin >> size;

    int *array = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> *(array + i);
    }
    
    reverse_array(array, size);

    for (int i = 0; i < size; i++)
    {
        cout << *(array + i) << " ";
    }

    delete[] array;

    return 0;

}
