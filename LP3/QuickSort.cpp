
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Partition function
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

// Deterministic Quick Sort
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// Randomized Quick Sort
void randomizedQuickSort(int a[], int low, int high) {
    if (low < high) {
        int randomIndex = low + rand() % (high - low + 1);

        swap(a[randomIndex], a[high]);

        int p = partition(a, low, high);

        randomizedQuickSort(a, low, p - 1);
        randomizedQuickSort(a, p + 1, high);
    }
}

// Display array
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size";
        return 0;
    }

    int a[1000], b[1000];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    srand(time(0));

    quickSort(a, 0, n - 1);
    randomizedQuickSort(b, 0, n - 1);

    cout << "\nDeterministic Quick Sort: ";
    display(a, n);

    cout << "Randomized Quick Sort: ";
    display(b, n);

    return 0;
}
