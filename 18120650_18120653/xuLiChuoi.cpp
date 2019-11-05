#include"xuLiChuoi.h"
string chiSoToString(int i, int j)
{
	//Ứng với từng tọa độ mà ta trả về với các chuỗi khác nhau
	string res = "";
	if (i == 0)
		res += "x~y";
	if (i == 1)
		res += "xy";
	if (i == 2)
		res += "~xy";
	if (i == 3)
		res += "~x~y";
	if (j == 0)
		res += "z~t";
	if (j == 1)
		res += "zt";
	if (j == 2)
		res += "~zt";
	if (j == 3)
		res += "~z~t";
	return res;
}
string* bieuDoToString(bool** a)
{
	//Cấp phát bộ nhớ cho chuỗi các đơn thức
	string* res = new string[16];
	for (int i = 0; i < 16; i++)
		res[i] = "";
	int n = 0;
	//Gán kết quả bằng hàm chiSoToString
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (a[i][j] != 0)
			{
				res[n] = chiSoToString(j, i);
				n++;
			}
	return res;
}
string sum(string a, string b)
{
	if (a.empty() || b.empty()) return "0";
	//Doi cho 2 string
	if (a.length() < b.length())
	{
		string temp = a;
		a = b;
		b = temp;
	}
	int flag = 1;
	for (int i = 0; i < b.length(); i++)
		if (a[i] != b[i])
			flag = 0;
	if (flag) return a;
	string res = "0";
	//Đếm số lượng các phần tử ở 2 string
	int x1, y1, z1, t1, notx1, noty1, notz1, nott1, x2, y2, z2, t2, notx2, noty2, notz2, nott2;
	x1 = y1 = z1 = t1 = notx1 = noty1 = notz1 = nott1 = x2 = y2 = z2 = t2 = notx2 = noty2 = notz2 = nott2 = 0;
	for (int i = 0; i < a.length() - 1; i++)
	{
		if (a[i] == '~')
		{
			if (a[i + 1] == 'x')
				notx1 = 1;
			if (a[i + 1] == 'y')
				noty1 = 1;
			if (a[i + 1] == 'z')
				notz1 = 1;
			if (a[i + 1] == 't')
				nott1 = 1;
		}
	}
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == 'x' && notx1 == 0)
			x1 = 1;
		if (a[i] == 'y' && noty1 == 0)
			y1 = 1;
		if (a[i] == 'z' && notz1 == 0)
			z1 = 1;
		if (a[i] == 't' && nott1 == 0)
			t1 = 1;
	}
	for (int i = 0; i < b.length() - 1; i++)
	{
		if (b[i] == '~')
		{
			if (b[i + 1] == 'x')
				notx2 = 1;
			if (b[i + 1] == 'y')
				noty2 = 1;
			if (b[i + 1] == 'z')
				notz2 = 1;
			if (b[i + 1] == 't')
				nott2 = 1;
		}
	}
	for (int i = 0; i < b.length(); i++)
	{
		if (b[i] == 'x' && notx2 == 0)
			x2 = 1;
		if (b[i] == 'y' && noty2 == 0)
			y2 = 1;
		if (b[i] == 'z' && notz2 == 0)
			z2 = 1;
		if (b[i] == 't' && nott2 == 0)
			t2 = 1;
	}
	//Denta là tổng số lượng các biến ở string 1 có mà string 2 không có hoặc ngược lại
	int denta = abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2) + abs(t1 - t2) + abs(notx1 - notx2) + abs(noty1 - noty2) + abs(notz1 - notz2) + abs(nott1 - nott2);
	//Đổi 2 string sang int
	int numa = 0;
	int numb = 0;
	for (int i = 0; i < a.length(); i++)
		numa += a[i];
	for (int i = 0; i < b.length(); i++)
		numb += b[i];
	//Nếu 2 string lệch nhau ký tự ~ thì mới cộng
	if (numa - numb == '~')
	{
		if (denta >= 4) return res;
		res = "";
		int i;
		for (i = 0; i < b.length(); i++)
			if (a[i] != b[i])
			{
				for (int j = 0; j < i; j++)
					res += b[j];
				for (int j = i + 1; j < b.length(); j++)
					res += b[j];
				break;
			}
	}
	return res;
}
string* loaiDonThucGiongNhau(string* s)
{
	//Cấp phát bộ nhớ cho string mới
	string* res = new string[16];
	for (int i = 0; i < 16; i++)
		res[i] = "";
	//Đổi các string sang dạng int
	int num[16] = { 0 };
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < s[i].length(); j++)
			num[i] += s[i][j];
	//Nếu các số bằng nhau thì loại nó đi
	for (int i = 0; i < 15; i++)
		for (int j = i + 1; j < 16; j++)
			if (num[i] == num[j])
				s[j] = "";
	//Lưu lại tất cả vào string res
	int n = 0;
	for (int i = 0; i < 16; i++)
		if (!s[i].empty())
		{
			res[n] = s[i];
			n++;
		}
	return res;
}
string* teBaoLon(string* s)
{
	//res1 res2 res3 lần lượt là các tế bào lớn có 3 2 1 phần tử
	//Ý tưởng: xây dựng 3 mảng đánh dấu numres1 numres2 numres3, nếu đã có thể cộng được thì sẽ không được đánh dấu 
	int n = 0;
	for (int i = 0; i < 16; i++)
		if (s[i][0] == 'x' || s[i][0] == '~' || s[i][0] == 'y' || s[i][0] == 'z' || s[i][0] == 't')
			n++;
	string* res1 = new string[16];
	for (int i = 0; i < 16; i++)
		res1[i] = "";
	int* numres1 = new int[16];
	for (int i = 0; i < 16; i++)
		numres1[i] = 0;
	int k = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (sum(s[i], s[j])[0] != '0')
			{
				res1[k] = sum(s[i], s[j]);
				numres1[i] = 1;
				numres1[j] = 1;
				k++;
			}
		}
	int numres2[16] = { 0 };
	string* res2 = new string[16];
	for (int i = 0; i < 16; i++)
		res2[i] = "";
	int l = 0;
	for (int i = 0; i < 15; i++)
		for (int j = i + 1; j < 16; j++)
			if (sum(res1[i], res1[j])[0] != '0')
			{
				res2[l] = sum(res1[i], res1[j]);
				l++;
			}
	res2 = loaiDonThucGiongNhau(res2);
	for (int i = 0; i < 15; i++)
		for (int j = i + 1; j < 16; j++)
			if (sum(res1[i], res1[j])[0] != '0')
			{
				numres2[i] = 1;
				numres2[j] = 1;
			}
	string* res3 = new string[16];
	for (int i = 0; i < 16; i++)
		res3[i] = "";
	int m = 0;
	int numres3[16] = { 0 };
	for (int i = 0; i < 15; i++)
		for (int j = i + 1; j < 16; j++)
		{
			if (sum(res2[i], res2[j])[0] != '0')
			{
				numres3[i] = 1;
				numres3[j] = 1;
				res3[m] = sum(res2[i], res2[j]);
				m++;
			}
		}
	res3 = loaiDonThucGiongNhau(res3);
	//Gán các phần tử chưa được đánh dấu vào mảng res4 cuối cùng
	string* res4 = new string[16];
	for (int i = 0; i < 16; i++)
		res4[i] = "";
	int o = 0;
	for (int i = 0; i < 16; i++)
		if (numres1[i] == 0 && !s[i].empty())
		{
			res4[o] = s[i];
			o++;
		}
	for (int i = 0; i < 16; i++)
		if (numres2[i] == 0 && !res1[i].empty())
		{
			res4[o] = res1[i];
			o++;
		}
	for (int i = 0; i < 16; i++)
		if (numres3[i] == 0 && !res2[i].empty())
		{
			res4[o] = res2[i];
			o++;
		}
	res4[o] = res3[0];
	o++;
	res4[o] = res3[1];
	o++;
	res4[o] = res3[2];
	return res4;
}
bool cmpBool(bool** a, bool** b)
{
	//Hàm so sánh 2 hàm bool
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (a[i][j] != b[i][j])
				return false;
	return true;
}
string* test(string* s, bool** d)
{
	//Hàm nhận vào 1 biểu đồ và string* tế bào lớn, kiểm tra các tổng các tế bào lớn và trả về tập hợp các tế bào lớn có thể ghép lại để tạo thành hàm bool ban đầu
	//Ý tưởng: 
	string* res = new string[256];
	for (int i = 0; i < 256; i++)
		res[i] = "";
	int count = 0;
	for (int i = 0; i < 16; i++)
		if (s[i][0] == 'x' || s[i][0] == 'y' || s[i][0] == 'z' || s[i][0] == '~' || s[i][0] == 't')
			count++;
	int index = 0;
	//Check 1 phan tu
	for (int i = 0; i < count; i++)
	{
		karnaughDaThuc b;
		b.donThuc = new string[1];
		b.donThuc[0] = s[i];
		b.loadDonThuc();
		if (cmpBool(b.bieuDo(), d))
		{
			res[index] = b.donThuc[i];
			index++;
		}
	};
	//Check 2 phan tu
	for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
		{
			karnaughDaThuc b;
			b.donThuc = new string[2];
			b.donThuc[0] = s[i];
			b.donThuc[1] = s[j];
			b.loadDonThuc(2);
			if (cmpBool(b.bieuDo(0, 1), d))
			{
				res[index] = s[i] + "+" + s[j];
				index++;
			}
		};
	//Check 3 phan tu
	for (int i = 0; i < count - 2; i++)
		for (int j = i + 1; j < count - 1; j++)
			for (int k = j + 1; k < count; k++)
			{
				karnaughDaThuc b;
				b.donThuc = new string[3];
				b.donThuc[0] = s[i];
				b.donThuc[1] = s[j];
				b.donThuc[2] = s[k];
				b.loadDonThuc(3);
				if (cmpBool(b.bieuDo(0, 1, 2), d))
				{
					res[index] = s[i] + "+" + s[j] + "+" + s[k];
					index++;
				}
			};
	//Check 4 phan tu
	for (int i = 0; i < count - 3; i++)
		for (int j = i + 1; j < count - 2; j++)
			for (int k = j + 1; k < count - 1; k++)
				for (int l = k + 1; l < count; l++)
				{
					karnaughDaThuc b;
					b.donThuc = new string[4];
					b.donThuc[0] = s[i];
					b.donThuc[1] = s[j];
					b.donThuc[2] = s[k];
					b.donThuc[3] = s[l];
					b.loadDonThuc(4);
					if (cmpBool(b.bieuDo(0, 1, 2, 3), d))
					{
						res[index] = s[i] + "+" + s[j] + "+" + s[k] + "+" + s[l];
						index++;
					}
				}
	//Check 5 phan tu
	for (int i = 0; i < count - 4; i++)
		for (int j = i + 1; j < count - 3; j++)
			for (int k = j + 1; k < count - 2; k++)
				for (int l = k + 1; l < count - 1; l++)
					for (int m = l + 1; m < count; m++)
					{
						karnaughDaThuc b;
						b.donThuc = new string[5];
						b.donThuc[0] = s[i];
						b.donThuc[1] = s[j];
						b.donThuc[2] = s[k];
						b.donThuc[3] = s[l];
						b.donThuc[4] = s[m];
						b.loadDonThuc(5);
						if (cmpBool(b.bieuDo(0, 1, 2, 3, 4), d))
						{
							res[index] = s[i] + "+" + s[j] + "+" + s[k] + "+" + s[l] + "+" + s[m];
							index++;
						}
					}

	//Check 6 phan tu
	for (int i = 0; i < count - 5; i++)
		for (int j = i + 1; j < count - 4; j++)
			for (int k = j + 1; k < count - 3; k++)
				for (int l = k + 1; l < count - 2; l++)
					for (int m = l + 1; m < count - 1; m++)
						for (int n = m + 1; n < count; n++)
						{
							karnaughDaThuc b;
							b.donThuc = new string[6];
							b.donThuc[0] = s[i];
							b.donThuc[1] = s[j];
							b.donThuc[2] = s[k];
							b.donThuc[3] = s[l];
							b.donThuc[4] = s[m];
							b.donThuc[5] = s[n];
							b.loadDonThuc(6);
							if (cmpBool(b.bieuDo(0, 1, 2, 3, 4, 5), d))
							{
								res[index] = s[i] + "+" + s[j] + "+" + s[k] + "+" + s[l] + "+" + s[m] + "+" + s[n];
								index++;
							}
						};
	//Check 7 phan tu
	for (int i = 0; i < count - 6; i++)
		for (int j = i + 1; j < count - 5; j++)
			for (int k = j + 1; k < count - 4; k++)
				for (int l = k + 1; l < count - 3; l++)
					for (int m = l + 1; m < count - 2; m++)
						for (int n = m + 1; n < count - 1; n++)
							for (int o = n + 1; o < count; o++)
							{
								karnaughDaThuc b;
								b.donThuc = new string[7];
								b.donThuc[0] = s[i];
								b.donThuc[1] = s[j];
								b.donThuc[2] = s[k];
								b.donThuc[3] = s[l];
								b.donThuc[4] = s[m];
								b.donThuc[5] = s[n];
								b.donThuc[6] = s[o];
								b.loadDonThuc(7);
								if (cmpBool(b.bieuDo(0, 1, 2, 3, 4, 5, 6), d))
								{
									res[index] = s[i] + "+" + s[j] + "+" + s[k] + "+" + s[l] + "+" + s[m] + "+" + s[o];
									index++;
								}
							};
	//Check 8 phan tu
	for (int i = 0; i < count - 7; i++)
		for (int j = i + 1; j < count - 6; j++)
			for (int k = j + 1; k < count - 5; k++)
				for (int l = k + 1; l < count - 4; l++)
					for (int m = l + 1; m < count - 3; m++)
						for (int n = m + 1; n < count - 2; n++)
							for (int o = n + 1; o < count - 1; o++)
								for (int p = o + 1; p < count; p++)
								{
									karnaughDaThuc b;
									b.donThuc = new string[8];
									b.donThuc[0] = s[i];
									b.donThuc[1] = s[j];
									b.donThuc[2] = s[k];
									b.donThuc[3] = s[l];
									b.donThuc[4] = s[m];
									b.donThuc[5] = s[n];
									b.donThuc[6] = s[o];
									b.donThuc[7] = s[p];
									b.loadDonThuc(8);
									if (cmpBool(b.bieuDo(0, 1, 2, 3, 4, 5, 6, 7), d))
									{
										res[index] = s[i] + "+" + s[j] + "+" + s[k] + "+" + s[l] + "+" + s[m] + "+" + s[o] + "+" + s[p];
										index++;
									}
								};
	return res;
}
int demPhanTu(string s)
{
	int res = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'x' || s[i] == 'y' || s[i] == 'z' || s[i] == 't')
			res++;
	return res;
}
string* finalRes(string* s)
{
	int soPhanTuMin = demPhanTu(s[0]);
	int n = 1;
	for (int i = 1; i < 256; i++)
		if (demPhanTu(s[i]) == soPhanTuMin)
			n++;
		else
			break;
	string* res = new string[n];
	for (int i = 0; i < n; i++)
	{
		res[i] = s[i];
		cout << res[i] << endl;
	}
	return res;
}