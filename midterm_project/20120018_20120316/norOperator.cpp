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