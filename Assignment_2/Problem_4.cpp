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

template <typename T>

class Stack {

private:

    T* array;
    int size;
    int capacity;
    const int MAX_STACK_SIZE = LIMIT;

    void manage_capacity() {

        if (size < capacity / 4) 
        {
            capacity /= 2;
            T* temp = new T[capacity];
    
            for (int i = 0; i < size; i++) 
            {
                temp[i] = array[i];
            }
    
            delete[] array;
            array = temp;
        }

    }

public:

    Stack() {

        capacity = 8;
        size = 0;
        array = new T[8];

    }

    Stack(int capacity) {

        this->capacity = capacity;
        this->size = 0;
        array = new T[capacity];

    }

    ~Stack() {

        size = 0;
        capacity = 0;
        delete[] array;

    }

    void push(T element) {

        if (size + 1 > MAX_STACK_SIZE)
        {
            throw runtime_error("Stack overflow! Maximum stack size reached.");
        } 

        if (size + 1 >= capacity)
        {
            capacity = min(capacity * 2, MAX_STACK_SIZE);
            T* temp = new T[capacity];

            for (int i = 0; i < size; i++)
            {
                temp[i] = array[i];
            }

            delete[] array;
            array = temp;
        }

        array[size++] = element;

    }

    int get_size() {

        return size;

    }

    bool is_empty() {

        if (size == 0)
        {
            return true;
        }
        
        return false;

    }

    void pop() {

        if (size == 0)
        {
            throw runtime_error("Error: Stack underflow! No element to pop.");
        }

        size--;

        manage_capacity();

    }

    T peek() {

        if (size == 0)
        {
            throw runtime_error("Error: Stack underflow! No element to pop.");
        }
        
        return array[size - 1];

    }

    void print_stack() {

        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << ln;
    }

};

template <typename T>
void copy_stack(Stack<T>& original, Stack<T>& target) {

    Stack<T> temp;

    while (!original.is_empty())
    {
        temp.push(original.peek());
        original.pop();
    }
    
    while (!temp.is_empty())
    {
        original.push(temp.peek());
        target.push(temp.peek());
        temp.pop();
    }

}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Stack<int> original;
    Stack<int> target;

    for (int i = 1; i <= 10; i++)
    {
        original.push(i);
    }
    
    copy_stack(original, target);

    cout << original.peek() << " " << target.peek() << ln;

    return 0;

}
