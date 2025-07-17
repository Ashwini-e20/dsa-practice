#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return;

        int temp = arr[n - 1]; 
        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = temp;  
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution obj;
    obj.rotate(arr); 

    cout << "Array after 1 rotation to the right:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
