#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class MaTran
{
private:
	int _m, _n; //_m dong, _n cot
	float** _a; // mang phan tu
public:
	void nhap();
	void xuat();
	void swap(int k, int i);
	float dinhthuc();
	void nghichdao();
	MaTran operator=(const MaTran& p);
	MaTran operator*(MaTran p);
	float hangMT();
	void HePT();

	MaTran();
	MaTran(int m, int n, float** a);
	MaTran(const MaTran& p);
	~MaTran();
};

#pragma once
