#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

void validateInput(float &nilai, const string &nilaiLabel) {
    do {
        cout << "Nilai " << nilaiLabel << "\t: ";
        while (!(cin >> nilai) || nilai < 0 || nilai > 100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR! Pastikan memasukkan angka nilai dari 0-100\nNilai " << nilaiLabel << "\t: ";
        }
    } while (false);

}

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
    } else {
        return "E";
    }
}

int main() {
    string MK, Nama, NIM;
    float Tugas1, Tugas2, UTS, UAS;

    cout << "Perhitungan Nilai Akhir Mahasiswa\n";
    cout << "=======================================\n";
    cout << "1. Masukan Data" << MK << "\n";
    cout << "2. Tampilkan Data" << Nama << "\n";
    cout << "3. aaaaasdsdad" << Nama << "\n";

    cout << "Mata Kuliah\t: ";
    getline(cin, MK);
    cout << "Nama\t\t: ";
    getline(cin, Nama);
    cout << "NIM\t\t: ";
    getline(cin, NIM);
    
    validateInput(Tugas1, "Tugas 1");
    validateInput(Tugas2, "Tugas 2");
    validateInput(UTS, "UTS");
    validateInput(UAS, "UAS");
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    

    float hasil = (Tugas1 + Tugas2 + UTS + UAS) / 4.0f;
    string nilaiMutu = tentukanNilaiMutu(hasil);

    cout << "Hasil Perhitungan Nilai Akhir Mahasiswa\n";
    cout << "=======================================\n";
    cout << "Mata Kuliah\t: " << MK << "\n";
    cout << "Nama\t\t: " << Nama << "\n";
    cout << "NIM\t\t\t: " << NIM << "\n";
    cout << "Nilai Akhir\t: " << fixed << setprecision(2) << hasil << "\n";
    cout << "Nilai Mutu\t: " << nilaiMutu << "\n";

    cout << "\nPress Enter to exit...";
    getchar();

    return 0;
}

