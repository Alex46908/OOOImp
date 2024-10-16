#include <iostream>

using namespace std;

int main() {
    long int a, b;

    cout << "Введите a:" << endl;

    cin >> a;

    cout << "Введите b:" << endl;

    cin >> b;

    cout << endl;

    for (long int i = a; i <= b; i++) {

        long int temp_i = i;
        bool isOkay = true;

        while (temp_i != 0) {
            int num = temp_i % 10;

            if ((num == 0) || ((i % num) != 0)) {
                isOkay = false;
                break;
            }

            temp_i = temp_i / 10;
        }

        if (isOkay) {
            cout << i << endl;
        }
    }
    

    return 0;
}