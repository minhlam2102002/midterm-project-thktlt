#include "Operator.h"
#include "Struct.h"

BigInt operator<<(BigInt& number, int move) {
    if (number.data2.size() == 0) {
        number.data2 = toBinary(number).data2;
    }
    BigInt res;
    res.base = number.base;
    res.data2 = number.data2;
    while (move--) {
        res.data2 += '0';
    }
    while (res.data2.size() > res.numBit) {
        res.data2.erase(0, 1);
    }
    res.data = toDecimal(res).data;
    return res;
}

BigInt operator>>(BigInt& number, int move) {
    if (number.data2.size() == 0) {
        number.data2 = toBinary(number).data2;
    }
    BigInt res;
    res.base = number.base;
    res.data2 = number.data2;
    while (move-- && res.data2.size() > 0) {
        res.data2.pop_back();
    }
    res.data = toDecimal(res).data;
    while (res.data2.size() < res.numBit) {
        res.data2 = "0" + res.data2;
    }
    return res;
}

BigInt operator&(BigInt &num1, BigInt &num2) {
    if (num1.data2.size() == 0) {
        num1.data2 = toBinary(num1).data2;
    }
    if (num2.data2.size() == 0) {
        num2.data2 = toBinary(num2).data2;
    }
    BigInt res;
    //res.sign = 1;
    res.base = 2;
    res.data2 = "";
    addZero(num1, num2);
    for (int i = 0; i < num1.data2.size(); i++) {
        res.data2 += (num1.data2[i] + num2.data2[i] == '1' + '1') ? "1" : "0";
    }
    return res;
}
BigInt operator|(BigInt& num1, BigInt& num2) {
    if (num1.data2.size() == 0) {
        num1.data2 = toBinary(num1).data2;
    }
    if (num2.data2.size() == 0) {
        num2.data2 = toBinary(num2).data2;
    }
    BigInt res;
    //res.sign = 1;
    res.base = 2;
    res.data2 = "";
    addZero(num1, num2);
    for (int i = 0; i < num1.data2.size(); i++) {
        res.data2 += (num1.data2[i] + num2.data2[i] == '0' + '0') ? "0" : "1";
    }
    return res;
}
BigInt operator^(BigInt& num1, BigInt& num2) {
    if (num1.data2.size() == 0) {
        num1.data2 = toBinary(num1).data2;
    }
    if (num2.data2.size() == 0) {
        num2.data2 = toBinary(num2).data2;
    }
    BigInt res;
    res.base = 2;
    res.data2 = "";
    addZero(num1, num2);
    for (int i = 0; i < num1.data2.size(); i++) {
        res.data2 += (num1.data2[i] == num2.data2[i]) ? "0" : "1";
    }
    return res;
}
BigInt operator~(BigInt number) {
    if (number.base == 10){
        if (number.sign <= 0) {
            // x <= 0, x = 0 -> -1
            // ~x = -x-1
            number.sign = 1; // -x
            BigInt One;
            One.SetData(10,"1");
            return number - One; //-x-1
        }
        else
        {
            number.data2 = toBinary(number).data;
        }
    }
    for (int i = 0; i < number.data2.size(); i++) {
        number.data2[i] = (number.data2[i] == '0') ? '1' : '0';
    }
    return number;
}

BigInt operator-(BigInt num1, BigInt num2)
{
    BigInt res;
    res.base = num1.base;
    if (num1.sign == -1 && num2.sign == -1) { // am - am -2-(-3) = 3 - 2
        num1.sign = num2.sign = 1;
        swap(num1, num2);
    }

    if (num1.sign == -1 && num2.sign == 1) { // am - duong -2-3 = - (2+3)
        num1.sign = 1;
        res = num1 + num2;
        res.sign = -1;
        return res;
    }
    if (num1.sign == 1 && num2.sign == -1) { // duong - am 2-(-3) = 2 + 3
        num2.sign = 1;
        return num1 + num2;
    }
    addZero(num1, num2);
    if (num1.data < num2.data)
    {
        swap(num1.data, num2.data);
        res.sign = -1;
    }
    int borrow = 0;
    for (int i = num1.data.length() - 1; i >= 0; i--)
    {
        int tmp = num1.data[i] - num2.data[i] - borrow;
        if (tmp < 0)
        {
            tmp += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        res.data = (char)(tmp % 10 + 48) + res.data;
    }
    while (res.data.length() > 1 && res.data[0] == '0')
        res.data.erase(0, 1);
    if(res.base == 2){
        res.data2 = toBinary(res).data2;
    }
    return res;
}
BigInt operator/(const BigInt number, const int divisor)
{
    BigInt res;
    int Int = 0;
    for (int i = 0; i < number.data.size(); i++) {
        Int = Int * 10 + number.data[i] - '0';
        if (Int > divisor) {
            break;
        }
    }
    if (Int < divisor) {
        res.sign = 0;
        res.data = "0";
        return res;
    }
    res.sign = number.sign;
    int idx = 0;
    int temp = number.data[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number.data[++idx] - '0');
    while (number.data.size() > idx)
    {
        res.data += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number.data[++idx] - '0';
    }
    return res;
}
BigInt operator+(BigInt num1, BigInt num2)
{
    BigInt res;
    res.base = num1.base;
    if (num1.sign == -1 && num2.sign == -1) //am + am
    {
        res.sign = -1;
    }
    else //duong + duong
    {
        res.sign = 1;
    }
    if (num1.sign == 1 && num2.sign == -1) { // duong + am
        num2.sign = 1;
        return num1 - num2;
    }
    if (num1.sign == -1 && num2.sign == 1) { // am + duong
        num1.sign = 1;
        return num2 - num1;
    }
    addZero(num1, num2);
    int carry = 0;
    for (int i = num1.data.length() - 1; i >= 0; i--)
    {
        int tmp = num1.data[i] - '0' + num2.data[i] - '0' + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        res.data = (char)(tmp + '0') + res.data;
    }
    if (carry > 0)
        res.data = "1" + res.data;
    if(res.base == 2){
        res.data2 = toBinary(res).data2;
    }
    return res;
}
BigInt operator*(const BigInt num1, const BigInt num2)
{
    BigInt res;
    res.base = num1.base;
    res.sign = num1.sign * num2.sign;
    if (num1.data == "0" || num2.data == "0")
    {
        res.data = "0";
        return res;
    }
    int n = num1.data.length();
    int m = num2.data.length();
    int len = n + m - 1;
    int carry = 0;
    for (int i = len; i >= 0; i--)
    {
        int tmp = 0;
        for (int j = n - 1; j >= 0; j--)
            if (i - j <= m && i - j >= 1)
            {
                tmp += (num1.data[j] - '0') * (num2.data[i - j - 1] - '0');
            }
        tmp += carry;
        carry = tmp / 10;
        res.data = (char)(tmp % 10 + 48) + res.data;
    }
    while (res.data.length() > 1 && res.data[0] == '0')
        res.data.erase(0, 1);
    if(res.base == 2){
        res.data2 = toBinary(res).data2;
    }
    return res;
}

BigInt operator%(BigInt a, BigInt b) {
    
    BigInt res;
    res.sign = 1;
    if (a.data == b.data) {
        res.sign = 0;
        res.data = "0";
        return res;
    }
    return res;
}

    