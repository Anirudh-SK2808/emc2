#include <iostream>
using namespace std;

int findMax(int A[], int left, int right) {
    if (left == right) 
        return A[left];

    int mid = (left + right) / 2;

    int max1 = findMax(A, left, mid);
    int max2 = findMax(A, mid + 1, right);

    return max(max1, max2);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Maximum element: " << findMax(A, 0, n - 1) << endl;

    return 0;
}
