#include <iostream>
#include <limits>
using namespace std;

#define MAX_ANGGOTA 100

// Struct untuk menyimpan data anggota
struct Anggota {
    string nama;
    int nomor;
    string motor;
    int tahun;
};

// Fungsi autentikasi 
int autentikasi() {
    string username_benar = "Devon";
    string nim_benar = "6055";
    int max_percobaan = 3;
    bool beri_akses = false;

    for (int percobaan = 1; percobaan <= max_percobaan; percobaan++) {
        string input_username, input_nim;
        cout << "Masukkan Nama: ";
        getline(cin >> std::ws, input_username);
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

// Fungsi penambahan anggota
void tambahAnggota(Anggota *data, int *total) {
    if (*total < MAX_ANGGOTA) {
        cout << "Masukkan Nama: ";
        getline(cin >> std::ws, (data + *total)->nama);
        cout << "Masukkan Nomor Anggota: ";
        cin >> (data + *total)->nomor;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukkan Jenis Motor: ";
        getline(cin, (data + *total)->motor);
        cout << "Masukkan Tahun Bergabung: ";
        cin >> (data + *total)->tahun;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        (*total)++;
        cout << "Anggota berhasil ditambahkan!" << endl;
    } else {
        cout << "Data penuh!" << endl;
    }
}

// Fungsi menampilkan anggota
void tampilkanAnggota(Anggota *data, int *total) {
    if (*total == 0) {
        cout << "Tidak ada anggota." << endl;
    } else {
        cout << "\n----------------------------------------------------------------------" << endl;
        cout << "| No  | Nama              | No. Anggota | Jenis Motor       | Tahun |" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        for (int i = 0; i < *total; i++) {
            cout << "| " << i + 1 << "   | " 
                << (data + i)->nama << string(18 - (data + i)->nama.length(), ' ') << "| "
                << (data + i)->nomor << "           | "
                << (data + i)->motor << string(17 - (data + i)->motor.length(), ' ') << "| "
                << (data + i)->tahun << "   |" << endl;
        }
        cout << "----------------------------------------------------------------------" << endl;
    }
}

// Fungsi menghapus data anggota
void hapusAnggota(Anggota *data, int *total) {
    if (*total == 0) {
        cout << "Tidak ada anggota untuk dihapus." << endl;
    } else {
        int index;
        cout << "Masukkan nomor anggota yang dihapus: ";
        cin >> index;
        if (index > 0 && index <= *total) {
            for (int i = index - 1; i < *total - 1; i++) {
                *(data + i) = *(data + i + 1);
            }
            (*total)--;
            cout << "Anggota dihapus!" << endl;
        } else {
            cout << "Nomor anggota tidak valid!" << endl;
        }
    }
}

// Fungsi mengedit data anggota
void editAnggota(Anggota *data, int *total) {
    if (*total == 0) {
        cout << "Tidak ada anggota untuk diedit." << endl;
    } else {
        int index;
        cout << "Masukkan nomor anggota yang diedit: ";
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (index > 0 && index <= *total) {
            cout << "Masukkan Nama Baru: ";
            getline(cin, (data + index - 1)->nama);
            cout << "Masukkan Jenis Motor Baru: ";
            getline(cin, (data + index - 1)->motor);
            cout << "Masukkan Tahun Bergabung Baru: ";
            cin >> (data + index - 1)->tahun;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Data diperbarui!" << endl;
        } else {
            cout << "Nomor anggota tidak valid!" << endl;
        }
    }
}

// Bubble Sort berdasarkan nama (A-Z)
void bubbleSortNamaAsc(Anggota data[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (data[j].nama > data[j + 1].nama) {
                swap(data[j], data[j + 1]);
            }
        }
    }
    cout << "Data telah diurutkan berdasarkan nama (A-Z) menggunakan Bubble Sort.\n";
}

// Merge Sort berdasarkan tahun (desc)
void merge(Anggota arr[], int l, int m, int r) {
    Anggota temp[MAX_ANGGOTA];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (arr[i].tahun >= arr[j].tahun) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (int x = 0; x < k; x++) {
        arr[l + x] = temp[x];
    }
}

void mergeSortTahunDesc(Anggota arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSortTahunDesc(arr, l, m);
        mergeSortTahunDesc(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort berdasarkan nomor (asc)
void quickSortNomor(Anggota arr[], int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    int pivot = arr[mid].nomor;
    int i = low, j = high;
    while (i <= j) {
        while (arr[i].nomor < pivot) i++;
        while (arr[j].nomor > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (low < j) quickSortNomor(arr, low, j);
    if (i < high) quickSortNomor(arr, i, high);
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
        cout << "5. Urutkan Data Anggota" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahAnggota(anggota, &totalAnggota);
                break;
            case 2:
                tampilkanAnggota(anggota, &totalAnggota);
                break;
            case 3:
                hapusAnggota(anggota, &totalAnggota);
                break;
            case 4:
                editAnggota(anggota, &totalAnggota);
                break;
            case 5: {
                int subPilihan;
                cout << "\nPILIH METODE SORTING:\n";
                cout << "1. Bubble Sort - Nama (A-Z)\n";
                cout << "2. Merge Sort - Tahun (Desc)\n";
                cout << "3. Quick Sort - Nomor (Asc)\n";
                cout << "Pilihan: ";
                cin >> subPilihan;
                switch (subPilihan) {
                    case 1:
                        bubbleSortNamaAsc(anggota, totalAnggota);
                        break;
                    case 2:
                        mergeSortTahunDesc(anggota, 0, totalAnggota - 1);
                        cout << "Data telah diurutkan berdasarkan tahun bergabung menggunakan Merge Sort (Descending).\n";
                        break;
                    case 3:
                        quickSortNomor(anggota, 0, totalAnggota - 1);
                        cout << "Data telah diurutkan berdasarkan nomor anggota menggunakan Quick Sort (Ascending).\n";
                        break;
                    default:
                        cout << "Pilihan tidak valid.\n";
                }
                break;
            }
            case 6:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 6);

    return 0;
}
