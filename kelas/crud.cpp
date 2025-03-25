#include <iostream>

using namespace std;

int main() {
    int panjang = 0;
    string buah [MAX_BUAH];

    int pilihan, index;
    do {
    system("clear");
    cout << "Menu Program"      << endl;
    cout << "1. Tampilkan Buah" << endl;
    cout << "2. Tambah Buah"    << endl;
    cout << "3. Ubah Buah"      << endl;
    cout << "4. Hapus Buah"     << endl;
    cout << "5. Keluar"         << endl;
    cout << "Pilihan: ";
    cin  >> pilihan;
    