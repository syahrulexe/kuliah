#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

struct Mahasiswa
{
    string MK;
    string Nama;
    string NIM;
    float Tugas1;
    float Tugas2;
    float UTS;
    float UAS;
};

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

int getOption(){
	int input;
    system("CLS");
	cout << "\nProgram Perhitungan data mahasiswa" << endl;
	cout << "=============================" << endl;
	cout << "1. Tambah data mahasiswa" << endl;
	cout << "2. Tampilkan data mahasiswa" << endl;
	cout << "3. Akhiri Program" << endl;
	cout << "=============================" << endl;
	cout << "pilih [1-3]? : ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return input;
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

void create(Mahasiswa mahasiswa[], int &jumlahData) {

    system("CLS");
    cout << "Berapaa data yang ingin dimasukan?\t: ";
    std::cin >> jumlahData;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("CLS");

    for(int i=0; i<jumlahData; ++i){
    cout << "Input Data Mahasiswa ke\t: "<< i+ 1 << "\n";
    cout << "Mata Kuliah\t: ";
    std::getline(std::cin, mahasiswa[i].MK);
    cout << "Nama\t\t: ";
    std::getline(std::cin, mahasiswa[i].Nama);
    cout << "NIM\t\t: ";
    std::getline(std::cin, mahasiswa[i].NIM);        
    
    validateInput(mahasiswa[i].Tugas1, "Tugas 1");
    validateInput(mahasiswa[i].Tugas2, "Tugas 2");
    validateInput(mahasiswa[i].UTS, "UTS");
    validateInput(mahasiswa[i].UAS, "UAS");
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
	cout << "kembali (tekan Y) lalu pilih 2 untuk menampilkan data" << endl;
}

void read(Mahasiswa mahasiswa[], int &jumlahData) {
    
    system("CLS");

    cout << "Hasil Perhitungan Nilai Akhir Mahasiswa\n";
    cout << "=======================================\n";
    cout << "\n";
    cout << std::left; 
    
	cout<<setw(5)<< "No"
        << setw(20) << "Mata Kuliah" 
        << setw(30) << "Nama Mahasiswa" 
        << setw(15) << "NIM" 
        << setw(15) << "Nilai Akhir" 
        << setw(15) << "Grade" 
        << endl;

    for(int i = 0; i < jumlahData; ++i) {
        
    float hasil = (mahasiswa[i].Tugas1 + mahasiswa[i].Tugas1 + mahasiswa[i].Tugas1 + mahasiswa[i].UAS) / 4.0f;
    string nilaiMutu = tentukanNilaiMutu(hasil);

    cout<<setw(5)<< i + 1
        << setw(20) << mahasiswa[i].MK 
        << setw(30) << mahasiswa[i].Nama 
        << setw(15) << mahasiswa[i].NIM 
        << setw(15) << hasil 
        << setw(15) << nilaiMutu 
        << endl;

    };

    if(jumlahData < 1){
    cout << "\n" <<"   Tidak ada data"<< "\n"<< "\n";
    };
}

int main(){
    int pilihan = getOption();
    char isContinue;
    int jumlahData;
    int MAX_MAHASISWA = 50;
    Mahasiswa mahasiswa[MAX_MAHASISWA];

	enum option{CREATE = 1, READ, FINISH};
    while(pilihan != FINISH){
        switch (pilihan){
            case CREATE:
                cout << "1. Tambah data mahasiswa" << endl;
                create(mahasiswa, jumlahData);
                break;
            case READ:
                cout << "2. TAMPILKAN data mahasiswa" << endl;
                read(mahasiswa, jumlahData);
                break;
            default:
                cout << "INPUT TIDAK VALID" << endl;
                break;
        }
        
        cout << "Lanjutkan? (y/n): ";
        cin >> isContinue;
        if (isContinue == 'n' || isContinue == 'N') {
            cin.get();
            break;
        } else if (isContinue != 'y' && isContinue != 'Y') {
            cout << "Input tidak valid. Silakan masukkan 'y' atau 'n'." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;  
        }
        pilihan = getOption();
    }

	cout << "terimakasih telah mencoba demo program ini" << endl;
    cin.get();
    return 0;
}




