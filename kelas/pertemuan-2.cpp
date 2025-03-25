#include <iostream>

using namespace std;

int main() 

string nama[5] = {"Dimas", "Harahap", "Santoso", "Kalingga", "Ucup"}

int angka[3]; 
angka[0] = 1;
angka[1] = 2;
angka[2] = 3;

//int angka [5] = {1, 2, 3, 4, 5};
//cout << sizeof(angka);

//cout << nama[0] << endl;
//cout << angka[2] << endl:

int panjang1 = sizeof(angka) / sizeof(angka[0]);


//looping

for (int i = 0; i < panjang1; 1++) {
    cout << angka[i] << endl;
}

for(int item: angka) {

}

