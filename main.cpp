#include <iostream>
#include <conio.h>
#include <dos.h>
#include <cstdlib>
#include "link_list.cpp"

using namespace std;

int main()
{
    int pilihan;
    list_beasiswa Lbeasiswa;
    list_mahasiswa Lmahasiswa;
    infotype_beasiswa info_beasiswa;
    infotype_mahasiswa info_mahasiswa;
    CreateBeasiswa(Lbeasiswa);
    CreateMahasiswa(Lmahasiswa);
    infotype_beasiswa infoB;
    infotype_mahasiswa infoM;
    menu_awal:
    int menu_1;
    int menu_2;
    system("cls");
    cout<<"|                Beasiswa Dan Mahasiswa                |"<<endl<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"|                       | Menu  |"<<endl<<endl;
    cout<<"| 1. Tambah Data Beasiswa Dan Mahasiswa"<<endl;
    cout<<"| 2. Lihat Data Beasiswa Dan Mahasiswa"<<endl;
    cout<<"| 3. Hapus Data Beasiswa Dan Mahasiswa"<<endl;
    cout<<"| 4. Tambah Beasiswa Ke Mahasiswa"<<endl;
    cout<<"| 5. Lihat Mahasiswa Yang Mendapatkan Beasiswa"<<endl;
    cout<<"| 6. Hapus Beasiswa Yang Dimiliki Mahasiswa"<<endl;
    cout<<"| 7. Lihat Mahasiswa Dengan Beasiswa Paling Banyak"<<endl;
    cout<<"| 8. Lihat Mahasiswa Dengan Beasiswa Paling Sedikit"<<endl;
    cout<<"| 9. Quit                 "<<endl;
    cout<<"-=====================================================-"<<endl;
    cout<<"Masukan Pilihan Anda --> ";cin>>pilihan;
    switch(pilihan){
        case 1:{
            menu_satu:
            system("cls");
            cout<<" Menu Tambah Data "<<endl;
            cout<<" 1.Tambah Data Beasiswa "<<endl;
            cout<<" 2.Tambah Data Mahasiswa "<<endl;
            cout<<" 3.Back"<<endl;
            cout<<"Masukan Pilihan Anda --> ";cin>>menu_1;
            if(menu_1 == 1){
                system("cls");
                cout<<"Tambah Data Beasiswa"<<endl;
                cout<<"--------------------"<<endl;
                cout<<"Jenis Beasiswa : ";cin>>infoB.jenis;
                cout<<"Tahun          : ";cin>>infoB.tahun;
                address_beasiswa cek_ketersediaanData = findBeasiswa(Lbeasiswa, infoB);
                if(cek_ketersediaanData == NULL){
                    insertBeasiswa(Lbeasiswa, alokasiBeasiswa(infoB));
                    cout<<"Data Berhasil Dimasukkan"<<endl;
                    getche();
                    goto menu_awal;
                }
                else{
                    cout<<"Beasiswa Yang Anda Masukkan Sudah Ada"<<endl;
                    getche();
                    goto menu_satu;
                }
            }
            else if(menu_1 == 2){
                system("cls");
                cout<<"Tambah Data Mahasiswa"<<endl;
                cout<<"--------------------"<<endl;
                cout<<"Nama Mahasiswa : ";cin>>infoM.nama;
                cout<<"Nim            : ";cin>>infoM.nim;
                address_mahasiswa cek_ketersediaanData = findMahasiswa(Lmahasiswa, infoM);
                if(cek_ketersediaanData == NULL){
                    insertMahasiswa(Lmahasiswa, alokasiMahasiswa(infoM));
                    cout<<"Data Berhasil Dimasukkan"<<endl;
                    getche();
                    goto menu_awal;
                }
                else{
                    cout<<"Beasiswa Yang Anda Masukkan Sudah Ada"<<endl;
                    getche();
                    goto menu_satu;
                }
            }
            else if(menu_1 == 3){
                goto menu_awal;
            }
            else{
                cout<<"Pilihan Menu Salah"<<endl;
                getche();
                goto menu_satu;
            }
        }

        case 2:{
            menu_dua:
            system("cls");
            cout<<" Menu Lihat Data "<<endl;
            cout<<" 1.Lihat Data Beasiswa "<<endl;
            cout<<" 2.Lihat Data Mahasiswa "<<endl;
            cout<<" 3.Back"<<endl;
            cout<<"Masukan Pilihan Anda --> ";cin>>menu_2;
            if(menu_2 == 1){
                system("cls");
                cout<<"Data Beasiswa"<<endl;
                printBeasiswa(Lbeasiswa);
                cout<<endl<<"Back to menu...";
                getche();
                goto menu_awal;
            }
            else if(menu_2 == 2){
                system("cls");0

                cout<<"Data Mahasiswa"<<endl;
                printMahasiswa(Lmahasiswa);
                cout<<endl<<"Back to menu...";
                getche();
                goto menu_awal;
            }
            else if(menu_2 == 3){
                goto menu_awal;
            }
            else{
                cout<<"Pilihan Menu Salah"<<endl;
                getche();
                goto menu_satu;
            }
        }

        case 3:{

        }

        case 4:{

        }

        case 5:{

        }

        case 6:{

        }

        case 7:{

        }

        case 8:{

        }

        case 9:{

        }
    }
}
