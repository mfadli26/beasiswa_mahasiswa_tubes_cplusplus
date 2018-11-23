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
    int menu_3;
    int menu_4;
    string hpus_beasiswa;
    string hpus_mahasiswa;
    system("cls");
    cout<<"|                    Beasiswa Dan Mahasiswa                     |"<<endl<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"                        | Menu  |"<<endl<<endl;
    cout<<" 1. Tambah Data Beasiswa Dan Mahasiswa"<<endl;
    cout<<" 2. Lihat Data Beasiswa Dan Mahasiswa"<<endl;
    cout<<" 3. Cari Data Beasiswa Dan Mahasiswa"<<endl;
    cout<<" 4. Hapus Data Beasiswa Dan Mahasiswa"<<endl;
    cout<<" 5. Update Data Beasiswa Dan Mahasiswa"<<endl;
    cout<<" 6. Tambah Beasiswa Ke Mahasiswa"<<endl;
    cout<<" 7. Lihat Mahasiswa Yang Mendapatkan Beasiswa"<<endl;
    cout<<" 8. Hapus Beasiswa Yang Dimiliki Mahasiswa"<<endl;
    cout<<" 9. Lihat Mahasiswa Dengan Beasiswa Terbanyak Dan Tersedikit"<<endl;
    cout<<" 10. Quit                 "<<endl;
    cout<<"-===============================================================-"<<endl;
    cout<<"Masukan Pilihan Anda : ";cin>>pilihan;
    switch(pilihan){
        case 1:{
            menu_satu:
            system("cls");
            cout<<" Menu Tambah Data "<<endl;
            cout<<" 1.Tambah Data Beasiswa "<<endl;
            cout<<" 2.Tambah Data Mahasiswa "<<endl;
            cout<<" 3.Back"<<endl;
            cout<<"Masukan Pilihan Anda : ";cin>>menu_1;
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
            cout<<"       Menu Lihat Data "<<endl;
            cout<<"---------------------------"<<endl<<endl;
            cout<<" 1.Lihat Data Beasiswa "<<endl;
            cout<<" 2.Lihat Data Mahasiswa "<<endl;
            cout<<" 3.Back"<<endl;
            cout<<"Masukan Pilihan Anda : ";cin>>menu_2;
            if(menu_2 == 1){
                system("cls");
                cout<<"               Data Beasiswa"<<endl;
                cout<<"-------------------------------------------"<<endl;
                printBeasiswa(Lbeasiswa);
                cout<<endl<<"Back to menu...";
                getche();
                goto menu_dua;
            }
            else if(menu_2 == 2){
                system("cls");
                cout<<"               Data Mahasiswa"<<endl;
                cout<<"--------------------------------------------"<<endl;
                printMahasiswa(Lmahasiswa);
                cout<<endl<<"Back to menu...";
                getche();
                goto menu_dua;
            }
            else if(menu_2 == 3){
                goto menu_awal;
            }
            else{
                cout<<"Pilihan Menu Salah"<<endl;
                getche();
                goto menu_dua;
            }
        }

        case 3:{
            menu_tiga:
            system("cls");
            cout<<"Menu Pencarian Data Beasiswa Dan Mahasiswa"<<endl;
            cout<<"-=========================================-"<<endl;
            cout<<" 1. Cari Data Beasiswa"<<endl;
            cout<<" 2. Cari Data Mahasiswa"<<endl;
            cout<<" 3. Back"<<endl;
            cout<<"___________________________________________"<<endl;
            cout<<"Masukkan Pilihan Anda : ";cin>>menu_3;
            if(menu_3 == 1){
                system("cls");
                cout<<"         Pencarian Data Beasiswa"<<endl;
                cout<<"========================================"<<endl;
                cout<<"Masukkan Jenis Beasiswa : ";cin>>infoB.jenis;
                address_beasiswa Cari_B = findBeasiswa(Lbeasiswa, infoB);
                if(Cari_B != NULL){
                    system("cls");
                    cout<<"         Pencarian Data Beasiswa"<<endl;
                    cout<<"========================================"<<endl;
                    cout<<"Jenis : "<<info(Cari_B).jenis<<endl;
                    cout<<"Tahun : "<<info(Cari_B).tahun<<endl<<endl;
                    cout<<"Data Ditemukan"<<endl;
                    cout<<"Klik [Enter] Untuk Kembali...."<<endl;
                    getche();
                    goto menu_tiga;
                }
                else{
                    system("cls");
                    cout<<"         Pencarian Data Beasiswa"<<endl;
                    cout<<"========================================"<<endl;
                    cout<<"Jenis Beasiswa Yang Anda Cari Tidak Ditemukan"<<endl<<endl<<endl;
                    cout<<"Klik [Enter] Untuk Kembali...."<<endl;
                    getche();
                    goto menu_tiga;
                }

            }
            else if(menu_3 == 2){
                system("cls");
                cout<<"         Pencarian Data Mahasiswa"<<endl;
                cout<<"========================================"<<endl;
                cout<<"Masukkan Nama Mahasiswa : ";cin>>infoM.nama;
                address_mahasiswa Cari_M = findMahasiswa(Lmahasiswa, infoM);
                if(Cari_M != NULL){
                    system("cls");
                    cout<<"         Pencarian Data Beasiswa"<<endl;
                    cout<<"========================================"<<endl;
                    cout<<"Nama : "<<info(Cari_M).nama<<endl;
                    cout<<"Nim : "<<info(Cari_M).nim<<endl<<endl;
                    cout<<"Data Ditemukan"<<endl;
                    cout<<"Klik [Enter] Untuk Kembali...."<<endl;
                    getche();
                    goto menu_tiga;
                }
                else{
                    system("cls");
                    cout<<"         Pencarian Data Beasiswa"<<endl;
                    cout<<"========================================"<<endl;
                    cout<<"Nama Mahasiswa Yang Anda Cari Tidak Ditemukan"<<endl<<endl<<endl;
                    cout<<"Klik [Enter] Untuk Kembali...."<<endl;
                    getche();
                    goto menu_tiga;
                }
            }
            else if(menu_3 == 3){
                goto menu_awal;
            }
            else{
                cout<<"Menu Yang Anda Pilih Salah..."<<endl;
                getche();
                goto menu_tiga;
            }
        }

        case 4:{
            menu_empat:
            system("cls");
            cout<<" Menu Hapus Data Beasiswa Dan Mahasiswa"<<endl;
            cout<<"======================================="<<endl;
            cout<<" 1. Hapus Data Beasiswa"<<endl;
            cout<<" 2. Hapus Data Mahasiswa"<<endl;
            cout<<" 3. Back"<<endl;
            cout<<"_______________________________________"<<endl;
            cout<<"Masukkan Pilihan Anda : ";cin>>menu_4;
            if( menu_4 == 1){
                system("cls");
                cout<<"       Hapus Data Beasiswa"<<endl;
                cout<<"================================="<<endl;
                cout<<"Masukkuan Jenis Beasiswa :";cin>>infoB.jenis;
                cout<<endl;
                address_beasiswa cari_hapus_beasiswa = findBeasiswa(Lbeasiswa, infoB);
                if(cari_hapus_beasiswa != NULL){
                    system("cls");
                    cout<<"       Hapus Data Beasiswa"<<endl;
                    cout<<"================================="<<endl;
                    cout<<"Data Ditemukan"<<endl;
                    cout<<"Jenis Beasiswa : "<<info(cari_hapus_beasiswa).jenis<<endl;
                    cout<<"Tahun Beasiswa : "<<info(cari_hapus_beasiswa).tahun<<endl<<endl;
                    cout<<"Apakah Anda Yakin Menghapus Data Beasiswa? [y/n] : ";cin>>hpus_beasiswa;
                    if(hpus_beasiswa == "y" or hpus_beasiswa == "Y"){
                        deleteBeasiswa(Lbeasiswa, cari_hapus_beasiswa);
                        cout<<"Data Beasiswa Berhasil Dihapus"<<endl;
                        getche();
                        goto menu_empat;
                    }
                    else{
                        goto menu_empat;
                    }
                }
                else{
                    cout<<"Data Tidak Ditemukan atau List Kosong...";
                    getch();
                    goto menu_empat;
                }
            }
            else if(menu_4 == 2){
                cout<<"       Hapus Data Mahasiswa"<<endl;
                cout<<"================================="<<endl;
                cout<<"Masukkuan Nama Mahasiswa :";cin>>infoM.nama;
                cout<<endl;
                address_mahasiswa cari_hapus_mahasiswa = findMahasiswa(Lmahasiswa, infoM);
                if(cari_hapus_mahasiswa != NULL){
                    system("cls");
                    cout<<"       Hapus Data Mahasiswa"<<endl;
                    cout<<"================================="<<endl;
                    cout<<"Data Ditemukan"<<endl;
                    cout<<"Nama Mahasiswa : "<<info(cari_hapus_mahasiswa).nama<<endl;
                    cout<<"Nim Mahasiswa : "<<info(cari_hapus_mahasiswa).nim<<endl<<endl;
                    cout<<"Apakah Anda Yakin Menghapus Data Mahasiswa? [y/n] : ";cin>>hpus_mahasiswa;
                    if(hpus_mahasiswa== "y" or hpus_mahasiswa== "Y"){
                        deleteMahasiswa(Lmahasiswa, cari_hapus_mahasiswa);
                        cout<<"Data Mahasiswa Berhasil Dihapus"<<endl;
                        getche();
                        goto menu_empat;
                    }
                    else{
                        goto menu_empat;
                    }
                }
                else{
                    cout<<"Data Tidak Ditemukan atau List Kosong...";
                    getch();
                    goto menu_empat;
                }
            }
            else if(menu_4 == 3){
                goto menu_awal;
            }
            else{
                cout<<"Menu Yang Anda Pilih Salah..."<<endl;
                getche();
                goto menu_empat;
            }
        }

        case 5:{

        }

        case 6:{

        }

        case 7:{

        }

        case 8:{
            exit(0);
        }
    }
}
