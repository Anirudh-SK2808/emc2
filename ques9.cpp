#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool compareByX(const Point &a, const Point &b) {
    return a.x < b.x;
}

bool compareByY(const Point &a, const Point &b) {
    return a.y < b.y;
}

bool compareByAvgDescending(const Point &a, const Point &b) {
    return (a.x + a.y) / 2.0 > (b.x + b.y) / 2.0;
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;
    vector<Point> points(n);
    cout << "Enter the points (x y):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> sortByX = points;
    sort(sortByX.begin(), sortByX.end(), compareByX);
    vector<Point> sortByY = points;
    sort(sortByY.begin(), sortByY.end(), compareByY);
    vector<Point> sortByAvgDescending = points;
    sort(sortByAvgDescending.begin(), sortByAvgDescending.end(), compareByAvgDescending);

    cout << "\nSorted by X-coordinate:" << endl;
    for (const auto &p : sortByX) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;

    cout << "\nSorted by Y-coordinate:" << endl;
    for (const auto &p : sortByY) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;

    cout << "\nSorted by (x + y)/2 in decreasing order:" << endl;
    for (const auto &p : sortByAvgDescending) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;

    return 0;
}
