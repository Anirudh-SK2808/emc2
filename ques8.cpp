#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0, j = 0, k = left;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < leftArr.size()) arr[k++] = leftArr[i++];
    while (j < rightArr.size()) arr[k++] = rightArr[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void valueBasedMergeSort(vector<int>& arr) {
    if (arr.size() <= 1) return;

    int pivot = arr[arr.size() / 2];
    vector<int> left, right;

    for (int x : arr) {
        if (x < pivot)
            left.push_back(x);
        else if (x > pivot)
            right.push_back(x);
    }

    valueBasedMergeSort(left);
    valueBasedMergeSort(right);

    arr = left;
    arr.push_back(pivot);
    arr.insert(arr.end(), right.begin(), right.end());
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> arr1 = arr, arr2 = arr;

    clock_t start = clock();
    mergeSort(arr1, 0, arr1.size() - 1);
    clock_t end = clock();
    cout << "Sorted using Traditional Merge Sort: ";
    for (int num : arr1) cout << num << " ";
    cout << "\nTime: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    start = clock();  
    valueBasedMergeSort(arr2);
    end = clock();
    cout << "Sorted using Value-based Merge Sort: ";
    for (int num : arr2) cout << num << " ";
    cout << "\nTime: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    return 0;
}
