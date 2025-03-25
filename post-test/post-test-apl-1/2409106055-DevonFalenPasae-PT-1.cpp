#include <iostream>
using namespace std;

int main() {
    const int pin_benar = 6055;
    const int max_percobaan = 3;
    bool beri_akses = false;
    int saldo = 0;
    int pilihan;

    for(int percobaan = 1; percobaan <= max_percobaan; percobaan++) {
        int input_pengguna;
        cout << "Masukkan PIN Anda: ";
        cin >> input_pengguna;

        if(input_pengguna == pin_benar) {
            beri_akses = true;
            cout << "\n== Autentikasi berhasil! ==\n";
            break;
        } else {
            cout << "PIN salah! Sisa percobaan: " << (max_percobaan - percobaan) << "\n\n";
        }
    }

    if(!beri_akses) {
        cout << "\n== Autentikasi gagal. Akun terkunci. ==\n";
        return 0;
    }

    do {
        cout << "\n=== MENU TRANSAKSI ==="
            << "\n1. Cek Saldo"
            << "\n2. Tarik Tunai"
            << "\n3. Setor Tunai"
            << "\n4. Keluar"
            << "\nPilih opsi (1-4): ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "\nSaldo Anda: Rp" << saldo << endl;
                break;
                
            case 2: {
                int jumlah;
                cout << "\nMasukkan jumlah penarikan: Rp";
                cin >> jumlah;
                
                if(jumlah > saldo) {
                    cout << "Saldo tidak cukup!\n";
                } else {
                    saldo -= jumlah;
                    cout << "Penarikan berhasil. Saldo tersisa: Rp" << saldo << endl;
                }
                break;
            }
            
            case 3: {
                int jumlah;
                cout << "\nMasukkan jumlah setoran: Rp";
                cin >> jumlah;
                
                saldo += jumlah;
                cout << "Setoran berhasil. Saldo saat ini: Rp" << saldo << endl;
                break;
            }
            
            case 4:
                cout << "\nTerima kasih telah menggunakan layanan kami.\n";
                break;
                
            default:
                cout << "\nPilihan tidak valid! Silakan coba lagi.\n";
        }
        
    } while(pilihan != 4); 

    return 0;
}
