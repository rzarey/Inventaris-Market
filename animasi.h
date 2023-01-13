// =============================================================
															
// 	  		    	Proyek ini dikembangkan dengan menggunakan
//                  Tujuan dari proyek ini adalah untuk mengembangkan sebuah sistem manajemen inventaris yang 
                    //dapat digunakan untuk mengelola stok produk secara efisien dan akurat dengan menggunakan bahasa pemrograman C++ dan struktur data stack. Fungsi-fungsi yang diterapkan dalam sistem termasuk menambahkan produk baru, menghapus produk, memodifikasi detail produk, dan menampilkan produk yang tersedia. Tujuan dari proyek ini adalah untuk membantu perusahaan dalam meningkatkan efisiensi operasional dan meningkatkan kepuasan pelanggan. 


															
															
// 					Oleh : Reyhanssan Islamey
//                  Nim  : 2200018411
//                  Kelas : I

															
															
// =============================================================  
	#include <iostream>
	//#include <windows.h>
	using namespace std;

	COORD coord = {0, 0};
	void gotoxy(int x, int y){
		COORD coord;
		coord.X = x;
		coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void animasi(){
	for(int i=45; i>=1; i--){
		Sleep(30);
		gotoxy(1, i);
	}
	for(int i=1; i<20; i++){
		Sleep(40);
		gotoxy(1, i);
		}
	}