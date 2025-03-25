#include <iostream>
using namespace std;

#define MAX_ANGGOTA 100
string nama[MAX_ANGGOTA];
int nomor[MAX_ANGGOTA];
string motor[MAX_ANGGOTA];
int tahun[MAX_ANGGOTA];
int totalAnggota = 0;

int autentikasi() {
    const string username_benar = "Devon";
    const string nim_benar = "6055";
    const int max_percobaan = 3;
    bool beri_akses = false;

    for (int percobaan = 1; percobaan <= max_percobaan; percobaan++) {
        string input_username, input_nim;
        cout << "Masukkan Nama: ";
        cin >> input_username;
        cout << "Masukkan NIM: ";
        cin >> input_nim;

        if (input_username == username_benar && input_nim == nim_benar) {
            beri_akses = true;
            cout << "== Autentikasi berhasil! ==\n";
            break;
        } else {
            cout << "Nama atau NIM salah! Sisa percobaan: " << (max_percobaan - percobaan) << endl;
        }
    }

    if (!beri_akses) {
        cout << "== Autentikasi gagal. Program berhenti. ==\n";
        return 0;
    }

    return 1;
}

int tambah() {
    if (totalAnggota < MAX_ANGGOTA) {
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, nama[totalAnggota]);
        cout << "Masukkan Nomor Anggota: ";
        cin >> nomor[totalAnggota];
        cout << "Masukkan Jenis Motor: ";
        cin.ignore();
        getline(cin, motor[totalAnggota]);
        cout << "Masukkan Tahun Bergabung: ";
        cin >> tahun[totalAnggota];
        totalAnggota++;
        cout << "Anggota berhasil ditambahkan!" << endl;
    } else {
        cout << "Data penuh!" << endl;
    }
    return 0;
}

int tampilkan() {
    if (totalAnggota == 0) {
        cout << "Tidak ada anggota." << endl;
    } else {
        cout << "\n----------------------------------------------------------------------" << endl;
        cout << "| No  | Nama              | No. Anggota | Jenis Motor       | Tahun |" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        for (int i = 0; i < totalAnggota; i++) {
            cout << "| " << i + 1 << "   | " 
                << nama[i] << string(18 - nama[i].length(), ' ') << "| "
                << nomor[i] << "           | "
                << motor[i] << string(17 - motor[i].length(), ' ') << "| "
                << tahun[i] << "   |" << endl;
        }
        cout << "----------------------------------------------------------------------" << endl;
    }
    return 0;
}

int hapus() {
    if (totalAnggota == 0) {
        cout << "Tidak ada anggota untuk dihapus." << endl;
    } else {
        int index;
        cout << "Masukkan nomor anggota yang dihapus: ";
        cin >> index;
        if (index > 0 && index <= totalAnggota) {
            for (int i = index - 1; i < totalAnggota - 1; i++) {
                nama[i] = nama[i + 1];
                nomor[i] = nomor[i + 1];
                motor[i] = motor[i + 1];
                tahun[i] = tahun[i + 1];
            }
            totalAnggota--;
            cout << "Anggota dihapus!" << endl;
        } else {
            cout << "Nomor anggota tidak valid!" << endl;
        }
    }
    return 0;
}

int edit() {
    if (totalAnggota == 0) {
        cout << "Tidak ada anggota untuk diedit." << endl;
    } else {
        int index;
        cout << "Masukkan nomor anggota yang diedit: ";
        cin >> index;
        if (index > 0 && index <= totalAnggota) {
            cout << "Masukkan Nama Baru: ";
            cin.ignore();
            getline(cin, nama[index - 1]);
            cout << "Masukkan Jenis Motor Baru: ";
            getline(cin, motor[index - 1]);
            cout << "Masukkan Tahun Bergabung Baru: ";
            cin >> tahun[index - 1];
            cout << "Data diperbarui!" << endl;
        } else {
            cout << "Nomor anggota tidak valid!" << endl;
        }
    }
    return 0;
}

int main() {
    if (autentikasi() == 0) {
        return 0;
    }

    int pilihan;
    do {
        cout << "\nMENU:" << endl;
        cout << "1. Tambah Anggota" << endl;
        cout << "2. Tampilkan Anggota" << endl;
        cout << "3. Hapus Anggota" << endl;
        cout << "4. Edit Anggota" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Menambah anggota..." << endl;
                tambah();
                break;
            case 2:
                cout << "Menampilkan anggota..." << endl;
                tampilkan();
                break;
            case 3:
                cout << "Menghapus anggota..." << endl;
                hapus();
                break;
            case 4:
                cout << "Mengedit anggota..." << endl;
                edit();
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);
    return 0;
}
