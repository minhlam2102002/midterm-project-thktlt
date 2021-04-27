#include "Struct.h"
#include "Operator.h"
#include "Function.h"

int compare(BigInt a, BigInt b)//Judge the size of two positive numbers a > b = 1 | a < b = -1 | a == b = 0
{
    if (a.data.length() > b.data.length()) return 1;
    if (a.data.length() < b.data.length()) return -1;
    for (int i = 0; i < a.data.length(); i++)
    {
        if (a.data[i] > b.data[i]) return 1;
        if (a.data[i] < b.data[i]) return -1;
    }
    return 0;
}
void deleteZero(BigInt &number) {
    reverse(number.data.begin(), number.data.end());
    while (number.data.size() > 0 && number.data.back() == '0') {
        number.data.pop_back();
    }
    reverse(number.data.begin(), number.data.end());

    reverse(number.data2.begin(), number.data2.end());
    while (number.data2.size() > 0 && number.data2.back() == '0') {
        number.data2.pop_back();
    }
    reverse(number.data2.begin(), number.data2.end());
}
void addZero(BigInt& num1, BigInt& num2) {
    while (num1.data.length() < num2.data.length())
        num1.data = "0" + num1.data;
    while (num2.data.length() < num1.data.length())
        num2.data = "0" + num2.data;
    while (num1.data2.length() < num1.numBit)
        num1.data2 = "0" + num1.data2;
    while (num2.data2.length() < num2.numBit)
        num2.data2 = "0" + num2.data2;
    return;
}
BigInt toBinary(BigInt number)
{
    BigInt res;
    res.sign = number.sign;
    res.base = 2;
    res.data = number.data;
    while (number.sign != 0)
    {
        int lastdigit = number.data.back() - '0';
        res.data2 += char(lastdigit % 2 + '0');
        number = number / 2;
    }
    reverse(res.data2.begin(), res.data2.end());
    //2 -> 0010 -> 1101 -> 1110
    if (res.sign == -1) {
        bool flag = false;
        while (res.data2.size() < res.numBit) {
            res.data2 = "0" + res.data2;
        }
        res = ~res;
        for (int i = res.data2.size() - 1; i >= 0; i--) {
            if (res.data2[i] == '0') {
                res.data2[i] = '1';
                flag = true;
                break;
            }
            else {
                res.data2[i] = '0';
            }
        }
        if (flag == false) {
            res.data2 = "1" + res.data2;
        }
    }
    return res;
}
BigInt toDecimal(BigInt number)
{
    // number.base = 2, xet data2
    BigInt two, Pow2, res;
    res.sign = 1;
    res.base = 10;
    res.data2 = number.data2;
    two.SetData("2");
    Pow2.SetData("1");
    for (int i = number.data2.size() - 1; i >= 0; i--)
    {
        if (number.data2[i] == '1')
        {
            res = res + Pow2;
        }
        Pow2 = Pow2 * two;
    }
    return res;
}
BigInt Max(BigInt& num1, BigInt& num2) {
    if (compare(num1, num2) == 1)
        return num1;
    return num2;
}
BigInt Min(BigInt& num1, BigInt& num2) {
    if (compare(num1, num2) == 1)
        return num2;
    return num1;
}

BigInt Abs(BigInt number) {
    number.sign = 1;
    return number;
}
