#include "Struct.h"
#include "Operator.h"
#include "Function.h"

int compare(BigInt a, BigInt b)//a > b = 1 | a < b = -1 | a == b = 0
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
}
void addZero(BigInt& num1, BigInt& num2) {
    while (num1.data.length() < num2.data.length())
        num1.data = "0" + num1.data;
    while (num2.data.length() < num1.data.length())
        num2.data = "0" + num2.data;
    return;
}
BigInt toBinary(BigInt number)
{
    BigInt res;
    res.sign = number.sign;
    res.base = 2;
    while (number.data != "0")
    {
        int lastdigit = number.data.back() - '0';
        res.data += char(lastdigit % 2 + '0');
        number = number / 2;
    }
    reverse(res.data.begin(), res.data.end());
    //2 -> 0010 -> 1101 -> 1110
    if (res.sign == -1) {
        bool flag = false;
        while (res.data.size() < res.numBit) {
            res.data = "0" + res.data;
        }
        res = ~res;
        for (int i = res.data.size() - 1; i >= 0; i--) {
            if (res.data[i] == '0') {
                res.data[i] = '1';
                flag = true;
                break;
            }
            else {
                res.data[i] = '0';
            }
        }
        if (flag == false) {
            res.data = "1" + res.data;
        }
    }
    return res;
}
BigInt toDecimal(BigInt number)
{
    // number.base = 2, xet data2
    BigInt two, Pow2, res;
    res.sign = number.sign;
    res.base = 10;
    two.SetData(10,"2");
    Pow2.SetData(10,"1");
    for (int i = number.data.size() - 1; i >= 0; i--)
    {
        if (number.data[i] == '1')
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
    if(number.sign == 1) return number;
    if(number.base == 10){
        number.sign = 1;
        return number;
    }
    else if(number.base == 2){
        BigInt dec = toDecimal(number);
        dec.sign = 1;
        number = toBinary(dec);
        number.sign = 1;
        return number;
    }
}
