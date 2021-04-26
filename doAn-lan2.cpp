// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>



using namespace std;

struct BigInt
{
    string pData;
};



string GetDigit(BigInt x) // lấy chữ số hàng đơn vị của x nếu x <= 9
{
    return "";
}

BigInt OperatorMod(BigInt x, BigInt y)
{
    BigInt res = x;
    return res;
}

BigInt OperatorDivide(BigInt x, BigInt y)
{
    BigInt res = x ;
    return res;
}

bool IsNonZero(BigInt x)
{
    return false;
}

string ReverseString(string s)
{
    string sTemp = s;
    reverse(sTemp.begin(), sTemp.end());
    return sTemp;
}

void    BigInt2String(BigInt x, string& str)
{
    string sReverse = ReverseString(x.pData);
    str = sReverse;
}

void    OperatorAssignment(BigInt source, BigInt& target)
{
}

int GetNumberOfDigits(BigInt x)
{
    return x.pData.length();
}

int GetDigit(BigInt x, int pos)
{
    int n = GetNumberOfDigits(x);
    if (pos < n)
        return x.pData[pos]-48;
    return 0;
}

string Value2String(int v)
{
    char pTemp[1024];
    
    sprintf(pTemp, "%d", v);
    return pTemp;
}

BigInt  OperatorAdd(BigInt x, BigInt y)
{
    int nx = GetNumberOfDigits(x);
    int ny = GetNumberOfDigits(y);
    BigInt res;
    int carry = 0;
    int n = (nx > ny) ? nx : ny;
    int temp;
    string str = "";
    for (int i = 0; i < n; i++)
    {
        int a = GetDigit(x, i); // lấy chữ số thứ i trong x
        int b = GetDigit(y, i);
        temp = a + b + carry;
        
        str = str + Value2String(temp % 10);
        carry = temp / 10;
    }

    if (carry)
        str = str + Value2String(carry % 10);
    res.pData = str;
    return res;
}


bool    String2BigInt(string str, BigInt& x)
{
    string sReverse = ReverseString(str);
    x.pData = sReverse;
    return true;
}


int main()
{
    BigInt x, y, z;
    String2BigInt("99945", x);
    String2BigInt("99", y);
    z = OperatorAdd(x, y);
    string temp;
    BigInt2String(z, temp);
    cout << temp;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
