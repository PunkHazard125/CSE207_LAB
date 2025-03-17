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

int postfix(string str) {

    if (str.empty())
    {
        throw runtime_error("Expression is empty!");
    }
    
    Stack<int> numbers;
    int i = 0;

    while (i < str.size())
    {
        if (isdigit(str[i]))
        {
            int num = 0;

            while (i < str.size() && isdigit(str[i]))
            {
                num = (num * 10) + str[i] - '0';
                i++;
            }
            
            numbers.push(num);
        }
        else if (str[i] == ' ')
        {
            i++;
        }
        else
        {
            if (numbers.get_size() < 2)
            {
                throw runtime_error("Not enough operands for the operator(s)!");
            }
            
            int num2 = numbers.peek();
            numbers.pop();
            int num1 = numbers.peek();
            numbers.pop();

            if (str[i] == '+') 
            {
                numbers.push(num1 + num2);
            } 
            else if (str[i] == '-') 
            {
                numbers.push(num1 - num2);
            } 
            else if (str[i] == '*') 
            {
                numbers.push(num1 * num2);
            } 
            else if (str[i] == '/') 
            {
                if (num2 == 0) 
                {
                    throw runtime_error("Cannot divide by zero!");
                }

                numbers.push(num1 / num2);
            } 
            else if (str[i] == '%') 
            {
                numbers.push(num1 % num2);
            } 
            else 
            {
                throw runtime_error("Invalid Operator!");
            }

            i++;
        }
    }

    if (numbers.get_size() != 1) 
    {
        throw runtime_error("Invalid postfix expression!");
    }
    
    return numbers.peek();

}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter expression: ";
    cout.flush();

    string str;
    getline(cin, str);

    try
    {
        int result = postfix(str);
        cout << "Result: " << result << ln;
    }
    catch(const runtime_error& e)
    {
        cout << e.what() << ln;
    }

    return 0;

}
