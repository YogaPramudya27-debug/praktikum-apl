#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <limits>
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

int inputAngka(string pesan){
    int x;
    while(true){
        try{
            cout<<pesan;
            cin>>x;

            if(cin.fail()){
                throw invalid_argument("Input harus angka!");
            }

            if(x < 0){
                throw out_of_range("Tidak boleh negatif!");
            }

            return x;
        }
        catch(exception &e){
            cout<<"Error: "<<e.what()<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

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
    } else{
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
    try{
        cout<<"\nNama Penyewa : ";
        cin>>(dataRental+(*jumlahDataRental))->penyewa;

        cout<<"Jenis PS : ";
        cin>>(dataRental+(*jumlahDataRental))->jenisPS;

        (dataRental+(*jumlahDataRental))->durasi = inputAngka("Durasi : ");
        (dataRental+(*jumlahDataRental))->harga  = inputAngka("Harga : ");

        (*jumlahDataRental)++;

        cout<<"Data berhasil ditambahkan!\n";
    }
    catch(exception &e){
        cout<<"Gagal tambah data: "<<e.what()<<endl;
    }
}

void ubahData(rental *dataRental, int *jumlahDataRental){
    try{
        tampilData(dataRental,jumlahDataRental);

        int nomor = inputAngka("Pilih nomor : ");
        nomor--;

        if(nomor<0 || nomor>=*jumlahDataRental){
            throw out_of_range("Nomor tidak valid!");
        }

        cout<<"Jenis PS baru: ";
        cin>>(dataRental+nomor)->jenisPS;

        (dataRental+nomor)->durasi = inputAngka("Durasi baru: ");
        (dataRental+nomor)->harga  = inputAngka("Harga baru: ");

        cout<<"Data berhasil diubah!\n";
    }
    catch(exception &e){
        cout<<"Error: "<<e.what()<<endl;
    }
}

void hapusData(rental *dataRental, int *jumlahDataRental){
    try{
        tampilData(dataRental,jumlahDataRental);

        int nomor = inputAngka("Pilih nomor yang dihapus: ");
        nomor--;

        if(nomor<0 || nomor>=*jumlahDataRental){
            throw out_of_range("Data tidak ditemukan!");
        }

        for(int i=nomor;i<*jumlahDataRental-1;i++){
            *(dataRental+i)=*(dataRental+i+1);
        }

        (*jumlahDataRental)--;

        cout<<"Data berhasil dihapus!\n";
    }
    catch(exception &e){
        cout<<"Error: "<<e.what()<<endl;
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
}

void sequentialSearchNama(rental *dataRental, int *jumlahDataRental){
    string cari;
    cout<<"Cari nama: ";
    cin>>cari;

    for(int i=0;i<*jumlahDataRental;i++){
        if((dataRental+i)->penyewa == cari){
            cout<<"Ditemukan di data ke-"<<i+1<<endl;
            return;
        }
    }
    cout<<"Tidak ditemukan\n";
}

void binarySearchHarga(rental *dataRental, int *jumlahDataRental){
    int cari = inputAngka("Cari harga: ");

    int kiri=0, kanan=*jumlahDataRental-1;

    while(kiri<=kanan){
        int tengah=(kiri+kanan)/2;

        if((dataRental+tengah)->harga == cari){
            cout<<"Ditemukan di data ke-"<<tengah+1<<endl;
            return;
        }
        else if((dataRental+tengah)->harga < cari)
            kanan=tengah-1;
        else
            kiri=tengah+1;
    }
    cout<<"Tidak ditemukan\n";
}

void sewaPS(rental *dataRental, int *jumlahDataRental, string namaLogin){

    (dataRental+(*jumlahDataRental))->penyewa=namaLogin;

    cout<<"Jenis PS: ";
    cin>>(dataRental+(*jumlahDataRental))->jenisPS;

    (dataRental+(*jumlahDataRental))->durasi = inputAngka("Durasi: ");

    (dataRental+(*jumlahDataRental))->harga =
        hitungHarga((dataRental+(*jumlahDataRental))->durasi);

    (*jumlahDataRental)++;

    cout<<"Sewa berhasil!\n";
}

int login(akun *daftarUser, int jumlahUser,
          string namaAdmin, string passwordAdmin,
          string &namaLogin){

    string password;
    int kesempatan=3;

    while(kesempatan--){
        cout<<"Username & Password: ";
        cin>>namaLogin>>password;

        if(namaLogin==namaAdmin && password==passwordAdmin)
            return 2;

        for(int i=0;i<jumlahUser;i++){
            if(namaLogin==(daftarUser+i)->nama &&
               password==(daftarUser+i)->password)
                return 1;
        }

        cout<<"Login gagal! Sisa percobaan: "<<kesempatan<<endl;
    }
    return 0;
}

void registerUser(akun *daftarUser, int *jumlahUser){
    cout<<"Username: ";
    cin>>(daftarUser+(*jumlahUser))->nama;

    cout<<"Password: ";
    cin>>(daftarUser+(*jumlahUser))->password;

    (*jumlahUser)++;

    cout<<"Registrasi berhasil!\n";
}

int main(){

    akun daftarUser[10];
    rental dataRental[100];

    int jumlahUser=0;
    int jumlahDataRental=0;

    string admin="yoga", pass="049";

    int menu;

    do{
        cout<<"\n========================\n";
        cout<<"      MENU UTAMA\n";
        cout<<"========================\n";
        cout<<"1. Login\n";
        cout<<"2. Register\n";
        cout<<"3. Keluar\n";
        cout<<"========================\n";
        cout<<"Pilih: ";
        cin>>menu;

        if(menu==2){
            registerUser(daftarUser,&jumlahUser);
        }

        else if(menu==1){

            string nama;
            int status=login(daftarUser, jumlahUser, admin, pass, nama);

            if(status==0){
                cout<<"Akses ditolak!\n";
                return 0;
            }

            if(status==2){
                int pilih;
                do{
                    cout<<"\n===== MENU ADMIN =====\n";
                    cout<<"1. Tambah\n";
                    cout<<"2. Lihat\n";
                    cout<<"3. Ubah\n";
                    cout<<"4. Hapus\n";
                    cout<<"5. Sort\n";
                    cout<<"6. Search\n";
                    cout<<"7. Logout\n";
                    cout<<"Pilih: ";
                    cin>>pilih;

                    if(pilih==1) tambahData(dataRental,&jumlahDataRental);
                    else if(pilih==2) tampilData(dataRental,&jumlahDataRental);
                    else if(pilih==3) ubahData(dataRental,&jumlahDataRental);
                    else if(pilih==4) hapusData(dataRental,&jumlahDataRental);

                    else if(pilih==5){
                        int s;
                        cout<<"1. Nama\n2. Harga\n3. Durasi\nPilih: ";
                        cin>>s;

                        if(s==1) bubbleSortNama(dataRental,&jumlahDataRental);
                        else if(s==2) selectionSortHarga(dataRental,&jumlahDataRental);
                        else if(s==3) insertionSortDurasi(dataRental,&jumlahDataRental);
                    }

                    else if(pilih==6){
                        int s;
                        cout<<"1. Nama\n2. Harga\nPilih: ";
                        cin>>s;

                        if(s==1) sequentialSearchNama(dataRental,&jumlahDataRental);
                        else if(s==2) binarySearchHarga(dataRental,&jumlahDataRental);
                    }

                }while(pilih!=7);
            }

            else{
                int pilih;
                do{
                    cout<<"\n===== MENU USER =====\n";
                    cout<<"1. Sewa\n";
                    cout<<"2. Lihat\n";
                    cout<<"3. Logout\n";
                    cout<<"Pilih: ";
                    cin>>pilih;

                    if(pilih==1)
                        sewaPS(dataRental,&jumlahDataRental,nama);
                    else if(pilih==2)
                        tampilData(dataRental,&jumlahDataRental);

                }while(pilih!=3);
            }
        }

    }while(menu!=3);

    cout<<"Program selesai\n";
}