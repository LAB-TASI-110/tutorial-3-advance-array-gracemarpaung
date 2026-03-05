#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <stdlib.h> // Diperlukan untuk fungsi exit() untuk menghentikan program

int main() {
    int n;
    double sum = 0.0;
    double value;
    int i;
    int scan_result;

    // --- Membaca jumlah nilai (n) ---
    // Memberikan instruksi kepada pengguna (opsional, tapi bagus untuk user experience)
    // Walaupun format output tidak boleh ada teks, format input bisa saja ada.
    // Namun, sesuai instruksi, kita asumsikan tidak ada teks instruksi di output final.
    // Jika input tidak valid, kita akan keluar dengan pesan error ke stderr (standar C untuk error)
    // agar tidak mengganggu stdout (tempat output hasil).

    // Baca nilai n
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

    // --- Membaca n buah nilai dan menghitung jumlahnya ---
    for (i = 0; i < n; i++) {
        scan_result = scanf("%lf", &value); // Membaca setiap nilai sebagai double

        // Penanganan kesalahan untuk setiap nilai
        if (scan_result != 1) {
            fprintf(stderr, "Error: Input nilai ke-%d tidak valid. Harap masukkan bilangan.\n", i + 1);
            return 1; // Keluar dengan kode error
        }
        sum += value; // Menambahkan nilai ke total jumlah
    }

    // --- Menampilkan hasil ---
    // 1. Jumlah seluruh nilai (tanpa desimal karena output contoh)
    printf("%.0lf\n", sum);

    // 2. Nilai rata-rata dengan 2 digit presisi
    printf("%.2lf\n", sum / n);

    return 0; // Mengembalikan 0 menandakan program berhasil dieksekusi
}

