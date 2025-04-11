#include <iostream>
using namespace std;

#define MAX_ANGGOTA 100

struct Anggota {
    string nama;
    int nomor;
    string motor;
    int tahun;
};

int autentikasi() {
    const string username_benar = "Devon";
    const string nim_benar = "6055";
    const int max_percobaan = 3;
    bool beri_akses = false;

    for (int percobaan = 1; percobaan <= max_percobaan; percobaan++) {
        string input_username, input_nim;
        cout << "Masukkan Nama: ";
        cin >> ws; getline(cin, input_username);
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

void tambahAnggota(Anggota data[], int &total) {
    if (total < MAX_ANGGOTA) {
        cout << "Masukkan Nama: ";
        cin >> ws; getline(cin, data[total].nama);
        cout << "Masukkan Nomor Anggota: ";
        cin >> data[total].nomor;
        cout << "Masukkan Jenis Motor: ";
        cin >> ws; getline(cin, data[total].motor);
        cout << "Masukkan Tahun Bergabung: ";
        cin >> data[total].tahun;
        total++;
        cout << "Anggota berhasil ditambahkan!" << endl;
    } else {
        cout << "Data penuh!" << endl;
    }
}

void tampilkanAnggota(Anggota data[], int total) {
    if (total == 0) {
        cout << "Tidak ada anggota." << endl;
    } else {
        cout << "\n----------------------------------------------------------------------" << endl;
        cout << "| No  | Nama              | No. Anggota | Jenis Motor       | Tahun |" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        for (int i = 0; i < total; i++) {
            cout << "| " << i + 1 << "   | " 
                << data[i].nama << string(18 - data[i].nama.length(), ' ') << "| "
                << data[i].nomor << "           | "
                << data[i].motor << string(17 - data[i].motor.length(), ' ') << "| "
                << data[i].tahun << "   |" << endl;
        }
        cout << "----------------------------------------------------------------------" << endl;
    }
}

void hapusAnggota(Anggota data[], int &total) {
    if (total == 0) {
        cout << "Tidak ada anggota untuk dihapus." << endl;
    } else {
        int index;
        cout << "Masukkan nomor anggota yang dihapus: ";
        cin >> index;
        if (index > 0 && index <= total) {
            for (int i = index - 1; i < total - 1; i++) {
                data[i] = data[i + 1];
            }
            total--;
            cout << "Anggota dihapus!" << endl;
        } else {
            cout << "Nomor anggota tidak valid!" << endl;
        }
    }
}

void editAnggota(Anggota data[], int total) {
    if (total == 0) {
        cout << "Tidak ada anggota untuk diedit." << endl;
    } else {
        int index;
        cout << "Masukkan nomor anggota yang diedit: ";
        cin >> index;
        if (index > 0 && index <= total) {
            cout << "Masukkan Nama Baru: ";
            cin >> ws; getline(cin, data[index - 1].nama);
            cout << "Masukkan Jenis Motor Baru: ";
            getline(cin, data[index - 1].motor);
            cout << "Masukkan Tahun Bergabung Baru: ";
            cin >> data[index - 1].tahun;
            cout << "Data diperbarui!" << endl;
        } else {
            cout << "Nomor anggota tidak valid!" << endl;
        }
    }
}

int main() {
    if (autentikasi() == 0) return 0;

    Anggota anggota[MAX_ANGGOTA];
    int totalAnggota = 0;
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
                tambahAnggota(anggota, totalAnggota);
                break;
            case 2:
                tampilkanAnggota(anggota, totalAnggota);
                break;
            case 3:
                hapusAnggota(anggota, totalAnggota);
                break;
            case 4:
                editAnggota(anggota, totalAnggota);
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
