#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
string findLCS(const string &X, const string &Y) {
    int m = X.length(), n = Y.length();
    vector<vector<int>> c(2, vector<int>(n + 1, 0));
 
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                c[i % 2][j] = c[(i - 1) % 2][j - 1] + 1;
            else
                c[i % 2][j] = max(c[(i - 1) % 2][j], c[i % 2][j - 1]);
        }
    }
 
    int i = m, j = n;
    string lcs;
    
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--, j--;
        } else if (c[(i - 1) % 2][j] >= c[i % 2][j - 1])
            i--;
        else
            j--;
    }
 
    return lcs;
}
 
int main() {
    string X, Y;
    cin >> X >> Y;
    cout << findLCS(X, Y) << endl;
    return 0;
}
