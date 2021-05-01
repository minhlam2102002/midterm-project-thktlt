#include "Function.h"

bool isNeg(BigInt& number) {
	if (number.data[number.nByte - 1] > 128) {
		return true;
	}
	return false;
}
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
	if (res.back() == '1') {
		res += '0';
	}
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
}
bool decimalToBigInt(string number, BigInt& res) {
	string bin;
	if (number[0] == '-') {
		negDecimalToBinary(number, bin);
		res.nByte = countBinBytes(bin);
		while (bin.size() < res.nByte * 8) {
			bin = '1' + bin;
		}
	}
	else {
		posDecimalToBinary(number, bin);
		res.nByte = countBinBytes(bin);
		if (bin.size() % 8 == 0 && bin[0] == '1') {
			res.nByte++;
		}
		while (bin.size() < res.nByte * 8) {
			bin = '0' + bin;
		}
	}
	binaryToBigInt(bin, res);
	return true;
}
bool binaryToBigInt(string number, BigInt& res) {
	while (number.size() < res.nByte * 8) {
		number = number[0] + number;
	}
	res.data = new BYTE[res.nByte];
	int n = number.size();
	for (int i = 0; i < res.nByte; i++) {
		int Pow = 1;
		res.data[i] = 0;
		for (int j = n - i*8 - 1; j >= 0; j--) {
			res.data[i] += Pow * (number[j] == '1');
			Pow *= 2;
		}
	}
	return true;
}

int countBinBytes(string number) {
	return number.size() / 8 + (number.size() % 8 != 0);
}

int countDecBytes(string number) {
	return 0;
}