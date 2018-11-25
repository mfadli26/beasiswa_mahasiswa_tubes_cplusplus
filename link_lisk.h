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

struct infotype_beasiswa
{
    string jenis;
    int tahun;
};
struct infotype_mahasiswa
{
    string nama;
    string nim;
    string jurusan;
    string angkatan;
    string asal;
};


typedef struct elmlist_beasiswa *address_beasiswa;
typedef struct elmlist_mahasiswa *address_mahasiswa;

struct elmlist_beasiswa
{
    infotype_beasiswa info;
    address_beasiswa next;
    address_beasiswa prev;
};

struct elmlist_mahasiswa
{
    infotype_mahasiswa info;
    address_mahasiswa next;
    address_mahasiswa prev;
};

struct list_beasiswa
{
    address_beasiswa first;
    address_beasiswa last;
};

struct list_mahasiswa
{
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

void deleteBeasiswa(list_beasiswa &Lbeasiswa, address_beasiswa X);
void deleteMahasiswa(list_mahasiswa &Lmahasiswa,address_mahasiswa X);

//Update Data
void updateDataMahasiswa(address_mahasiswa &M, infotype_mahasiswa A);
void updateDataBeasiswa(address_beasiswa &B, infotype_beasiswa A);

//*Proses*//
void printBeasiswa(list_beasiswa Lbeasiswa);
void printMahasiswa(list_mahasiswa Lmahasiswa);

void printBeasiswa1(list_beasiswa Lbeasiswa);
void printMahasiswa1(list_mahasiswa Lmahasiswa);

#endif // LINK_LISK_H_INCLUDED
