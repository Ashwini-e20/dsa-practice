#include <iostream>
using namespace std;

bool isSortedAndRotated(int arr[], int n) {
    int count = 0;
        
        if (arr[i] > arr[(i + 1) % n]) {
            count++;
        }
    }

    return (count <= 1);
}

int main() {
    int n;

    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (isSortedAndRotated(arr, n)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
