#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstdio>
#include <sstream>
#include<vector>
#include "Operator.h"
#include "Struct.h"
#include "Function.h"
using namespace std;

int main()//int argc, char** argv)
{
    /*BigInt a, b;    
    a.SetData(10, "9246");
    b.SetData(10, "3");
    cout << To_string(Pow(a,b)) << endl;
    cout << "endl1 " << endl;
    cout << To_string(To_base(a,56)) << endl;
    return 0;*/
    const char* inp = "D:\INPUTHung.txt";//argv[1];
    const char* out = "output.txt";//argv[2];
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
        if (push[0] == "10" && push[1] == "2") {
            num.SetData(10,push[2]);
            cout << To_string(toBinary(num)) << endl;
        }
        else if (push[0] == "2" && push[1] == "10") {
            num.SetData(2,push[2]);
            cout << To_string(toDecimal(num)) << endl;
        }
        else if (push[1] == "~") {
            num.SetData(base, push[2]);
            cout << To_string(~num) << endl;
        }
        else {
            num1.SetData(base, push[1]);
            num2.SetData(base, push[3]);
            if (push[2] == "+")
                cout << To_string(num1 + num2) << endl;
            else if (push[2] == "-")
                cout << To_string(num1 - num2) << endl;
            else if (push[2] == "*")
                cout << To_string(num1 * num2) << endl;
            else if (push[2] == "%")
                cout << To_string(num1 % num2) << endl;
            else if (push[2] == ">>") {
                int move = stoi(push[3]);
                cout << To_string(num1 >> move) << endl;
            }
            else if (push[2] == "<<") {
                int move = stoi(push[3]);
                cout << To_string(num1 << move) << endl;
            }
            else if (push[2] == "&") {
               cout << To_string(num1 & num2) << endl;
            }
            else if (push[2] == "|") {
                cout << To_string(num1 | num2)<<endl;
            }
            else if (push[2] == "^") {
                cout << To_string(num1 ^ num2) << endl;
            }
        }
    }
    cout << "done";
    return 0;
}