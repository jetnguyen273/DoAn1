#include"karnaughDaThuc.h"
void karnaughDaThuc::nhapDaThuc()	//Hàm nhập đa thức
{
	cout << "Nhap da thuc: ";
	getline(cin, daThuc);
}
int karnaughDaThuc::demDaThuc() //Hàm đếm số lượng phần tử trong đa thức
{
	//Nếu tìm thấy 1 ký tự + thì tăng biến kết quả lên 1
	int res = 0;
	for (int i = 0; i < daThuc.length(); i++)
		if (daThuc[i] == '+')
			res++;
	return res + 1;
}
string* karnaughDaThuc::tachDaThuc()
{
	donThuc = new string[demDaThuc()]; //Cấp phát bộ nhớ cho biến đơn thức
	for (int i = 0; i < demDaThuc(); i++)
		donThuc[i] = ""; //Định nghĩa các đơn thức ban đầu là đơn thức rỗng 
	int n = 1;
	//Gán phần tử đầu tiên vào đa thức
	for (int i = 0; i < daThuc.length(); i++)
	{
		if (daThuc[i] != '+')
			donThuc[0] += daThuc[i];
		else
			break;
	}
	//Gán các phần tử tiếp theo
	for (int i = 0; i < daThuc.length(); i++)
	{
		if (daThuc[i] == '+')
		{
			for (int j = i + 1; j < daThuc.length(); j++)
				if (daThuc[j] != '+')
					donThuc[n] += daThuc[j];
				else
					break;
			n++;
		}
	}
	return donThuc;
}
void karnaughDaThuc::loadDonThuc()
{
	//Cấp phát phần tử
	int n = demDaThuc();
	c = new karnaughDonThuc[n];
	//Gán phần tử là string vào string* donThuc
	for (int i = 0; i < demDaThuc(); i++)
	{
		c[i].s = donThuc[i];
		c[i].d();
	}
}
void karnaughDaThuc::loadDonThuc(int n)
{
	//Như hàm trên nhưng giới hạn đến tham số n truyền vào
	c = new karnaughDonThuc[n];
	for (int i = 0; i < n; i++)
	{
		c[i].s = donThuc[i];
		c[i].d();
	}
}
bool** karnaughDaThuc::bieuDo()
{
	//Hàm trả về biểu đồ của đa thức
	bool** res = new bool* [4];
	for (int i = 0; i < 4; i++)
		res[i] = new bool[4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			res[i][j] = 0;
	for (int x = 0; x < demDaThuc(); x++)
		for (int y = 0; y < 4; y++)
			for (int z = 0; z < 4; z++)
				if (c[x].d()[y][z] == 1)
					res[y][z] = 1;
	return res;
}
bool** karnaughDaThuc::bieuDo(int n1, int n2)
{
	//Hàm trả về biểu đồ của đa thức gồm 2 đơn thức
	bool** res = new bool* [4];
	for (int i = 0; i < 4; i++)
		res[i] = new bool[4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			res[i][j] = 0;
	for (int y = 0; y < 4; y++)
		for (int z = 0; z < 4; z++)
			if (c[n1].d()[y][z] == 1 || c[n2].d()[y][z] == 1)
				res[y][z] = 1;
	return res;
}
bool** karnaughDaThuc::bieuDo(int n1, int n2, int n3)
{
	//Hàm trả về biểu đồ của đa thức gồm 3 đơn thức
	bool** res = new bool* [4];
	for (int i = 0; i < 4; i++)
		res[i] = new bool[4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			res[i][j] = 0;
	for (int y = 0; y < 4; y++)
		for (int z = 0; z < 4; z++)
			if (c[n1].d()[y][z] == 1 || c[n2].d()[y][z] == 1 || c[n3].d()[y][z] == 1)
				res[y][z] = 1;
	return res;
}
bool** karnaughDaThuc::bieuDo(int n1, int n2, int n3, int n4)
{
	//Hàm trả về biểu đồ của đa thức gồm 4 đơn thức
	bool** res = new bool* [4];
	for (int i = 0; i < 4; i++)
		res[i] = new bool[4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			res[i][j] = 0;
	for (int y = 0; y < 4; y++)
		for (int z = 0; z < 4; z++)
			if (c[n1].d()[y][z] == 1 || c[n2].d()[y][z] == 1 || c[n3].d()[y][z] == 1 || c[n4].d()[y][z] == 1)
				res[y][z] = 1;
	return res;
}
bool** karnaughDaThuc::bieuDo(int n1, int n2, int n3, int n4, int n5)
{
	//Hàm trả về biểu đồ của đa thức gồm 5 đơn thức
	bool** res = new bool* [4];
	for (int i = 0; i < 4; i++)
		res[i] = new bool[4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			res[i][j] = 0;
	for (int y = 0; y < 4; y++)
		for (int z = 0; z < 4; z++)
			if (c[n1].d()[y][z] == 1 || c[n2].d()[y][z] == 1 || c[n3].d()[y][z] == 1 || c[n4].d()[y][z] == 1 || c[n5].d()[y][z] == 1)
				res[y][z] = 1;
	return res;
}
bool** karnaughDaThuc::bieuDo(int n1, int n2, int n3, int n4, int n5, int n6)
{
	//Hàm trả về biểu đồ của đa thức gồm 6 đơn thức
	bool** res = new bool* [4];
	for (int i = 0; i < 4; i++)
		res[i] = new bool[4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			res[i][j] = 0;
	for (int y = 0; y < 4; y++)
		for (int z = 0; z < 4; z++)
			if (c[n1].d()[y][z] == 1 || c[n2].d()[y][z] == 1 || c[n3].d()[y][z] == 1 || c[n4].d()[y][z] == 1 || c[n5].d()[y][z] == 1 || c[n6].d()[y][z] == 1)
				res[y][z] = 1;
	return res;
}
bool** karnaughDaThuc::bieuDo(int n1, int n2, int n3, int n4, int n5, int n6, int n7)
{
	//Hàm trả về biểu đồ của đa thức gồm 7 đơn thức
	bool** res = new bool* [4];
	for (int i = 0; i < 4; i++)
		res[i] = new bool[4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			res[i][j] = 0;
	for (int y = 0; y < 4; y++)
		for (int z = 0; z < 4; z++)
			if (c[n1].d()[y][z] == 1 || c[n2].d()[y][z] == 1 || c[n3].d()[y][z] == 1 || c[n4].d()[y][z] == 1 || c[n5].d()[y][z] == 1 || c[n6].d()[y][z] == 1 || c[n7].d()[y][z] == 1)
				res[y][z] = 1;
	return res;
}
bool** karnaughDaThuc::bieuDo(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8)
{
	//Hàm trả về biểu đồ của đa thức gồm 8 đơn thức
	bool** res = new bool* [4];
	for (int i = 0; i < 4; i++)
		res[i] = new bool[4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			res[i][j] = 0;
	for (int y = 0; y < 4; y++)
		for (int z = 0; z < 4; z++)
			if (c[n1].d()[y][z] == 1)
				res[y][z] = 1;
	for (int y = 0; y < 4; y++)
		for (int z = 0; z < 4; z++)
			if (c[n1].d()[y][z] == 1 || c[n2].d()[y][z] == 1 || c[n3].d()[y][z] == 1 || c[n4].d()[y][z] == 1 || c[n5].d()[y][z] == 1 || c[n6].d()[y][z] == 1 || c[n7].d()[y][z] == 1 || c[n8].d()[y][z] == 1)
				res[y][z] = 1;
	return res;
}
int karnaughDaThuc::demPhanTu()
{
	//Hàm đếm số lượng phần tử x y z t ... trong đơn thức
	int res = 0;
	for (int i = 0; i <= donThuc->length(); i++)
		res += c[i].soPhanTu();
	return res;
}
