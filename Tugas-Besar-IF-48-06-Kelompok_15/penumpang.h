#ifndef PENUMPANG_H_INCLUDED
#define PENUMPANG_H_INCLUDED

using namespace std;

// penumpang
struct Penumpang {
    string idPenumpang;
    string nama;
    string noTelp;
    string alamat;
    Penumpang* next;

    struct Relasi* relasiHead;
};

// ojek
struct Ojek {
    string idOjek;
    string nama;
    Ojek* next;
};

// anak
struct Relasi {
    Penumpang* p;
    Ojek* o;
    Relasi* next;
};


Penumpang* createPenumpang(string id, string nama, string telp, string alamat);
Ojek* createOjek(string id, string nama);
Relasi* createRelasi(Penumpang* p, Ojek* o);

void insertPenumpang(Penumpang* p);
void insertOjek(Ojek* o);

void hubungkanPenumpangKeOjek(Penumpang* p, Ojek* o);

Penumpang* findPenumpang(string id);
Ojek* findOjek(string id);

void tampilPenumpang();


#endif // PENUMPANG_H_INCLUDED
