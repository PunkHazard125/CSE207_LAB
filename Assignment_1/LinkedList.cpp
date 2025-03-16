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

class Node {

public:

    int data;
    Node* next;

    Node(int value) {

        data = value;
        next = NULL;

    }

};

class LinkedList {

private:

    Node* head;
    Node* tail;
    int size;

    Node* split(Node* head) {

        if (head == nullptr || head->next == nullptr)
        {        
            return nullptr;
        }

        Node* fast = head->next;
        Node* slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* temp = slow->next;
        slow->next = NULL;
        return temp;

    }

    Node* merge(Node* first, Node* second) {

        if (first == nullptr)
        {
            return second;
        }
        
        if (second == nullptr)
        {
            return first;
        }
        
        if (first->data < second->data)
        {
            first->next = merge(first->next, second);
            return first;
        }
        else
        {
            second->next = merge(first, second->next);
            return second;
        }

    }

    Node* merge_sort(Node* head) {

        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        Node* second = split(head);

        head = merge_sort(head);
        second = merge_sort(second);

        return merge(head, second);

    }

public:

    LinkedList() {

        head = NULL;
        tail = NULL;
        size = 0;

    }

    ~LinkedList() {

        Node* current = head;

        while (current != NULL)
        {
            Node* temp = current;
            current = temp->next;
            delete temp;
        }
        
        head = tail = NULL;
        size = 0;

    }

    void push_front(int value) {

        Node* new_node = new Node(value);

        if (head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }

        size++;

    }

    void push_back(int value) {

        Node* new_node = new Node(value);

        if (head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }

        size++;

    }

    void pop_front() {

        if (head == NULL)
        {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
        size--;

    }

    void pop_back() {

        if (head == NULL)
        {
            cout << "List is empty!\n";
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            size--;
            return;
        }

        Node* current = head;

        while (current->next != tail)
        {
            current = current->next;
        }
        
        delete tail;
        tail = current;
        tail->next = NULL;
        size--;

    }

    void remove(int position) {

        if (head == NULL)
        {
            cout << "List is empty!\n";
            return;
        }

        if (position == 0)
        {
            Node* temp = head;
            head = head->next;
            if (head == nullptr)
            {
                tail = nullptr;
            }
            delete temp;
            size--;
            return;
        }
        
        Node* current = head;
        int index = 0;

        while (current != NULL)
        {
            if (index == position - 1) 
            {
                Node* temp = current->next;

                if (temp == NULL) 
                {
                    cout << "Index out of bounds!\n";
                    return;
                }

                current->next = temp->next;

                if (temp->next == NULL) 
                {
                    tail = current;
                }

                delete temp;
                size--;
                return;
            }
            
            current = current->next;
            index++;
        }

    }

    bool contains(int element) {

        Node* current = head;

        while (current != NULL)
        {
            if (current->data == element)
            {
                return true;
            }
            current = current->next;
        }

        return false;

    }

    void print_list() {

        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << ln;

    }

    void insert(int value, int index) {

        Node* new_node = new Node(value);
        Node* temp = head;

        if (index < 0)
        {
            cout << "Index out of bounds!\n";
            delete new_node;
            return;
        }

        if (index == 0)
        {
            if (temp != NULL)
            {
                new_node->next = temp;
                head = new_node;
            }
            else
            {
                head = tail = new_node;
            }
            return;
        }
        
        for (int i = 0; i < index - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Index out of bounds!\n";
                delete new_node;
                return;
            }
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Index out of bounds!\n";
            delete new_node;
            return;
        }
        
        new_node->next = temp->next;
        temp->next = new_node;

        if (new_node->next == NULL)
        {
            tail = new_node;
        }

        size++;

    }

    int get_size() {

        return size;

    }

    bool is_empty() {

        if (head == NULL)
        {
            return true;
        }
        
        return false;

    }

    int get(int index) {

        if (index < 0 or index >= size)
        {
            cout << "Index out of bounds!\n";
            return - 1;
        }

        if (size == 0)
        {
            cout << "List is empty!\n";
            return - 1;
        }

        Node* current = head;
        int start = 0;

        while (current != NULL)
        {
            if (start == index)
            {
                break;
            }
            
            current = current->next;
            start++;
        }

        return current->data;

    }

    int index_of(int value) {

        if (size == 0)
        {
            cout << "List is empty!\n";
            return - 1;
        }

        Node* current = head;
        int index = 0;
        bool flag = false;

        while (current != NULL)
        {
            if (current->data == value)
            {
                flag = true;
                break;
            }
            
            current = current->next;
            index++;
        }

        if (flag)
        {
            return index;
        }
        else
        {
            return -1;
        }

    }

    void sort() {

        head = merge_sort(head);

        Node* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }

        tail = temp;

    }

    void reverse() {

        if (head == NULL) 
        {
            cout << "List is empty!\n";
            return;
        }
        
        if (head == tail) 
        {
            return;
        }
        
        Node* previous = NULL;
        Node* current = head;
        tail = head;
    
        while (current != NULL) 
        {
            Node* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        
        head = previous;

        if (tail != NULL) 
        {
            tail->next = NULL;
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

    LinkedList array;

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
