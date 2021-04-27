#pragma once
#include<iostream>
using namespace std;

struct BigInt
{
    int sign = 1; // 1 la so duong, -1 la so am, 0 la so 0
    int base = 10;
    int numBit = 4;//000000010 -> 1111111101
    string data, data2; // data in Decimal, data in Binary
    BigInt& operator=(const BigInt &number) {
        sign = number.sign;
        base = number.base;
        data = number.data;
        data2 = number.data2;
        return *this;
    }
    void Read()
    {
        cin >> data;
        if (data[0] == '-')
        {
            sign = -1;
            data.erase(0, 1);
        }
        else {
            sign = 1;
        }
    }
    void SetData(string number) {
        data = number;
        if (number[0] == '-')
        {
            sign = -1;
            data.erase(0, 1);
        }
        else
        {
            sign = 1;
        }
    }
    string PrintData() {
        string res = "";
        if (sign == -1 && base == 10) {
            res += '-';
        }
        if (base == 10) {
            res += data;
        }
        else {
            res += data2;
        }
        return res;
    }
};