    #include <iostream>
    #include <conio.h>
    #include <bits/stdc++.h>
    //#include <winioctl.h>
    using namespace std;

    struct Node
    {
        string nama;

        Node* berikut;
    //   node* nama;

        };

        Node* depan = NULL;
        Node* belakang = NULL;

    bool kosong()
    {
        if(depan == NULL && belakang == NULL)
        return true;
        else
        return false;
    }

    void enqueue(string nama)
    {
        Node* baru = new Node();
        baru->nama = nama;
        baru->berikut = NULL;

        if(depan == NULL){
            depan = baru;
            belakang = baru;
        }else{
            belakang->berikut = baru;
            belakang = baru;
        }

    }

    void dequeue()
    {
        if(kosong())
            cout<<"Antrian Kosong"<<endl;
        else if(depan == belakang){
            free(depan);
            depan = belakang = NULL;
        }else{
            Node *hapus = depan;
            depan = depan->berikut;
        free(hapus);
        }
    }

    void tampilkan_depan()
    {
        if(kosong())
            cout<<"Antrian Kosong"<<endl;
        else
            cout<<"Elemen di depan: "<<depan->nama<<endl;
    }

    void tampilkan_antrian()
    {
        if(kosong())
            cout<<"Antrian Kosong"<<endl;
        else{
            Node* pos = depan;
            while(pos != NULL)
        {
            cout<<"\t"<<pos->nama<<endl;
            pos = pos->berikut;
            }
        }
    }


