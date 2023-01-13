// =============================================================
															
// 	  		    	Proyek ini dikembangkan dengan menggunakan
//                  Tujuan dari proyek ini adalah untuk mengembangkan sebuah sistem manajemen inventaris yang 
                    //dapat digunakan untuk mengelola stok produk secara efisien dan akurat dengan menggunakan bahasa pemrograman C++ dan struktur data stack. Fungsi-fungsi yang diterapkan dalam sistem termasuk menambahkan produk baru, menghapus produk, memodifikasi detail produk, dan menampilkan produk yang tersedia. Tujuan dari proyek ini adalah untuk membantu perusahaan dalam meningkatkan efisiensi operasional dan meningkatkan kepuasan pelanggan. 


															
															
// 					Oleh : Reyhanssan Islamey
//                  Nim  : 2200018411
//                  Kelas : I

															
															
// =============================================================  
    #include <bits/stdc++.h> 
    // #include <cstddef>
    // #include <iostream>
    // #include "antrian1.h"


    using namespace std; 
    

    struct troli
    {
        int data;
        troli* link;
    };
        
    struct troli* atas = NULL; 

    //    troli* atas = NULL;

    void masuk(int data)
    {
        struct troli* temp;
        temp = new troli;
    //    keranjang *temp = new keranjang();

        if (!temp)
    {
        cout << "Overflow heap";
        exit(1);
    }

            temp->data = data;

            temp->link = atas;

            atas = temp;

    } 
    
    int inikosong()
    {
        return atas == NULL;
    }
    
    int peek()
    {
        if (!inikosong())
            return atas->data;
        else
            exit(1);
    }


    void keluarkan() 
    { 
        struct troli* temp; 

        
        if (atas == NULL)
    {
        cout << "\nStack" << endl;
        exit(1);
    }
    else{
        temp = atas;
        atas = atas->link;
        temp->link = NULL;

        free(temp);
        }
        cout << "Data yang di keluarkan: " << atas->data << endl;
        cout << "                  ___" << endl;
        cout << "                 /  |" << endl;
        cout << "  ______________/   --" << endl;
        cout << " |___/__ /___/_|     " << endl;
        cout << " |__/___/___/__|     " << endl;
        cout << " |_/___/___/___|     " << endl;
        cout << "    _______/         " << endl;
        cout << "     O   O           " << endl;
    }

    //void tulisNota(){
    //    ofstream notaBelanja;
    //    notaBelanja.open("nota.txt");
    //    struct node *p = head;
    //    	notaBelanja << "Nota Belanja\n\n";
    //   		notaBelanja << "ID\tNama Produk\tHarga\tJumlah\n";
    //    while(p != NULL){
    //        notaBelanja << p->ID << "\t" << p->nama_produk << "\t" << p->harga << "\t" << p->jumlah << "\n";
    //        p = p->berikut;
    //    }
    //    notaBelanja.close();
    //    cout << "Nota telah tersimpan dalam file nota.txt" << endl;
    //}



    void tampilkan_stack() 
    { 
        struct troli* temp; 

        if (atas == NULL)
    {
        cout << "Stack" << endl;
        exit(1);
    }
    else
    {
        temp = atas;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        }
    } 
