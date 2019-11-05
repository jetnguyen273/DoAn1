#include "MaTran.h"

void MaTran::nhap()
{
	cout << "Nhap so dong: "; cin >> _m;
	cout << "Nhap so cot: "; cin >> _n;
	_a = new float* [_m];
	for (int i = 0; i < _m; i++)
		_a[i] = new float[_n];
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
		{
			cout << "Nhap phan tu a[" << i + 1 << "][" << j + 1 << "]: ";
			cin >> _a[i][j];
		}
}

void MaTran::xuat()
{
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < _n; j++)
		{
			cout << setprecision(2) << fixed << _a[i][j] << "  "; //xuat ra phan thap phan 2 chu so
		}
		cout << endl;
	}
}

void MaTran::swap(int k, int i)
{
	float tmp;
	for (int j = 0; j < _n; j++) //swap dong k voi dong i
	{
		tmp = _a[k][j];
		_a[k][j] = _a[i][j];
		_a[i][j] = tmp;
	}
}

float MaTran::dinhthuc()
{
	MaTran matrix(_m, _n, _a); //khoi tao matran copy de khong thay doi ma tran goc.

	float det = 1, index = 0;

	//ma tran bac thang
	for (int i = 0; i < _m; i++)
	{
		for (int k = i + 1; k < _m; k++) //vi dinh thuc la ma tran vuong nen _m = _n
		{
			if (matrix._a[i][i] == 0 && matrix._a[k][i] != 0) //neu phan tu dau cua dong i = 0 va phan tu dau cua dong k != 0 thi swap dong k voi dong i
			{
				matrix.swap(k, i);
				index += 1; //moi lan swap dinh thuc * (-1)
			}
			if (matrix._a[k][i] == 0) continue; //phan tu dau cua dong k = 0 thi tang k len 1
			float tmp = matrix._a[k][i] / matrix._a[i][i]; //heso
			for (int j = i; j < matrix._m; j++)
			{
				matrix._a[k][j] -= tmp * matrix._a[i][j]; //dong k - dong i * heso
				if (abs(matrix._a[k][j]) < 0.0001) matrix._a[k][j] = 0; //matrix._a[k][j] = 1.9263548e+06 = 0.00000016...
			}
		}
	}
	for (int i = 0; i < matrix._m; i++) //dinh thuc = tich cac phan tu cua duong cheo cua ma tran
		det *= matrix._a[i][i];
	if (det == -0) return 0;
	if (abs(det) < 0.0001) det = 0;
	return det * pow(-1, index);
}

float MaTran::hangMT()
{
	MaTran matrix(_m, _n, _a);

	//ma tran bac thang
	int t = 0; // neu phan tu cot i dong t = 0 thi xet tiep cot t + 1
	for (int i = 0; i < matrix._m; i++) //dong i
	{
		for (int j = i + 1; j < matrix._m; j++) //dong j = i + 1 
		{
			if (matrix._a[i][t] == 0 && matrix._a[j][t] != 0)
			{
				matrix.swap(j, i);
			}
			if (j == matrix._m - 1 && matrix._a[i][t] == 0) //Xu li khi a11 == 0 -> a12...
			{
				j = i;
				t++;
				continue;
			}
			if (matrix._a[j][t] == 0) continue;
			float tmp = matrix._a[j][t] / matrix._a[i][t];
			for (int k = t; k < matrix._n; k++)
			{
				matrix._a[j][k] -= tmp * matrix._a[i][k];
				if (abs(matrix._a[j][k]) < 0.0001)
					matrix._a[j][k] = 0;
			}
		}
		t++;
		if (t >= _n) break; // neu t >= _n cot thi dung vong lap
	}
	//tra ve hang ma tran
	int dem = 0;
	int j = 0;
	for (int i = 0; i < matrix._m; i++)
		while (j < matrix._n)
		{
			if (matrix._a[i][j] != 0) // dem so dong co phan tu khac 0 va phan tu cua dong duoi o ben phai so voi phan tu tren
			{
				dem++;
				j++;
				break;
			}
			j++; //cot j = 0 xet tiep cot j + 1 
		}
	return dem;
}

void MaTran::nghichdao()
{
	if (dinhthuc() == 0)
	{
		cout << "Ma tran khong kha nghich!";
	}
	else
	{
		MaTran p;
		p._m = _m;
		p._n = _n;
		p._a = new float* [p._m];

		for (int i = 0; i < _m; i++)
			p._a[i] = new float[p._n];

		for (int i = 0; i < _m; i++) //Khoi tao ma tran don vi 
			for (int j = 0; j < _n; j++)
				if (i == j) p._a[i][j] = 1;
				else p._a[i][j] = 0;

		MaTran matrix(_m, _n, _a);

		//Ma tran bac thang
		for (int i = 0; i < matrix._m; i++) //dong i
		{
			for (int k = i + 1; k < matrix._m; k++) //xet dong k = i + 1
			{
				if (matrix._a[i][i] == 0 && matrix._a[k][i] != 0)
				{
					matrix.swap(k, i); //neu dong i = 0 & dong k != 0 thi swap(k,i)
					p.swap(k, i);
				}
				if (matrix._a[k][i] == 0) continue; //neu dong k = 0 thi xet tiep dong k + 1
				float tmp = matrix._a[k][i] / matrix._a[i][i]; //heso
				for (int j = i; j < matrix._m; j++) //dong k - dong i * heso
				{
					matrix._a[k][j] -= tmp * matrix._a[i][j];
					if (abs(matrix._a[k][j]) < 0.0001) matrix._a[k][j] = 0; //truong hop kq = 1.98273e+06 = 0.000000026...
					p._a[k][j] -= tmp * p._a[i][j]; //phan tu cua ma tran don vi
					if (abs(p._a[k][j]) < 0.0001) p._a[k][j] = 0;
				}
				if (k > 1 && i > 0) //Xu ly vi tri truoc i cua ma tran bac thang khong duoc thuc hien o tren.
				{
					for (int j = 0; j < i; j++)
					{
						p._a[k][j] -= tmp * p._a[i][j];
						if (abs(p._a[k][j]) < 0.0001) p._a[k][j] = 0;
					}
				}
			}
		}

		//chuyen ma tran don vi
		for (int i = matrix._m - 1; i >= 0; i--) //dong i
		{
			for (int k = matrix._m - 1; k >= i; k--)
			{
				if (i == k) //Phan tu tren duong cheo
				{
					float tmp = matrix._a[i][i];
					matrix._a[i][i] /= tmp; //dua ve 1
					for (int j = 0; j < matrix._m; j++) //thuc hien tren dong i cua ma tran don vi
						p._a[i][j] /= tmp;
				}
				else //Phan tu khong nam tren duong cheo
				{
					float tmp = matrix._a[i][k];
					matrix._a[i][k] -= tmp * matrix._a[k][k]; //phan tu ngoai duong cheo dua ve 0
					for (int j = 0; j < matrix._m; j++) //thuc hien phep tinh tren dong i cua ma tran don vi
					{
						p._a[i][j] -= tmp * p._a[k][j];
						if (abs(p._a[i][j]) < 0.0001) p._a[i][j] = 0;
					}
				}
			}
		}

		//xuat ra ket qua
		for (int i = 0; i < _m; i++)
		{
			for (int j = 0; j < _n; j++)
				cout << setprecision(2) << fixed << p._a[i][j] << "  ";
			cout << endl;
		}
	}
}

MaTran MaTran::operator=(const MaTran& p)
{
	this->_m = p._m;
	this->_n = p._n;
	_a = new float* [_m];
	for (int i = 0; i < _m; i++)
		_a[i] = new float[_n];
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			this->_a[i][j] = p._a[i][j];
	return *this;
}

MaTran MaTran::operator*(MaTran p)
{
	MaTran c;
	if (_n != p._m) //so cot cua ma tran a = so dong cua ma tran b
	{
		c._a = NULL;
		return c;
	}
	c._m = _m;
	c._n = p._n;
	c._a = new float* [c._m];
	for (int i = 0; i < c._m; i++)
		c._a[i] = new float[c._n];

	for (int i = 0; i < c._m; i++)
		for (int j = 0; j < c._n; j++)
		{
			c._a[i][j] = 0;
			for (int k = 0; k < _n; k++)
				c._a[i][j] += _a[i][k] * p._a[k][j]; //phan tu ma tran tich = tong tung tich cua phan tu dong a * phan tu cot b
		}
	return c;
}

void MaTran::HePT()
{
	float* b = new float[_m];
	cout << "Nhap he so tu do: " << endl;
	for (int i = 0; i < _m; i++)
	{
		cout << "Nhap b[" << i + 1 << "]: ";
		cin >> b[i];
	}

	MaTran c;
	c._m = _m;
	c._n = _n + 1;
	c._a = new float* [c._m];
	for (int i = 0; i < c._m; i++)
		c._a[i] = new float[c._n];

	for (int i = 0; i < c._m; i++) //them cot b vao ma tran a 
		for (int j = 0; j < c._n; j++)
		{
			if (j == c._n - 1) //cot cuoi cung la phan tu cua b
				c._a[i][j] = b[i];
			else
				c._a[i][j] = _a[i][j]; // phan tu cua a
		}

	//Giai PT
	if (hangMT() != c.hangMT())
		cout << "He PT vo nghiem!!!";

	if (hangMT() == c.hangMT() && hangMT() < _n)
		cout << "He PT vo so nghiem!!!";

	if (hangMT() == c.hangMT() && hangMT() == _n)
	{
		MaTran matrix(_m, _n, _a);
		for (int i = 0; i < _m; i++) //ma tran bac thang tuong tu nhu tren
		{
			for (int k = i + 1; k < _m; k++)
			{
				if (matrix._a[i][i] == 0 && matrix._a[k][i] != 0)
				{
					matrix.swap(k, i);
					float index = b[k]; //swap b[k] voi b[i]
					b[k] = b[i];		//
					b[i] = index;		//
				}
				if (matrix._a[k][i] == 0) continue;
				float tmp = matrix._a[k][i] / matrix._a[i][i];
				for (int j = i; j < _n; j++)
				{
					matrix._a[k][j] -= tmp * matrix._a[i][j];
					if (abs(matrix._a[k][j]) < 0.0001) matrix._a[k][j] = 0;
				}
				b[k] -= tmp * b[i]; //thuc hien tinh toan tren b
				if (abs(b[k]) < 0.0001) b[k] = 0;
			}
		}

		for (int i = _m - 1; i >= 0; i--) //ma tran don vi
		{
			for (int k = _n - 1; k >= i; k--)
			{
				if (i == k)
				{
					float tmp = matrix._a[i][i];
					matrix._a[i][i] /= tmp;
					b[i] /= tmp;
				}
				else
				{
					float tmp = matrix._a[i][k];
					matrix._a[i][k] -= tmp * matrix._a[k][k];
					b[i] -= tmp * b[k];
				}
			}
		}

		cout << endl;
		for (int i = 0; i < _n; i++)
		{
			if (b[i] == -0) b[i] = 0;
			cout << "x" << i + 1 << " = " << setprecision(2) << fixed << b[i] << endl;
		}
	}
}

MaTran::MaTran()
{
	_m = _n = 0;
	_a = NULL;
}

MaTran::MaTran(int m, int n, float** a)
{
	_m = m;
	_n = n;
	_a = new float* [_m];
	for (int i = 0; i < _m; i++)
		_a[i] = new float[_n];
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			_a[i][j] = a[i][j];
}

MaTran::MaTran(const MaTran& p)
{

	_m = p._m;
	_n = p._n;
	_a = new float* [_m];
	for (int i = 0; i < _m; i++)
		_a[i] = new float[_n];
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			_a[i][j] = p._a[i][j];
}

MaTran::~MaTran()
{
	delete[] _a;
}
