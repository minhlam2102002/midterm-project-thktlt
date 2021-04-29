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
	int nByte = 0;
	BYTE* data;
	void Print() {
		for (int i = 0; i < nByte; i++) {
			cout << (int)data[i] << ' ';
		}
		cout << endl;
	}
};