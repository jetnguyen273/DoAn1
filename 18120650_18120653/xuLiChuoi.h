#pragma once
#pragma once
#include<string>
#include<iostream>
#include"karnaughDaThuc.h"
using namespace std;
string chiSoToString(int i, int j); //Hàm nhận 1 tọa độ(i,j) trong biểu đồ 4x4 và trả về 1 string đơn thức
string* bieuDoToString(bool** a);// Hàm nhận 1 biểu đồ và trả về chuỗi các đơn thức
string sum(string a, string b);//Hàm tính tổng 2 chuỗi
string* loaiDonThucGiongNhau(string* s); //Hàm nhận vào 1 chuỗi string và trả về 1 chuỗi string khác loại bỏ đi các đơn thức giống nhau 
string* teBaoLon(string* s); //Hàm nhận 1 chuỗi string đơn thức và trả về 1 chuỗi string đơn thức là tế bào lớn
bool cmpBool(bool** a, bool** b);//Hàm so sánh 2 biểu đồ
string* test(string* s, bool** d);//Hàm nhận vào 1 biểu đồ và string* tế bào lớn, kiểm tra các tổng các tế bào lớn và trả về tập hợp các tế bào lớn có thể ghép lại để tạo thành hàm bool ban đầu
string* finalRes(string* s);//Hàm nhận vào 1 string* các đa thức cần thiết ở hàm test, và kiểm tra xem cái nào có độ dài nhỏ nhất và trả về 1 string* kết quả cuối cùng