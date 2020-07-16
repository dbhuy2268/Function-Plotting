#include <iostream>
#include <string>
#include <graphics.h>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;
//Bĩnh Huy
#pragma region Nhapxuat
void nhap(float hamso[], int loai);
void xuat(float hamso[], int loai, ostream& os = cout);
void nhapABCDphanSo(float hamso[], int loai = 0);
#pragma endregion
//Ngân
#pragma region timTXD

void xuatTXD(float hamso[], int loai, ostream& os = cout);

//check loại -> tìm txd -> xuất ra
#pragma endregion
//Ngân
#pragma region timdaoham

float* timDaoHam(float hamso[], int loai, ostream& os = cout);

//trả về kq[]{a,b,..} tùy loại pt
// vd 2x^2 -5x + 4, loại 2 => kq trả về là (4, -5), kq xuất ra là "f'(x) = 4x - 5"
#pragma endregion
//Nam Quang
#pragma region timlim

void timLim(float hamso[], int loai, ostream& os = cout);

// cho x-> ??, xuat ra kq
#pragma endregion
//Nam Quang
#pragma region minmax
//ở phần tìm đạo hàm
void timMINMAX(float hamso[], int loai, ostream& os = cout);
#pragma endregion
//Anh Huy
#pragma region xetdau_ve_BBT

void veBBT(float hamso[], int loai, ostream& os = cout);

//xuất ra bảng xét dấu y'
/*
xài thư viện iomanip/setw để canh khoảng trắng chuẩn

	  x		|-oo	nghiem1		nghiem2		 nghiem4	+oo
---------------------------------------------------------------------------
	  y'	|	  +   ||	 -	   0      +		||	  -
*/

/*
	thêm phần biến thiên

	*có hàm tìm cực trị float* timMINMAX(float hamso[], int loai); trả về min, max,
	2 người làm 2 hàm này làm chung với nhau để thống nhất
	vd:
---------------------------------------------------------------------------
	  y		|-oo  /	  max	 \	  min	  /		max	   \ -oo


	 kq hoàn chỉnh:
	  x		|-oo	nghiem1		nghiem2		 nghiem4	+oo
---------------------------------------------------------------------------
	  y'	|	  +   ||	 -	   0      +		||	  -
---------------------------------------------------------------------------
	  y		|-oo  /	  max	 \	  min	  /		max	   \ -oo
*/
#pragma endregion
//Bĩnh Huy
#pragma region vedothi
void veDoThi(float hamso[], int loai, int color = 6);//6 loai co ban
void veDoThiKhac(); //tron elipse hyperbol, parabol
void veDaDoThiVatimgiaoDiem();
//utilities
void cuaSo(float x1, float y1, float x2, float y2);
void khungNhin(int x1, int y1, int x2, int y2);
void myMoveto(float x, float y);
void myLineto(float x, float y);
void chu(float x, float y, char* s);
void veOXY(int i);
const int W = 960;//width
const int H = 960;//height
#pragma endregion


int main() {
start:
	char yn;
	int lc1 = 0;
	cout << "Co xuat kq ra file ko?(y/n) "; cin >> yn;
	string tenfile = "";
	std::ofstream outfile;
	if (yn == 'y') {
		lc1 = 5;
		cout << "Nhap ten file: ";
		cin.ignore();
		getline(cin, tenfile);
		outfile.open(tenfile.c_str());
	}
startX:
	cout << "1. Ham so thuong.";
	cout << "\n2. Ve Do thi cac hinh tron, elipse, hypebol, parabol. " << endl;
	cout << "3. Bonus a,b,c,d la phan so. \n";
	cout << "4. Ve Da do thi. \n";

	float i;// he so tile
	int lc = 0;
	int flag = 0;
	cout << "chon 1 trong 4 (1/2/3/4): "; cin >> lc;
	switch (lc) {
	case 1:
		flag = 0;
		break;
	case 2:
	start5:
		veDoThiKhac();
		cout << "\nVe tiep? (y/n)";
		cin >> yn;
		if (yn == 'y') {
			closegraph();
			goto start5;
		}
		else {
			cout << "bat dau lai tu dau? (y/n) ";
			cin >> yn;
			if (yn == 'y') {
				goto start;
			}
			else {
				return 0;
			}
		}
	case 3:
		flag = 1;
		break;
	case 4:
	start2:
		i = 5;
		initwindow(W, H);
		cuaSo(-10 * i, -10 * i, 9 * i, 10 * i);
		khungNhin(100, 100, 1024, 1024);
		veDaDoThiVatimgiaoDiem();
		cout << "\nVe tiep? (y/n)";
		cin >> yn;
		if (yn == 'y') {
			closegraph();
			goto start2;
		}
		else {
			cout << "bat dau lai tu dau? (y/n) ";
			cin >> yn;
			if (yn == 'y') {
				goto start;
			}
			else {
				return 0;
			}
		}
	default:
		cout << "\nChon sai. \n";
		cout << "\nChon option khac? (y/n)";
		cin >> yn;
		if (yn == 'y') {
			goto startX;
		}
		else {
			cout << "bat dau lai tu dau? (y/n) ";
			cin >> yn;
			if (yn == 'y') {
				goto start;
			}
			else {
				return 0;
			}
		}
	}


	float* hamso = NULL;
opt1:
	cout << "1. ax+b";
	cout << "\n2. ax^2 + bx + c";
	cout << "\n3. ax^3 + bx^2 + cx + d";
	cout << "\n4. ax^4 + bx^2 + c";
	cout << "\n5. (ax + b)/(cx + d)";
	cout << "\n6. (ax^2 + bx + c)/(ax + b)";

	int loai = 0;
	cout << "\nNhap lua chon: "; cin >> loai; // tuy loai, moi loai 1 size
	if (loai == 1) {
		hamso = new float[2];
	}
	else if (loai == 2) {
		hamso = new float[3];
	}
	else if (loai == 3) {
		hamso = new float[4];
	}
	else if (loai == 4) {
		hamso = new float[3];
	}
	else if (loai == 5) {
		hamso = new float[4];
	}
	else if (loai == 6) {
		hamso = new float[5];
	}
	else {
		cout << "\nChon sai. \n";
		cout << "\nChon option khac? (y/n)";
		cin >> yn;
		if (yn == 'y') {
			goto opt1;
		}
		else {
			cout << "bat dau lai tu dau? (y/n) ";
			cin >> yn;
			if (yn == 'y') {
				goto start;
			}
			else {
				return 0;
			}
		}
	}

	if (flag == 0) {
		nhap(hamso, loai);
	}
	else if (flag == 1) {
		nhapABCDphanSo(hamso, loai);
	}
	cout << endl << endl;

start1:
	cout << "1. Xuat Chuoi ham so da nhap. " << endl << endl;
	cout << "2. Tim TXD cua ham so. " << endl << endl;
	cout << "3. Dao ham y. " << endl << endl;
	cout << "4. Tim lim. " << endl << endl;
	cout << "5. Xet dau, lap bang bien thien. " << endl << endl;
	cout << "6. Tim MIN, MAX neu co. " << endl << endl;
	cout << "7. Ve do thi. " << endl << endl;

	int luaChon = 0;
	cout << "Lua chon: "; cin >> luaChon;
	switch (luaChon) {
	case 1:
		if (lc1 != 5) {
			xuat(hamso, loai);
		}
		else {
			xuat(hamso, loai, outfile);
			cout << "\nDa xuat kq ra file " << tenfile << "\n";
		}
		cout << "\nChon option khac? (y/n)";
		cin >> yn;
		if (yn == 'y') {
			goto start1;
		}
		else {
			break;
		}
	case 2:
		if (lc1 != 5) {
			xuatTXD(hamso, loai);
		}
		else {
			xuatTXD(hamso, loai, outfile);
			cout << "\nDa xuat kq ra file " << tenfile << "\n";
		}
		cout << "\nChon option khac? (y/n)";
		cin >> yn;
		if (yn == 'y') {
			goto start1;
		}
		else {
			break;
		}
	case 3:
		if (lc1 != 5) {
			timDaoHam(hamso, loai);
		}
		else {
			timDaoHam(hamso, loai, outfile);
			cout << "\nDa xuat kq ra file " << tenfile << "\n";
		}
		cout << "\nChon option khac? (y/n)";
		cin >> yn;
		if (yn == 'y') {
			goto start1;
		}
		else {
			break;
		}
	case 4:
		if (lc1 != 5) {
			timLim(hamso, loai);
		}
		else {
			timLim(hamso, loai, outfile);
			cout << "\nDa xuat kq ra file " << tenfile << "\n";
		}
		cout << "\nChon option khac? (y/n)";
		cin >> yn;
		if (yn == 'y') {
			goto start1;
		}
		else {
			break;
		}
	case 5:
		if (lc1 != 5) {
			veBBT(hamso, loai);
		}
		else {
			veBBT(hamso, loai, outfile);
			cout << "\nDa xuat kq ra file " << tenfile << "\n";
		}
		cout << "\nChon option khac? (y/n)";
		cin >> yn;
		if (yn == 'y') {
			goto start1;
		}
		else {
			break;
		}
	case 6:
		if (lc1 != 5) {
			timMINMAX(hamso, loai);
		}
		else {
			timMINMAX(hamso, loai, outfile);
			cout << "\nDa xuat kq ra file " << tenfile << "\n";
		}
		cout << "\nChon option khac? (y/n)";
		cin >> yn;
		if (yn == 'y') {
			goto start1;
		}
		else {
			break;
		}
	case 7:
		i = 10;// he so tile
		initwindow(W, H);
		cuaSo(-10 * i, -10 * i, 9 * i, 10 * i);
		khungNhin(100, 100, 768, 768);
		veDoThi(hamso, loai);
		cout << "\nChon option khac? (y/n)";
		cin >> yn;
		if (yn == 'y') {
			closegraph();
			goto start1;
		}
		else {
			closegraph();
			break;
		}
	default:
		cout << "\nChon sai. \n";
		cout << "\nChon option khac? (y/n)";
		cin >> yn;
		if (yn == 'y') {
			goto start1;
		}
		else {
			break;
		}
	}

	cout << "bat dau lai tu dau? (y/n) ";
	cin >> yn;
	if (yn == 'y') {
		goto start;
	}
	else {
		delete[] hamso;
		return 0;
	}
}

float xw1, yw1, xw2, yw2;
int xv1, yv1, xv2, yv2;
float tlx, tly;

void cuaSo(float x1, float y1, float x2, float y2) {
	xw1 = x1; yw1 = y1; xw2 = x2; yw2 = y2;
}

void khungNhin(int x1, int y1, int x2, int y2) {
	xv1 = x1; yv1 = y1; xv2 = x2; yv2 = y2;
	tlx = (xv2 - xv1) / (xw2 - xw1), tly = (yv2 - yv1) / (yw2 - yw1);
}

void myMoveto(float x, float y) {
	int xm = (int)(tlx * (x - xw1) + xv1);
	int ym = (int)(tly * (yw2 - y) + yv1);
	moveto(xm, ym);
}

void myLineto(float x, float y) {
	int xm = (int)(tlx * (x - xw1) + xv1);
	int ym = (int)(tly * (yw2 - y) + yv1);
	lineto(xm, ym);
}

void chu(float x, float y, char* s) {
	int xm = (int)(tlx * (x - xw1) + xv1);
	int ym = (int)(tly * (yw2 - y) + yv1);
	outtextxy(xm, ym, s);
}

void veOXY(int i = 1) {
	setcolor(WHITE);
	float x = -120 * i, y = -2 * i, dx = 0.01;
	while (x < 110 * i) {
		myMoveto(x, y);
		myLineto(x, 2 * i);
		x = x + 10 * i;
	}
	y = -120 * i; x = -1 * i;
	while (y < 120 * i) {
		myMoveto(x, y);
		myLineto(1 * i, y);
		y = y + 10 * i;
	}
	setcolor(4);
	x = -130 * i, y = 0;
	myMoveto(x, y); x = 120 * i;
	myLineto(x, y);
	myLineto(x - 4 * i, y - 1 * i);
	myMoveto(x, y);
	myLineto(x - 4 * i, y + 1 * i);
	chu(x + 5 * i, y, "x");
	x = 0; y = -130 * i;
	myMoveto(x, y);
	y = 120 * i;
	myLineto(x, y);
	myLineto(x + 0.9 * i, y - 4 * i);
	myMoveto(x, y);
	myLineto(x - 0.9 * i, y - 4 * i);
	chu(x, y + 5 * i, "y");
	x = -5 * i; y = -5 * i;
	chu(x, y, "O");
	x = 22 * i; y = -5 * i;
	chu(x, y, "2O");
	x = 40 * i; y = -5 * i;
	chu(x, y, "4O");
	x = 60 * i; y = -5 * i;
	chu(x, y, "6O");
	x = -22 * i; y = -5 * i;
	chu(x, y, "-2O");
	x = -40 * i; y = -5 * i;
	chu(x, y, "-4O");
	x = -60 * i; y = -5 * i;
	chu(x, y, "-6O");
	x = -5 * i; y = 20 * i;
	chu(x, y, "2O");
	x = -5 * i; y = 40 * i;
	chu(x, y, "4O");
	x = -5 * i; y = 60 * i;
	chu(x, y, "6O");
	x = -10 * i; y = -20 * i;
	chu(x, y, "-2O");
	x = -10 * i; y = -40 * i;
	chu(x, y, "-4O");
	x = -10 * i; y = -60 * i;
	chu(x, y, "-6O");
}

struct ps {
	int tu;
	int mau;
	nhap() {
		cout << "tu = "; cin >> tu;
		cout << "mau = "; cin >> mau;
	}
};

void nhapABCDphanSo(float hamso[], int loai) {
	float a = 0, b = 0, c = 0, d = 0;
	ps aa, bb, cc, dd;
	switch (loai) {
	case 1:
		cout << "nhap a: ";
		aa.nhap();
		a = aa.tu / (float)aa.mau;
		cout << "nhap b: ";
		bb.nhap();
		b = bb.tu / (float)bb.mau;
		hamso[0] = a;
		hamso[1] = b;
		break;
	case 2: case 4:
		cout << "nhap a: ";
		aa.nhap();
		a = aa.tu / (float)aa.mau;
		cout << "nhap b: ";
		bb.nhap();
		b = bb.tu / (float)bb.mau;
		cout << "nhap c: ";
		cc.nhap();
		c = cc.tu / (float)cc.mau;
		hamso[0] = a;
		hamso[1] = b;
		hamso[2] = c;
		break;
	case 3: case 5:
		cout << "nhap a: ";
		aa.nhap();
		a = aa.tu / (float)aa.mau;
		cout << "nhap b: ";
		bb.nhap();
		b = bb.tu / (float)bb.mau;
		cout << "nhap c: ";
		cc.nhap();
		c = cc.tu / (float)cc.mau;
		cout << "nhap d: ";
		dd.nhap();
		d = dd.tu / (float)dd.mau;
		hamso[0] = a;
		hamso[1] = b;
		hamso[2] = c;
		hamso[3] = d;
		break;
	case 6:
		cout << "nhap a: ";
		aa.nhap();
		a = aa.tu / (float)aa.mau;
		cout << "nhap b: ";
		bb.nhap();
		b = bb.tu / (float)bb.mau;
		cout << "nhap c: ";
		cc.nhap();
		c = cc.tu / (float)cc.mau;
		hamso[0] = a;
		hamso[1] = b;
		hamso[2] = c;
		hamso[3] = a;
		hamso[4] = b;
		break;
	}
}

void nhap(float hamso[], int loai) {
	float a = 0, b = 0, c = 0, d = 0;
	switch (loai) {
	case 1:
		cout << "nhap a: "; cin >> a;
		cout << "nhap b: "; cin >> b;
		hamso[0] = a;
		hamso[1] = b;
		break;
	case 2: case 4:
		cout << "nhap a: "; cin >> a;
		cout << "nhap b: "; cin >> b;
		cout << "nhap c: "; cin >> c;
		hamso[0] = a;
		hamso[1] = b;
		hamso[2] = c;
		break;
	case 3: case 5:
		cout << "nhap a: "; cin >> a;
		cout << "nhap b: "; cin >> b;
		cout << "nhap c: "; cin >> c;
		cout << "nhap d: "; cin >> d;
		hamso[0] = a;
		hamso[1] = b;
		hamso[2] = c;
		hamso[3] = d;
		break;
	case 6:
		cout << "nhap a: "; cin >> a;
		cout << "nhap b: "; cin >> b;
		cout << "nhap c: "; cin >> c;
		hamso[0] = a;
		hamso[1] = b;
		hamso[2] = c;
		hamso[3] = a;
		hamso[4] = b;
		break;
	}
}

void xuat(float hamso[], int loai, ostream& os) {
	switch (loai) {
	case 1:
		os << "f(x) = " << hamso[0] << "x + " << hamso[1];
		break;
	case 2:
		os << "f(x) = " << hamso[0] << "x^2 + " << hamso[1] << "x + " << hamso[2];
		break;
	case 3:
		os << "f(x) = " << hamso[0] << "x^3 + " << hamso[1] << "x^2 + " << hamso[2] << "x + " << hamso[3];
		break;
	case 4:
		os << "f(x) = " << hamso[0] << "x^4 + " << hamso[1] << "x^2 + " << hamso[2];
		break;
	case 5:
		os << "f(x) = " << "(" << hamso[0] << "x + " << hamso[1] << ")/(" << hamso[2] << "x + " << hamso[3] << ")";
		break;
	case 6:
		os << "f(x) = " << "(" << hamso[0] << "x^2 + " << hamso[1] << "x + " << hamso[2] << ")/(" << hamso[3] << "x + " << hamso[4] << ")";
		break;
	}
}

void veDoThi(float hamso[], int loai, int color) {
	float dx = 0.001;
	float x = xw1;
	float y;

	switch (loai) {
	case 1:
		y = hamso[0] * x + hamso[1];
		myMoveto(x, y);
		while (x <= xw2) {
			x = x + dx;
			y = hamso[0] * x + hamso[1];
			setcolor(color);
			myLineto(x, y);
		}
		Sleep(10);
		break;
	case 2:
		y = hamso[0] * pow(x, 2) + hamso[1] * x + hamso[2];
		myMoveto(x, y);
		while (x <= xw2) {
			x = x + dx;
			y = hamso[0] * pow(x, 2) + hamso[1] * x + hamso[2];
			setcolor(color);
			myLineto(x, y);
		}
		setcolor(6);
		Sleep(10);
		break;
	case 3:
		y = hamso[0] * pow(x, 3) + hamso[1] * pow(x, 2) + hamso[2] * x + hamso[3];
		myMoveto(x, y);
		while (x <= xw2) {
			x = x + dx;
			y = hamso[0] * pow(x, 3) + hamso[1] * pow(x, 2) + hamso[2] * x + hamso[3];
			setcolor(color);
			myLineto(x, y);
		}
		Sleep(10);
		break;
	case 4:
		y = hamso[0] * pow(x, 4) + hamso[1] * pow(x, 2) + hamso[2];
		myMoveto(x, y);
		while (x <= xw2) {
			x = x + dx;
			y = hamso[0] * pow(x, 4) + hamso[1] * pow(x, 2) + hamso[2];
			setcolor(color);
			myLineto(x, y);
		}
		Sleep(10);
		break;
	case 5:
		y = ((hamso[0] * x) + hamso[1]) / ((hamso[2] * x) + hamso[3]);
		myMoveto(x, y);
		while (x <= xw2) {
			x = x + dx;
			y = ((hamso[0] * x) + hamso[1]) / ((hamso[2] * x) + hamso[3]);
			setcolor(color);
			myLineto(x, y);
			putpixel(x, y, color);
		}
		Sleep(10);
		break;
	case 6:
		y = (((hamso[0] * pow(x, 2)) + (hamso[1] * x)) + hamso[2]) / ((hamso[3] * x) + hamso[4]);
		myMoveto(x, y);
		while (x <= xw2) {
			x = x + dx;
			y = (((hamso[0] * pow(x, 2)) + (hamso[1] * x)) + hamso[2]) / ((hamso[3] * x) + hamso[4]);
			setcolor(color);
			myLineto(x, y);
		}
		Sleep(10);
		break;
	}

	veOXY();
}

#pragma region veHyperbol
void hypebolduongy(int a, int b)
{
	float dx = 0.001;
	float x = xw1;
	float y = sqrt((x * x * b * b) / (a * a) + (b * b));
	myMoveto(x, y);
	while (x <= xw2)
	{
		x = x + dx;
		y = sqrt((x * x * b * b) / (a * a) + (b * b));
		setcolor(6);
		myLineto(x, y);
	}

}
void hypebolamy(int a, int b)
{
	float dx = 0.001;
	float x = xw1;
	float y = -sqrt((x * x * b * b) / (a * a) + (b * b));
	myMoveto(x, y);
	while (x <= xw2)
	{
		x = x + dx;
		y = -sqrt((x * x * b * b) / (a * a) + (b * b));
		setcolor(6);
		myLineto(x, y);
	}

}
/****************************************************/
// Ve nhanh thuoc truc x
void hypebolduongx(int a, int b)
{

	float dy = 0.001;
	float y = yw1;
	float x = sqrt((y * y * b * b) / (a * a) + (b * b));
	myMoveto(x, y);
	while (y <= yw2)
	{
		y = y + dy;
		x = sqrt((y * y * b * b) / (a * a) + (b * b));
		setcolor(6);
		myLineto(x, y);
	}

}
void hypebolamx(int a, int b)
{
	float dy = 0.001;
	float y = yw1;
	float x = -sqrt((y * y * b * b) / (a * a) + (b * b));
	myMoveto(x, y);
	while (y <= yw2)
	{
		y = y + dy;
		x = -sqrt((y * y * b * b) / (a * a) + (b * b));
		setcolor(6);
		myLineto(x, y);
	}

}
//2 tiem can
void veduongthangx(int a, int b) {
	double dx = 0.01, x = xw1, y = b / a * x;
	myMoveto(x, y);
	while (x <= xw2) {
		x = x + dx;
		y = b / a * x;
		myLineto(x, y);
		myMoveto(x, y);
	}
	setcolor(4);
	veOXY();
}
void veduongthangy(int a, int b) {
	double dx = 0.01, x = xw1, y = -b / a * x;
	myMoveto(x, y);
	while (x <= xw2) {
		x = x + dx;
		y = -b / a * x;
		myLineto(x, y);
		myMoveto(x, y);
	}
	setcolor(4);
	veOXY();
}
#pragma endregion

#pragma region veDuongtron
void VeDT(int xc, int yc, int R, int c = 6) {//toa do cuc
	float i = 0;
	float x = xc + R * cos(i * 3.141592654 / 180);
	float y = yc + R * sin(i * 3.141592654 / 180);
	myMoveto(x, y);
	while (i <= 360) {
		i += 0.001;
		x = xc + R * cos(i * 3.141592654 / 180);
		y = yc + R * sin(i * 3.141592654 / 180);
		setcolor(c);
		myLineto(x, y);
	}
}

#pragma endregion

void velineXuyenTam(int a, int b) {
	double dx = 0.01, dy = 0.01, x = xw1, y = a;
	myMoveto(x, y);
	while (x <= xw2) {
		x = x + dx;
		y = a;
		myLineto(x, y);
		myMoveto(x, y);
	}
	setcolor(4);
	veOXY();
	y = yw1;
	x = b;
	myMoveto(x, y);
	while (y <= yw2) {
		y = y + dy;
		x = b;
		myLineto(x, y);
		myMoveto(x, y);
	}
	setcolor(4);
	veOXY();
}

#pragma region ellip
void myellipse(int xc, int yc, int a, int b, int c = 6)// ve elipse
{
	float i = atan2(0, 0);
	float x = xc + a * cos(i * 3.141592654 / 180);
	float y = yc + b * sin(i * 3.141592654 / 180);
	myMoveto(x, y);
	while (i <= 360) {
		i += 0.001;
		x = xc + a * cos(i * 3.141592654 / 180);
		y = yc + b * sin(i * 3.141592654 / 180);
		setcolor(c);
		myLineto(x, y);
	}
}
#pragma endregion

void veDoThiKhac() {
	cout << "\n1. Hypebol = (x ^ 2 / a ^ 2) - (y ^ 2 / b ^ 2) = 1";
	cout << "\n2. Tron = (x ^ 2 - a ^ 2) + (y ^ 2 - b ^ 2) = R ^ 2";
	cout << "\n3. Elipse = (x ^ 2 / a ^ 2) + (y ^ 2 / b ^ 2) = 1";
	int loai = 0;
	int lc3 = 0;
	cout << "\nchon loai do thi: "; cin >> loai;
	float a = 0, b = 0;
	float x = 0, y = 0, bk = 0;
	float trucchinh = 0, trucphu = 0;
	float i = 0;
	int n = 0;
	switch (loai) {
	case 1:
		cout << "nhap a: "; cin >> a;
		cout << "nhap b: "; cin >> b;
		cout << "\n1. Nhanh Thuoc Truc y ";
		cout << "\n2. Nhanh Thuoc Truc x ";
		cout << "\nChon 1 Trong 2 Truong hop :"; cin >> n;
		break;
	case 2:
		break;
	case 3:
		break;
	}
	switch (loai) {
	case 1:
		switch (n)
		{
		case 1:
			i = 10;// he so tile
			initwindow(W, H);
			cuaSo(-10 * i, -10 * i, 9 * i, 10 * i);
			khungNhin(100, 100, 768, 768);
			veOXY();
			hypebolduongy(a, b);
			hypebolamy(a, b);
			delay(10);
			veduongthangx(a, b);
			veduongthangy(a, b);
			break;
		case 2:
			i = 10;// he so tile
			initwindow(W, H);
			cuaSo(-10 * i, -10 * i, 9 * i, 10 * i);
			khungNhin(100, 100, 768, 768);
			veOXY();
			hypebolduongx(a, b);
			hypebolamx(a, b);
			delay(10);
			veduongthangx(a, b);
			veduongthangy(a, b);
			break;
		default:
			cout << "Chon Sai.";
		}
		break;
	case 2:
		cout << "\nTam((x, y) < 100) = ";
		cout << "\nx = "; cin >> x;
		cout << "\ny = "; cin >> y;
		cout << "\nBK = "; cin >> bk;

		initwindow(W, H);
		cuaSo(-100, -100, 100, 100);
		khungNhin(100, 100, 788, 788);

		VeDT(x, y, bk);
		myMoveto(x, y);
		velineXuyenTam(x, y);
		chu(x - 1, y + 2, ".O");
		veOXY();
		break;
	case 3:
		cout << "\nTam((x, y) < 100) = ";
		cout << "\nx = "; cin >> x;
		cout << "\ny = "; cin >> y;
		cout << "nhap a: "; cin >> a;
		cout << "nhap b: "; cin >> b;
		initwindow(W, H);
		cuaSo(-100, -100, 100, 100);
		khungNhin(100, 100, 788, 788);

		myellipse(x, y, a, b, 6);
		myMoveto(x, y);
		velineXuyenTam(x, y);
		chu(x - 1, y + 2, ".O");
		veOXY();

		break;

	}
	return;
}

void veDaDoThiVatimgiaoDiem() {
	int sl = 0;
	int loai = 0;
	float* hamso = NULL;
	int color[] = { 2,3,7,5,6,8,9,10,11,12,13,14,15 };
	cout << "nhap sl do thi: "; cin >> sl;

	cout << "1. ax+b";
	cout << "\n2. ax^2 + bx + c";
	cout << "\n3. ax^3 + bx^2 + cx + d";
	cout << "\n4. ax^4 + bx^2 + c";
	cout << "\n5. (ax + b)/(cx + d)";
	cout << "\n6. (ax^2 + bx + c)/(ax + b)";

	for (int i = 0; i < sl; i++) {
		cout << "\nNhap lua chon: "; cin >> loai;
		if (loai == 1) {
			hamso = new float[2];
		}
		else if (loai == 2) {
			hamso = new float[3];
		}
		else if (loai == 3) {
			hamso = new float[4];
		}
		else if (loai == 4) {
			hamso = new float[3];
		}
		else if (loai == 5) {
			hamso = new float[4];
		}
		else if (loai == 6) {
			hamso = new float[5];
		}
		nhap(hamso, loai);
		veDoThi(hamso, loai, color[i % 12 + 1]);
	}
	getch();
	closegraph();
	char st;
	cout << "Ban muon xac dinh diem cat nhau cua cac do thi k?(y/n) " << endl << endl;
	cin >> st;
	switch (st) {
	case 'y':
		break;
	case 'n':
		break;
	}
}

/************************************/

void veBBT(float hamso[], int loai, ostream& os)
{
	// cho ham bac 2
	float HDdinh = -hamso[1] / (2 * hamso[0]);
	float delta = pow(hamso[1], 2) - 4 * hamso[0] * hamso[2];
	float TDdinh = -delta / 4 * hamso[0];
	// cho ham trung phuong
	int t1 = 0;
	float t2 = sqrt(hamso[1] / (2 * hamso[0]));
	float t3 = -sqrt(hamso[1] / (2 * hamso[0]));
	//chho ham bac 3
	float delta1 = pow((hamso[1] * 2), 2) - (4 * hamso[0] * 3 * hamso[2]);
	// cho ham loai 6
	float delta3 = 4 * hamso[2];
	switch (loai)
	{
	case 1:
		if (hamso[0] > 0)
		{
			os << " Ham so dong bien tren tap xac dinh " << endl;
			os << "bang bien thien : " << endl;
			os << " x | -oo              +oo |" << endl;
			os << "---|----------------------|--" << endl;
			os << " y | -oo              +oo |" << endl;
			os << "   |          /           |" << endl;
			os << "   |         /            |" << endl;
			os << "---|----------------------|--" << endl;
		}
		else
		{
			os << " ham so nghich bien tren tap xac dinh " << endl;
			os << "bang bien thien : " << endl;
			os << " x | -oo              +oo |" << endl;
			os << "---|----------------------|--" << endl;
			os << " y | -oo              +oo |" << endl;
			os << "   |         \\            |" << endl;
			os << "   |          \\           |" << endl;
			os << "---|----------------------|--" << endl;

		}
		break;
	case 2:
		/*float HDdinh = -hamso[1] / (2 * hamso[0]);
		float delta = pow(hamso[1], 2) - 4 * hamso[0] * hamso[2];
		float TDdinh = -delta / 4 * hamso[0];*/
		os << " toa do dinh : I (" << HDdinh << ";" << TDdinh << ")" << endl;
		if (hamso[0] > 0)
		{
			os << "Ham so nghich bien tren khoang (-oo;" << HDdinh << ") va dong bien tu (" << HDdinh << "; +oo )" << endl;
			os << "Bang bien thien: " << endl;
			os << " x | -oo               " << HDdinh << "                   +oo " << endl;
			os << "--|---------------------------------------------|--" << endl;
			os << " y| -oo               " << TDdinh << "                   +oo " << endl;
			os << "  |         \\                      /           " << endl;
			os << "  |          \\                    /            " << endl;
			os << "--|-----------------------------------------------" << endl;
		}
		else
		{
			os << "Ham so dong bien tren khoang (-oo;" << HDdinh << ") va nghich bien tu (" << HDdinh << "; +oo )" << endl;
			os << "Bang bien thien: " << endl;
			os << " x| -oo           " << HDdinh << "                       +oo  " << endl;
			os << "--|--------------------------------------------|--" << endl;
			os << " y| -oo           " << TDdinh << "                        +oo " << endl;
			os << "  |        /                       \\           |" << endl;
			os << "  |       /                         \\          |" << endl;
			os << "--|--------------------------------------------|--" << endl;
		}
		break;
	case 3:
		os << " Dao ham cua ham số f(x): " << endl;
		os << "f'(x)= " << hamso[0] * 3 << " x^2 +" << hamso[1] * 2 << "x +" << hamso[2] << endl;
		if (delta1 <= 0)
		{
			if (hamso[0] > 0)
			{
				os << "Ham so luon dong bien tren tap xac dinh " << endl;
				os << "bang bien thien : " << endl;
				os << " x | -oo              +oo |" << endl;
				os << "---|----------------------|--" << endl;
				os << " y'|           +          | " << endl;
				os << " y | -oo              +oo |" << endl;
				os << "   |          /           |" << endl;
				os << "   |         /            |" << endl;
				os << "---|----------------------|--" << endl;

			}
			else
			{
				os << "Ham so luon nghich bien tren tap xac dinh " << endl;
				os << "bang bien thien : " << endl;
				os << " x | -oo              +oo |" << endl;
				os << "---|----------------------|--" << endl;
				os << " y'|           -          | " << endl;
				os << "---|----------------------|--" << endl;
				os << " y | -oo              +oo |" << endl;
				os << "   |         \\            |" << endl;
				os << "   |          \\           |" << endl;
				os << "---|----------------------|--" << endl;
			}
		}
		else
		{
			float x1 = ((-hamso[1] * 2) + sqrt(delta1)) / (2 * hamso[0]);
			float x2 = ((-hamso[1] * 2) - sqrt(delta1)) / (2 * hamso[0]);
			if (hamso[0] > 0)
			{
				os << "Ham so dong bien tren khoang tu (-oo;" << x1 << ") và (" << x2 << ";+oo), nghich bien tren khoang (" << x1 << ";" << x2 << ")." << endl;
				os << " Bang bien thien: " << endl;
				os << " x |-oo" << setw(20) << x1 << setw(20) << x2 << setw(20) << "+oo   |" << endl;
				os << "----------------------|-----------------------|---------------------------" << endl;
				os << " y'|        +        0           -           0              +       |     " << endl;
				os << "--------------------------------------------------------------------------" << endl;
				os << " y |-oo              CD                                          +oo    " << endl; cin.ignore();
				os << "   |           /               \\                      /             " << endl;
				os << "   |          /                 \\                    /                " << endl;
				os << "   |                                         CT                      " << endl;
				os << "---------------------------------------------------------------------------" << endl;
			}
			else
			{
				os << "Ham so nghich bien tren khoang tu (-oo;" << x1 << ") và (" << x2 << ";+oo), dong bien tren khoang (" << x1 << ";" << x2 << ")." << endl;
				os << " Bang bien thien: " << endl;
				os << " x |-oo         " << x1 << "             " << x2 << "            +oo|" << endl;
				os << "----------------------|-----------------------|---------------------------" << endl;
				os << " y'|        -        0           +           0              -       |     " << endl;
				os << "--------------------------------------------------------------------------" << endl;
				os << " y |-oo                                      CT                  +oo    " << endl;
				os << "   |           \\                /                      \\                 " << endl;
				os << "   |            \\              /                        \\             " << endl;
				os << "   |                  CD                                             " << endl;
				os << "---------------------------------------------------------------------------" << endl;
			}
		}
		break;
	case 4:
		if (hamso[0] > 0 && hamso[1] >= 0)
		{
			os << "Ham so nghich bien tren khoang tu (-oo;0) va dong bien tren khoang (0;+oo)" << endl;
			os << "Bang bien thien: " << endl;
			os << " x| -oo                 0                   +oo " << endl;
			os << "--|---------------------------------------------|--" << endl;
			os << " y| -oo               " << hamso[2] << "                   +oo " << endl;
			os << "  |         \\                      /           " << endl;
			os << "  |          \\                    /            " << endl;
			os << "--|-----------------------------------------------" << endl;
		}
		else if (hamso[0] < 0 && hamso[1] <= 0)
		{
			os << "Ham so dong bien tren khoang tu (-oo;0) va nghich bien tren khoang (0;+oo)" << endl;
			os << "Bang bien thien: " << endl;
			os << " x| -oo                   0                       +oo  " << endl;
			os << "--|--------------------------------------------|--" << endl;
			os << " y| -oo           " << hamso[2] << "                        +oo " << endl;
			os << "  |        /                       \\           |" << endl;
			os << "  |       /                         \\          |" << endl;
			os << "--|--------------------------------------------|--" << endl;
		}
		else if (hamso[0] > 0 && hamso[1] < 0)
		{
			/*int t1 = 0;
			float t2 = sqrt(hamso[1] / (2 * hamso[0]));
			float t3 = -sqrt(hamso[1] / (2 * hamso[0]));*/
			os << " Ham so co 3 nghiem phan biet 0,t2,t3" << endl;
			os << "Ham so nghich bien tren khoang (-oo;t2) hoac (0;t3) va dong bien tren khoang ( t2 ;0) hoac ( t3;+oo)" << endl;
			os << "Bang bien thien : " << endl;
			os << " x |-oo                t2                0                             t3            +oo|" << endl;
			os << "-|-------------------------------------------------------------------------------------------|--" << endl;
			os << "y'|-oo     -         0            +                  -                 0           +        +oo| " << endl;
			os << "-|------------------------------------------------------------------------------------------|--" << endl;
			os << " |                                          CD                                                 " << endl;
			os << " |            \\                  /                     \\                        /             " << endl;
			os << " |             \\                /                       \\                      /               " << endl;
			os << " |                    CT                                             CT                        " << endl;
		}
		else
		{
			os << " Ham so co 3 nghiem phan biet 0,t2,t3" << endl;
			os << "Ham so dong bien tren khoang (-oo;t2) hoac (0;t3) va nghich bien tren khoang ( t2 ;0) hoac ( t3;+oo)" << endl;
			os << " x |-oo                t2                0                             t3            +oo|" << endl;
			os << "-|-------------------------------------------------------------------------------------------|--" << endl;
			os << "y'|-oo     +           0            -                  +                0           -       +oo| " << endl;
			os << "-|------------------------------------------------------------------------------------------|--" << endl;
			os << " |                    CD                                             CD                         " << endl;
			os << " |             /                \\                      /                        \\           " << endl;
			os << " |            /                  \\                    /                          \\           " << endl;
			os << " |                                         CT                                              " << endl;

		}
		break;
	case 5:
		if (hamso[0] * hamso[3] - hamso[2] * hamso[1] > 0)
		{
			os << "Ham so dong bien tren TXD" << endl;
			os << "Bang bien thien: " << endl;
			os << "x |-oo                 " << -hamso[3] / hamso[2] << "                                          +oo" << endl;
			os << "-----------------------------------------------------------------------------" << endl;
			os << "y'|   0                                ||                                 0 " << endl;
			os << "-------------------------------------------------------------------------------" << endl;
			os << "y |                                 +oo||                             " << hamso[0] / hamso[2] << endl;
			os << "  |                   /                ||              /                         " << endl;
			os << "  |                  /                 ||             /                            " << endl;
			os << "  |" << hamso[0] / hamso[2] << "                              ||-oo                                         " << endl;
		}
		else
		{
			os << "Ham so nghich bien tren TXD " << endl;
			os << "Bang bien thien: " << endl;
			os << "x |-oo                 " << -hamso[3] / hamso[2] << "                                          +oo" << endl;
			os << "-----------------------------------------------------------------------------" << endl;
			os << "y'|   0                                ||                                 0 " << endl;
			os << "-------------------------------------------------------------------------------" << endl;
			os << "  |" << hamso[0] / hamso[2] << "                                  ||+oo                                         " << endl;
			os << "  |               \\                    ||                   \\                  " << endl;
			os << "  |                \\                   ||                    \\                    " << endl;
			os << "  |                                  -oo||                                " << hamso[0] / hamso[2] << endl;

		}
		break;
	case 6:
		if (hamso[2] > 0)
		{
			os << "Dao ham cua ham so co 2 nghiem phan biet" << endl;
			float x3 = (sqrt(hamso[2]) - hamso[1]) / hamso[0];
			float x4 = (hamso[1] - sqrt(hamso[2])) / hamso[0];
			os << "Bang bien thien: " << endl;
			os << "x |-oo                     " << x3 << "                             " << -hamso[1] / hamso[0] << "                            " << x4 << "                           +oo" << endl;
			os << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
			os << "y'|           +            0                -                   ||                      -              0                +                  " << endl;
			os << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
			os << "y |-oo            /                       \\                     ||+oo                       \\                            /                   " << endl;
			os << "  |              /                         \\                 -oo||                           \\                          /                       " << endl;
		}
		if (hamso[2] < 0)
		{
			os << "Ham so luon dong bien tren TXD" << endl;
			os << "Bang bien thien : " << endl;
			os << " x|-oo                                   " << -hamso[1] / hamso[0] << "                               +oo" << endl;
			os << "--------------------------------------------------------------------------------------------" << endl;
			os << "y'|               +                   +oo||                         +                    +oo" << endl;
			os << " ---------------------------------------------------------------------------------------------" << endl;
			os << " y|                /                     ||                        /                          " << endl;
			os << "  |               /                      ||                       /                            " << endl;
			os << "  |-oo                                   ||-oo                                                   " << endl;
		}
		break;
	}
}

/************************************************/
void xuatTXD(float hamso[], int loai, ostream& os) {
	switch (loai) {
	case 1:
	case 2:
	case 3:
	case 4:
		os << "\nD = R\n";
		break;
	case 5:
		os << "\nD = R \\ { " << -hamso[3] / hamso[2] << " }\n";
		break;
	case 6:
		os << "\nD = R \\ { " << -hamso[4] / hamso[3] << " }\n";
		break;
	}
}

void timLim(float hamso[], int loai, ostream& os)
{
	switch (loai) {
	case 1:
		if (hamso[0] > 0)
		{
			os << "lim[x->+oo](" << hamso[0] << "x +" << hamso[1] << ")= +oo" << endl;
			os << "lim[x->-oo](" << hamso[0] << "x +" << hamso[1] << ")= -oo" << endl;
		}
		else if (hamso[0] < 0)
		{
			os << "lim[x->+oo](" << hamso[0] << "x +" << hamso[1] << ")= -oo" << endl;
			os << "lim[x->-oo](" << hamso[0] << "x +" << hamso[1] << ")= +oo" << endl;
		}
		break;
	case 2:
		if (hamso[0] > 0)
		{
			os << "lim[x->+oo](" << hamso[0] << "x^2 + " << hamso[1] << "x + " << hamso[2] << ")= +oo" << endl;
			os << "lim[x->-oo](" << hamso[0] << "x^2 + " << hamso[1] << "x + " << hamso[2] << ")= +oo" << endl;
		}
		else if (hamso[0] < 0)
		{
			os << "lim[x->+oo](" << hamso[0] << "x^2 + " << hamso[1] << "x + " << hamso[2] << ")= -oo" << endl;
			os << "lim[x->-oo](" << hamso[0] << "x^2 + " << hamso[1] << "x + " << hamso[2] << ")= -oo" << endl;
		}
		break;
	case 3:
		if (hamso[0] > 0)
		{
			os << "lim[x->+oo](" << hamso[0] << "x^3 + " << hamso[1] << "x^2 + " << hamso[2] << "x + " << hamso[3] << ")= +oo" << endl;
			os << "lim[x->-oo](" << hamso[0] << "x^3 + " << hamso[1] << "x^2 + " << hamso[2] << "x + " << hamso[3] << ")= -oo" << endl;
		}
		else if (hamso[0] < 0)
		{
			os << "lim[x->+oo](" << hamso[0] << "x^3 + " << hamso[1] << "x^2 + " << hamso[2] << "x + " << hamso[3] << ")= -oo" << endl;
			os << "lim[x->-oo](" << hamso[0] << "x^3 + " << hamso[1] << "x^2 + " << hamso[2] << "x + " << hamso[3] << ")= +oo" << endl;
		}
		break;
	case 4:
		if (hamso[0] > 0)
		{
			os << "lim[x->+oo](" << hamso[0] << "x^4 + " << hamso[1] << "x^2 + " << hamso[2] << ")= +oo" << endl;
			os << "lim[x->-oo](" << hamso[0] << "x^4 + " << hamso[1] << "x^2 + " << hamso[2] << ")= +oo" << endl;
		}
		else if (hamso[0] < 0)
		{
			os << "lim[x->+oo](" << hamso[0] << "x^4 + " << hamso[1] << "x^2 + " << hamso[2] << ")= -oo" << endl;
			os << "lim[x->-oo](" << hamso[0] << "x^4 + " << hamso[1] << "x^2 + " << hamso[2] << ")= -oo" << endl;
		}
		break;
	case 5:
		if ((hamso[0] * hamso[3] - hamso[1] * hamso[2]) > 0)
		{
			os << "lim[x->+oo](" << "(" << hamso[0] << "x + " << hamso[1] << ")/(" << hamso[2] << "x + " << hamso[3] << ")" << ")= " << hamso[0] / hamso[2] << endl;
			os << "lim[x->-oo](" << "(" << hamso[0] << "x + " << hamso[1] << ")/(" << hamso[2] << "x + " << hamso[3] << ")" << ")= " << hamso[0] / hamso[2] << endl;
			float t = -(hamso[3] / hamso[2]);
			os << "lim[x->(" << t << ")+](y)= +oo" << endl;
			os << "lim[x->(" << t << ")-](y)= -oo" << endl;
		}
		else if ((hamso[0] * hamso[3] - hamso[1] * hamso[2]) < 0)
		{
			os << "lim[x->+oo](" << "(" << hamso[0] << "x + " << hamso[1] << ")/(" << hamso[2] << "x + " << hamso[3] << ")" << ")= " << hamso[0] / hamso[2] << endl;
			os << "lim[x->-oo](" << "(" << hamso[0] << "x + " << hamso[1] << ")/(" << hamso[2] << "x + " << hamso[3] << ")" << ")= " << hamso[0] / hamso[2] << endl;
			float z = -(hamso[3] / hamso[2]);
			os << "lim[x->(" << z << ")+](y)= -oo" << endl;
			os << "lim[x->(" << z << ")-](y)= +oo" << endl;
		}
		break;
	case 6:
		if (hamso[0] * hamso[3] > 0)
		{
			os << "lim[x->+oo](" << "(" << hamso[0] << "x + " << hamso[1] << ")/(" << hamso[2] << "x + " << hamso[3] << ")" << ")= +oo" << endl;
			os << "lim[x->-oo](" << "(" << hamso[0] << "x + " << hamso[1] << ")/(" << hamso[2] << "x + " << hamso[3] << ")" << ")= -oo" << endl;
			float t = -(hamso[4] / hamso[3]);
			os << "lim[x->(" << t << ")+](y)= +oo" << endl;
			os << "lim[x->(" << t << ")-](y)= -oo" << endl;
		}
		else if (hamso[0] * hamso[3] < 0)
		{
			os << "lim[x->+oo](" << "(" << hamso[0] << "x + " << hamso[1] << ")/(" << hamso[2] << "x + " << hamso[3] << ")" << ")= -oo" << endl;
			os << "lim[x->-oo](" << "(" << hamso[0] << "x + " << hamso[1] << ")/(" << hamso[2] << "x + " << hamso[3] << ")" << ")= +oo" << endl;
			float z = -(hamso[4] / hamso[3]);
			os << "lim[x->(" << z << ")+](y)= -oo" << endl;
			os << "lim[x->(" << z << ")-](y)= +oo" << endl;
		}
		break;
	}
}


/*******************************************/

float* timDaoHam(float hamso[], int loai, ostream& os)
{
	float x, y, z, t, u;

	switch (loai) {
	case 1:
		x = hamso[0];
		y = hamso[1];
		hamso[0] = hamso[0];
		hamso[1] = 0;
		os << "f'(x) = " << hamso[0] << "\n";
		hamso[0] = x;
		hamso[1] = y;
		break;
	case 2:
		x = hamso[0];
		y = hamso[1];
		z = hamso[2];
		hamso[0] = 2 * hamso[0];
		hamso[1] = hamso[1];
		hamso[2] = 0;
		os << "f'(x) = " << hamso[0] << "x + " << hamso[1] << "\n";
		hamso[0] = x;
		hamso[1] = y;
		hamso[2] = z;
		break;
	case 3:
		x = hamso[0];
		y = hamso[1];
		z = hamso[2];
		t = hamso[3];
		hamso[0] = 3 * hamso[0];
		hamso[1] = 2 * hamso[1];
		hamso[2] = hamso[2];
		hamso[3] = 0;
		os << "f'(x) = " << hamso[0] << "x^2 + " << hamso[1] << "x + " << hamso[2] << "\n";
		hamso[0] = x;
		hamso[1] = y;
		hamso[2] = z;
		hamso[3] = t;
		break;
	case 4:
		x = hamso[0];
		y = hamso[1];
		z = hamso[2];
		hamso[0] = 4 * hamso[0];
		hamso[1] = 2 * hamso[1];
		hamso[2] = 0;
		os << "f'(x) = " << hamso[0] << "x^3 + " << hamso[1] << "x" << "\n";
		hamso[0] = x;
		hamso[1] = y;
		hamso[2] = z;
		break;

	case 5:
		x = hamso[0];
		y = hamso[1];
		z = hamso[2];
		t = hamso[3];
		hamso[0] = hamso[0] * hamso[3] - hamso[1] * hamso[2];
		hamso[1] = 0;
		hamso[2] = hamso[2];
		hamso[3] = hamso[3];
		os << "f'(x) = " << hamso[0] << " / (" << hamso[2] << "x + " << hamso[3] << ")^2" << "\n";
		hamso[0] = x;
		hamso[1] = y;
		hamso[2] = z;
		hamso[3] = t;
		break;
	case 6:
		x = hamso[0];
		y = hamso[1];
		z = hamso[2];
		t = hamso[3];
		u = hamso[4];
		hamso[0] = hamso[0] * hamso[3];
		hamso[1] = 2 * hamso[0] * hamso[4];
		hamso[2] = hamso[1] * hamso[4] - hamso[2] * hamso[3];
		hamso[3] = hamso[3];
		hamso[4] = hamso[4];
		os << "f'(x) = (" << hamso[0] << "x^2 + " << hamso[1] << "x + " << hamso[2] << ") / (" << hamso[2] << "x + " << hamso[3] << ")^2\n";
		hamso[0] = x;
		hamso[1] = y;
		hamso[2] = z;
		hamso[3] = t;
		hamso[4] = u;
		break;
	}
	return hamso;
}

int GiaiPTBac2(float a, float b, float c, float& x1, float& x2)
{
	float delta = b * b - 4 * a * c;
	if (delta < 0)
	{
		x1 = x2 = 0.0;
		return 0;
	}
	else if (delta == 0)
	{
		x1 = x2 = -b / (2 * a);
		return 1;
	}
	else
	{
		float candelta = sqrt(delta);
		x1 = (-b + candelta) / (2 * a);
		x2 = (-b - candelta) / (2 * a);
		return 2;
	}
}

void timMINMAX(float hamso[], int loai, ostream& os)
{
	float x, y, z, t;
	float x1, x2;
	int x0 = 0;
	switch (loai) {
	case 1:
	case 2:
		if (hamso[0] > 0)
		{
			float x = -(hamso[1] / 2 * hamso[0]);
			float y = (hamso[0] * x * x) + (hamso[1] * x) + hamso[2];
			os << "MIN tai A(" << x << "," << y << ")" << endl;
		}
		else if (hamso[0] < 0)
		{
			float x = -(hamso[1] / 2 * hamso[0]);
			float y = (hamso[0] * x * x) + (hamso[1] * x) + hamso[2];
			os << "MAX tai A(" << x << "," << y << ")" << endl;
		}
		break;
	case 3:
		x = hamso[0];
		y = hamso[1];
		z = hamso[2];
		t = hamso[3];
		hamso[0] = 3 * hamso[0];
		hamso[1] = 2 * hamso[1];
		hamso[2] = hamso[2];
		hamso[3] = hamso[3];
		if (hamso[0] > 0)
		{
			if (GiaiPTBac2(hamso[0], hamso[1], hamso[2], x1, x2) == 0 || GiaiPTBac2(hamso[0], hamso[1], hamso[2], x1, x2) == 1)
			{
				os << "KHONG co MIN, MAX";
			}
			else if (GiaiPTBac2(hamso[0], hamso[1], hamso[2], x1, x2) == 2)
			{
				float y1 = (hamso[0] / 3) * pow(x1, 3) + (hamso[1] / 2) * pow(x1, 2) + hamso[2] * x1 + hamso[3];
				float y2 = (hamso[0] / 3) * pow(x2, 3) + (hamso[1] / 2) * pow(x1, 2) + hamso[2] * x2 + hamso[3];
				if (x1 < x2)
				{
					os << "MAX tai A(" << x1 << "," << y1 << ")" << endl;
					os << "MIN tai B(" << x2 << "," << y2 << ")" << endl;
				}
				else if (x1 > x2)
				{
					os << "MAX tai A(" << x2 << "," << y2 << ")" << endl;
					os << "MIN tai B(" << x1 << "," << y1 << ")" << endl;
				}
			}
		}
		else if (hamso[0] < 0)
		{
			if (GiaiPTBac2(hamso[0], hamso[1], hamso[2], x1, x2) == 0 || GiaiPTBac2(hamso[0], hamso[1], hamso[2], x1, x2) == 1)
			{
				os << "KHONG co MIN, MAX";
			}
			else if (GiaiPTBac2(hamso[0], hamso[1], hamso[2], x1, x2) == 2)
			{
				float y1 = (hamso[0] / 3) * pow(x1, 3) + (hamso[1] / 2) * pow(x1, 2) + hamso[2] * x1 + hamso[3];
				float y2 = (hamso[0] / 3) * pow(x2, 3) + (hamso[1] / 2) * pow(x2, 2) + hamso[2] * x2 + hamso[3];
				if (x1 < x2)
				{
					os << "MAX tai A(" << x2 << "," << y2 << ")" << endl;
					os << "MIN tai B(" << x1 << "," << y1 << ")" << endl;
				}
				else if (x1 > x2)
				{
					os << "MAX tai A(" << x2 << "," << y2 << ")" << endl;
					os << "MIN tai B(" << x1 << "," << y1 << ")" << endl;
				}
			}
		}
		hamso[0] = x;
		hamso[1] = y;
		hamso[2] = z;
		hamso[3] = t;
		break;
	case 4:
		x = hamso[0];
		y = hamso[1];
		z = hamso[2];
		hamso[0] = 4 * hamso[0];
		hamso[1] = 2 * hamso[1];
		hamso[2] = hamso[2];
		if (hamso[0] > 0)
		{
			if (GiaiPTBac2(hamso[0], 0, hamso[1], x1, x2) == 0 || GiaiPTBac2(hamso[0], 0, hamso[1], x1, x2) == 1)
			{
				os << "MIN tai A(" << x0 << "," << hamso[2] << ")" << endl;
			}
			else if (GiaiPTBac2(hamso[0], 0, hamso[1], x1, x2) == 2)
			{
				float y1 = (hamso[0] / 4) * pow(x1, 4) + (hamso[1] / 2) * pow(x1, 2) + hamso[2];
				os << "MIN tai A(" << x1 << "," << y1 << ") va B(" << x2 << "," << y1 << ")" << endl;
				os << "MAX tai C(" << x0 << "," << hamso[2] << ")" << endl;
			}
		}
		else if (hamso[0] < 0)
		{
			if (GiaiPTBac2(hamso[0], 0, hamso[1], x1, x2) == 0 || GiaiPTBac2(hamso[0], 0, hamso[1], x1, x2) == 1)
			{
				os << "MAX tai A(" << x0 << "," << hamso[2] << ")" << endl;
			}
			else if (GiaiPTBac2(hamso[0], 0, hamso[1], x1, x2) == 2)
			{
				float y1 = (hamso[0] / 4) * pow(x1, 4) + (hamso[1] / 2) * pow(x1, 2) + hamso[2];
				os << "MAX tai A(" << x1 << "," << y1 << ") va B(" << x2 << "," << y1 << ")" << endl;
				os << "MIN tai C(" << x0 << "," << hamso[2] << ")" << endl;
			}
		}
		hamso[0] = x;
		hamso[1] = y;
		hamso[2] = z;
		break;
	case 5:
		os << "Khong co MINMAX.";
		break;
	case 6:
		os << "Khong co MINMAX";
		break;
	}
}
