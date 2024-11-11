#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

int generateRandomNumber(int& min, int& max);

void binarySearch(int& target, int low, int high, int& attempts);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int min = 0;
    int max = 1000;
    int targetNumber = generateRandomNumber(min, max);
    int attempts = 0;

    cout << "Задуманное число: " << targetNumber << endl; 
    binarySearch(targetNumber, min, max, attempts);

    return 0;
}

int generateRandomNumber(int& min, int& max) {
    return rand() % (max - min + 1) + min;
}

void binarySearch(int& target, int low, int high, int& attempts) {
    if (low > high) {
        cout << "Число не найдено в диапазоне." << endl;
        return;
    }

    int guess = (low + high) / 2;
    attempts++;

    cout << "Попытка #" << attempts << ": " << guess << endl;

    if (guess < target) {
        cout << "Число больше, чем " << guess << endl;
        binarySearch(target, guess + 1, high, attempts);
    }
    else if (guess > target) {
        cout << "Число меньше, чем " << guess << endl;
        binarySearch(target, low, guess - 1, attempts);
    }
    else {
        cout << "Число угадано! Это " << guess << " после " << attempts << " попыток." << endl;
    }
}
