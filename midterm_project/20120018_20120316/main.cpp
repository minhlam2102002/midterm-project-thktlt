#define _CRT_SECURE_NO_WARNINGS
#include "Struct.h"
#include "Function.h"
//#include "bitOperator.h"
#include "norOperator.h"

using namespace std;

int main() {
	BigInt a, b,c,d;
	
	decimalToBigInt("893", a);
	decimalToBigInt("66584", b);
	cout << "893 = "; //893 = 125 3 0 0 = 11 0111 1101
	a.Print();
	cout << "66584 = ";
	b.Print();
	d = b - a;
	d.Print();
	string str = BigIntToBinary(d);
	cout << str << endl;
	string ss = binaryToDecimal(str);
	cout << ss << endl;

	//string str=BigIntToDecimal(d);
	//cout << str << endl;
	
	//BigInt bina, binb,res;
	//decimalToBigInt("983", bina);
	////decimalToBigInt("914432", binb);
	//bina.Print();
	//binb.Print();
	//cout << "hel";
	//res = bina + binb;
	//res.Print();
	//cout << BigIntToBinary(bina) << endl;
	//cout << binaryToDecimal("101") << endl;
	//bina.Print();
	//binb.Print();

	//cout<<binaryToDecimal("01101010111110111111")<<endl;
	//string bin="";
	//posDecimalToBinary("213", bin);
	//cout << bin << endl;
	//cout << decimalToBinary("8793278316383117319") << endl;
	//BigInt c = a + b;
	//a.Print();
	//b.Print();
	//c.Print();
	//delete[]a.data;
	//delete[]b.data;

}