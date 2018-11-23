#include <cstdlib>
#include <iostream>
#include <conio.h>
#include "link_lisk.h"


void CreateBeasiswa(list_beasiswa &Lbeasiswa){
    first(Lbeasiswa) = NULL;
    last(Lbeasiswa) = NULL;
};

void CreateMahasiswa(list_mahasiswa &Lmahasiswa){
    first(Lmahasiswa) = NULL;
    last(Lmahasiswa) = NULL;
};

address_beasiswa alokasiBeasiswa(infotype_beasiswa X){
    address_beasiswa P = new elmlist_beasiswa;
    info(P).jenis = X.jenis;
    info(P).tahun = X.tahun;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
};
address_mahasiswa alokasiMahasiswa(infotype_mahasiswa X){
    address_mahasiswa P = new elmlist_mahasiswa;
    info(P).nama = X.nama;
    info(P).nim = X.nim;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
};

void dealokasiBeasiswa(address_beasiswa P){
    delete P;
};

void dealokasiMahasiswa(address_mahasiswa P){
    delete P;
};



address_beasiswa findBeasiswa(list_beasiswa Lbeasiswa, infotype_beasiswa X){
    address_beasiswa P = first(Lbeasiswa);
    if (first(Lbeasiswa) == NULL){
        P = NULL;
        return P;
    }
    else {
        while (info(P).jenis != X.jenis and next(P) != NULL){
            P = next(P);
        }
        if (info(P).jenis == X.jenis){
            return P;
        }
        else {
            P = NULL;
            return P;
        }
    }
};

address_mahasiswa findMahasiswa(list_mahasiswa Lmahasiswa, infotype_mahasiswa X){
    address_mahasiswa P = first(Lmahasiswa);
    if (first(Lmahasiswa) == NULL){
        cout<<"Error Data Tidak Ditemukan"<<endl;
        P = NULL;
        return P;
    }
    else {
        while (info(P).nama != X.nama and next(P) != NULL){
            P = next(P);
        }
        if (info(P).nama == X.nama){
            return P;
        }
        else {
            P = NULL;
            return P;
        }
    }
};

void insertBeasiswa(list_beasiswa &Lbeasiswa, address_beasiswa P){
    if(first(Lbeasiswa) == NULL){
        first(Lbeasiswa) = P;
        last(Lbeasiswa) = P;
    }
    else {
        next(P) = first(Lbeasiswa);
        prev(first(Lbeasiswa)) = P;
        first(Lbeasiswa) = P;
    }
};

void insertMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa P){
    if(first(Lmahasiswa) == NULL){
        first(Lmahasiswa) = P;
        last(Lmahasiswa) = P;
    }
    else {
        next(P) = first(Lmahasiswa);
        prev(first(Lmahasiswa)) = P;
        first(Lmahasiswa) = P;
    }
};

void deleteFirstBeasiswa(list_beasiswa &Lbeasiswa, address_beasiswa &P){
    if (first(Lbeasiswa) == last(Lbeasiswa)) {
        first(Lbeasiswa) = NULL;
        last(Lbeasiswa) = NULL;
    }
    else {
        P = first(Lbeasiswa);
        first(Lbeasiswa) = next(P);
        next(P) = NULL;
        prev(first(Lbeasiswa)) = NULL;
    }
};
void deleteAfterBeasiswa(list_beasiswa &Lbeasiswa, address_beasiswa &P){
    if (first(Lbeasiswa) == last(Lbeasiswa)) {
        first(Lbeasiswa) = NULL;
        last(Lbeasiswa) = NULL;
    }
    else {
        address_beasiswa Prec = prev(P);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
};
void deleteLastBeasiswa(list_beasiswa &Lbeasiswa, address_beasiswa &P){
    if (first(Lbeasiswa) == last(Lbeasiswa)) {
        first(Lbeasiswa) = NULL;
        last(Lbeasiswa) = NULL;
    }
    else {
        P = last(Lbeasiswa);
        last(Lbeasiswa) = prev(P);
        next(last(Lbeasiswa)) = NULL;
        prev(P) = NULL;
    }

};
void deleteFirstMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa &P){
    if (first(Lmahasiswa) == last(Lmahasiswa)) {
        first(Lmahasiswa) = NULL;
        last(Lmahasiswa) = NULL;
    }
    else {
        P = first(Lmahasiswa);
        first(Lmahasiswa) = next(P);
        next(P) = NULL;
        prev(first(Lmahasiswa)) = NULL;
    }
};
void deleteAfterMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa &P){
    if (first(Lmahasiswa) == last(Lmahasiswa)) {
        first(Lmahasiswa) = NULL;
        last(Lmahasiswa) = NULL;
    }
    else {
        address_mahasiswa Prec = prev(P);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
};
void deleteLastMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa &P){
    if (first(Lmahasiswa) == last(Lmahasiswa)) {
        first(Lmahasiswa) = NULL;
        last(Lmahasiswa) = NULL;
    }
    else {
        P = last(Lmahasiswa);
        last(Lmahasiswa) = prev(P);
        next(last(Lmahasiswa)) = NULL;
        prev(P) = NULL;
    }

};

void printBeasiswa(list_beasiswa Lbeasiswa){
    if(first(Lbeasiswa) == NULL){
        cout<<"Anda Belum Memasukkan Data Beasiswa"<<endl;
    }
    else {
        address_beasiswa P = first(Lbeasiswa);
        while (P != NULL){
            cout<<endl;
            cout<<"Jenis Beasiswa = "<<info(P).jenis<<endl;
            cout<<"Tahun = "<<info(P).tahun<<endl;
            P = next(P);
            cout<<endl;
        }
    }
    cout<<endl;
};

void printMahasiswa(list_mahasiswa Lmahasiswa){
    if(first(Lmahasiswa) == NULL){
        cout<<"Anda Belum Memasukkan Data Mahasiswa"<<endl;
    }
    else {
        address_mahasiswa P = first(Lmahasiswa);
        while (P != NULL){
            cout<<endl;
            cout<<"Nama Mahasiswa = "<<info(P).nama<<endl;
            cout<<"Nim Mahasiswa = "<<info(P).nim<<endl;
            P = next(P);
            cout<<endl;
        }
    }
    cout<<endl;
};

/*

void printPegawai1(list_pegawai Lpegawai){
    if(first(Lpegawai) == NULL){
        cout<<"Daftar Pegawai Kosong"<<endl;
    }
    else {
        address_pegawai P = first(Lpegawai);
        while (P != NULL){
            cout<<endl;
            cout<<"Nama Pegawai = "<<info(P).nama<<endl;
            cout<<"Nip = "<<info(P).nip<<endl;
            cout<<"Departemen = ";
            P = next(P);
            cout<<endl;
        }
    }
    cout<<endl;
};

void printDepartemen1(list_departemen Ldepartemen){
    if(first(Ldepartemen) == NULL){
        cout<<"Daftar Departemen Kosong"<<endl;
    }
    else {
        address_departemen P = first(Ldepartemen);
        while (P != NULL){
            cout<<endl;
            cout<<"Nama Departemen = "<<info(P).nama_departemen<<endl;
            cout<<"Alamat = "<<info(P).alamat<<endl;
            P = next(P);
            cout<<endl;
        }
    }
    cout<<endl;
};

*/

void deleteBeasiswa(list_beasiswa &Lbeasiswa, address_beasiswa P){
    if (P == first(Lbeasiswa)){
        deleteFirstBeasiswa(Lbeasiswa, P);
    }
    else if (P == last(Lbeasiswa)){
        deleteLastBeasiswa(Lbeasiswa, P);
    }
    else{
        deleteAfterBeasiswa(Lbeasiswa, P);
    }
};

void deleteMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa P){
    if (P == first(Lmahasiswa)){
        deleteFirstMahasiswa(Lmahasiswa, P);
    }
    else if (P == last(Lmahasiswa)){
        deleteLastMahasiswa(Lmahasiswa, P);
    }
    else{
        deleteAfterMahasiswa(Lmahasiswa, P);
    }
};

