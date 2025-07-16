#include <iostream>
#include <climits>
using namespace std;

int getSecondLargest(int *arr, int n) {
    if (n < 2) return -1;

    int largest = INT_MIN;
    int secondl = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondl = largest;
            largest = arr[i];
        } else if (arr[i] > secondl && arr[i] != largest) {
            secondl = arr[i];
        }
    }

    return (secondl == INT_MIN) ? -1 : secondl;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = getSecondLargest(arr, n);

    if (result == -1)
        cout << "Second largest element not found (array too small or all elements same)" << endl;
    else
        cout << "Second largest element is: " << result << endl;

    return 0;
}
