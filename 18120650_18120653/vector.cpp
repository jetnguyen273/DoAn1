#include "vector.h"
void vector::nhapVector()
{
	cout << "Nhap so phan tu: ";
	cin >> n;
	a = new float[n];
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> a[i];
	}
}
void vector::xuatVector()
{
	cout << "Vector can xuat la: ";
	for (int i = 0; i < n; i++)
		cout << "a[" << i + 1 << "] = " << a[i] << " ";
}
vector& vector::operator=(const vector& b)
{
	n = b.n;
	this->a = new float[n];
	for (int i = 0; i < b.n; i++)
		this->a[i] = b.a[i];
	return *this;
}
vector vector::operator+(const vector& b)
{
	if (n != b.n)
	{
		cout << "Khong the cong 2 vector!";
		return vector();
	}
	for (int i = 0; i < n; i++)
		a[i] += b.a[i];
	return *this;
}
vector vector::operator-(const vector& b)
{
	if (n != b.n)
	{
		cout << "Khong the cong 2 vector!";
		return vector();
	}
	for (int i = 0; i < n; i++)
		a[i] -= b.a[i];
	return *this;
}
vector vector::operator*(float b)
{
	for (int i = 0; i < n; i++)
		a[i] *= b;
	return *this;
}
float vector::operator[](int b)
{
	if (b > n || b < 0)
		return NULL;
	else
		return a[b];
}