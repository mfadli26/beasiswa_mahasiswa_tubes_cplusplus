#ifndef LINK_LIST_RELASI_H_INCLUDED
#define LINK_LIST_RELASI_H_INCLUDED

#define Beasiswa(P) (P)->Beasiswa
#define Mahasiswa(P) (P)->Mahasiswa

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_beasiswa Beasiswa;
    address_relasi next;
    address_mahasiswa Mahasiswa;
};

struct relasi_list{
    address_relasi first;
};

void CreateListRelasi(relasi_list &Lrelasi);
address_relasi alokasiRelasi(address_beasiswa B, address_mahasiswa M);
void dealokasiRelasi(address_relasi R);
void insertRelasi(relasi_list &Lrelasi, address_relasi R);

address_relasi findRelasi(relasi_list Lrelasi, address_beasiswa B, address_mahasiswa M);

void printBeasiswaRelasiMahasiswa(list_beasiswa Lbeasiswa, relasi_list Lrelasi);
void printBeasiswaRelasiTertentu(relasi_list Lrelasi, address_beasiswa B);
void printBeasiswaYangDimilikiMahasiswa(relasi_list Lrelasi, address_beasiswa B);

void deletefirstRelasi(relasi_list &Lrelasi);
void deletelastRelasi(relasi_list &Lrelasi);
void deleteafterRelasi(relasi_list &Lrelasi, address_relasi &R);
void deleteRelasi(relasi_list &Lrelasi, address_relasi R);
void deleteSemuaRelasiBeasiswa(relasi_list Lrelasi, address_beasiswa B);
void deleteSemuaRelasiMahasiswa(relasi_list Lrelasi, address_mahasiswa M);

void updateRelasiBeasiswa(address_relasi &R, address_beasiswa B, address_mahasiswa M);
#endif // LINK_LIST_RELASI_H_INCLUDED
