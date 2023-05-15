#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define A_SIZE 20 // dizi uzunluğunun tanımlanması
#define G_SIZE 10 // g grafiğinin düğüm sayısı uzunluğu
#define MAX_W 10

//Max deger icin sonsuz sayi
#define INF INT_MAX

void generate(int a[], int size); // diziyi oluşturma
void quickSortSiralamasi(int a[], int left, int right); // dizinin QuickSort ile sıralanması
void quickSortPrint(int a[], int size); // dizinin sıralanmış halinin ekrana bastırılması

int pozitifToplamOrtalamaBul(int a[], int size); // en büyük pozitif toplamın ortalaması
void pozitifMaxBulPrint(int g[][G_SIZE], int size); // en büyük pozitif toplam değerinin ekrana bastırılması

void floydWarshall(int g[][G_SIZE], int d[][G_SIZE], int size); // floydwarshall ile graflar arasındaki en kısa yolu bulma
void floydWarshallPrint(int g[][G_SIZE], int size, int t); // floydwarshall ile graflar arasındaki en kısa yolun ekraa bastırılması



int main() {
    int a[A_SIZE];
    // G_SIZE ile belirtilen 10 düğümlü grafın matris şeklinde gösterilmesi
    int g[G_SIZE][G_SIZE] = {
    { 0, 10,  3,  0,  0,  5,  0, 17,  0, 22},
    {10,  0,  5,  0,  2,  0, 13,  0,  0,  0},
    { 3,  5,  0,  2,  0,  4,  0, 21,  0, 11},
    { 0,  0,  2,  0,  7,  0,  6,  0,  0,  0},
    { 0,  2,  0,  7,  0,  6,  0,  0, 19,  0},
    { 5,  0,  4,  0,  6,  0,  9,  3,  0,  0},
    { 0, 13,  0,  6,  0,  9,  0,  4,  0,  0},
    {17,  0, 21,  0,  0,  3,  4,  0,  8,  0},
    { 0,  0,  0,  0, 19,  0,  0,  8,  0,  5},
    {22,  0, 11,  0,  0,  0,  0,  0,  5,  0}
    };
    int d[G_SIZE][G_SIZE]; // düğümün birbiri arasındaki uzaklk
    int t; // ortalama değer

    // Rastgele sayi uretici icin seed
    srand(time(NULL));

    // Calisma suresinin hesaplanmasi
    clock_t start, end;
    double time;

    start = clock();

    
    generate(a, A_SIZE);
    printf("A:\n");
    quickSortPrint(a, A_SIZE);


    quickSortSiralamasi(a, 0, A_SIZE - 1); // Quick Sort
    printf("\nQuick Sort Sıralama Sonuc:\n");
    quickSortPrint(a, A_SIZE);


    t = pozitifToplamOrtalamaBul(a, A_SIZE);
    printf("\nEn Büyük Pozitif Toplam Sonucu: %d\n", t);

    printf("\nG:\n");
    pozitifMaxBulPrint(g, G_SIZE);

    floydWarshall(g, d, G_SIZE);
    printf("\nFloyd Warshall Sonucu:\n");
    pozitifMaxBulPrint(d, G_SIZE);

    printf("\n%d icin sonuc:\n", t);
    floydWarshallPrint(d, G_SIZE, t);

    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nCalisma Suresi: %f sn\n", time);

    return 0;
}

//Random dizi oluşturulması
void generate(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % (2 * MAX_W) - MAX_W;
    }
}

// dizini quicksort ile sıralanması
void quickSortSiralamasi(int a[], int left, int right) {
    if (left < right) {
           int pivot = a[left];
           int i = left;
           int j = right;
           while (i < j) {
               // while döngüleri i ve j değerlerini karşılaştırarak pivot elemanın konumunu bulmaya çalışır
               while (i < j && a[j] >= pivot)
                   j--;
               if (i < j) a[i++] = a[j];
               
               while (i < j && a[i] < pivot)
                   i++;
               if (i < j) a[j--] = a[i];
           }
           a[i] = pivot;
           quickSortSiralamasi(a, left, i - 1);
           quickSortSiralamasi(a, i + 1, right);
       }
}

// en büyük pozitif toplamın ortalamasının hesaplanması
int pozitifToplamOrtalamaBul(int a[], int size) {
    int t = 0, current_sum = 0, count=0;
    for (int i = 0; i < size; i++) {
        if (current_sum + a[i] > 0) {
            current_sum = current_sum + a[i];
        }
        else {
            current_sum = 0;
        }
        if (current_sum > t) {
            t = current_sum;
            count++;
        }
    }
    return t/count;
}

// graflardaki düğümler arasındaki en kısa yolun hesaplanması
void floydWarshall(int g[][G_SIZE], int d[][G_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                d[i][j] = 0;
            }
            else if (g[i][j] != 0) {
                d[i][j] = g[i][j];
            }
            else {
                d[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (d[i][k] != INF && d[k][j] != INF &&
                    d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

// Quicksort ile sıralanmış dizinin ekrana bastırması için gerekli fonksiyon
void quickSortPrint(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

// en büyük pozitif toplamın ortalamasının ekrana bastırması için gerekli fonksiyon
void pozitifMaxBulPrint(int g[][G_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (g[i][j] == INF) {
                printf("INF ");
            }
            else {
                printf("%3d ", g[i][j]);
            }
        }
        printf("\n");
    }
}

// floyd-warshall fonksiyonunu ekrana bastırması için gerekli fonksiyon
void floydWarshallPrint(int d[][G_SIZE], int size, int t) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && d[i][j] < t) {
                printf("%c -> %c: %d\n", 'A' + i, 'A' + j, d[i][j]);
            }
        }
    }
}
