#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

// Struct untuk KTP
struct KTP {
    string nik;
    string nama;
    string alamat;
};

// Program untuk entri data KTP dan menyimpannya ke file
void programKTP() {
    ofstream file("data_ktp.txt", ios::app);
    if (!file) {
        cerr << "Gagal membuka file data_ktp.txt!" << endl;
        return;
    }

    int jumlah;
    cout << "Masukkan jumlah KTP yang akan dientri (maksimal 3): ";
    cin >> jumlah;
    cin.ignore();

    for (int i = 0; i < jumlah; ++i) {
        KTP ktp;
        cout << "\nData KTP ke-" << i + 1 << ":\n";
        cout << "NIK: ";
        getline(cin, ktp.nik);
        cout << "Nama: ";
        getline(cin, ktp.nama);
        cout << "Alamat: ";
        getline(cin, ktp.alamat);

        file << ktp.nik << "|" << ktp.nama << "|" << ktp.alamat << "\n";
    }

    file.close();
    cout << "Data KTP berhasil disimpan ke file data_ktp.txt!\n";
}

// Struct untuk barang di gudang
struct Item {
    string kode;
    string tanggal;
};

// Program untuk inventori barang dengan metode LIFO
void programLIFO() {
    stack<Item> lifoGudang;
    int jumlah;
    cout << "Masukkan jumlah barang yang akan dientri: ";
    cin >> jumlah;
    cin.ignore();

    for (int i = 0; i < jumlah; ++i) {
        Item item;
        cout << "\nBarang ke-" << i + 1 << ":\n";
        cout << "Kode Item: ";
        getline(cin, item.kode);
        cout << "Tanggal Masuk (YYYY-MM-DD): ";
        getline(cin, item.tanggal);
        lifoGudang.push(item);
    }

    cout << "Barang berhasil dientri ke gudang (LIFO).\n";

    cout << "\nBarang yang dijual (LIFO):\n";
    while (!lifoGudang.empty()) {
        Item item = lifoGudang.top();
        lifoGudang.pop();
        cout << "Kode: " << item.kode << ", Tanggal Masuk: " << item.tanggal << "\n";
    }
}

// Program untuk inventori barang dengan metode FIFO
void programFIFO() {
    queue<Item> fifoGudang;
    int jumlah;
    cout << "Masukkan jumlah barang yang akan dientri: ";
    cin >> jumlah;
    cin.ignore();

    for (int i = 0; i < jumlah; ++i) {
        Item item;
        cout << "\nBarang ke-" << i + 1 << ":\n";
        cout << "Kode Item: ";
        getline(cin, item.kode);
        cout << "Tanggal Masuk (YYYY-MM-DD): ";
        getline(cin, item.tanggal);
        fifoGudang.push(item);
    }

    cout << "Barang berhasil dientri ke gudang (FIFO).\n";

    cout << "\nBarang yang dijual (FIFO):\n";
    while (!fifoGudang.empty()) {
        Item item = fifoGudang.front();
        fifoGudang.pop();
        cout << "Kode: " << item.kode << ", Tanggal Masuk: " << item.tanggal << "\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\nPilih Program:\n";
        cout << "1. Program KTP\n";
        cout << "2. Program Inventori Barang (LIFO)\n";
        cout << "3. Program Inventori Barang (FIFO)\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
        case 1:
            programKTP();
            break;
        case 2:
            programLIFO();
            break;
        case 3:
            programFIFO();
            break;
        case 4:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 4);

    return 0;
}
