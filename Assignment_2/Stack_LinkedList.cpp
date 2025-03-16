#include <bits/stdc++.h>
#include <chrono>
#include <windows.h>
#include <psapi.h>

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vp;
typedef complex<double> point;

#define ln "\n"
#define RESULT cout << "Result: "
#define FIXED(x) cout << fixed << setprecision(x)

const int64_t LIMIT = 1e6;

template <typename T>
class Node {

public:

    T data;
    Node* next;

    Node(T value) {

        data = value;
        next = nullptr;

    }

};

template <typename T>
class Stack {

private:

    Node<T>* head;
    int size;
    const int MAX_STACK_SIZE = LIMIT;

public:

    Stack() {

        head = nullptr;
        size = 0;

    }

    ~Stack() {

        Node<T>* current = head;

        while (current != nullptr)
        {
            Node<T>* temp = current;
            current = temp->next;
            delete temp;
        }
        
        head = nullptr;
        size = 0;

    }

    void push(T value) {

        if (size + 1 > MAX_STACK_SIZE)
        {
            throw runtime_error("Stack overflow! Maximum stack size reached.");
        }

        Node<T>* new_node = new Node<T>(value);
        new_node->next = head;
        head = new_node;

        size++;

    }

    void pop() {

        if (size == 0)
        {
            throw runtime_error("Error: Stack underflow! No element to pop.");
        }

        Node<T>* current = head;
        head = head->next;
        delete current;

        size--;

    }

    T peek() {

        if (size == 0)
        {
            throw runtime_error("Error: Stack underflow! No element to peek.");
        }

        return head->data;

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

};

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Stack<int> array;

    auto start = high_resolution_clock::now();

    for (int i = 1; i <= LIMIT; i++) 
    {
        array.push(i);
    }

    int size = array.get_size();

    for (int i = size - 1; i >= size / 2; i--) 
    {
        array.pop();
    }

    for (int i = (size / 2) + 1; i <= LIMIT; i++) 
    {
        array.push(i);
    }

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(end - start);

    FIXED(2);
    cout << "Execution Time: " << (duration.count() / 1000.00) << " ms" << ln;

    return 0;

}
