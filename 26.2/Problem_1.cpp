#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define ln "\n"
#define FIXED(x) cout << fixed << setprecision(x)

const int64_t LIMIT = 1e4;
const double PRECISION = 0.0001;

double root(double number) {

    if (number == 0.00 or number == 1.00)
    {
        return number;
    }
    
    double start = 0.00, end = number, middle, square = number + 1, diff;

    while (abs(square - number) > PRECISION)
    {
        middle = (start + end) / 2.00;

        square = middle * middle;

        diff = abs(square - number);
        diff = round(diff * LIMIT) / LIMIT;

        if (diff <= PRECISION)
        {
            return middle;
        }
        
        if (square < number)
        {
            start = middle;
        }
        else
        {
            end = middle;
        }
    }

    return -1;

}

void solve() {

    double number;
    cin >> number;

    FIXED(4);
    cout << root(number) << ln;

}

int main(void) {

    solve();

    return 0;

}
