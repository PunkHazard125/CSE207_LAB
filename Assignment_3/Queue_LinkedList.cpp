#include <bits/stdc++.h>
#include <chrono>

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

class Queue {

private:

    Node<T>* head;
    Node<T>* tail;
    int size;
    const int MAX_QUEUE_SIZE = LIMIT;

public:

    Queue() {

        head = nullptr;
        tail = nullptr;
        size = 0;

    }

    ~Queue() {

        Node<T>* current = head;

        while (current != nullptr)
        {
            Node<T>* temp = current;
            current = temp->next;
            delete temp;
        }
        
        head = nullptr;
        tail = nullptr;
        size = 0;

    }

    void enqueue(T value) {

        if (size + 1 > MAX_QUEUE_SIZE)
        {
            throw runtime_error("Queue overflow! Maximum Queue size reached.");
        }

        Node<T>* new_node = new Node<T>(value);

        if (is_empty())
        {
            head = tail = new_node;
            size++;
            return;
        }

        tail->next = new_node;
        tail = new_node;

        size++;

    }

    void dequeue() {

        if (is_empty())
        {
            throw runtime_error("Queue underflow! Queue is empty.");
        }

        Node<T>* current = head;
        head = head->next;
        delete current;

        size--;

    }

    int get_size() {

        return size;

    }

    bool is_empty() {

        return (size == 0);

    }

    T peek() {

        if (is_empty())
        {
            throw runtime_error("Queue underflow! Queue is empty.");
        }

        return head->data;

    }

    T back() {

        if (is_empty())
        {
            throw runtime_error("Queue underflow! Queue is empty.");
        }

        return tail->data;

    }

    void display() {

        Node<T>* current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        } 

        cout << ln;

    }

};

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Queue<int> array;

    for (int i = 1; i <= 10; i++) 
    {
        array.enqueue(i);
    }

    cout << "Queue: ";
    array.display();

    cout << "Front: " << array.peek() << ln;
    cout << "Rear: " << array.back() << ln;

    for (int i = 1; i <= 10; i++) 
    {
        array.dequeue();
    }

    if (array.is_empty())
    {
        cout << "Queue is empty\n";
    }
    else
    {
        cout << "Queue is not empty\n";
    }

    return 0;

}
