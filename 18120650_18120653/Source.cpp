#pragma once
#include"karnaughDaThuc.h"
#include"xuLiChuoi.h"
#include"vector.h"
#include"maTran.h"
#include <Windows.h>

int main()
{
	int n;
	do
	{
		system("cls");
		system("Color 0B");
		cout << "\t\t\t===================MENU====================\n";
		cout << "\t\t\t|1. Tim cong thuc da thuc toi tieu ham bool|\n";
		cout << "\t\t\t|2. Lam phep toan tren vector              |\n";
		cout << "\t\t\t|3. Phep toan tren ma tran                 |\n";
		cout << "\t\t\t|0. Thoat!!!                               |\n";
		cout << "\t\t\t============================================\n";

		cout << "\n\nMoi chon menu: ";
		cin >> n;
		rewind(stdin);
		switch (n)
		{
		case 1:
		{
			karnaughDaThuc a;
			a.nhapDaThuc();
			a.tachDaThuc();
			a.loadDonThuc();
			string* s;
			s = bieuDoToString(a.bieuDo());
			cout << "ket qua la: ";
			finalRes(test(teBaoLon(s), a.bieuDo()));
			system("pause");
			break;
		}
		case 2:
		{
			int m;
			do
			{
				system("cls");
				cout << "\t\t\t============================================\n";
				cout << "\t\t\t|1. Phep toan cong hai vector              |\n";
				cout << "\t\t\t|2. Phep toan nhan vector voi 1 so alpha   |\n";
				cout << "\t\t\t|0. Thoat!!!                               |\n";
				cout << "\t\t\t============================================\n";
				cout << "\n\nMoi chon menu: ";
				rewind(stdin);
				cin >> m;
				switch (m)
				{
				case 1:
				{
					vector a;
					vector b;
					a.nhapVector();
					b.nhapVector();
					(a + b).xuatVector();
					system("pause");
					break;
				}
				case 2:
				{
					vector a;
					float b;
					a.nhapVector();
					cout << "Nhap so thuc: ";
					cin >> b;
					(a * b).xuatVector();
					system("pause");
					break;
				}
				default:
					break;
				}
			} while (m != 0);
			break;
		}
		case 3:
		{
			MaTran a, b, c;
			int k;
			do
			{
				system("cls");
				cout << "\t\t\t============================================\n";
				cout << "\t\t\t|1. Nhap ma tran                           |\n";
				cout << "\t\t\t|2. Tim dinh thuc cua ma tran              |\n";
				cout << "\t\t\t|3. Nghich dao ma tran                     |\n";
				cout << "\t\t\t|4. Tich hai ma tran                       |\n";
				cout << "\t\t\t|5. Tim hang cua ma tran                   |\n";
				cout << "\t\t\t|6. He phuong trinh tuyen tinh             |\n";
				cout << "\t\t\t|0. Thoat                                  |\n";
				cout << "\t\t\t============================================\n";
				cout << "\n\nMoi chon phuong thuc thuc hien: ";
				rewind(stdin);
				cin >> k;
				switch (k)
				{
				case 1:
				{
					cout << endl;
					a.nhap();
					cout << endl;
					a.xuat();
					system("pause");
					break;
				}
				case 2:
				{
					cout << "Dinh thuc cua ma tran : " << a.dinhthuc() << endl;
					system("pause");
					break;
				}
				case 3:
				{
					cout << "Ma tran nghich dao: " << endl;
					a.nghichdao();
					system("pause");
					break;
				}
				case 4:
				{
					cout << "Nhap ma tran muon nhan: \n";
					b.nhap();
					c = a * b;
					c.xuat();
					system("pause");
					break;
				}
				case 5:
				{
					cout << "Hang cua ma tran: " << a.hangMT() << endl;
					system("pause");
					break;
				}
				case 6:
				{
					a.HePT();
					system("pause");
					break;
				}
				case 0:
					break;
				}
			} while (k != 0);
			system("pause");
		}
		default:
			break;
		}
	} while (n != 0);
	return 0;
}