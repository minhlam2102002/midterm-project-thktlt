#include"norOperator.h"

BigInt operator+(BigInt num1, BigInt num2) {
	BigInt res;
	res.nByte = num1.nByte;
	res.data = new BYTE[res.nByte];
	int carry = 0;
	for(int i =0;i<res.nByte;i++){
		if (num1.data[i] + num2.data[i] + carry >= 256)
			carry = 1;
		else carry = 0;
		res.data[i] = (num1.data[i] + num2.data[i]+carry)%256;
	}
	return res;
}

BigInt operator-(BigInt num1, BigInt num2) {
	//if (num2.data[num1.nByte - 1] >= 128) {
	//	return ;
	//}
	//else {
	//	for (int i = 0; i < num2.nByte; i++) {

	//	}
	//}
	//return num1 + num2;
	BigInt res;
	return res;
}

BigInt operator*(BigInt num1, BigInt num2) {
	BigInt res;
	return res;
}
BigInt operator/(BigInt num1, BigInt num2) {
	return num1;
}

BigInt operator%(BigInt num1, BigInt num2) {
	return num1;
}

string addString(string num1, string num2){
	string res = "";
	while (num1.length() < num2.length()) {
		num1 = "0" + num1;
	}
	while (num2.length() < num1.length()) {
		num2 = "0" + num2;
	}
	int carry = 0;
	for (int i = num1.length() - 1; i >= 0; i--){
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