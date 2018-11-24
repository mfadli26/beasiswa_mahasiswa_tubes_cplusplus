#include <cstdlib>
#include <iostream>
#include <conio.h>
#include "link_list_relasi.h"
#include "link_lisk.h"

void CreateListRelasi(relasi_list &Lrelasi){
    first(Lrelasi) = NULL;
};

address_relasi alokasiRelasi(address_beasiswa B, address_mahasiswa M){
    address_relasi R = new elmlist_relasi;
    Beasiswa(R) = B;
    next(R) = NULL;
    Mahasiswa(R) =  M;
    return R;
};

void dealokasiRelasi(address_relasi R){
    delete(R);
};

void insertRelasi(relasi_list &Lrelasi, address_relasi R){
    if(first(Lrelasi) == NULL){
        first(Lrelasi) = R;
        next(R) = first(Lrelasi);
    }
    else {
        address_relasi R2 = first(Lrelasi);
        do{
            R2 = next(R2);
        } while(next(R2) != first(Lrelasi));
        next(R2) = R;
        next(R) = first(Lrelasi);
    }
};

void printBeasiswaRelasiMahasiswa(list_beasiswa Lbeasiswa, relasi_list Lrelasi){
    if(first(Lbeasiswa) == NULL){
        cout<<"Anda Belum Memasukkan Data Beasiswa"<<endl;
    }
    else {
        address_beasiswa B = first(Lbeasiswa);
        while (B != NULL){
            cout<<endl;
            cout<<"Jenis Beasiswa = "<<info(B).jenis<<endl;
            cout<<"Tahun = "<<info(B).tahun<<endl;
            cout<<"Mahasiswa = ";
            address_relasi R = first(Lrelasi);
            do{
                if(Beasiswa(R) == B){
                    cout<<info(Mahasiswa(R)).nama<<", ";
                }
                R = next(R);
            } while(R != first(Lrelasi));
            B = next(B);
            cout<<endl;
        }
    }
    cout<<endl;
};

void printBeasiswaRelasiTertentu(relasi_list Lrelasi, address_beasiswa B){
    address_relasi Q = first(Lrelasi);
    cout<<endl;
    cout<<"Jenis Beasiswa : "<<info(B).jenis<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"Tahun Beasiswa : "<<info(B).tahun<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"Mahasiswa : ";
    do{
        if(Beasiswa(Q) == B){
            cout<<info(Mahasiswa(Q)).nama<<", ";
        }
        Q = next(Q);
    } while(Q != first(Lrelasi));
    cout<<endl<<"-----------------------"<<endl;
}

address_relasi findRelasi(relasi_list Lrelasi, address_beasiswa B, address_mahasiswa M){
    address_relasi R = first(Lrelasi);
    if (first(Lrelasi) == NULL){
        R = NULL;
        return R;
    }
    else {
        do{
            if(Beasiswa(R) == B and Mahasiswa(R) == M){
                return R;
            }
            R = next(R);
        } while(R != first(Lrelasi));
    }
    return NULL;
};

void printBeasiswaYangDimilikiMahasiswa(relasi_list Lrelasi, address_beasiswa B){
    address_relasi Q = first(Lrelasi);
    do{
        if(Beasiswa(Q) == B){
            cout<<"Nama Mahasiswa : "<<info(Mahasiswa(Q)).nama<<endl;
            cout<<"Nim Mahasiswa : "<<info(Mahasiswa(Q)).nim<<endl<<endl;
        }
        Q = next(Q);
    } while(Q != first(Lrelasi));
    cout<<endl<<"-----------------------"<<endl;
}

void deletefirstRelasi(relasi_list &Lrelasi){
    address_relasi R = first(Lrelasi);
    if(next(first(Lrelasi)) == first(Lrelasi)){
        first(Lrelasi) = NULL;
        dealokasiRelasi(R);
    }
    else{
        do{
            R = next(R);
        } while(next(R) != first(Lrelasi));
        next(R) = next(first(Lrelasi));
        R = first(Lrelasi);
        first(Lrelasi) = next(R);
        next(R) = NULL;
        dealokasiRelasi(R);
    }
}

void deletelastRelasi(relasi_list &Lrelasi){
    address_relasi R = first(Lrelasi);
    if(next(first(Lrelasi)) == first(Lrelasi)){
        first(Lrelasi) = NULL;
        dealokasiRelasi(R);
    }
    else{
        do{
            R = next(R);
        } while(next(next(R)) != first(Lrelasi));
        address_relasi R2 = next(R);
        next(R) = first(Lrelasi);
        next(R2) = NULL;
        dealokasiRelasi(R2);
    }
}

void deleteafterRelasi(relasi_list &Lrelasi, address_relasi &R){
    address_relasi R2 = first(Lrelasi);
    while(next(R2) != R){
        R = next(R);
    }
    next(R2) = next(R);
    next(R) = NULL;
    dealokasiRelasi(R);
}

void deleteRelasi(relasi_list &Lrelasi, address_relasi R){
    if (R == first(Lrelasi)){
        deletefirstRelasi(Lrelasi);
    }
    else if (next(R) == first(Lrelasi)){
        deletelastRelasi(Lrelasi);
    }
    else{
        deleteafterRelasi(Lrelasi, R);
    }
};

void deleteSemuaRelasiBeasiswa(relasi_list Lrelasi, address_beasiswa B){
    address_relasi R = first(Lrelasi);
    do{
        if(Beasiswa(R) == B){
            address_relasi R2 = next(R);
            deleteRelasi(Lrelasi, R);
            R = R2;
        }
        else{
            R = next(R);
        }
        if(first(Lrelasi) == NULL){
            R = NULL;
        }
    } while(R != first(Lrelasi) and R != NULL);
};

void deleteSemuaRelasiMahasiswa(relasi_list Lrelasi, address_mahasiswa M){
    address_relasi R = first(Lrelasi);
    do{
        if(Mahasiswa(R) == M){
            address_relasi R2 = next(R);
            deleteRelasi(Lrelasi, R);
            R = R2;
        }
        else{
            R = next(R);
        }
        if(first(Lrelasi) == NULL){
            R = NULL;
        }
    } while(R != first(Lrelasi) and R != NULL);
};
