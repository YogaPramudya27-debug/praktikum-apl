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

            cout<<"\n=== REGISTER ==="<<endl;

            cout<<"Nama : ";
            cin>>daftarUser[jumlahUser].nama;

            cout<<"Password : ";
            cin>>daftarUser[jumlahUser].password;

            jumlahUser++;

            cout<<"Akun berhasil dibuat\n";
        }

        else if(pilihanMenuAwal==1){

            string namaLogin,passwordLogin;
            int kesempatanLogin=3;
            int statusLogin=0;
            int statusAdmin=0;

            while(kesempatanLogin>0){

                cout<<"\n=== LOGIN ==="<<endl;

                cout<<"Nama : ";
                cin>>namaLogin;

                cout<<"Password : ";
                cin>>passwordLogin;

                if(namaLogin==namaAdmin && passwordLogin==passwordAdmin){
                    statusLogin=1;
                    statusAdmin=1;
                    break;
                }

                for(int i=0;i<jumlahUser;i++){
                    if(namaLogin==daftarUser[i].nama && passwordLogin==daftarUser[i].password){
                        statusLogin=1;
                    }
                }

                if(statusLogin==1) break;

                kesempatanLogin--;
                cout<<"Login gagal... coba lagi\n";
            }

            if(statusLogin==0){
                cout<<"Login gagal 3x\n";
                return 0;
            }

            if(statusAdmin==1){

                cout<<"\nLogin berhasil sebagai ADMIN\n";

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

                    if(pilihanMenuAdmin==1){

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

                    else if(pilihanMenuAdmin==2){

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

                    else if(pilihanMenuAdmin==3){

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
                            else{
                                cout<<"Nomor tidak valid\n";
                            }
                        }
                    }

                    else if(pilihanMenuAdmin==4){

                        cout<<"\n=== DATA RENTAL ===\n";

                        for(int i=0;i<jumlahDataRental;i++){

                            cout<<i+1<<". "
                                <<dataRental[i].penyewa<<" "
                                <<dataRental[i].jenisPS<<" "
                                <<dataRental[i].durasi<<" jam "
                                <<"Rp"<<dataRental[i].harga<<endl;
                        }

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
                        else{
                            cout<<"Nomor tidak valid\n";
                        }
                    }

                }while(pilihanMenuAdmin!=5);

            }

            else{

                cout<<"\nLogin berhasil sebagai USER\n";

                int pilihanMenuUser;

                do{

                    cout<<"\n=== MENU USER ==="<<endl;
                    cout<<"1. Sewa PS"<<endl;
                    cout<<"2. Lihat Data"<<endl;
                    cout<<"3. Logout"<<endl;
                    cout<<"Pilih : ";
                    cin>>pilihanMenuUser;

                    if(pilihanMenuUser==1){

                        dataRental[jumlahDataRental].penyewa = namaLogin;

                        cout<<"Jenis PS : ";
                        cin>>dataRental[jumlahDataRental].jenisPS;

                        cout<<"Durasi : ";
                        cin>>dataRental[jumlahDataRental].durasi;

                        dataRental[jumlahDataRental].harga =
                        dataRental[jumlahDataRental].durasi * 20000;

                        cout<<"Total Harga : Rp"
                            <<dataRental[jumlahDataRental].harga<<endl;

                        jumlahDataRental++;

                        cout<<"Sewa berhasil\n";
                    }

                    else if(pilihanMenuUser==2){

                        cout<<"\n=== DATA RENTAL ===\n";

                        for(int i=0;i<jumlahDataRental;i++){

                            cout<<i+1<<". "
                                <<dataRental[i].penyewa<<" "
                                <<dataRental[i].jenisPS<<" "
                                <<dataRental[i].durasi<<" jam "
                                <<"Rp"<<dataRental[i].harga<<endl;
                        }
                    }

                }while(pilihanMenuUser!=3);

            }

        }

    }while(pilihanMenuAwal!=3);

    cout<<"Program selesai\n";

}