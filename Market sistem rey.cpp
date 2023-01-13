    #include <iostream>
    #include <string>
    #include <sstream>
    #include <bits/stdc++.h>
    #include <windows.h>
    #include <fstream>
    #include "antrian.h"
    #include "animasi.h"
    #include "keranjang.h"

    using namespace std;

    int cari(int);
    int display();
    string cek(int);

    struct node
    {
        int ID;
        string nama_produk;
        double harga;
        int jumlah;
        struct node* berikut;
    };

    struct node* head = NULL;

    void beg()
    {
    system("cls");
        int id, jumlah;
        string nama;
        double harga;
        struct node *t = new node;
        struct node *p = head;

        cout << "\t\t\tMasukkan ID produk: ";
        cin >> id;
        t->ID = id;
        cout << "\t\t\tMasukkan nama produk: ";
        cin >> nama;
        t->nama_produk = nama;
        cout << "\t\t\tMasukkan harga produk: ";
        cin >> harga;
        t->harga = harga;
        cout << "\t\t\tMasukkan jumlah produk: ";
        cin >> jumlah;
        t->jumlah = jumlah;

    if (head == NULL)
    {
        t->berikut = head;
        head = t;
    }
    else
    {
        while (p->berikut != NULL)
        {
            p = p->berikut;
        }
        p->berikut = t;
        t->berikut = NULL;
    }

        system("cls");
        cout<<"\n\n\t\t\t\tProduk telah dimasukkan!\n\n\n";

        }

        int cari(int id)
    {
    int hitung = 1;
        struct node *p = head;
        while (p != NULL){
            if (p->ID == id)
            break;
            else
            hitung++;
            p = p->berikut;
            }
        return hitung;
        }

    int hash(int x, int mod){
        return x % mod;
    }

        void hapusProduk()
    {
        system("cls");
            display();
        int id;
        struct node *sekarang = head;
        struct node *sebelumnya = head;
            cout << "\n\nMasukkan ID untuk menghapus produk tersebut:\n\n";
            cin >> id;
            if (head == NULL){
                system("cls");
                cout << "Daftar kosong" << endl;
            }
            int posisi = 0;
            int hitung = display();
        posisi = cari(id);
        if (posisi <= hitung)
        {
            while (sekarang->ID != id)
        {
                sebelumnya = sekarang;
                sekarang = sekarang->berikut;
        }
        sebelumnya->berikut = sekarang->berikut;
        system("cls");
        cout << "\n<< produk dihapus >>\n";
        }
        else
        {
        cout << "\n<<< Tidak ditemukan >>\n\n";
        }
    }

    void ubah()
    {
        int id;
        double hargabaru;
        string namaProduk;
        int idBaru;
        int jumlahBaru;
        if (head == NULL){
            system("cls");
            cout << "Daftar kosong" << endl;
        }else{
            display();
            cout << "\n\nMasukkan ID untuk mengubah nama produk dan harganya:\n";
            cin >> id;
            struct node *sekarang = head;
        int posisi = 0;
        int hitung = display();
        posisi = cari(id);

            if(posisi<=hitung)
        {
            while(sekarang->ID!=id)
            {
                sekarang=sekarang->berikut;
            }
            cout<<"\n============Data sebelumnya============="<<endl;
            cout<<"\n ID : "<<sekarang->ID<<endl;
            cout<<"\n Nama : "<<sekarang->nama_produk<<endl;
            cout<<"\n Harga : "<<sekarang->harga<<endl;
            cout<<"\n Jumlah : "<<sekarang->jumlah<<endl;

            cout<<endl<<endl;
            cout<<"Masukan ID baru:";
            cin>>idBaru;
            sekarang->ID=idBaru;
            cout<<"Masukan Nama baru:";
            cin>>namaProduk;
            sekarang->nama_produk=namaProduk;
            cout<<"Masukan harga baru:";
            cin>>hargabaru;
            sekarang->harga=hargabaru;
            cout<<"Masukan jumlah baru:";
            cin>>jumlahBaru;
            sekarang->jumlah=jumlahBaru;
        }

            else
        {
            cout<<id<<" Tidak <<ditemukan>>\n\n";
        }
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////

    int display()
    {
        system("cls");
        int jumlah = 0;
        struct node *p = head;
            cout << "Produk yang tersedia: \n";
            cout << "ID\t\tNama Produk\t\tHarga\t\tJumlah\n";
            cout << "===================================================\n";
        while (p != NULL)
        {
        cout << p->ID << "\t\t" << p->nama_produk << "\t\t\t" << p->harga<< "\t\t\t" << cek(p->jumlah) << "\n";
        p = p->berikut;
        jumlah= jumlah + 1;
        }
        cout << "\nTotal produk di toko kami : " << jumlah << "\n\n\n";
        return jumlah;
    }


    ////////////////////////////////////////////////////////////////////////////////////////
            string cek(int quant)
        {             
            int a = quant;
        stringstream ss;
        ss << a;
        string jumlah = ss.str();

                if(quant<=0)
                    return "Stok habis!";
                else
                    return jumlah;
            }

    ///////////////////////////////////////////////////////////////////////
        void beli()
        {
            system("cls");
            display();
            string products[20];
            
            int bayar=0,no,c=0,price,id,i=1;

            if(head==NULL){
                cout<<"\n<<<<Barang tidak tersedia>>>>\n\n";
            }else{
            cout<<"Berapa banyak barang yang inin di beli?\n";
            cout<<"Masukkan jumlah : ";
            cin>>no; 
            int hitung=display();          
            while (i<=no)
            {
                struct node *sekarang=head;
                int quant,cho;   a:          
                cout<<"Masukan id barang yang ingin di beli : ";
                int id,pos=0;
                cin>>id;
                if(id==-1){system("cls"); return;	}
                pos=cari(id);
                if(pos<=hitung)
            {
            
            while(sekarang->ID!=id)
            {
                sekarang=sekarang->berikut;
            }
            cout<<"Berapa banyak yang ingin di beli :";
            cin>>quant;
            if(sekarang->jumlah < quant)
            {
                cout<<"\n\n\t\t\t----Jumlah yang anda masukan sekarang tidak tersedia!---"<<endl;
                cout<<"\n\t\t\t-----(Tekan -1 untuk kembali ke menu awal)------"<<endl;
                goto a;
                
            }
            products[c]=sekarang->nama_produk; 
            c++;   
            
            bayar=bayar+(sekarang->harga*quant); 
            sekarang->jumlah=sekarang->jumlah-quant;    
            i++;

            }
            else
            {    
                
            cout<<"\n<<<<<<<<<Barang ini tidak tersedia di toko saat ini >>>>\n\n";
            
            }
    }
            string customer;
            cout<<"\n\t\t Masukan namamu :"; cin>>customer;
            enqueue(customer);
            system("cls");
            cout<<"\n\n\n\n\t\t\tBarang belanjaanmu : ";
            for(int i=0;i<no;i++)
        {             
            cout<<products[i]<<",";
        }
            price=bayar*(0.90);          
            cout<<"\n\nHarga barang adalah : "<<bayar;
            cout<<"\n dengan 10% diskon : "<<price<<"\nTerima kasih sudah berbelanja!\n\n";

            ofstream nota;
            nota.open("nota.txt",ios::app);
            if(nota.is_open()){
                nota << "Nota Pembelian\n";
                nota << "Nama Pelanggan: " << customer << "\n";
                nota << "Daftar Barang: ";
            for(int i=0;i<no;i++){             
                nota << products[i] << ",";
            }
            nota << "\nHarga Barang: " << bayar << "\n";
            nota << "Diskon 10%: " << (bayar) * (10/100)  << "\n";
            nota << "Total Bayar: " << price << "\n";
            nota << "Terima kasih sudah berbelanja!\n\n";
            nota.close();
             }else{
            cout << "Gagal membuat nota, periksa kembali file nota.txt" << endl;
            }
         }
            
    }


    /////////////////////////////////////////////////////////////////////////////////////////
        void administator()
        {
            system("cls");
                int ch;
        do {
        cout<<"\t\t============================================"<<endl;
        cout<<"\t\t|          Admin Portal              |"<<endl;
        cout<<"\t\t============================================"<<endl;

        cout<<"\t\t Masukkan 1 untuk menambahkan produk baru "<<endl;
        cout<<"\t\t Masukkan 2 untuk menampilkan semua produk "<<endl;
        cout<<"\t\t Masukkan 3 untuk mengubah produk yang sudah ada"<<endl;
        cout<<"\t\t Masukkan 4 untuk menghapus produk tertentu "<<endl;
        cout<<"\t\t Masukkan 5 untuk melihat daftar pelanggan "<<endl;
        cout<<"\t\t Masukkan 6 untuk mengeluarkan pelanggan dari antrian"<<endl;
        cout<<"\t\t Masukkan 7 untuk menghasilkan hash"<<endl;
        cout<<"\t\t Masukkan 0 untuk kembali ke menu utama"<<endl;
        cout<<"\nMasukkan pilihan Anda >>>"; cin>>ch;

        switch(ch){
        case 1:
        beg();
        break;
    case 2:
        system("cls");
        display();
        break;
    case 3:
        ubah();
        system("cls");
        break;
    case 4:
        hapusProduk();
    cout<<"\n-------Produk sudah Dihapus-------\n";
        break;
    case 5:
        system("cls");
        cout<<"|============LIST NAMA CUSTOMER==============|"<<endl;
        tampilkan_antrian();
        break;
    case 6:
        system("cls");
        cout<<"|============LIST NAMA CUSTOMER==============|"<<endl;
        dequeue();
        tampilkan_antrian();
        break;
    case 7:
                int x,n;
                cout << "Masukkan elemen untuk menghasilkan hash = ";
                cin >> x; cout<<"Dari jumlah total daftar : "; cin>>n;
    //            cout << "Hash dari " << x << " adalah = " << hash(x,n );
                
                break;


    default: system("cls");

        }
    }
    while(ch!=0);
    }


    ////////////////////////////////////////////////////////////////////////////////////
    int main()
    {
        
        for(int i=0;i<=51;i++){
            masuk(i);
        }


        system("color F1");  
        gotoxy(17,5);
        cout<<"--------------------------------------------------"<<endl;
        gotoxy(17,7);
        cout<<"||              Sistem Belanja                   ||"<<endl;
        gotoxy(17,9);
        cout<<"--------------------------------------------------"<<endl;
        gotoxy(17,11);
        cout<<"|Dosen pengampu ->> Bambang Robi'in, S.T., M.T. <<-- |\n"<<endl;
        gotoxy(17,13);
        cout<<">>>----Mahasiswa Informatika-----<<<"<<endl;
        gotoxy(22,15);
        cout<<"Nama : Reyhanssan islamey "<<endl;
        gotoxy(22,16);
        cout<<"Nim  : 2200018411"<<endl;
        gotoxy(22,17);
        cout<<"Kelas: I"<<endl<<endl;
        system("pause");
        system("cls");
        system("color Fc"); 
        int ch;
        while(ch!=3){
        
        cout<<"\n\t\t|--------<Menu Utama>-----------|";
        cout<<"\n\n";
        cout<<"\t\t 1)Admin Toko\n";
        cout<<"\t\t 2)Customer               \n";
        cout<<"\t\t 3)Keluar                    \n";



        cout<<"\nMasukan pilihanmu >>>";cin>>ch;
        switch(ch){
        case 1:
            administator();
            break;

        case 2:
            cout<<endl<<endl;
            keluarkan();
            system("pause");
            beli();
            break;

        case 3:
            cout<<"\n\n\t\t\t\t\tTerima Kasih\t\t\t\t";
            break;
    
        }
    }
    return 0;	
    }