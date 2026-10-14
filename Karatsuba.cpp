#include <iostream>
#include <string>
using namespace std;

// Remove leading zeros
string removeZeros(string s) {
    int i = 0;

    while (i < s.length() - 1 && s[i] == '0')
        i++;

    return s.substr(i);
}

// Add two large numbers
string add(string a, string b) {
    string result = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry != 0) {
        int sum = carry;

        if (i >= 0)
            sum = sum + (a[i] - '0');

        if (j >= 0)
            sum = sum + (b[j] - '0');

        result = char((sum % 10) + '0') + result;
        carry = sum / 10;

        i--;
        j--;
    }

    return removeZeros(result);
}

// Subtract b from a
// Here we assume a >= b
string subtract(string a, string b) {
    string result = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int borrow = 0;

    while (i >= 0) {
        int x = (a[i] - '0') - borrow;
        int y = 0;

        if (j >= 0)
            y = b[j] - '0';

        if (x < y) {
            x = x + 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        result = char((x - y) + '0') + result;

        i--;
        j--;
    }

    return removeZeros(result);
}

// Add zeros at the end
string addZeros(string s, int n) {
    if (s == "0")
        return s;

    for (int i = 0; i < n; i++)
        s = s + "0";

    return s;
}

// Karatsuba multiplication
string karatsuba(string x, string y){
    x = removeZeros(x);
    y = removeZeros(y);

    // Base case
    if (x.length() <= 9 && y.length() <= 9) {
        long long a = stoll(x);
        long long b = stoll(y);

        long long result = a * b;

        return to_string(result);
    }

    // Make both numbers equal in length
    int n = x.length();

    if (y.length() > n)
        n = y.length();

    while (x.length() < n)
        x = "0" + x;

    while (y.length() < n)
        y = "0" + y;

    // Make length even
    if (n % 2 != 0) {
        x = "0" + x;
        y = "0" + y;
        n++;
    }

    int m = n / 2;

    // DIVIDE
    string a = x.substr(0, m);
    string b = x.substr(m);

    string c = y.substr(0, m);
    string d = y.substr(m);

    // CONQUER
    string P1 = karatsuba(a, c);
    string P2 = karatsuba(b, d);

    string aPlusB = add(a, b);
    string cPlusD = add(c, d);

    string P3 = karatsuba(aPlusB, cPlusD);

    // Middle term
    string middle = subtract(P3, P1);
    middle = subtract(middle, P2);

    // COMBINE
    string part1 = addZeros(P1, 2 * m);
    string part2 = addZeros(middle, m);

    string result = add(part1, part2);
    result = add(result, P2);

    return removeZeros(result);
}

int main() {
    string N;

    cout << "Enter a 20-digit number: ";
    cin >> N;

    if (N.length() != 20) {
        cout << "Please enter exactly 20 digits." << endl;
        return 0;
    }

    string square = karatsuba(N, N);

    cout << endl;
    cout << "N  = " << N << endl;
    cout << "N^2 = " << square << endl;
    cout << "Digits in N^2: " << square.length() << endl;
    cout << "Method: Karatsuba Divide and Conquer" << endl;

    return 0;
}