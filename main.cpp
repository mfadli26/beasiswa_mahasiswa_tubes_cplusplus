#include <iostream>
#include <conio.h>
#include <dos.h>
#include <cstdlib>
#include "link_list.cpp"
#include "link_list_relasi.cpp"

using namespace std;

int main()
{

    int pilihan;
    list_beasiswa Lbeasiswa;
    list_mahasiswa Lmahasiswa;
    relasi_list Lrelasi;
    infotype_beasiswa info_beasiswa;
    infotype_mahasiswa info_mahasiswa;
    CreateBeasiswa(Lbeasiswa);
    CreateMahasiswa(Lmahasiswa);
    CreateListRelasi(Lrelasi);
    infotype_beasiswa infoB;
    infotype_mahasiswa infoM;
    infoB.jenis = "penuh";
    infoB.tahun = 2001;
    insertBeasiswa(Lbeasiswa, alokasiBeasiswa(infoB));
    infoM.nama = "ucok";
    infoM.nim = "13109p";
    infoM.angkatan = "2006";
    infoM.jurusan = "Bisnis";
    infoM.asal = "Jogja";
    insertMahasiswa(Lmahasiswa, alokasiMahasiswa(infoM));
    menu_awal:
    int menu_1;
    int menu_2;
    int menu_3;
    int menu_4;
    int menu_5;
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
    cout<<" 9. Update Relasi Beasiswa Yang Dimiliki Mahasiswa"<<endl;
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
                cout<<"Nama Mahasiswa     : ";cin>>infoM.nama;
                cout<<"Nim Mahasiswa      : ";cin>>infoM.nim;
                cout<<"Jurusan Mahasiswa  : ";cin>>infoM.jurusan;
                cout<<"Angkatan Mahasiswa : ";cin>>infoM.angkatan;
                cout<<"Asal Mahasiswa     : ";cin>>infoM.asal;
                address_mahasiswa cek_ketersediaanData = findMahasiswa(Lmahasiswa, infoM);
                if(cek_ketersediaanData == NULL){
                    insertMahasiswa(Lmahasiswa, alokasiMahasiswa(infoM));
                    cout<<"Data Berhasil Dimasukkan"<<endl;
                    getche();
                    goto menu_awal;
                }
                else{
                    cout<<"Mahasiswa Yang Anda Masukkan Sudah Ada"<<endl;
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
                    cout<<"         Pencarian Data Mahasiswa"<<endl;
                    cout<<"========================================"<<endl;
                    cout<<"Nama     : "<<info(Cari_M).nama<<endl;
                    cout<<"Nim      : "<<info(Cari_M).nim<<endl;
                    cout<<"Angkatan : "<<info(Cari_M).angkatan<<endl;
                    cout<<"Jurusan  : "<<info(Cari_M).jurusan<<endl;
                    cout<<"Asal     : "<<info(Cari_M).asal<<endl<<endl;
                    cout<<"Data Ditemukan"<<endl;
                    cout<<"Klik [Enter] Untuk Kembali....";
                    getche();
                    goto menu_tiga;
                }
                else{
                    system("cls");
                    cout<<"         Pencarian Data Mahasiswa"<<endl;
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
                        deleteSemuaRelasiBeasiswa(Lrelasi, cari_hapus_beasiswa);
                        deleteBeasiswa(Lbeasiswa, cari_hapus_beasiswa);
                        cout<<"Data Beasiswa Berhasil Dihapus"<<endl;
                        getche();
                        goto menu_empat;
                    }
                    else{
                        cout<<"Pilihan Yang Anda Masukkan Salah....";
                        getch();
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
                    cout<<"Nama Mahasiswa       : "<<info(cari_hapus_mahasiswa).nama<<endl;
                    cout<<"Nim Mahasiswa        : "<<info(cari_hapus_mahasiswa).nim<<endl;
                    cout<<"Jurusan Mahasiswa    : "<<info(cari_hapus_mahasiswa).jurusan<<endl;
                    cout<<"Angkatan Mahasiswa   : "<<info(cari_hapus_mahasiswa).angkatan<<endl;
                    cout<<"Asal Mahasiswa       : "<<info(cari_hapus_mahasiswa).asal<<endl<<endl;
                    cout<<"Apakah Anda Yakin Menghapus Data Mahasiswa? [y/n] : ";cin>>hpus_mahasiswa;
                    if(hpus_mahasiswa== "y" or hpus_mahasiswa== "Y"){
                        deleteSemuaRelasiMahasiswa(Lrelasi, cari_hapus_mahasiswa);
                        deleteMahasiswa(Lmahasiswa, cari_hapus_mahasiswa);
                        cout<<"Data Mahasiswa Berhasil Dihapus"<<endl;
                        getche();
                        goto menu_empat;
                    }
                    else{
                        cout<<"Pilihan Yang Anda Masukkan Salah....";
                        getch();
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
            menu_lima:
            system("cls");
            cout<<" Menu Tambah Data "<<endl;
            cout<<" 1.Update Data Beasiswa "<<endl;
            cout<<" 2.Update Data Mahasiswa "<<endl;
            cout<<" 3.Back"<<endl;
            cout<<"Masukan Pilihan Anda : ";cin>>menu_5;
            if(menu_5 == 1){
                system("cls");
                cout<<"Update Data Beasiswa"<<endl;
                cout<<"--------------------"<<endl;
                cout<<"Jenis Beasiswanya ? ";cin>>infoB.jenis;
                address_beasiswa B = findBeasiswa(Lbeasiswa, infoB);
                if(B != NULL){
                    cout<<"       Update Data Beasiswa"<<endl;
                    cout<<"================================="<<endl;
                    cout<<"Data Ditemukan"<<endl;
                    cout<<"Jenis Beasiswa Menjadi : ";cin>>infoB.jenis;
                    cout<<"Tahun Beasiswa  Manjadi: ";cin>>infoB.tahun;cout<<endl;
                    address_beasiswa cek_ketersediaanData = findBeasiswa(Lbeasiswa, infoB);
                    if(cek_ketersediaanData != NULL){
                        cout<<"Jenis Beasiswa Yang Anda Masukkan Sudah Ada"<<endl;
                        getche();
                        goto menu_lima;
                    }
                    updateDataBeasiswa(B, infoB);
                    cout<<"Data Berhasil Diupdate"<<endl;
                    getche();
                    goto menu_awal;
                }
                else{
                    cout<<"Beasiswa Yang Anda Masukkan Tidak Ada"<<endl;
                    getche();
                    goto menu_lima;
                }
            }
            else if(menu_5 == 2){
                system("cls");
                cout<<"Update Data Mahasiswa"<<endl;
                cout<<"--------------------"<<endl;
                cout<<"Nama Mahasiswanya ? ";cin>>infoM.nama;
                address_mahasiswa M = findMahasiswa(Lmahasiswa, infoM);
                if(M != NULL){
                    cout<<"       Update Data Mahasiswa"<<endl;
                    cout<<"================================="<<endl;
                    cout<<"Data Ditemukan"<<endl;
                    cout<<"Nama Mahasiswanya Menjadi : ";cin>>infoM.nama;
                    cout<<"Nim Mahasiswanya Manjadi  : ";cin>>infoM.nim;
                    cout<<"Jurusan Mahasiswanya Manjadi  : ";cin>>infoM.jurusan;
                    cout<<"Angkatan Mahasiswanya Manjadi  : ";cin>>infoM.angkatan;
                    cout<<"Asal Mahasiswanya Manjadi  : ";cin>>infoM.asal;cout<<endl;
                    address_mahasiswa cek_ketersediaanData = findMahasiswa(Lmahasiswa, infoM);
                    if(cek_ketersediaanData != NULL){
                        cout<<"Nama Mahasiswa Yang Anda Masukkan Sudah Ada"<<endl;
                        getche();
                        goto menu_lima;
                    }
                    updateDataMahasiswa(M, infoM);
                    cout<<"Data Berhasil Diupdate"<<endl;
                    getche();
                    goto menu_awal;
                }
                else{
                    cout<<"Nama Mahasiswa Yang Anda Masukkan Tidak Ada"<<endl;
                    getche();
                    goto menu_lima;
                }
            }
            else if(menu_5 == 3){
                goto menu_awal;
            }
            else{
                cout<<"Pilihan Menu Salah"<<endl;
                getche();
                goto menu_lima;
            }
        }

        case 6:{
            system("cls");
            cout<<" Tambah Mahasiswa Yang Mendapatkan Beasiswa "<<endl;
            cout<<"---------------------------"<<endl<<endl;
            printBeasiswaRelasiMahasiswa(Lbeasiswa, Lrelasi);
            cout<<" Beasiswa mana yang akan dipilih (jenis) : ";cin>>infoB.jenis;
            address_beasiswa cari_beasiswa = findBeasiswa(Lbeasiswa, infoB);
            if(cari_beasiswa){
                printBeasiswaRelasiTertentu(Lrelasi, cari_beasiswa);
                cout<<" Akan Menampilkan Mahasiswa";
                getch();
                cout<<endl<<endl;
                printMahasiswa(Lmahasiswa);
                cout<<endl<<" Mahasiswa mana yang akan dipilih (Nama) : ";cin>>infoM.nama;
                address_mahasiswa cari_mahasiswa = findMahasiswa(Lmahasiswa, infoM);
                if(cari_mahasiswa){
                    address_relasi cari_relasi = findRelasi(Lrelasi, cari_beasiswa, cari_mahasiswa);
                    if(cari_relasi){
                        cout<<endl<<" Beasiswa tidak dapat dua kali, Mahasiswa telah lebih dulu memiliki Beasiswa";
                        getch();
                        goto menu_awal;
                    }
                    insertRelasi(Lrelasi, alokasiRelasi(cari_beasiswa, cari_mahasiswa));
                    cout<<endl<<" Beasiswa telah ditambahkan ke mahasiswa";
                    getch();
                    goto menu_awal;
                }
            }
            cout<<" Data Tidak Ditemukan ";
            getch();
            goto menu_awal;
        }

        case 7:{
            system("cls");
            cout<<" Lihat Mahasiswa Yang Mendapatkan Beasiswa "<<endl;
            cout<<"---------------------------"<<endl<<endl;
            printBeasiswaRelasiMahasiswa(Lbeasiswa, Lrelasi);
            cout<<" Press any key to back ";
            getch();
            goto menu_awal;
        }
        case 8:{
            system("cls");
            cout<<" Hapus Beasiswa Yang Dimiliki Mahasiswa "<<endl;
            cout<<"---------------------------"<<endl<<endl;
            printBeasiswaRelasiMahasiswa(Lbeasiswa, Lrelasi);
            cout<<" Beasiswa mana yang akan dipilih (jenis) : ";cin>>infoB.jenis;
            address_beasiswa cari_beasiswa = findBeasiswa(Lbeasiswa, infoB);
            if(cari_beasiswa){
                printBeasiswaRelasiTertentu(Lrelasi, cari_beasiswa);
                cout<<" Akan Menampilkan Mahasiswanya";
                getch();
                cout<<endl<<endl;
                printBeasiswaYangDimilikiMahasiswa(Lrelasi, cari_beasiswa);
                cout<<endl<<" Mahasiswa mana yang akan dipilih (Nama) : ";cin>>infoM.nama;
                address_mahasiswa cari_mahasiswa = findMahasiswa(Lmahasiswa, infoM);
                if(cari_mahasiswa){
                    address_relasi cari_relasi = findRelasi(Lrelasi, cari_beasiswa, cari_mahasiswa);
                    deleteRelasi(Lrelasi, cari_relasi);
                    cout<<endl<<" Beasiswa telah dihapus dari mahasiswa";
                    getch();
                    goto menu_awal;
                }
            }
            cout<<" Data Tidak Ditemukan ";
            getch();
            goto menu_awal;
        }
        case 9:{
            system("cls");
            cout<<" Update Relasi Beasiswa Yang Dimiliki Mahasiswa "<<endl;
            cout<<"------------------------------------------------"<<endl<<endl;
            printBeasiswaRelasiMahasiswa(Lbeasiswa, Lrelasi);
            cout<<" Beasiswa mana yang akan dipilih (jenis) : ";cin>>infoB.jenis;
            address_beasiswa cari_beasiswa = findBeasiswa(Lbeasiswa, infoB);
            if(cari_beasiswa){
                printBeasiswaRelasiTertentu(Lrelasi, cari_beasiswa);
                cout<<" Akan Menampilkan Mahasiswanya";
                getch();
                cout<<endl<<endl;
                printBeasiswaYangDimilikiMahasiswa(Lrelasi, cari_beasiswa);
                cout<<endl<<" Mahasiswa mana yang akan digantikan (Nama) : ";cin>>infoM.nama;
                address_mahasiswa cari_mahasiswa = findMahasiswa(Lmahasiswa, infoM);
                if(cari_mahasiswa){
                    printMahasiswa(Lmahasiswa);
                    cout<<endl<<" Mahasiswa mana yang akan dipilih (Nama) : ";cin>>infoM.nama;
                    address_mahasiswa cari_mahasiswa2 = findMahasiswa(Lmahasiswa, infoM);
                    if(cari_mahasiswa2){
                        address_relasi cari_relasi = findRelasi(Lrelasi, cari_beasiswa, cari_mahasiswa);
                        address_relasi cari_relasi2 = findRelasi(Lrelasi, cari_beasiswa, cari_mahasiswa2);
                        if(cari_relasi2){
                            cout<<endl<<" Beasiswa tidak dapat dua kali, Mahasiswa telah lebih dulu memiliki Beasiswa";
                            getch();
                            goto menu_awal;
                        }
                        updateRelasiBeasiswa(cari_relasi, cari_beasiswa, cari_mahasiswa2);
                        cout<<endl<<" Relasi Beasiswa telah diupdate Mahasiswanya";
                        getch();
                        goto menu_awal;
                    }
                }
            }
            cout<<" Data Tidak Ditemukan ";
            getch();
            goto menu_awal;
        }
        case 10:{
            exit(0);
        }
    }
}
