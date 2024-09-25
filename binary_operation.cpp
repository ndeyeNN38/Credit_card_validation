#include <iostream>
#include <string>
#include <bitset>
#include <utility>

using namespace std;

pair<string, string> divide(const string& dividend, const string& divisor) {
    // Check if the divisor is greater than the dividend
    if (divisor > dividend) {
        return make_pair("0", dividend); // Quotient is 0, remainder is dividend
    }

    // Check if both dividend and divisor are short integers (less than 16 bits)
    bool isShortDivision = (dividend.length() <= 16 && divisor.length() <= 16); // 16 characters = 16 bits

    if (isShortDivision) {
        // Perform short integer division
        int dividendValue = stoi(dividend, nullptr, 2);
        int divisorValue = stoi(divisor, nullptr, 2);

        int quotientValue = dividendValue / divisorValue;
        int remainderValue = dividendValue % divisorValue;

        // Convert quotient and remainder back to binary strings
        string quotient = bitset<16>(quotientValue).to_string().substr(16 - dividend.length());
        string remainder = bitset<16>(remainderValue).to_string().substr(16 - divisor.length());

        return make_pair(quotient, remainder);
    } else {
        // Placeholder for long integer division (e.g., polynomial long division)
        // Implement your long division algorithm here
        // For demonstration purposes, we'll just return the original inputs
        return make_pair("Long division not implemented", "Long division not implemented");
    }
}


const int SIZE = 2;

using namespace std;

// Function prototypes
string* get_binaries(const int);
bool is_binary(const string&);
void add_leading_zeros(string*, const int);
void swap(string&, string&);
string add(const string&, const string&);
string subtract(const string&, const string&);
string multiply(const string&, const string&);
pair<string, string> divide(const string&, const string&);
void deallocate_binaries(string*);

int main() {
    string* binaries = get_binaries(SIZE);

    if (binaries == nullptr) {
        cout << "The value entered is not binary number" << endl;
        return 1;
    }

    // Perform binary arithmetic operations
    add_leading_zeros(binaries, SIZE);
    string sum = add(binaries[0], binaries[1]);
    string difference = subtract(binaries[0], binaries[1]);
    string product = multiply(binaries[0], binaries[1]);
    pair<string, string> division_result = divide(binaries[0], binaries[1]);

    // Display results

// Display results
cout << "Enter a binary:  " << binaries[0] << endl;
cout << "Enter a binary:  " << binaries[1] << endl;
cout << "Result of +  :   " << sum << endl;
cout << "Result of - :    " << difference << endl;
cout << "Result of * :    " << product << endl;
cout << "Result of / :    "<< endl;


    pair<string, string> result = divide(binaries[0], binaries[1]);

    cout << "q = : " << result.first << endl;
    cout << "r = : " << result.second << endl;

    return 0;
}


// User Input and Validation
string* get_binaries(const int size) {
    string* binaries = new string[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter binary number " << i + 1 << ": ";
        getline(cin, binaries[i]);

        // Validate binary input
        while (!is_binary(binaries[i])) {
            cout << "The value entered is not a binary number"<<endl;
            cout << "Enter a binary: ";
            getline(cin, binaries[i]);
        }
    }

    return binaries;
}


bool is_binary(const string& binary) {
    for (char c : binary) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}

// Add leading zeros
void add_leading_zeros(string* binaries, const int size) {
    int maxLength = 0;
    for (int i = 0; i < size; i++) {
        maxLength = max(maxLength, static_cast<int>(binaries[i].length()));
    }

    for (int i = 0; i < size; i++) {
        binaries[i].insert(0, maxLength - binaries[i].length(), '0');
    }
}

// Swap two strings
void swap(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

// Binary Addition
string add(const string& a, const string& b) {
    string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 2;
        sum %= 2;
        result = to_string(sum) + result;
    }
    return result;
}

// Binary Subtraction
string subtract(const string& a, const string& b) {
    string result = "";
    int borrow = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0) {
        int digitA = i >= 0 ? a[i--] - '0' : 0;
        int digitB = j >= 0 ? b[j--] - '0' : 0;
        int diff = digitA - digitB - borrow;
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = to_string(diff) + result;
    }
    // Remove leading zeros
    result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
    return result;
}

// Binary Multiplication
string multiply(const string& a, const string& b) {
    int m = a.length();
    int n = b.length();
    string result(m + n, '0');

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + (result[i + j + 1] - '0');
            result[i + j + 1] = sum % 2 + '0';
            result[i + j] += sum / 2;
        }
    }

    // Remove leading zeros
    result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
    return result;
}

// Binary Division


    // If quotie

// Memory deallocation
void deallocate_binaries(string* binaries) {
    delete[] binaries;
}

