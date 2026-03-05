#include <stdio.h>
#include <stdlib.h> // Diperlukan untuk malloc dan free
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN

int main() {
    int n, i;
    int *scores; // Pointer untuk menyimpan nilai-nilai tugas
    long long sum = 0;
    double average;
    int count_above_average = 0;
    int min_score = INT_MAX; // Inisialisasi dengan nilai maksimum integer
    int max_score = INT_MIN; // Inisialisasi dengan nilai minimum integer

    // Membaca nilai n
    scanf("%d", &n);

    // Alokasi memori untuk menyimpan nilai-nilai
    scores = (int *)malloc(n * sizeof(int));
    if (scores == NULL) {
        // Penanganan error jika alokasi memori gagal
        return 1;
    }

    // Membaca n nilai tugas mahasiswa, menghitung total, serta mencari min dan max
    for (i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
        sum += scores[i];

        if (scores[i] < min_score) {
            min_score = scores[i];
        }
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }

    // Menghitung rata-rata
    if (n > 0) {
        average = (double)sum / n;
    } else {
        average = 0.0; // Jika n adalah 0, rata-rata juga 0
    }

    // Menghitung banyaknya mahasiswa yang ni atas atau sama dengan rata-rata
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

    // Mencetak rentang nilai (max_score - min_score)
    // Periksa jika n > 0 untuk menghindari masalah jika tidak ada nilai
    if (n > 0) {
        printf("%d\n", max_score - min_score);
    } else {
        printf("0\n"); // Atau penanganan lain jika tidak ada nilai
    }

    // Membebaskan memori yang dialokasikan
    free(scores);

    return 0;
}