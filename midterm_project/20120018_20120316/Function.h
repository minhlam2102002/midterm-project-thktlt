#pragma once
#include "Struct.h"
#include "norOperator.h"

int countDecBytes(string number);
int countBinBytes(string number);
bool decimalToBigInt(string number, BigInt& res);
bool binaryToBigInt(string number, BigInt& res);
string BigIntToBinary(BigInt number);
string decimalToBinary(string dec);
bool posDecimalToBinary(string number, string& res);
bool negDecimalToBinary(string number, string& res);
string binaryToDecimal(string bin);