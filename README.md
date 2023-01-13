# Inventaris-Market

Reyhanssan islamey

Kode ini menggunakan sepenuhnya bahasa c++ yang di implementasikan ke dalam sebuah sitem kasir, yang nantinya sistem ini aka memiliki 2 pengguna utama. 
Yang pertama adalah admin atau dia yang memiliki wewenang untuk memanipulasi merubash serta menghapus daftar barang yang ada didalamnya sesuai dengan kedaan sesungguhnya di lokasi.
yang kedua adalah customer atau pelanggan adalah dia yang hanya memiliki wewenang untuk membeli arang di dalammarekt tersebut. 

Kode ini adalah sebuah program yang ditulis dalam bahasa pemrograman C++. Program ini  adalah sebuah sistem manajemen inventaris yang memungkinkan pengguna untuk menambahkan, menghapus dan memodifikasi produk. Program ini menggunakan struktur data linked list untuk menyimpan produk. Fungsi-fungsi dalam program ini meliputi:
•	beg(): Fungsi ini digunakan untuk menambahkan produk baru ke inventaris. Ini mengambil input pengguna untuk ID produk, nama, harga dan jumlah, dan menciptakan sebuah node baru dalam linked list dengan informasi ini.
•	cari(int id): Fungsi ini digunakan untuk mencari produk dalam inventaris dengan ID-nya. Ini mengambil parameter integer, ID produk yang akan dicari, dan mengembalikan posisi produk dalam linked list.
•	hapusProduk(): Fungsi ini digunakan untuk menghapus produk dari inventaris. Ini mengambil input pengguna untuk ID produk yang akan dihapus dan mencari di linked list. Jika ditemukan, menghapus node dari daftar dan memperbarui daftar.
•	ubah(): Fungsi ini digunakan untuk memodifikasi detail produk dalam inventaris. Ini mengambil input pengguna untuk ID produk yang akan diubah dan mencari di linked list. Jika ditemukan, memungkinkan pengguna untuk memperbarui nama, harga, ID dan jumlah produk.
•	display(): Fungsi ini digunakan untuk menampilkan produk dalam inventaris. Ini menampilkan ID, nama, harga dan jumlah semua produk dalam linked list.
Kode ini juga memiliki beberapa pernyataan include, yang membawa perpustakaan eksternal dan file header seperti "iostream", "string", "sstream", "bits/stdc++.h", "windows.h", "fstream", "antrian.h", "animasi.h" dan "keranjang.h". Perpustakaan dan file header ini menyediakan fungsi tambahan yang dapat digunakan program.
