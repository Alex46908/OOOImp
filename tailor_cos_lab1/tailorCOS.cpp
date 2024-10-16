#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double 
        x, 
        eps;

    cout << "Input x:" << endl;
    cin >> x;

    cout << "Input eps:" << endl;
    cin >> eps;


    while((x >= M_PI) || (x <= -M_PI)) {
        if (x < 0) {
            x += 2 * M_PI;
        } else {
            x -= 2 * M_PI;
        }
    }


    double 
        sum = 0, 
        t = 1;

    int k = 0;

    while(abs(t) >= eps) {
        sum += t;
        t = (-t * x * x) / ((2 * k + 1) * (2 * k + 2));
        k++;
    }

    cout << sum << " " << cos(x) << endl;

    return 0;
}