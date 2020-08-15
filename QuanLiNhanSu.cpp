#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define MAX_SIZE 100

// Định nghĩa kiểu dữ liệu của nhân viên.
struct NhanVien
{
	char ma[10];
	char ho[10];
	char dem[10];
	char ten[10];
	char gioitinh[10];
	int tuoi;
	int songaylam;
	float luong=1;
};
//Các hàm sử dụng trong bài.
void nhapNhanVien(NhanVien &nhanvien);
void tinhLuongNhanVien(NhanVien &nhanvien);
void hienThiThuTuNhanVien(NhanVien nhanvien);
void hienThiDanhSachNhanVien(NhanVien *danhsach, int soluong);
void hienThiTenCot();
void sapXepTheoTen(NhanVien *danhsach, int soluong);
void timTheoTen(NhanVien *danhsach, int soluong);
void docFile(FILE *file, char str[MAX_SIZE]);
void huongDanSuDung();
int main()
{	
	char str[MAX_SIZE];
	FILE *file;
	NhanVien danhsach[MAX_SIZE], nhanvien;
	int soluong=0;
	system ("color F4");
	printf("DANH SACH NHAN VIEN DA LUU VAO FILE.\n");
	hienThiTenCot();
	docFile(file,str);
	huongDanSuDung();
}
// Tính lương của các nhân viên.
void tinhLuongNhanVien(NhanVien &nhanvien)
{
	nhanvien.luong=nhanvien.songaylam*400000;
}

// Nhập thông số các nhân viên.
void nhapNhanVien(NhanVien &nhanvien)
{
	printf("Nhap ma nhan vien: ");
	scanf("%s",&nhanvien.ma);
	printf("\nNhap ho: ");
	scanf("%s",&nhanvien.ho);
	printf("\nNhap ten dem: ");
	scanf("%s",&nhanvien.dem);
	printf("\nNhap ten: ");
	fflush(stdin);
	scanf("%s",&nhanvien.ten);
	printf("\nNhap tuoi: ");
	scanf("%d",&nhanvien.tuoi);
	printf("\nNhap gioi tinh: ");
	scanf("%s",&nhanvien.gioitinh);
	printf("\nNhap so ngay lam: ");
	scanf("%d",&nhanvien.songaylam);
	tinhLuongNhanVien(nhanvien);
}
// Hiển thị nhân viên đã nhập.
void hienThiThuTuNhanVien(NhanVien nhanvien)
{
	printf("%12s%10s%12s%10s%8d%20s%15d%15.0f\n",
	nhanvien.ma, nhanvien.ho, nhanvien.dem, nhanvien.ten, nhanvien.tuoi, nhanvien.gioitinh, nhanvien.songaylam, nhanvien.luong);
}
// Sắp xếp từ a-z theo tên các nhân viên đã nhập.
void sapXepTheoTen(NhanVien *danhsach, int soluong) 
{
	for(int i=0; i<soluong-1; i++){
		for(int j=i+1; j< soluong; j++){
			if(strcmp(danhsach[i].ten, danhsach[i+1].ten)>0){
				NhanVien nhanvien = danhsach[j];
				danhsach[j] = danhsach[i];
				danhsach[i] = nhanvien;
			}
		}
	}
}
// Tìm kiếm tên nhân viên trong danh sách đã nhập.
void timTheoTen(NhanVien *danhsach, int soluong)
{
	char ten[10];
	fflush(stdin);
	printf("Nhap ten: ");
	gets(ten);
	getchar;
	hienThiTenCot();
	int timnhanvien = 0;
	for(int i=0; i<soluong; i++){
		if(strcmp(ten, danhsach[i].ten) == 0){
			hienThiThuTuNhanVien(danhsach[i]);
			timnhanvien = 1;
		}
	}
	if(timnhanvien == 0){
		printf("Khong co nhan vien %s trong danh sach!\n", ten);
	}
}
// Lưu dữ liệu vào File.
void ghiFile ( NhanVien *danhsach, int soluong)
{
	FILE *file = fopen("NV.txt", "a+");
	int i;
	for (i=0; i<soluong; i++){
	fprintf(file,"%12s%10s%12s%10s%8d%20s%15d%15.0f\n",
	danhsach[i].ma, danhsach[i].ho, danhsach[i].dem, danhsach[i].ten, danhsach[i].tuoi, danhsach[i].gioitinh, danhsach[i].songaylam, danhsach[i].luong);
	}
	fclose(file);
}

// Đọc dữ liệu các nhân viên đã nhập từ tệp.
void docFile(FILE *file, char str[MAX_SIZE])
{
	file = fopen("C:\\visual\\C-master\\QuanLi\\NV.txt", "r+");
	if (file == NULL){
		printf ("File rong\n");
	}
	while (fgets(str,MAX_SIZE,file)!=NULL)
	printf("%s",str);
	fclose(file);
}
// Hiển thị những miền của các nhân viên.
void hienThiTenCot() {
	printf("----------------------------------------------------"
	"------------------------------------------------------------------\n");
	printf("%10s%10s%10s%10s%10s%20s%20s%10s\n", 
		"Ma Nhan Vien", "Ho", "Dem", "Ten", "Tuoi", "Gioi Tinh", "So Ngay Lam Viec", "Luong");
}
// Hiển thị danh sác các nhân viên đã nhập.
void hienThiDanhSachNhanVien(NhanVien *danhsach, int soluong)
{
	printf("\nDANH SACH NHAN VIEN\n");
	hienThiTenCot();
	for(int i = 0; i < soluong; i++) {
		hienThiThuTuNhanVien(danhsach[i]);
	}
	printf("-----------------------------------------------------"
	"-----------------------------------------------------------------\n");
}
// Nhập các thông số muốn sử dụng.
void huongDanSuDung()
{
	//Ở đây cá bạn sẽ thấy 1 mảng và 1 biến được khai báo theo kiểu NhanVien và 2 biến được khai báo theo kiểu int thì đến những hàm sử dụng mình sẽ giải thích
	NhanVien danhsach[MAX_SIZE], nhanvien;
	int luachon, soluong = 0;
	do {
		printf("============ MENU ============");
		printf("\n1. Them nhan vien vao danh sach.");
		printf("\n2. Hien thi danh sach nhan vien.");
		printf("\n3. Sap xep theo ten.");                
		printf("\n4. Tim nhan vien theo ten.");
		printf("\n5. Ghi thong tin ra File");
		printf("\n0. Thoat chuong trinh.");
		printf("\nNhap lua chon: ");
		scanf("%d", &luachon);
		switch(luachon) {
			case 0:
				break;
				
			case 1:
				nhapNhanVien(nhanvien);
				danhsach[soluong++] = nhanvien;
				break;
				
			case 2:
				hienThiDanhSachNhanVien(danhsach, soluong);
				break;
				
			case 3:
				sapXepTheoTen(danhsach, soluong);
				printf("\nDanh sach nhan vien sau khi sap xep theo ten a-z:\n");
				hienThiDanhSachNhanVien(danhsach, soluong);
				break;
			case 5:
				ghiFile(danhsach, soluong);
				break;
			case 4:
				timTheoTen(danhsach, soluong);
				break;
			
			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;
		}
		
		} while(luachon);
}

