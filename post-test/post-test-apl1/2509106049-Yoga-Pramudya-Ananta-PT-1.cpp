#include <iostream>
using namespace std;

int main() {

    string nama_kamu;
    string pass;
    int kesempatan = 0;
    string passBenar = "049";   

    cout << "PROGRAM KONVERSI WAKTU\n";
    cout << "=======================\n";

    while (kesempatan < 3) {

        cout << "\nLogin dulu ya\n";
        cout << "Nama_anda : ";
        cin >> nama_kamu;
        cout << "Password : ";
        cin >> pass;

        if (pass == passBenar) {
            cout << "Login berhasil\n";
            break;
        } else {
            cout << "Password kamu salah\n";
            kesempatan++;
        }
    }

    if (kesempatan == 3) {
        cout << "Terlalu banyak kesalahan. Program berhenti.\n";
        return 0;
    }

    int pilih;

    do {
        cout << "\nMenu\n";
        cout << "1. Jam ke Menit dan Detik\n";
        cout << "2. Menit ke Jam dan Detik\n";
        cout << "3. Detik ke Jam dan Menit\n";
        cout << "4. Keluar\n";
        cout << "Pilih : ";
        cin >> pilih;

        if (pilih == 1) {
            int jam;
            cout << "Masukkan jam : ";
            cin >> jam;

            int menit = jam * 60;
            int detik = jam * 3600;

            cout << "Hasilnya : " << menit << " menit dan "
                 << detik << " detik\n";
        }
        else if (pilih == 2) {
            int menit;
            cout << "Masukkan menit : ";
            cin >> menit;

            int jam = menit / 60;
            int detik = menit * 60;

            cout << "Hasilnya : " << jam << " jam dan "
                 << detik << " detik\n";
        }
        else if (pilih == 3) {
            int detik;
            cout << "Masukkan detik : ";
            cin >> detik;

            int jam = detik / 3600;
            int menit = detik / 60;

            cout << "Hasilnya : " << jam << " jam dan "
                 << menit << " menit\n";
        }
        else if (pilih == 4) {
            cout << "Program selesai\n";
        }
        else {
            cout << "Menu yang kamu pilih tidak ada\n";
        }

    } while (pilih != 4);

    return 0;
}