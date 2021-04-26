// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

typedef unsigned char BYTE;
using namespace std;

struct BigInt
{
    int   nBytes;
    BYTE* pData;
};


void FreeBigInt(BigInt& x)
{
    delete[] x.pData;
    x.pData = NULL;
    x.nBytes = 0;
}

string GetDigit(BigInt x) // lấy chữ số hàng đơn vị của x nếu x <= 9
{
    char temp[3];
    temp[0] = x.pData[0] + 48;
    temp[1] = 0;
    return temp;
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
    for (int i = 0; i < x.nBytes; i++)
        if (x.pData[i] != 0)
            return true;
    return false;
}

void    BigInt2String(BigInt x, string str)
{
    str = "";

    BigInt y, z1, z2;
    InitByteValue(y, 10);// khởi gán với giá trị < 256

    do
    {
        z1 = OperatorMod(x, y);    // z1 = x % y
        z2 = OperatorDivide(x, y); // z2 = x / y
        str = str + GetDigit(z1);
    } while (IsNonZero(z2));
}

void    OperatorAssignment(BigInt source, BigInt& target)
{
    FreeBigInt(target);
    target.nBytes = source.nBytes;
    target.pData = new BYTE[target.nBytes];
    memcpy(target.pData, source.pData, target.nBytes); // deep copy
}


BigInt  OperatorAdd(BigInt x, BigInt y)
{
    int nx = x.nBytes;
    int ny = y.nBytes;
    int n = (nx > ny) ? nx : ny;

    BYTE* pTemp = new BYTE[n+1];

    BYTE carry = 0;
    int temp;
    for (int i = 0; i < n; i++)
    {
         temp = x.pData[i] + y.pData[i] + carry;
         pTemp[i] = temp % 256; // lấy phần lưu trữ trong byte hiện tại
         carry = temp / 256;
    }

    if (carry != 0)
    {
        pTemp[n] = carry;
        n++;        
    }

    BigInt res;
    res.nBytes = n;
    res.pData = pTemp;

    return res;
}

// Khởi gán 1 số bigint bằng giá trị 1 byte 0-->255
bool InitByteValue(BigInt& x, BYTE v)
{
    x.pData = new BYTE[1];
    x.nBytes = 1;
    x.pData[0] = v;
    return true;
}


bool    String2BigInt(string str, BigInt& x)
{

    return true;
}


int main()
{
    BigInt x;
    x.pData = new BYTE[1];
    x.nBytes = 1;
    x.pData[0] = 100;

    BigInt y;
    y.pData = new BYTE[1];
    y.nBytes = 1;
    y.pData[0] = 200;


    BigInt z;
    z = OperatorAdd(x, y); //z[0] = 300%256, z[1] = 300/256

    cout<< GetDigit(x);



    std::cout << "Hello World!\n";
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
