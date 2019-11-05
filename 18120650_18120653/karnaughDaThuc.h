#pragma once
#include"karnaughDonThuc.h"
#include<iostream>
#include<string>
using namespace std;
class karnaughDaThuc
{
public:
	string daThuc; //Chuỗi đa thức
	karnaughDonThuc* c; //Gồm 1 mảng các đơn thức
	string* donThuc; // Gồm 1 mảng các chuỗi đơn thức
	void nhapDaThuc();//Hàm nhập đa thức
	int demDaThuc();//Hàm đếm tổng số lượng phần tử trong đa thức
	string* tachDaThuc();//Hàm tách chuỗi đa thức thành string* các đơn thức
	void loadDonThuc();//tai toan bo don thuc vao da thuc
	void loadDonThuc(int n);//tai n don thuc vao da thuc tinh tu 0->n
	bool** bieuDo();//ma tran cua ca da thuc
	bool** bieuDo(int n1, int n2);//ma tran cua tong 2 don thuc
	bool** bieuDo(int n1, int n2, int n3);//ma tran cua tong 3 don thuc
	bool** bieuDo(int n1, int n2, int n3, int n4);//ma tran cua tong 4 don thuc
	bool** bieuDo(int n1, int n2, int n3, int n4, int n5);//ma tran cua tong 5 don thuc
	bool** bieuDo(int n1, int n2, int n3, int n4, int n5, int n6);//ma tran cua tong 6 don thuc
	bool** bieuDo(int n1, int n2, int n3, int n4, int n5, int n6, int n7);//ma tran cua tong 7 don thuc
	bool** bieuDo(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8);//ma tran cua tong 8 don thuc
	int demPhanTu();//Hàm đếm tổng số lượng các phần tử trong 1 đa thức
};