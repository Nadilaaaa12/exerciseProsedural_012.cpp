#include <iostream>
using namespace std;

int Kandidat = 5;         //menentukan kandidat
char nama[5][50];
int nilaiM[5];
int nilaiBing[5];

void inputData() {          //void tidak mengembalikan nilai
	for (int i = 0; i < Kandidat; i++) {
		cout << "Masukkan Nama Kandidat" << i + 1 << ": ";
		cin.getline(nama[i], 50);
		cout << "Masukkan Nilai Matematika : ";
		cin >> nilaiM[i];
		cout << "Masukkan Nilai Bahasa Inggris : ";
		cin >> nilaiBing[i];
		cin.ignore();
		cout << endl;
	}
}

bool diterima(int index) {       //mengembalikan nilai boolean
	return(nilaiM[index] > 80 or (nilaiM[index] + nilaiBing[index]) / 2 >= 70);
}

void tampilkandata() {           //menampilkan data kandidat pada layar
	cout << "Data Kandidat : " << endl;
	cout << "Nama" << "\t\t" << "Status" << endl;
	for (int i = 0; i < Kandidat; i++) {
		cout << nama[i] << "\t\t";
		if (diterima(i)) {
			cout << "Diterima";
		}
		else {
			cout << "Tidak Diterima";
		}
		cout << endl;
	}
	cout << endl;
}

void hitungjumlahditerima() {     //menghitung jumlah kandidat ygditerima dan tidakditerima
	int ygditerima = 0;
	int ygtidakditerima = 0;

	for (int i = 0; i < Kandidat; i++) {
		if (diterima(i)) {
			ygditerima++;
		}
		else {
			ygtidakditerima++;
		}
	}
	cout << "Jumlah Kandidat Diterima: " << ygditerima << endl;
	cout << "Jumlah Kandidat yang Tidak Diterima: " << ygtidakditerima << endl;
}

int main() {                        //yang akan dijalankan pertama kali ketika program dijalankan
	inputData();
	tampilkandata();
	hitungjumlahditerima();
	return 0;
}
