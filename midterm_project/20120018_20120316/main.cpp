#define _CRT_SECURE_NO_WARNINGS
#include "Struct.h"
#include "Function.h"
//#include "bitOperator.h"
#include "norOperator.h"

using namespace std;

int main() {
	BigInt a, b;
	decimalToBigInt("1111", a);
	decimalToBigInt("555", b);
	BigInt c;
	c = a / b;
	a.Print();
	b.Print();
	c.Print();

	//BigInt bina, binb;
	//binaryToBigInt("110011011111", bina); 
	//binaryToBigInt("10010101", binb);

	//cout << BigIntToBinary(bina) << endl;
	//cout << binaryToDecimal("101") << endl;
	//bina.Print();
	//binb.Print();

	//cout<<binaryToDecimal("01101010111110111111")<<endl;
	//cout << decimalToBinary("3385");
	//cout << decimalToBinary("8793278316383117319") << endl;
	//BigInt c = a + b;
	//a.Print();
	//b.Print();
	//c.Print();
	//delete[]a.data;
	//delete[]b.data;
}