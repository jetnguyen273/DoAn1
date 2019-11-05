#pragma once
#include<iostream>
using namespace std;
class vector
{
private:
	int n;
	float* a;
public:
	void nhapVector();
	void xuatVector();
	vector& operator=(const vector& b);
	vector operator+(const vector& b);
	vector operator-(const vector& b);
	vector operator*(float b);
	float operator[](int b);
	vector()
	{
		n = 0;
		a = nullptr;
	}
	vector(int n1, float* a1)
	{
		n = n1;
		a = new float[n];
		for (int i = 0; i < n; i++)
			a[i] = a1[i];
	}
	vector(const vector& b)
	{
		n = b.n;
		a = new float[n];
		for (int i = 0; i < n; i++)
			a[i] = b.a[i];
	}
	~vector()
	{
		delete a;
	}
};

