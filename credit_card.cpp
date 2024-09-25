#include <iostream>
using namespace std;

bool isValid(long number);
int sumOfDoubleEvenPlace(long number);
int getDigit(int number);
bool prefixMatched(long number, int d);
int getSize(long d);
long getPrefix(long number, int k);
int sumOfOddPlace(long number);

int main() {
    long cardNumber;
    cout << "Enter a credit card number: ";
    cin >> cardNumber;
    
    if (isValid(cardNumber)) {
        cout << "Valid credit card number." << endl;
    } else {
        cout << "Invalid credit card number." << endl;
    }
    
    return 0;
}

bool isValid(long number) {
    int total = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return (total % 10 == 0);
}

int sumOfDoubleEvenPlace(long number) {
    int sum = 0;
    while (number > 0) {
        int digit = (number % 100) / 10;
        sum += getDigit(digit * 2);
        number /= 100;
    }
    return sum;
}

int getDigit(int number) {
    if (number < 10) {
        return number;
    } else {
        return (number % 10) + (number / 10);
    }
}

bool prefixMatched(long number, int d) {
    return getPrefix(number, getSize(d)) == d;
}

int getSize(long d) {
    int count = 0;
    while (d > 0) {
        d /= 10;
        count++;
    }
    return count;
}

long getPrefix(long number, int k) {
    int size = getSize(number);
    if (size < k) {
        return number;
    }
    while (size > k) {
        number /= 10;
        size--;
    }
    return number;
}

int sumOfOddPlace(long number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 100;
    }
    return sum;
}
