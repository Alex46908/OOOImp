#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

int* swapAndMerge(int* arr, int firstElNum, int secondElNum) {
    int newFirstEl = arr[firstElNum];
    arr[firstElNum] = arr[secondElNum];

    for (int i = firstElNum + 1; i <= secondElNum; i++) {
        int tempEl = arr[i];
        arr[i] = newFirstEl;
        newFirstEl = tempEl;
    }

    return arr;
}

int* sort(int* arr, int arrLen) {
    int counter = 0;
    bool isSorted = false;

    while(true) {
        bool swapElNotFound = true;

        for (int i = counter; i < arrLen; i++) {
            if (arr[i] % 2 == 0) {
                swapElNotFound = false;
                arr = swapAndMerge(arr, counter, i);
                counter++;
                break;
            }
        }
        
        if (swapElNotFound) {
            break;
        }
    }

    return arr;
}

int task1 (int* arr, int N) {
    int changeCol = 0;
    bool lastIsPlus = arr[0] >= 0;

    for (int i = 0; i < N; i++) {
        bool elementIsPlus = arr[i] >= 0;

        if (elementIsPlus != lastIsPlus) {
            lastIsPlus = elementIsPlus;
            changeCol++;
        }
    }

    return changeCol;
}

int task2(int* arr, int N) {
    int sumCounter = 1;

    bool findFirstNull = false;
    bool findSecondNull = false;

    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) {
            if (!findFirstNull) {
                findFirstNull = true;
            } else {
                findSecondNull = true;
            }
        } else {
            if (findFirstNull && !findSecondNull) {
                sumCounter *= arr[i];
            }
        }
    }

    if (!findFirstNull || !findSecondNull) {
        return 0;
    }

    return sumCounter;
}

int main() {
    int N = 0;

    while (N < 1) {
        cout << "Задайте размер массива, не меньше 1:" << endl;
        cin >> N; 
    }

    int *arr = new int[N];

    cout << "Ваш массив в " << N << " элементов. Хотите ввести элементы сами (или они будут сгенерированны автоматически)? (Y/N)" << endl;

    string answer;

    cin >> answer;

    if (answer == "Y" || answer == "y") {
        for (int i = 0; i < N; i++) {
            int el;
            cout << "Введи элемент (целое число):" << endl;
            cin >> el;
            arr[i] = el;
        }
        
    } else {
        int min, max;
        cout << "Укажите минемальное значение" << endl;
        cin >> min;
        cout << "Укажите максимальное значение" << endl;
        cin >> max;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(min, max);

        for (int i = 0; i < N; i++) {
            arr[i] = dist(gen);
        }

        cout << "Числа сгенерированны" << endl;
    }

    cout << "Ваш массив: [ ";

    for (int i = 0; i < N; i++) {
            cout << arr[i] << ", ";
    }

    cout << "]" << endl;

    

    cout << "Количество перемен знака: " << task1(arr, N) << endl;
    cout << "Произведение элементов массива, расположенных между первым и вторым нулевыми элементами: " << task2(arr, N) << endl;

    arr = sort(arr, N);

    cout << "Новый массив: [ ";

    for (int i = 0; i < N; i++) {
            cout << arr[i] << ", ";
    }

    cout << "]" << endl;

    return 0;
}