#include <bits/stdc++.h>
#include <chrono>
#include <windows.h>
#include <psapi.h>

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<int64_t> v64;

#define ln "\n"
#define PRINT_RESULT cout << "Result: "
#define FIXED(x) cout << fixed << setprecision(x);

const int64_t LIMIT = 1e6;

class ArrayList {

private:

    int* array;
    int size;
    int capacity;

    void merge(int left, int mid, int right) {

        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++)
        {
            L[i] = array[left + i];
        }
        
        for (int i = 0; i < n2; i++)
        {
            R[i] = array[mid + 1 + i];
        }

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                array[k] = L[i];
                i++;
            }
            else
            {
                array[k] = R[j];
                j++;
            }
            
            k++;
        }
        
        while (i < n1) 
        {
            array[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) 
        {
            array[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;

    }

    void merge_sort(int left, int right) {

        if (left >= right)
        {
            return;
        }
        
        int mid = left + (right - left) / 2;

        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);

    }

    void manage_capacity() {

        if (size < capacity / 4) 
        {
            capacity /= 2;
            int* temp = new int[capacity];
    
            for (int i = 0; i < size; i++) 
            {
                temp[i] = array[i];
            }
    
            delete[] array;
            array = temp;
        }

    }

public:

    ArrayList() {

        capacity = 8;
        size = 0;
        array = new int[8];

    }

    ArrayList(int capacity) {

        this->capacity = capacity;
        this->size = 0;
        array = new int[capacity];

    }

    ~ArrayList() {

        size = 0;
        capacity = 0;
        delete[] array;

    }

    void push_back(int element) {

        if (size + 1 >= capacity)
        {
            capacity = capacity * 2;
            int* temp = new int[capacity];

            for (int i = 0; i < size; i++)
            {
                temp[i] = array[i];
            }

            delete[] array;
            array = temp;
        }

        array[size++] = element;

    }

    void push_front(int element) {

        if (size + 1 >= capacity)
        {
            capacity = capacity * 2;
        }

        int* temp = new int[capacity];

        for (int i = 1; i < size + 1; i++)
        {
            temp[i] = array[i - 1];
        }

        delete[] array;
        array = temp;
        array[0] = element;
        size++;

    }

    void insert(int position, int element) {

        if (position < 0 || position >= size)
        {
            cout << "Index out of bounds!\n";
            return;
        }

        if (size + 1 >= capacity)
        {
            capacity = capacity * 2;
        }

        int* temp = new int[capacity];
        bool flag = false;

        for (int i = 0; i < size + 1; i++)
        {
            if (i == position)
            {
                temp[i] = element;
                flag = true;
            }
            
            if (flag)
            {
                temp[i] = array[i - 1];
            }
            else
            {
                temp[i] = array[i];
            }
        }

        delete[] array;
        array = temp;
        size++;

    }

    bool contains(int element) {

        for (int i = 0; i < size; i++)
        {
            if (array[i] == element)
            {
                return true;
            }
        }

        return false;

    }

    int get_size() {

        return size;

    }

    int get_capacity() {

        return capacity;

    }

    bool is_empty() {

        if (size == 0)
        {
            return true;
        }
        
        return false;

    }

    int get(int position) {

        if (position < 0 || position >= size)
        {
            cout << "Index out of bounds!\n";
            return -1;
        }
        
        return array[position];

    }

    int index_of(int element) {
        
        for (int i = 0; i < size; i++)
        {
            if (array[i] == element)
            {
                return i;
            }
        }

        return -1;

    }

    void pop_front() {

        if (size == 0)
        {
            cout << "Array is empty!";
            return;
        }

        for (int i = 0; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }

        size--;

        manage_capacity();

    }

    void pop_back() {

        if (size == 0)
        {
            cout << "Array is empty!";
            return;
        }

        size--;

        manage_capacity();

    }

    void remove(int position) {

        if (size == 0)
        {
            cout << "Array is empty!";
            return;
        }

        if (position < 0 || position >= size)
        {
            cout << "Index out of bounds!";
            return;
        }

        for (int i = position; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }

        size--;

        manage_capacity();

    }

    void reverse() {

        int* temp = new int[capacity];
        int j = size - 1;
    
        for (int i = 0; i < size; i++) {
            temp[i] = array[j];
            j--;
        }
    
        delete[] array;
        array = temp;

    }

    void print_array() {

        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << ln;
    }

    void sort() {

        if (size > 1)
        {
            merge_sort(0, size - 1);
        }

    }

};

double get_memory_usage() {

    PROCESS_MEMORY_COUNTERS memCounter;
    GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
    return memCounter.WorkingSetSize / (1024.0 * 1024.0);

}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ArrayList array;

    auto start = high_resolution_clock::now();

    for (int i = 1e4; i >= 1; i--) 
    {
        array.push_back(i);
    }
    
    array.reverse();

    int size = array.get_size();

    for (int i = size - 1; i >= size / 2; i--) 
    {
        array.pop_back();
    }

    array.reverse();

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(end - start);

    FIXED(4);
    cout << "Execution Time: " << (duration.count() / 1000.00) << " ms" << ln;
    cout << "Memory Usage: " << get_memory_usage() << " MB" << ln;

    return 0;

}
