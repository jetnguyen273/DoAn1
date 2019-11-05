#pragma once
#include<iostream>
#include<string>
using namespace std;
class karnaughDonThuc
{
private: //Lưu các giá trị của số phần tử trong 1 đơn thức. VD: xyz thì x=1 y=1 z=1 t=0 notx=0 noty=0 notz=0 notx=0
	int x;
	int y;
	int z;
	int t;
	int notx;
	int noty;
	int notz;
	int nott;
public:
	string s; //Lưu chuỗi dưới dạng string. VD: s=xyzt
	void nhapDonThuc(); //Hàm đẻ nhập 1 đơn thức là 1 string
	void demPhanTu(); //Hàm đếm số lượng phần tử và trả về chính nó
	bool** d(); // Đơn thức sau khi được dịch ra và trả về 1 ma trận 4x4 với giá trị 1 và 0
	int soPhanTu(); //Hàm đếm tổng số lượng phần tử x+y+z+t+notx+notz+nott+noty
};
