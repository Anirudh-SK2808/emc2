#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& A, int left, int mid, int right) {
    vector<int> leftArr(A.begin() + left, A.begin() + mid + 1);
    vector<int> rightArr(A.begin() + mid + 1, A.begin() + right + 1);
    
    int i = 0, j = 0, k = left;
    long long count = 0;
    
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            A[k++] = leftArr[i++];
        } else {
            A[k++] = rightArr[j++];
            count += leftArr.size() - i;
        }
    }
    
    while (i < leftArr.size()) A[k++] = leftArr[i++];
    while (j < rightArr.size()) A[k++] = rightArr[j++];
    
    return count;
}

long long countInversions(vector<int>& A, int left, int right) {
    if (left >= right) return 0;
    
    int mid = left + (right - left) / 2;
    long long count = countInversions(A, left, mid);
    count += countInversions(A, mid + 1, right);
    count += mergeAndCount(A, left, mid, right);
    
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    
    for (int i = 0; i < n; i++) cin >> A[i];
    
    cout << countInversions(A, 0, n - 1) << endl;
    
    return 0;
}
