#include <iostream>
using namespace std;

void complexMultiply(int a, int b, int c, int d, int &realPart, int &imagPart) {
    int P1 = a * c;
    int P2 = b * d;
    int P3 = (a + b) * (c + d);

    realPart = P1 - P2;
    imagPart = P3 - P1 - P2;
}

int main() {
    int a, b, c, d;
    cout << "Enter real and imaginary parts of first complex number: ";
    cin >> a >> b;
    cout << "Enter real and imaginary parts of second complex number: ";
    cin >> c >> d;

    int realPart, imagPart;
    complexMultiply(a, b, c, d, realPart, imagPart);

    cout << "Product: " << realPart << " + " << imagPart << "i" << endl;
    return 0;
}
