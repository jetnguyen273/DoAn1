#include"karnaughDonThuc.h"
void karnaughDonThuc::nhapDonThuc()
{
	cout << "Nhap don thuc: ";
	getline(cin, s);
}
void karnaughDonThuc::demPhanTu() //Hàm đếm tổng số lượng phần tử x+y+z+t+notx+notz+nott+noty
{
	x = y = z = t = notx = noty = notz = nott = 0;
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == '~')
		{
			if (s[i + 1] == 'x')
				notx = 1;
			if (s[i + 1] == 'y')
				noty = 1;
			if (s[i + 1] == 'z')
				notz = 1;
			if (s[i + 1] == 't')
				nott = 1;
		}
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'x' && notx == 0)
			x = 1;
		if (s[i] == 'y' && noty == 0)
			y = 1;
		if (s[i] == 'z' && notz == 0)
			z = 1;
		if (s[i] == 't' && nott == 0)
			t = 1;
	}
}
bool** karnaughDonThuc::d() //Hàm trả về biểu đồ 4x4 của 1 đơn thức
{
	bool** res = new bool* [4];
	for (int i = 0; i < 4; i++)
		res[i] = new bool[4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			res[i][j] = 1;
	demPhanTu();
	if (x == 1)
	{
		for (int i = 0; i < 4; i++)
			res[i][2] = 0;
		for (int i = 0; i < 4; i++)
			res[i][3] = 0;
	}
	if (notx == 1)
	{
		for (int i = 0; i < 4; i++)
			res[i][0] = 0;
		for (int i = 0; i < 4; i++)
			res[i][1] = 0;
	}
	if (y == 1)
	{
		for (int i = 0; i < 4; i++)
			res[i][0] = 0;
		for (int i = 0; i < 4; i++)
			res[i][3] = 0;
	}
	if (noty == 1)
	{
		for (int i = 0; i < 4; i++)
			res[i][1] = 0;
		for (int i = 0; i < 4; i++)
			res[i][2] = 0;
	}
	if (z == 1)
	{
		for (int i = 0; i < 4; i++)
			res[2][i] = 0;
		for (int i = 0; i < 4; i++)
			res[3][i] = 0;
	}
	if (notz == 1)
	{
		for (int i = 0; i < 4; i++)
			res[0][i] = 0;
		for (int i = 0; i < 4; i++)
			res[1][i] = 0;
	}
	if (t == 1)
	{
		for (int i = 0; i < 4; i++)
			res[0][i] = 0;
		for (int i = 0; i < 4; i++)
			res[3][i] = 0;
	}
	if (nott == 1)
	{
		for (int i = 0; i < 4; i++)
			res[1][i] = 0;
		for (int i = 0; i < 4; i++)
			res[2][i] = 0;
	}
	return res;
}
int karnaughDonThuc::soPhanTu() //hàm đếm số lượng phần tử trong đơn thức
{
	return x + y + z + t + notx + noty + notz + nott;
}