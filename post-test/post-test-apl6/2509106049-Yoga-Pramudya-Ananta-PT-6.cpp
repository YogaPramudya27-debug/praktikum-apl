#include <iostream>
#include <iomanip>
using namespace std;

struct akun{
    string nama;
    string password;
};

struct rental{
    string penyewa;
    string jenisPS;
    int durasi;
    int harga;
};

int hitungHarga(int durasi){
    if(durasi==0)
        return 0;
    else
        return 20000 + hitungHarga(durasi-1);
}

void tampilData(rental *dataRental, int *jumlahDataRental){

    cout<<"\n=== DATA RENTAL ===\n";

    if(*jumlahDataRental==0){
        cout<<"Belum ada data\n";
    }
    else{

        cout<<left<<setw(5)<<"No"
            <<setw(15)<<"Nama"
            <<setw(10)<<"PS"
            <<setw(10)<<"Durasi"
            <<setw(10)<<"Harga"<<endl;

        for(int i=0;i<*jumlahDataRental;i++){
            cout<<left<<setw(5)<<i+1
                <<setw(15)<<(dataRental+i)->penyewa
                <<setw(10)<<(dataRental+i)->jenisPS
                <<setw(10)<<(dataRental+i)->durasi
                <<setw(10)<<(dataRental+i)->harga<<endl;
        }
    }
}

void tambahData(rental *dataRental, int *jumlahDataRental){

    cout<<"\nNama Penyewa : ";
    cin>>(dataRental+(*jumlahDataRental))->penyewa;

    cout<<"Jenis PS : ";
    cin>>(dataRental+(*jumlahDataRental))->jenisPS;

    cout<<"Durasi : ";
    cin>>(dataRental+(*jumlahDataRental))->durasi;

    cout<<"Harga : ";
    cin>>(dataRental+(*jumlahDataRental))->harga;

    (*jumlahDataRental)++;

    cout<<"Data berhasil ditambah\n";
}

void ubahData(rental *dataRental, int *jumlahDataRental){

    tampilData(dataRental,jumlahDataRental);

    int nomor;
    cout<<"\nPilih nomor data yang diubah : ";
    cin>>nomor;
    nomor--;

    if(nomor>=0 && nomor<*jumlahDataRental){

        cout<<"Jenis PS baru : ";
        cin>>(dataRental+nomor)->jenisPS;

        cout<<"Durasi baru : ";
        cin>>(dataRental+nomor)->durasi;

        cout<<"Harga baru : ";
        cin>>(dataRental+nomor)->harga;

        cout<<"Data berhasil diubah\n";
    }
    else{
        cout<<"Nomor tidak valid\n";
    }
}

void hapusData(rental *dataRental, int *jumlahDataRental){

    tampilData(dataRental,jumlahDataRental);

    int nomor;
    cout<<"Pilih nomor yang dihapus : ";
    cin>>nomor;
    nomor--;

    if(nomor>=0 && nomor<*jumlahDataRental){

        for(int i=nomor;i<*jumlahDataRental-1;i++){
            *(dataRental+i)=*(dataRental+i+1);
        }

        (*jumlahDataRental)--;

        cout<<"Data berhasil dihapus\n";
    }
    else{
        cout<<"Nomor tidak valid\n";
    }
}

void bubbleSortNama(rental *dataRental, int *jumlahDataRental){
    for(int i=0;i<*jumlahDataRental-1;i++){
        for(int j=0;j<*jumlahDataRental-i-1;j++){
            if((dataRental+j)->penyewa > (dataRental+j+1)->penyewa){
                rental temp = *(dataRental+j);
                *(dataRental+j)=*(dataRental+j+1);
                *(dataRental+j+1)=temp;
            }
        }
    }
    cout<<"Data diurutkan berdasarkan nama (A-Z)\n";
}

void selectionSortHarga(rental *dataRental, int *jumlahDataRental){
    for(int i=0;i<*jumlahDataRental-1;i++){
        int max=i;
        for(int j=i+1;j<*jumlahDataRental;j++){
            if((dataRental+j)->harga > (dataRental+max)->harga){
                max=j;
            }
        }
        rental temp=*(dataRental+i);
        *(dataRental+i)=*(dataRental+max);
        *(dataRental+max)=temp;
    }
    cout<<"Data diurutkan berdasarkan harga (terbesar)\n";
}

void insertionSortDurasi(rental *dataRental, int *jumlahDataRental){
    for(int i=1;i<*jumlahDataRental;i++){
        rental key=*(dataRental+i);
        int j=i-1;

        while(j>=0 && (dataRental+j)->durasi > key.durasi){
            *(dataRental+j+1)=*(dataRental+j);
            j--;
        }
        *(dataRental+j+1)=key;
    }
    cout<<"Data diurutkan berdasarkan durasi\n";
}

void sequentialSearchNama(rental *dataRental, int *jumlahDataRental){
    string cari;
    cout<<"Masukkan nama yang dicari : ";
    cin>>cari;

    for(int i=0;i<*jumlahDataRental;i++){
        if((dataRental+i)->penyewa == cari){
            cout<<"Data ditemukan di nomor "<<i+1<<endl;
            return;
        }
    }
    cout<<"Data tidak ditemukan\n";
}

void binarySearchHarga(rental *dataRental, int *jumlahDataRental){
    int cari;
    cout<<"Masukkan harga yang dicari : ";
    cin>>cari;

    int kiri=0, kanan=*jumlahDataRental-1;

    while(kiri<=kanan){
        int tengah=(kiri+kanan)/2;

        if((dataRental+tengah)->harga == cari){
            cout<<"Data ditemukan di nomor "<<tengah+1<<endl;
            return;
        }
        else if((dataRental+tengah)->harga < cari)
            kanan=tengah-1;
        else
            kiri=tengah+1;
    }

    cout<<"Data tidak ditemukan\n";
}

void sewaPS(rental *dataRental, int *jumlahDataRental, string *namaLogin){

    (dataRental+(*jumlahDataRental))->penyewa = *namaLogin;

    cout<<"Jenis PS : ";
    cin>>(dataRental+(*jumlahDataRental))->jenisPS;

    cout<<"Durasi : ";
    cin>>(dataRental+(*jumlahDataRental))->durasi;

    (dataRental+(*jumlahDataRental))->harga =
    hitungHarga((dataRental+(*jumlahDataRental))->durasi);

    cout<<"Total Harga : Rp"
        <<(dataRental+(*jumlahDataRental))->harga<<endl;

    (*jumlahDataRental)++;

    cout<<"Sewa berhasil\n";
}

int login(akun *daftarUser, int *jumlahUser,
          string *namaAdmin, string *passwordAdmin,
          string *namaLogin){

    string passwordLogin;
    int kesempatan=3;

    while(kesempatan>0){

        cout<<"\n=== LOGIN ==="<<endl;

        cout<<"Nama : ";
        cin>>*namaLogin;

        cout<<"Password : ";
        cin>>passwordLogin;

        if(*namaLogin==*namaAdmin && passwordLogin==*passwordAdmin)
            return 2;

        for(int i=0;i<*jumlahUser;i++){
            if(*namaLogin==(daftarUser+i)->nama &&
               passwordLogin==(daftarUser+i)->password)
                return 1;
        }

        kesempatan--;
        cout<<"Login gagal\n";
    }

    return 0;
}

void registerUser(akun *daftarUser, int *jumlahUser){

    cout<<"\n=== REGISTER ==="<<endl;

    cout<<"Nama : ";
    cin>>(daftarUser+(*jumlahUser))->nama;

    cout<<"Password : ";
    cin>>(daftarUser+(*jumlahUser))->password;

    (*jumlahUser)++;

    cout<<"Akun berhasil dibuat\n";
}

int main(){

    akun daftarUser[10];
    rental dataRental[100];

    int jumlahUser=0;
    int jumlahDataRental=0;

    string admin="yoga", pass="049";

    int menu;

    do{
        cout<<"\n=== MENU AWAL ==="<<endl;
        cout<<"1. Login"<<endl;
        cout<<"2. Register"<<endl;
        cout<<"3. Keluar"<<endl;
        cout<<"Pilih: ";
        cin>>menu;

        if(menu==2){
            registerUser(daftarUser,&jumlahUser);
        }

        else if(menu==1){

            string nama;
            int status=login(daftarUser,&jumlahUser,&admin,&pass,&nama);

            if(status==0){
                cout<<"Login gagal 3x\n";
                return 0;
            }

            if(status==2){

                int pilih;
                do{
                    cout<<"\n=== MENU ADMIN ==="<<endl;
                    cout<<"1. Tambah Data"<<endl;
                    cout<<"2. Lihat Data"<<endl;
                    cout<<"3. Ubah Data"<<endl;
                    cout<<"4. Hapus Data"<<endl;
                    cout<<"5. Sorting"<<endl;
                    cout<<"6. Searching"<<endl;
                    cout<<"7. Logout"<<endl;
                    cout<<"Pilih: ";
                    cin>>pilih;

                    if(pilih==1)
                        tambahData(dataRental,&jumlahDataRental);

                    else if(pilih==2)
                        tampilData(dataRental,&jumlahDataRental);

                    else if(pilih==3)
                        ubahData(dataRental,&jumlahDataRental);

                    else if(pilih==4)
                        hapusData(dataRental,&jumlahDataRental);

                    else if(pilih==5){
                        int s;
                        cout<<"\n=== MENU SORTING ==="<<endl;
                        cout<<"1. Nama (A-Z)"<<endl;
                        cout<<"2. Harga (Desc)"<<endl;
                        cout<<"3. Durasi (Asc)"<<endl;
                        cout<<"Pilih: ";
                        cin>>s;

                        if(s==1) bubbleSortNama(dataRental,&jumlahDataRental);
                        else if(s==2) selectionSortHarga(dataRental,&jumlahDataRental);
                        else if(s==3) insertionSortDurasi(dataRental,&jumlahDataRental);
                    }

                    else if(pilih==6){
                        int s;
                        cout<<"\n=== MENU SEARCHING ==="<<endl;
                        cout<<"1. Cari Nama"<<endl;
                        cout<<"2. Cari Harga"<<endl;
                        cout<<"Pilih: ";
                        cin>>s;

                        if(s==1) sequentialSearchNama(dataRental,&jumlahDataRental);
                        else if(s==2) binarySearchHarga(dataRental,&jumlahDataRental);
                    }

                }while(pilih!=7);
            }

            else{

                int pilih;
                do{
                    cout<<"\n=== MENU USER ==="<<endl;
                    cout<<"1. Sewa PS"<<endl;
                    cout<<"2. Lihat Data"<<endl;
                    cout<<"3. Logout"<<endl;
                    cout<<"Pilih: ";
                    cin>>pilih;

                    if(pilih==1)
                        sewaPS(dataRental,&jumlahDataRental,&nama);

                    else if(pilih==2)
                        tampilData(dataRental,&jumlahDataRental);

                }while(pilih!=3);
            }
        }

    }while(menu!=3);

    cout<<"Program selesai\n";
}