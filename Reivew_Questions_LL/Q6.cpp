#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<int64_t> v64;

#define ln "\n"
#define PRINT_RESULT cout << "Result: "
#define FIXED(x) cout << fixed << setprecision(x);

const int64_t LIMIT = 1e9;

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

class LinkedList {

private:

    Node<T>* head;
    Node<T>* tail;
    int size;

    void remove_loops() {

        Node<T>* slow = head;
        Node<T>* fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }
        
        if (slow != fast)
        {
            return;
        }
        
        slow = head;
        
        if (slow == fast)
        {
            while (fast->next != slow)
            {
                fast = fast->next;
            }
        }
        else
        {
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        fast->next = nullptr;

    }

public:

    LinkedList() {

        head = nullptr;
        tail = nullptr;
        size = 0;

    }

    ~LinkedList() {

        Node<T>* current = head;

        while (current != nullptr)
        {
            Node<T>* temp = current;
            current = temp->next;
            delete temp;
        }
        
        head = tail = nullptr;
        size = 0;

    }

    void push_front(T value) {

        Node<T>* new_node = new Node(value);

        if (head == nullptr)
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

    void push_back(T value) {

        Node<T>* new_node = new Node<T>(value);

        if (head == nullptr)
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

        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }

        Node<T>* temp = head;
        head = head->next;

        temp->next = nullptr;
        delete temp;
        size--;

    }

    void pop_back() {

        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            size--;
            return;
        }

        Node<T>* current = head;

        while (current->next != tail)
        {
            current = current->next;
        }
        
        delete tail;
        tail = current;
        tail->next = nullptr;
        size--;

    }

    void remove(int position) {

        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }

        if (position == 0)
        {
            Node<T>* temp = head;
            head = head->next;
            if (head == nullptr)
            {
                tail = nullptr;
            }
            delete temp;
            size--;
            return;
        }
        
        Node<T>* current = head;
        int index = 0;

        while (current != nullptr)
        {
            if (index == position - 1) 
            {
                Node<T>* temp = current->next;

                if (temp == nullptr) 
                {
                    cout << "Index out of bounds!\n";
                    return;
                }

                current->next = temp->next;

                if (temp->next == nullptr) 
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

    bool contains(T element) {

        Node<T>* current = head;

        while (current != nullptr)
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

        Node<T>* temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << ln;

    }

    void insert(T value, int index) {

        Node<T>* new_node = new Node<T>(value);
        Node<T>* temp = head;

        if (index < 0)
        {
            cout << "Index out of bounds!\n";
            delete new_node;
            return;
        }

        if (index == 0)
        {
            if (temp != nullptr)
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
            if (temp == nullptr)
            {
                cout << "Index out of bounds!\n";
                delete new_node;
                return;
            }
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Index out of bounds!\n";
            delete new_node;
            return;
        }
        
        new_node->next = temp->next;
        temp->next = new_node;

        if (new_node->next == nullptr)
        {
            tail = new_node;
        }

        size++;

    }

    int get_size() {

        return size;

    }

    bool is_empty() {

        return (size == 0);

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

        Node<T>* current = head;
        int start = 0;

        while (current != nullptr)
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

    int index_of(T value) {

        if (size == 0)
        {
            cout << "List is empty!\n";
            return - 1;
        }

        Node<T>* current = head;
        int index = 0;
        bool flag = false;

        while (current != nullptr)
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

        Node<T>* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }

        tail = temp;

    }

    void reverse() {

        if (head == nullptr) 
        {
            cout << "List is empty!\n";
            return;
        }
        
        if (head == tail) 
        {
            return;
        }
        
        Node<T>* previous = nullptr;
        Node<T>* current = head;
        tail = head;
    
        while (current != nullptr) 
        {
            Node<T>* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        
        head = previous;

        if (tail != nullptr) 
        {
            tail->next = nullptr;
        }
    }

};

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;

}
