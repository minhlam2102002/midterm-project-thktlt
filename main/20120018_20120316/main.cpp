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
    const char* inp = "inputTuan.txt";//argv[1];
    const char* out = "outputTuan.txt";//argv[2];
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
            if(base == 2){
                num1.data = toDecimal(num1).data;
                num2.data = toDecimal(num2).data;
            }
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
            else if (push[2] == "|") {
                cout << (num1 | num2).PrintData()<<endl;
            }
            else if (push[2] == "^") { 
                cout << (num1 ^ num2).PrintData()<<endl;
            }
        }
    }
    cout << "done";
    return 0;
}