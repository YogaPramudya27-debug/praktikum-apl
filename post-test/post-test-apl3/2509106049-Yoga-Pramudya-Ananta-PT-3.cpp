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

void tampilData(rental dataRental[], int jumlahDataRental){

    cout<<"\n=== DATA RENTAL ===\n";

    if(jumlahDataRental==0){
        cout<<"Belum ada data\n";
    }
    else{

        cout<<left<<setw(5)<<"No"
            <<setw(15)<<"Nama"
            <<setw(10)<<"PS"
            <<setw(10)<<"Durasi"
            <<setw(10)<<"Harga"<<endl;

        for(int i=0;i<jumlahDataRental;i++){

            cout<<left<<setw(5)<<i+1
                <<setw(15)<<dataRental[i].penyewa
                <<setw(10)<<dataRental[i].jenisPS
                <<setw(10)<<dataRental[i].durasi
                <<setw(10)<<dataRental[i].harga<<endl;
        }
    }
}

void tampilData(){
    cout<<"Belum ada data rental\n";
}

void tambahData(rental dataRental[], int &jumlahDataRental){

    cout<<"\nNama Penyewa : ";
    cin>>dataRental[jumlahDataRental].penyewa;

    cout<<"Jenis PS : ";
    cin>>dataRental[jumlahDataRental].jenisPS;

    cout<<"Durasi : ";
    cin>>dataRental[jumlahDataRental].durasi;

    cout<<"Harga : ";
    cin>>dataRental[jumlahDataRental].harga;

    jumlahDataRental++;

    cout<<"Data berhasil ditambah\n";
}

void ubahData(rental dataRental[], int jumlahDataRental){

    tampilData(dataRental,jumlahDataRental);

    int nomor;

    cout<<"\nPilih nomor data yang diubah : ";
    cin>>nomor;
    nomor--;

    if(nomor>=0 && nomor<jumlahDataRental){

        cout<<"Jenis PS baru : ";
        cin>>dataRental[nomor].jenisPS;

        cout<<"Durasi baru : ";
        cin>>dataRental[nomor].durasi;

        cout<<"Harga baru : ";
        cin>>dataRental[nomor].harga;

        cout<<"Data berhasil diubah\n";
    }
}

void hapusData(rental dataRental[], int &jumlahDataRental){

    tampilData(dataRental,jumlahDataRental);

    int nomor;

    cout<<"Pilih nomor yang dihapus : ";
    cin>>nomor;
    nomor--;

    if(nomor>=0 && nomor<jumlahDataRental){

        for(int i=nomor;i<jumlahDataRental-1;i++){
            dataRental[i]=dataRental[i+1];
        }

        jumlahDataRental--;

        cout<<"Data berhasil dihapus\n";
    }
}

void sewaPS(rental dataRental[], int &jumlahDataRental, string namaLogin){

    dataRental[jumlahDataRental].penyewa = namaLogin;

    cout<<"Jenis PS : ";
    cin>>dataRental[jumlahDataRental].jenisPS;

    cout<<"Durasi : ";
    cin>>dataRental[jumlahDataRental].durasi;

    dataRental[jumlahDataRental].harga =
    hitungHarga(dataRental[jumlahDataRental].durasi);

    cout<<"Total Harga : Rp"
        <<dataRental[jumlahDataRental].harga<<endl;

    jumlahDataRental++;

    cout<<"Sewa berhasil\n";
}

int login(akun daftarUser[], int jumlahUser,
          string namaAdmin, string passwordAdmin,
          string &namaLogin){

    string passwordLogin;
    int kesempatanLogin=3;

    while(kesempatanLogin>0){

        cout<<"\n=== LOGIN ==="<<endl;

        cout<<"Nama : ";
        cin>>namaLogin;

        cout<<"Password : ";
        cin>>passwordLogin;

        if(namaLogin==namaAdmin && passwordLogin==passwordAdmin)
            return 2;

        for(int i=0;i<jumlahUser;i++){
            if(namaLogin==daftarUser[i].nama &&
               passwordLogin==daftarUser[i].password)
                return 1;
        }

        kesempatanLogin--;
        cout<<"Login gagal\n";
    }

    return 0;
}

void registerUser(akun daftarUser[], int &jumlahUser){

    cout<<"\n=== REGISTER ==="<<endl;

    cout<<"Nama : ";
    cin>>daftarUser[jumlahUser].nama;

    cout<<"Password : ";
    cin>>daftarUser[jumlahUser].password;

    jumlahUser++;

    cout<<"Akun berhasil dibuat\n";
}

int main(){

    akun daftarUser[10];
    rental dataRental[100];

    int jumlahUser = 0;
    int jumlahDataRental = 0;

    string namaAdmin = "yoga";
    string passwordAdmin = "049";

    int pilihanMenuAwal;

    do{

        cout<<"\n=== MENU AWAL ==="<<endl;
        cout<<"1. Login"<<endl;
        cout<<"2. Register"<<endl;
        cout<<"3. Keluar"<<endl;
        cout<<"Pilih : ";
        cin>>pilihanMenuAwal;

        if(pilihanMenuAwal==2){

            registerUser(daftarUser,jumlahUser);

        }

        else if(pilihanMenuAwal==1){

            string namaLogin;

            int statusLogin =
            login(daftarUser,jumlahUser,
                  namaAdmin,passwordAdmin,
                  namaLogin);

            if(statusLogin==0){
                cout<<"Login gagal 3x\n";
                return 0;
            }

            if(statusLogin==2){

                int pilihanMenuAdmin;

                do{

                    cout<<"\n=== MENU ADMIN ==="<<endl;
                    cout<<"1. Tambah Data"<<endl;
                    cout<<"2. Lihat Data"<<endl;
                    cout<<"3. Ubah Data"<<endl;
                    cout<<"4. Hapus Data"<<endl;
                    cout<<"5. Logout"<<endl;
                    cout<<"Pilih : ";
                    cin>>pilihanMenuAdmin;

                    if(pilihanMenuAdmin==1)
                        tambahData(dataRental,jumlahDataRental);

                    else if(pilihanMenuAdmin==2)
                        tampilData(dataRental,jumlahDataRental);

                    else if(pilihanMenuAdmin==3)
                        ubahData(dataRental,jumlahDataRental);

                    else if(pilihanMenuAdmin==4)
                        hapusData(dataRental,jumlahDataRental);

                }while(pilihanMenuAdmin!=5);
            }

            else{

                int pilihanMenuUser;

                do{

                    cout<<"\n=== MENU USER ==="<<endl;
                    cout<<"1. Sewa PS"<<endl;
                    cout<<"2. Lihat Data"<<endl;
                    cout<<"3. Logout"<<endl;
                    cout<<"Pilih : ";
                    cin>>pilihanMenuUser;

                    if(pilihanMenuUser==1)
                        sewaPS(dataRental,
                               jumlahDataRental,
                               namaLogin);

                    else if(pilihanMenuUser==2)
                        tampilData(dataRental,
                                   jumlahDataRental);

                }while(pilihanMenuUser!=3);

            }

        }

    }while(pilihanMenuAwal!=3);

    cout<<"Program selesai\n";

}