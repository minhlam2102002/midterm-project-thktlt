#define _CRT_SECURE_NO_WARNINGS
#include "Struct.h"
#include "Function.h"
//#include "bitOperator.h"
#include "norOperator.h"

using namespace std;

int main() {
	//string dec = "-300", bin;
	//BigInt x;
	//negDecimalToBinary(dec, bin);
	//cout << bin << endl;
	//decimalToBigInt(dec, x);
	//x.Print();
	// 1byte -> -2^7 -> 2^7-1
	//          -128 -> 127
	// 2 byte 
	// 1111 1110 = -2
	BigInt a, b;
	decimalToBigInt("252", a);
	decimalToBigInt("-252", b);
	//countDecBytes(a, b);
	a.Print();
//<<<<<<< HEAD
	b.Print();

	BigInt bina, binb;
	bina.nByte = binb.nByte = max(countBinBytes("01010"),countBinBytes("10010101"));
	binaryToBigInt("10101010", bina);
	binaryToBigInt("10010101", binb);
	bina.Print();
	binb.Print();
	//binaryToBigInt("01101110", b);
	//BigInt c = a + b;
	//a.Print();
	//b.Print();
	//c.Print();
	//delete[]a.data;
	//delete[]b.data;
	//01
	//1111111111
	cout << "hello";
}