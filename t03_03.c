#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <stdlib.h> // Diperlukan untuk fungsi exit() untuk menghentikan program

#define MAX_N 1000 // Menetapkan batas maksimum untuk jumlah nilai yang bisa diinput

int main() {
    int n;
    // Mendeklarasikan array untuk menyimpan semua nilai yang diinput
    // Menggunakan ukuran MAX_N untuk menghindari alokasi dinamis yang lebih kompleks untuk kasus ini.
    double values[MAX_N];
    double sum = 0.0;
    double average;
    int i;
    int scan_result;
    int count_above_average = 0; // Variabel untuk menyimpan hitungan nilai di atas/sama dengan rata-rata

    // --- Membaca jumlah nilai (n) ---
    scan_result = scanf("%d", &n);

    // Penanganan kesalahan untuk input n
    if (scan_result != 1) { // Jika scanf tidak berhasil membaca satu integer
        fprintf(stderr, "Error: Input 'n' tidak valid. Harap masukkan bilangan bulat.\n");
        return 1; // Keluar dengan kode error
    }
    if (n <= 0) { // Jika n adalah nol atau negatif
        fprintf(stderr, "Error: Input 'n' harus bilangan bulat positif.\n");
        return 1; // Keluar dengan kode error
    }
    if (n > MAX_N) { // Penanganan kesalahan jika n melebihi kapasitas array
        fprintf(stderr, "Error: Jumlah nilai 'n' terlalu besar (maksimal %d). Gunakan nilai yang lebih kecil.\n", MAX_N);
        return 1;
    }

    // --- Membaca n buah nilai dan menyimpannya ke array, sekaligus menghitung jumlahnya ---
    for (i = 0; i < n; i++) {
        scan_result = scanf("%lf", &values[i]); // Membaca setiap nilai sebagai double dan menyimpannya ke array

        // Penanganan kesalahan untuk setiap nilai
        if (scan_result != 1) {
            fprintf(stderr, "Error: Input nilai ke-%d tidak valid. Harap masukkan bilangan.\n", i + 1);
            return 1; // Keluar dengan kode error
        }
        sum += values[i]; // Menambahkan nilai ke total jumlah
    }

    // --- Menampilkan hasil yang pertama (Jumlah) ---
    printf("%.0lf\n", sum);

    // --- Menghitung rata-rata ---
    average = sum / n;

    // --- Menampilkan hasil yang kedua (Rata-rata) ---
    printf("%.2lf\n", average);

    // --- Menghitung banyaknya nilai yang di atas atau sama dengan rata-rata ---
    for (i = 0; i < n; i++) {
        if (values[i] >= average) { // Membandingkan setiap nilai dalam array dengan rata-rata
            count_above_average++; // Jika kondisi terpenuhi, increment counter
        }
    }

    // --- Menampilkan hasil yang ketiga (Banyaknya nilai di atas/sama dengan rata-rata) ---
    printf("%d\n", count_above_average);

    return 0; // Mengembalikan 0 menandakan program berhasil dieksekusi
}