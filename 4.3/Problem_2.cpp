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

class Book {

    string title;
    string author;
    int price;
    
public:

    Book() { }

    Book(string title, string author, int price) {

        this->title = title;
        this->author = author;
        this->price = price;

    }

    string get_title() { return title; }
    string get_author() { return author; }
    int get_price() { return price; }

    void set_title(string title) { this->title = title; }
    void set_author(string author) { this->author = author; }
    void set_price(int price) { this->price = price; }

};

int main(void) {
    
    int size;
    cin >> size;

    Book *books = new Book[size];
    string title, author;
    int price, max_price = 0, index;

    for (int i = 0; i < size; i++)
    {
        cin >> title >> author >> price;
        books[i] = Book(title, author, price);

        if (price > max_price)
        {
            max_price = price;
            index = i;
        }
    }

    cout << books[index].get_title() << " " << books[index].get_author() << " " << books[index].get_price() << ln;

    delete[] books;

    return 0;

}
