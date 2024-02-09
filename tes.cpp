#include <iostream>
#include <cstdio>  // Include the <cstdio> header for getchar()// 
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

string tentukanNilaiMutu(float hasil) {
    if (hasil >= 80) {
        return "A";
    } else if (hasil >= 77) {
        return "A-";
    } else if (hasil >= 74) {
        return "B+";
    } else if (hasil >= 71) {
        return "B";
    } else if (hasil >= 68) {
        return "B-";
    } else if (hasil >= 64) {
        return "C+";
    } else if (hasil >= 56) {
        return "C";
    } else if (hasil >= 46) {
        return "D";
    } else{
        return "E";
    }    

    return ""; 
}

int main() {
    string MK, Nama, NIM;
    float Tugas1, Tugas2, UTS, UAS;

    cout << "Mata Kuliah: ";
    getline(cin, MK);
    cout << "Nama: ";
    getline(cin, Nama);
    cout << "NIM: ";
    getline(cin, NIM);
    
    // Read numerical values
    cout << "Nilai Tugas 1: ";
    cin >> Tugas1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer
    cout << "Nilai Tugas 2: ";
    cin >> Tugas2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer
    cout << "Nilai UTS: ";
    cin >> UTS;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer
    cout << "Nilai UAS: ";
    cin >> UAS;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer

    float hasil = (Tugas1 + Tugas2 + UTS + UAS) / 4.0f;

    cout << "\nHasil Perhitungan Nilai Akhir Mahasiswa\n";
    cout << "=======================================\n";
    cout << "Mata Kuliah: \t" << MK << "\n";
    cout << "Nama: \t\t" << Nama << "\n";
    cout << "NIM: \t\t" << NIM << "\n";
    cout << "Nilai Akhir: \t" << hasil << "\n";

    string nilaiMutu = tentukanNilaiMutu(hasil);
    if (!nilaiMutu.empty()) {
        cout << "Nilai Mutu: " << nilaiMutu << "\n";
    } else {
        cout << "Nilai Mutu tidak terdefinisi\n";
    }

    // Add a pause before exiting
    cout << "\nPress Enter to exit...";
    getchar();

    return 0;
}
