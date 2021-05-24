#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstdio>
#include <sstream>
#include<vector>
#include "Operator.h"
#include "Struct.h"
#include "Function.h"
using namespace std;

void check() {
    // input so nhi phan auto > 0
    // so thap phan == 0 thi not ra 1
    // input so thap phan < 0 thi doi sang bu 2 roi xu ly cac phep tinh bit
    BigInt a, b;
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
int main(int argc, char** argv)
{
    char* inp = argv[1];
    char* out = argv[2];
    freopen(inp, "r", stdin);
    freopen(out, "w", stdout);
    string line, word;
    int base;
    while (getline(cin, line)) {
        BigInt num,num1,num2;
        vector<string> push;
        stringstream ss(line);
        while (ss >> word) {
            push.push_back(word) ;
        }
        base = stoi(push[0]);
        //cout << endl << push[2] << endl;

        if (push[0] == "10" && push[1] == "2") {
            num.SetData(10,push[2]);
            cout << toBinary(num).PrintData()<< endl;
        }
        else if (push[0] == "2" && push[1] == "10") {
            num.SetData(2,push[2]);
            cout << toDecimal(num).PrintData()<< endl;
        }
        else if (push[1] == "~") {
            num.SetData(base, push[2]);
            cout << (~num).PrintData() << endl;
        }
        else {
            num1.SetData(base, push[1]);
            num2.SetData(base, push[3]);
            if (push[2] == "+")
                cout << (num1 + num2).PrintData() << endl;
            else if (push[2] == "-")
                cout << (num1 - num2).PrintData() << endl;
            else if (push[2] == "*")
                cout << (num1 * num2).PrintData() << endl;
            else if (push[2] == "%")
                cout << (num1 % num2).PrintData() << endl;
            else if (push[2] == ">>") {
                int move = stoi(push[3]);
                cout << (num1 >> move).PrintData() << endl;
            }
            else if (push[2] == "<<") {
                int move = stoi(push[3]);
                cout << (num1 << move).PrintData() << endl;
            }
            else if (push[2] == "&") {
               cout << (num1 & num2).PrintData() << endl;
            }
            else if (push[2] == "&") {
                cout << (num1 & num2).PrintData() << endl;
            }
            else if (push[2] == "|") {
                cout << (num1 | num2).PrintData()<<endl;
            }
            else if (push[2] == "^") { 
                cout << (num1 ^ num2).PrintData()<<endl;
            }
        }
    }
    //cout << "done";
}