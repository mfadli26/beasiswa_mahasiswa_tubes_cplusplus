#ifndef LINK_LISK_H_INCLUDED
#define LINK_LISK_H_INCLUDED

#include <stdio.h>
#include <iostream>

#define first(Lbeasiswa) Lbeasiswa.first
#define last(Lbeasiswa) Lbeasiswa.last

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev

using namespace std;

struct infotype_beasiswa{
    string jenis;
    int tahun;
};
struct infotype_mahasiswa{
    string nama;
    string nim;
};


typedef struct elmlist_pegawai *address_pegawai;
typedef struct elmlist_departemen *address_departemen;

struct elmlist_beasiswa{
    infotype_beasiswa info;
    address_beasiswai next;
    address_beasiswa prev;
};

struct elmlist_mahasiswa{
    infotype_mahasiswa info;
    address_mahasiswa next;
    address_mahasiswa prev;
};

struct list_beasiswa{
    address_beasiswa first;
    address_beasiswa last;
};

struct list_mahasiswa{
    address_mahasiswa first;
    address_mahasiswa last;
};

void CreateBeasiswa(list_beasiswa &Lbeasiswa);
void CreateMahasiswa(list_mahasiswa &Lmahasiswa);

address_beasiswa alokasiBeasiswa(infotype_beasiswa X);
address_mahasiswa alokasiMahasiswa(infotype_mahasiswa X);

void dealokasiBeasiswa(address_beasiswa P);
void dealokasiMahasiswa(address_mahasiswa P);

address_beasiswa findBeasiswa(list_beasiswa Lbeasiswa, infotype_beasiswa X);
address_mahasiswa findMahasiswa (list_mahasiswa Lmahasiswa, infotype_mahasiswa X);

//* Insert *//
void insertBeasiswa(list_beasiswa &Lbeasiswa, address_beasiswa P);
void insertMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa P);
//*DELETE//*
void deleteFirstBeasiswa(list_beasiswa &Lbeasiswa, address_beasiswa &P);
void deleteAfterBeasiswa(list_beasiswa &Lbeasiswa, address_beasiswa &P);
void deleteLastBeasiswa(list_beasiswa &Lbeasiswa, address_beasiswa &P);

void deleteFirstMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa &P);
void deleteAfterMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa &P);
void deleteLastMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa &P);

void deletePegawai(list_pegawai &Lpegawai, infotype_pegawai X);
void deleteDepartemen(list_pegawai &Ldepartemen,infotype_departemen X);

//*Proses*//
void printPegawai(list_pegawai Lpegawai);
void printDepartemen(list_departemen Ldepartemen);

void printPegawai1(list_pegawai Lpegawai);
void printDepartemen1(list_departemen Ldepartemen);

#endif // LINK_LISK_H_INCLUDED
