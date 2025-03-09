#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> minimumValueMaximalSubarray(const vector<int>& A, int& min_sum) {
    int n = A.size(), current_sum = 0;
    int min_length = INT_MAX, start_index = 0;
    int best_start = 0, best_end = -1;
    min_sum = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        current_sum += A[i];

        if (current_sum < min_sum) {
            min_sum = current_sum;
            min_length = i - start_index + 1;
            best_start = start_index;
            best_end = i;
        } else if (current_sum == min_sum) {
            if (i - start_index + 1 < min_length) {
                min_length = i - start_index + 1;
                best_start = start_index;
                best_end = i;
            }
        }

        if (current_sum > 0) {
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

    int min_sum;
    vector<int> result = minimumValueMaximalSubarray(A, min_sum);
    
    cout << "Minimum sum: " << min_sum << endl;
    cout << "Shortest subarray with minimum sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
