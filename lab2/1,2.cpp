#include <iostream>

using namespace std;

int main() {
    long int inputNum;

    cout << "Введите число:" << endl;

    cin >> inputNum;


    int minNum = 10;

    long int
        num = inputNum,
        maxDischarge = 10;

    while (num != 0) {
        if (num / 10 > 10) {
            maxDischarge *= 10;
        }

        if (minNum > num % 10) {
            minNum = num % 10;
        }

        num = num / 10;
    }


    while (maxDischarge != 0) {
        long int dischargeNum = (inputNum / maxDischarge) % 10;

        if (dischargeNum % minNum != 0) {
            cout << dischargeNum;
        }

        maxDischarge = maxDischarge / 10;
    }

    cout << endl;

    return 0;
}