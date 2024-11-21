#include <iostream>
#include <ctime>
#include <Windows.h>
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
    std::cout << "Задуманное число: " << targetNumber << std::endl; 
    binarySearch(targetNumber, min, max, attempts);
    return 0;
}

int generateRandomNumber(int& min, int& max) {
    return rand() % (max - min + 1) + min;
}
void binarySearch(int& target, int low, int high, int& attempts) {
    if (low > high) {
        std::cout << "Число не найдено в диапазоне." << std::endl;
        return;
    }
    int guess = (low + high) / 2;
    attempts++;
    std::cout << "Попытка #" << attempts << ": " << guess << std::endl;

    if (guess < target) {
        std::cout << "Число больше, чем " << guess << std::endl;
        binarySearch(target, guess + 1, high, attempts);
    }
    else if (guess > target) {
        std::cout << "Число меньше, чем " << guess << std::endl;
        binarySearch(target, low, guess - 1, attempts);
    }
    else {
        std::cout << "Число угадано! Это " << guess << " после " << attempts << " попыток." << std::endl;
    }
}
