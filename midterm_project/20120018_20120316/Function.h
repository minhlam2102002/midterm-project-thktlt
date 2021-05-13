#pragma once
#include "Struct.h"
#include "norOperator.h"

bool decimalToBigInt(string number, BigInt& res);
bool binaryToBigInt(string number, BigInt& res);

string BigIntToBinary(BigInt number);
string decimalToBinary(string dec);
bool posDecimalToBinary(string number, string& res);
bool negDecimalToBinary(string number, string& res);

string posBinaryToDecimal(string bin);
string negBinaryToDecimal(string bin);
string binaryToDecimal(string bin);
string BigIntToDecimal(BigInt number);