#include <iostream>
#include <algorithm>
#include <string.h>
#include<stdio.h>

using namespace std;

string _plus(string &a, string &b) {
    int size_a = a.size();
    int size_b = b.size();
    int size = max(size_a, size_b) + 1;
    string result(size, '0');
    int i = size_a - 1;
    int j = size_b - 1;
    int adv = 0;
    int current = size - 1;
    while(i >= 0 || j >= 0) {
        int sum = 0;
        if(i < 0) {
            sum = adv + b[j] - '0';
        } else if (j < 0) {
            sum = adv + a[i] - '0';
        } else {
            sum = adv + a[i] + b[j] - '0' - '0';
        }
        if(sum >= 10) {
            adv = 1;
            result[current] = sum - 10 + '0';
        } else {
            adv = 0;
            result[current] = sum + '0';
        }
        --current;
        --i;
        --j;
    }
    if(adv == 1) {
        result[0] = '1';
        return result;
    } else {
        return result.substr(1, size - 1);
    }
}

string _multiply(string &s, int num) {
    if(num == 0) {
        return "0";
    } else if (num == 1) {
        return s;
    } else {
        int size = s.size();
        string result(size + 1, '0');
        int adv = 0;
        for(int i = size; i > 0; --i) {
            int val = num * (s[i - 1] - '0') + adv;
            adv = val / 10;
            result[i] = (val % 10) + '0';
        }
        if(adv == 0) {
            return result.substr(1, size);
        } else {
            result[0] = adv + '0';
            return result;
        }
    }
}

string multiply(string num1, string num2) {
    string result = "0";
    if(num1 == "0" || num2 == "0") {
        return result;
    } else if(num1 == "1") {
        return num2;
    } else if(num2 == "1") {
        return num1;
    }
    string tmp = "";
    int size1 = num1.size();
    for(int i = size1 - 1; i >= 0; --i) {
        string p = _multiply(num2, num1[i] - '0') + tmp;
        result = _plus(result, p);
        // cout << result << endl;
        tmp += '0';
    }
    return result;
}

int main() {
    cout << multiply("123", "456") << endl;
    return 0;
}
