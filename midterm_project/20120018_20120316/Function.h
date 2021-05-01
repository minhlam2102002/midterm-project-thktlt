#pragma once
#include "Struct.h"

int countDecBytes(string number);
int countBinBytes(string number);
bool decimalToBigInt(string number, BigInt& res);
bool binaryToBigInt(string number, BigInt& res);
bool posDecimalToBinary(string number, string& res);
bool negDecimalToBinary(string number, string& res);