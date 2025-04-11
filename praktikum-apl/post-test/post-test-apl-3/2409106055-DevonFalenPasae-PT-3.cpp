#include <iostream>
using namespace std;

#define MAX_ANGGOTA 100
struct Anggota {
    string nama;
    int nomor;
    string motor;
    int tahun;
};

Anggota anggota[MAX_ANGGOTA];
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
        getline(cin, anggota[totalAnggota].nama);
        cout << "Masukkan Nomor Anggota: ";
        cin >> anggota[totalAnggota].nomor;
        cout << "Masukkan Jenis Motor: ";
        cin.ignore();
        getline(cin, anggota[totalAnggota].motor);
        cout << "Masukkan Tahun Bergabung: ";
        cin >> anggota[totalAnggota].tahun;
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
                << anggota[i].nama << string(18 - anggota[i].nama.length(), ' ') << "| "
                << anggota[i].nomor << "           | "
                << anggota[i].motor << string(17 - anggota[i].motor.length(), ' ') << "| "
                << anggota[i].tahun << "   |" << endl;
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
                anggota[i] = anggota[i + 1];
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
            getline(cin, anggota[index - 1].nama);
            cout << "Masukkan Jenis Motor Baru: ";
            getline(cin, anggota[index - 1].motor);
            cout << "Masukkan Tahun Bergabung Baru: ";
            cin >> anggota[index - 1].tahun;
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
