#include <stdio.h>

int main() {
    int n, i;
    int score;
    long long sum = 0; // Menggunakan long long untuk mengakomodasi jumlah nilai yang besar
    double average;

    // Membaca nilai n
    scanf("%d", &n);

    // Membaca n nilai tugas mahasiswa dan menghitung totalnya
    for (i = 0; i < n; i++) {
        scanf("%d", &score);
        sum += score;
    }

    // Menghitung rata-rata
    if (n > 0) {
        average = (double)sum / n;
    } else {
        average = 0.0; // Jika n adalah 0, rata-rata juga 0
    }

    
    printf("%lld\n", sum);

    // Mencetak rata-rata dengan 2 digit presisi di belakang koma
    printf("%.2f\n", average);

    return 0;
}