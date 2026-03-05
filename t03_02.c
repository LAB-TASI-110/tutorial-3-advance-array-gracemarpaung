#include <stdio.h>
#include <stdlib.h> // Diperlukan untuk malloc

int main() {
    int n, i;
    int *scores; // Pointer untuk menyimpan nilai-nilai tugas
    long long sum = 0;
    double average;
    int count_above_average = 0;

    // Membaca nilai n
    scanf("%d", &n);

    // Alokasi memori untuk menan nilai-nilai
    // Kita perlu menyimpan nilai untuk iterasi kedua (menghitung yang di atas rata-rata)
    scores = (int *)malloc(n * sizeof(int));
    if (scores == NULL) {
        // Penanganan error jika alokasi memori gagal
        return 1;
    }

    // Membaca n nilai tugas mahasiswa dan menghitung totalnya
    for (i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
        sum += scores[i];
    }

    // Menghitung rata-rata
    if (n > 0) {
        average = (double)sum / n;
    } else {
        average = 0.0; // Jika n adalah 0, rata-rata juga 0
    }

    // Menghitung banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    for (i = 0; i < n; i++) {
        if (scores[i] >= average) {
            count_above_average++;
        }
    }

    // Mencetak total nilai
    printf("%lld\n", sum);

    // Mencetak rata-rata dengan 2 digit presisi di belakang koma
    printf("%.2f\n", average);

    // Mencetak banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    printf("%d\n", count_above_average);

    // Membebaskan memori yang dialokasikan
    free(scores);

    return 0;
}