#include <iostream>
#include <string>

using namespace std;
//Bĩnh Huy
#pragma region Nhapxuat
void nhap(float hamso[], int loai);
void xuat(float hamso[], int loai, ostream& os = cout);
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

void timLim(float hamso[], int loai);

// cho x-> ??, xuat ra kq
#pragma endregion
//Nam Quang
#pragma region minmax 
//ở phần tìm đạo hàm
float* timMINMAX(float hamso[], int loai);
#pragma endregion
//Anh Huy
#pragma region xetdau_ve_BBT

void veBBT(float hamso[], int loai, ostream& os = cout);

//xuất ra bảng xét dấu y'
/*
xài thư viện iomanip/setw để canh khoảng trắng chuẩn

	  x		|-vc	nghiem1		nghiem2		 nghiem4	+vc
---------------------------------------------------------------------------
	  y'	|	  +   ||	 -	   0      +		||	  -
*/

/*
	thêm phần biến thiên

	*có hàm tìm cực trị float* timMINMAX(float hamso[], int loai); trả về min, max,
	2 người làm 2 hàm này làm chung với nhau để thống nhất
	vd:
---------------------------------------------------------------------------
	  y		|-vc  /	  max	 \	  min	  /		max	   \ -vc


	 kq hoàn chỉnh:
	  x		|-vc	nghiem1		nghiem2		 nghiem4	+vc
---------------------------------------------------------------------------
	  y'	|	  +   ||	 -	   0      +		||	  -
---------------------------------------------------------------------------
	  y		|-vc  /	  max	 \	  min	  /		max	   \ -vc
*/
#pragma endregion
//Bĩnh Huy
#pragma region vedothi
void veDoThi(float hamso[], int loai);
void veDoThiKhac(); //tron elipse hyperbol, parabol
void veDaDoThiVatimgiaoDiem();
#pragma endregion


int main() {
	cout << "\n1. ax+b";
	cout << "\n2. ax^2 + bx + c";
	cout << "\n3. ax^3 + bx^2 + cx + d";
	cout << "\n4. ax^4 + bx^2 + c";
	cout << "\n5. (ax + b)/(cx + d)";
	cout << "\n6. (ax^2 + bx + c)/(ax + b)";

	int loai = 0;
	float* hamso = NULL;
	cout << "\nNhap loai ham so: "; cin >> loai;
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

	cout << endl << endl;
	cout << "1. Xuat Chuoi ham so da nhap. " << endl << endl;
	cout << "2. Tim TXD cua ham so. " << endl << endl;
	cout << "3. Tim y' va xet dau y'. " << endl << endl;
	cout << "4. Tim lim. " << endl << endl;
	cout << "5. Lap bang bien thien. " << endl << endl;
	cout << "6. Tim MIN, MAX neu co. " << endl << endl;
	cout << "7. Ve do thi. " << endl << endl;
	cout << "8. Ve Do thi cac hinh tron, elipse, hyperbol, parabol. " << endl << endl;
	cout << "9. Ve da do thi. " << endl << endl;
	cout << "10. Xac dinh diem cat nhau cua cac do thi. " << endl << endl;
	cout << "11. Nhap xuat file. " << endl << endl;
	int luaChon = 0;
	cout << "Lua chon: "; cin >> luaChon;
	switch (luaChon) {
	case 1:
		xuat(hamso, loai);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	}

	cout << endl;
	system("pause");
}

void nhap(float hamso[], int loai) {
	int a = 0, b = 0, c = 0, d = 0;
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
