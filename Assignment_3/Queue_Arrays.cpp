#include <bits/stdc++.h>
#include <chrono>

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

class Queue {

private:

    T* array;
    int front;
    int rear;
    int size;
    int capacity;
    const int MAX_QUEUE_SIZE = LIMIT;

public:

    Queue() {

        capacity = MAX_QUEUE_SIZE;
        front = 0;
        rear = 0;
        size = 0;
        array = new T[capacity];

    }

    Queue(int capacity) {

        if (capacity > MAX_QUEUE_SIZE)
        {
            throw runtime_error("Queue overflow! Maximum Queue size exceeded.");
        }

        this->capacity = capacity;
        size = 0;
        front = 0;
        rear = 0;
        array = new T[capacity];

    }

    ~Queue() {

        size = 0;
        front = 0;
        rear = 0;
        capacity = 0;
        delete[] array;

    }

    void enqueue(T element) {

        if (is_full())
        {
            throw runtime_error("Queue is full!");
        }

        rear = (front + size) % capacity;
        array[rear] = element;

        size++;

    }

    T dequeue() {

        if (is_empty())
        {
            throw runtime_error("Queue underflow! Queue is empty.");
        }

        T temp = array[front];
        front = (front + 1) % capacity;
        size--;

        return temp;

    }

    int get_size() {

        return size;

    }

    bool is_empty() {

        return (size == 0);

    }

    bool is_full() {

        return (size == capacity);

    }

    T peek() {

        if (size == 0)
        {
            throw runtime_error("Queue underflow! Queue is empty.");
        }
        
        return array[front];

    }

    T back() {

        if (size == 0)
        {
            throw runtime_error("Queue underflow! Queue is empty.");
        }
        
        return array[(front + size - 1) % capacity];

    }

    void display() {

        int temp = front;

        for (int i = 0; i < size; i++)
        {
            cout << array[temp] << " ";
            temp = (temp + 1) % capacity;
        } 
        
        cout << ln;

    }

};

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Queue<int> array(10);

    for (int i = 1; i <= 10; i++) 
    {
        array.enqueue(i);
    }

    cout << "Queue: ";
    array.display();

    cout << "Front: " << array.peek() << ln;
    cout << "Rear: " << array.back() << ln;
    
    if (array.is_full())
    {
        cout << "Queue is full\n";
    }
    else
    {
        cout << "Queue is not full\n";
    }

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
