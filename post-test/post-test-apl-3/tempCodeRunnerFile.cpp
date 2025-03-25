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
