#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> maximumValueMinimalSubarray(const vector<int>& A, int& max_sum) {
    int n = A.size(), current_sum = 0;
    int max_length = 0, start_index = 0;
    int best_start = 0, best_end = -1;
    max_sum = INT_MIN;

    for (int i = 0; i < n; i++) {
        current_sum += A[i];

        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_length = i - start_index + 1;
            best_start = start_index;
            best_end = i;
        } else if (current_sum == max_sum) {
            if (i - start_index + 1 > max_length) {
                max_length = i - start_index + 1;
                best_start = start_index;
                best_end = i;
            }
        }

        if (current_sum < 0) {
            current_sum = 0;
            start_index = i + 1;
        }
    }

    return vector<int>(A.begin() + best_start, A.begin() + best_end + 1);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    int max_sum;
    vector<int> result = maximumValueMinimalSubarray(A, max_sum);

    cout << "Maximum sum: " << max_sum << endl;
    cout << "Longest subarray with maximum sum: ";
    for (int num : result) cout << num << " ";
    cout << endl;

    return 0;
}
