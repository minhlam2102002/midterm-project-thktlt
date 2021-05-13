#include"norOperator.h"

BigInt operator+(BigInt num1, BigInt num2) {
	BigInt res;
	res.nByte = 16;
	res.data = new BYTE[16];
	int carry = 0;
	for (int i = 0; i < res.nByte; i++) {
		res.data[i] = (num1.data[i] + num2.data[i] + carry) % 256;
		if (num1.data[i] + num2.data[i] + carry >= 256)
			carry = 1;
		else carry = 0;
	}
	return res;
}

BigInt operator-(BigInt num1, BigInt num2) {
	BigInt res;
	res.data = new BYTE[16];
	string num = BigIntToBinary(num2);
	for (int i = 0; i < num.size(); i++) {
		num[i] = (num[i] == '0') ? '1' : '0';
	}
	for (int i = num.size() - 1; i >= 0; i--) {
		if (num[i] == '1') {
			num[i] = '0';
		}
		else {
			num[i] = '1';
			break;
		}
	}
	binaryToBigInt(num, res);
	return res + num1;
}

BigInt operator*(BigInt num1, BigInt num2) {
	BigInt res;
	res.data = new BYTE[16];
	for (int i = 0; i < 16; i++) {
		res.data[i] = 0;
	}
	//int carry = 0;
	for (int i = 0; i < 16; i++) {
		BigIntMultiInt(BigIntMultiInt(num1, num2.data[i]), pow(256, i)).Print();
		res = res + BigIntMultiInt(BigIntMultiInt(num1, num2.data[i]), pow(256, i));
		res.Print();
	}
	return res;
}
BigInt div2(BigInt number) {
	BigInt res;
	
	return res;
}
BigInt operator/(BigInt num1, BigInt num2) {
	BigInt left, right = num1;
	BigInt res;
	//while (left <= right) {
	//	BigInt mid = left + ((right - left) > 1);
	//	if (num2 * mid <= right) {
	//		res = mid;
	//		left = mid;
	//	}
	//	else {
	//		right = mid;
	//	}
	//}
	return res;
}

BigInt operator%(BigInt num1, BigInt num2) {
	BigInt div = num1 / num2;
	BigInt mod = num1 - (num2 * div);
	return mod;
}

string addString(string num1, string num2) {
	string res = "";
	while (num1.length() < num2.length()) {
		num1 = "0" + num1;
	}
	while (num2.length() < num1.length()) {
		num2 = "0" + num2;
	}
	int carry = 0;
	for (int i = num1.length() - 1; i >= 0; i--) {
		int tmp = num1[i] - '0' + num2[i] - '0' + carry;
		carry = tmp / 10;
		tmp = tmp % 10;
		res = (char)(tmp + '0') + res;
	}
	if (carry > 0) {
		res = "1" + res;
	}
	return res;
}

BigInt BigIntMultiInt(BigInt num, int n) {
	BigInt res;
	res.data = new BYTE[16];	//default
	int carry = 0;
	for (int i = 0; i < 16; i++) {
		res.data[i] = (n * num.data[i] + carry) % 256;
		carry = (n * num.data[i] + carry) / 256;
	}
	// quy uoc 16bytes nen day la truong hop khac
	/*
	if (carry != 0)
		res.data[17] = carry % 256;
	*/
	return res;
}

string operator/(string number, const int& divisor)
{
	string res;
	int Int = 0;
	for (int i = 0; i < number.size(); i++) {
		Int = Int * 10 + number[i] - '0';
		if (Int > divisor) {
			break;
		}
	}
	if (Int < divisor) {
		return "0";
	}
	int i = 0;
	Int = number[i] - '0';
	while (Int < divisor)
		Int = Int * 10 + (number[++i] - '0');

	while (number.size() > i) {
		res += (Int / divisor) + '0';
		Int = (Int % divisor) * 10 + number[++i] - '0';
	}
	return res;
}