#pragma once
#include <iostream>
#include <string> 
#include <cstdio>
#include <cstdint>
typedef unsigned char BYTE;
#define BASE 256
using namespace std;

struct BigInt {
	//
	int nByte = 16;
	BYTE* data;
	BigInt& operator=(const BigInt& number) {
		nByte = number.nByte;
		data = number.data;
		return *this;
	}
	void Print() {
		for (int i = 0; i < nByte; i++) {
			cout << (int)data[i] << ' ';
		}
		cout << endl;
	}
};