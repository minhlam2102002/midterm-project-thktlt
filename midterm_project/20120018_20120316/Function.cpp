#include "Function.h"
/*
	Note:
	- Binary to

*/

bool posDecimalToBinary(string number, string& res) {
	res = "";
	while (number != "0") {
		res += ((number.back() - '0') % 2 == 0) ? '0' : '1';
		number = number / 2;
	}
	reverse(res.begin(), res.end());
	return true;
}

bool negDecimalToBinary(string number, string& res) {
	if (number[0] == '-') {
		number = number.erase(0, 1);
	}
	posDecimalToBinary(number, res);
	for (int i = 0; i < res.size(); i++) {
		res[i] = (res[i] == '0') ? '1' : '0';
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		if (res[i] == '1') {
			res[i] = '0';
		}
		else {
			res[i] = '1';
			break;
		}
	}
	return true;
}
string decimalToBinary(string dec) {
	string bin;
	if (dec[0] == '-') {
		negDecimalToBinary(dec, bin);
		while (bin.size() < 128) {
			bin = '1' + bin;
		}
	}
	else {
		posDecimalToBinary(dec, bin);
	}
	return bin;
}
bool decimalToBigInt(string number, BigInt& res) {
	string bin;
	if (number[0] == '-') {
		negDecimalToBinary(number, bin);
		while (bin.size() < res.nByte * 8) {
			bin = '1' + bin;
		}
	}
	else {
		posDecimalToBinary(number, bin);
		while (bin.size() < res.nByte * 8) {
			bin = '0' + bin;
		}
	}
	binaryToBigInt(bin, res);
	return true;
}
bool binaryToBigInt(string number, BigInt& res) {
	while (number.size() % 8 != 0) {
		number = '0' + number;
	}
	res.data = new BYTE[res.nByte];
	for (int i = 0; i < res.nByte; i++) {
		res.data[i] = 0;
	}
	int n = number.size();
	for (int i = 0; i < res.nByte; i++) {
		int Pow = 1;
		for (int j = n - i * 8 - 1; j >= 0; j--) {
			res.data[i] += Pow * (number[j] == '1');
			Pow *= 2;
		}
	}
	return true;
}


string BigIntToBinary(BigInt number) {
	string res = "";
	for (int i = 0; i < 16; i++) {
		int bigI = number.data[i];
		if (bigI == 0) {
			res += "00000000";
		}
		while (bigI > 0) {
			res += char(bigI % 2 + '0');
			bigI /= 2;
		}
		while (res.size() % 8 != 0) {
			res += '0';
		}
	}
	while (res.size() < 128) res += '0';
	reverse(res.begin(), res.end());
	return res;
}
string posBinaryToDecimal(string bin) {
	string dec = "0";
	string Pow = "1";
	for (int i = bin.size() - 1; i >= 0; i--)
	{
		if (bin[i] == '1')
		{
			dec = addString(dec, Pow);
		}
		Pow = addString(Pow, Pow);
	}
	return dec;
}
string negBinaryToDecimal(string bin) {
	for (int i = 0; i < bin.size(); i++) {
		bin[i] = (bin[i] == '0') ? '1' : '0';
	}
	for (int i = bin.size() - 1; i >= 0; i--) {
		if (bin[i] == '1') {
			bin[i] = '0';
		}
		else {
			bin[i] = '1';
			break;
		}
	}
	return posBinaryToDecimal(bin);
}
string binaryToDecimal(string bin) {
	if (bin.size() > 127 && bin[0] == '1')
		return negBinaryToDecimal(bin);
	else {
		return posBinaryToDecimal(bin);
	}
}

string BigIntToDecimal(BigInt number) {
	return binaryToDecimal(BigIntToBinary(number));
}