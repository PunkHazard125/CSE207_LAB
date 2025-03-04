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

struct Node {

    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}

};

struct LinkedList {

    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) { }

    ~LinkedList() {

        Node* current = head;

        while (current != NULL)
        {
            Node* temp = current;
            current = temp->next;
            delete temp;
        }
        
        head = tail = NULL;

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

    }

};

int main(void) {
    
    int size, input;
    cin >> size;

    LinkedList array;

    while (size--)
    {
        cin >> input;
        array.push_back(input);
    }
    
    array.print_list();

    return 0;

}
