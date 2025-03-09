#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> findMaximalSubarray(const vector<int>& arr, int& maxSum) {
    int currentSum = 0, startIdx = 0;
    int bestStart = 0, bestEnd = -1;
    maxSum = INT_MIN;
    int minLength = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];

        if (currentSum > maxSum) {
            maxSum = currentSum;
            minLength = i - startIdx + 1;
            bestStart = startIdx;
            bestEnd = i;
        } else if (currentSum == maxSum) {
            if ((i - startIdx + 1) < minLength) {
                minLength = i - startIdx + 1;
                bestStart = startIdx;
                bestEnd = i;
            }
        }

        if (currentSum < 0) {
            currentSum = 0;
            startIdx = i + 1;
        }
    }

    return vector<int>(arr.begin() + bestStart, arr.begin() + bestEnd + 1);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSum;
    vector<int> result = findMaximalSubarray(arr, maxSum);
    
    cout << "Maximum sum: " << maxSum << endl;
    cout << "Subarray with maximum sum and minimal length: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
