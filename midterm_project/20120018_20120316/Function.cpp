#include "Function.h"

bool posDecimalToBinary(string number, string &res) {
	res = "";
	while (number.size() > 1 || stoi(number) >= 2) {
		res += ((number.back() - '0') % 2 == 0) ? '0' : '1';
		string div = "";
		int firstDigits = 0;
		for (int i = 0; i < number.size(); i++) {
			firstDigits = firstDigits * 10 + number[i] - '0';
			if (number[i] == '1' && i < number.size() - 1) {
				firstDigits = firstDigits * 10 + number[i + 1] - '0';
				i++;
			}
			div += to_string(firstDigits / 2);
			firstDigits %= 2;
		}
		number = div;
	}
	res += number.back();
	while (res.size() % 8 != 0) {
		res += '0';
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
	return true;
}
bool decimalToBigInt(string number, BigInt& res) {
	string bin;
	if (number[0] == '-') {
		negDecimalToBinary(number, bin);
	}
	else {
		posDecimalToBinary(number, bin);
	}
	binaryToBigInt(bin, res);
	return true;
}
bool binaryToBigInt(string number, BigInt& res) {
	res.nByte = number.size() / 8 + (number.size() % 8 != 0) + 1;
	if (number[0] == '1') {
		while (number.size() < res.nByte * 8) {
			number = '1' + number;
		}
	}
	res.data = new BYTE[res.nByte];
	int n = number.size();
	for (int i = 0; i < res.nByte; i++) {
		int Pow = 1;
		res.data[i] = 0;
		for (int j = n - i*8 - 1; j >= max(0, n - (i + 1) * 8); j--) {
			res.data[i] += Pow * (number[j] == '1');
			Pow *= 2;
		}
	}
	return true;
}

