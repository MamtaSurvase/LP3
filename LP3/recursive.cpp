
#include <iostream>
using namespace std;

// Non-recursive function
void nonRecursive(int n) {
    int a = 0, b = 1, c;
    cout << "Non-Recursive: ";

    for (int i = 0; i < n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

// Recursive function
int recursive(int n) {
    if (n <= 1)
        return n;

    return recursive(n - 1) + recursive(n - 2);
}

int main() {
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input";
        return 0;
    }

    nonRecursive(n);

    cout << "Recursive: ";
    for (int i = 0; i < n; i++)
        cout << recursive(i) << " ";

    cout << endl;
    return 0;
}
