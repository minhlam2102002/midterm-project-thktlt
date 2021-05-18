#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstdio>
#include "Operator.h"
#include "Struct.h"
#include "Function.h"
using namespace std;

void check() {
    // input so nhi phan auto > 0
    // so thap phan == 0 thi not ra 1
    // input so thap phan < 0 thi doi sang bu 2 roi xu ly cac phep tinh bit
    BigInt a, b;
    a.SetData("-2");
    b.SetData("3");
    int bint = 3;
    BigInt bin;
    bin.base = 2;
    bin.sign = 1;
    bin.data2 = "10101";
    cout << a.PrintData() << " x " << b.PrintData() << endl;
    a = toBinary(a);
    b = toBinary(b);
    int Int = 2;
    cout << a.data2 << " & " << b.data2 << " = " << (a & b).PrintData() << endl;
    cout << a.data2 << " | " << b.data2 << " = " << (a | b).PrintData() << endl;
    cout << a.data2 << " ^ " << b.data2 << " = " << (a ^ b).PrintData() << endl;
    cout << a.data2 << " >> " << Int << " = " << (a >> Int).PrintData() << endl;
    cout << a.data2 << " << " << Int << " = " << (a << Int).PrintData() << endl;
    cout << "Not of " << a.PrintData() << " is " << (~a).PrintData() << endl;
    //cout << "Not of " << bin.PrintData() << " is " << (~bin).PrintData() << endl;
    /*cout << a.data << " + " << b.data << " = " << (a+b).data << endl;
    cout << a.data << " - " << b.data << " = " << (a-b).data << endl;
    cout << a.data << " * " << b.data << " = " << (a*b).data << endl;
    cout << a.data << " / " << bint << " = " << (a/bint).data << endl;
    cout << a.data << " in binary is " << toBinary(a).data << endl;
    cout << bin.data2 << " in decimal is " << toDecimal(bin).data << endl;
    cout << "Before: " << a.data; 
    a = b;
    cout << ". After: " << a.data << endl;*/
    
}
int main(int argc, string argv[])
{
    freopen(argv[1].c_str(), "r", stdin);
    freopen(argv[2].c_str(), "w", stdout);
    //check();
    
}