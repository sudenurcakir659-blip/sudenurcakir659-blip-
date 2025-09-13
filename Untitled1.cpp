#include <stdio.h>
#include <string.h>

#define MAX_DERS 5
#define TOPLAM_DERS 6

char tum_dersler[TOPLAM_DERS][50] = {
    "Matematik",
    "Fizik",
    "Lineer Cebir",
    "Bilgisayar Programlama",
    "Edebiyat",
    "�nk�lap Tarihi"
};

int secilen_dersler[TOPLAM_DERS] = {0}; 
int secilen_sayisi = 0;

void tum_dersleri_goster() {
    printf("Mevcut Dersler:\n");
    for (int i = 0; i < TOPLAM_DERS; i++) {
        printf("%d. %s%s\n", i + 1, tum_dersler[i], secilen_dersler[i] ? " [SE��LD�]" : "");
    }
}

void secilen_dersleri_goster() {
    printf("Se�ti�iniz Dersler:\n");
    int bos = 1;
    for (int i = 0; i < TOPLAM_DERS; i++) {
        if (secilen_dersler[i]) {
            printf("- %s\n", tum_dersler[i]);
            bos = 0;
        }
    }
    if (bos) {
        printf("Hen�z hi� ders se�ilmedi.\n");
    }
}

void ders_ekle() {
    if (secilen_sayisi >= MAX_DERS) {
        printf("Maksimum %d ders se�ebilirsiniz.\n", MAX_DERS);
        return;
    }

    tum_dersleri_goster();
    int secim;
    printf("Eklemek istedi�iniz dersin numaras�n� girin: ");
    scanf("%d", &secim);

    if (secim < 1 || secim > TOPLAM_DERS) {
        printf("Ge�ersiz se�im.\n");
        return;
    }

    if (secilen_dersler[secim - 1]) {
        printf("Bu dersi zaten se�mi�siniz.\n");
        return;
    }

    secilen_dersler[secim - 1] = 1;
    secilen_sayisi++;
    printf("%s dersi eklendi.\n", tum_dersler[secim - 1]);
}

void ders_birak() {
    if (secilen_sayisi == 0) {
        printf("Hi� se�ili ders yok.\n");
        return;
    }

    secilen_dersleri_goster();
    int secim;
    printf("B�rakmak istedi�iniz dersin numaras�n� girin (1-6): ");
    scanf("%d", &secim);

    if (secim < 1 || secim > TOPLAM_DERS || !secilen_dersler[secim - 1]) {
        printf("Bu ders se�ilmemi� veya ge�ersiz numara.\n");
        return;
    }

    secilen_dersler[secim - 1] = 0;
    secilen_sayisi--;
    printf("%s dersi b�rak�ld�.\n", tum_dersler[secim - 1]);
}

int main() {
    int secim;

    do {
        printf("\n--- DERS EKLEME / BIRAKMA S�STEM� ---\n");
        printf("1. Ders Ekle\n");
        printf("2. Ders B�rak\n");
        printf("3. Se�ilen Dersleri G�r�nt�le\n");
        printf("4. T�m Dersleri G�r�nt�le\n");
        printf("5. ��k��\n");
        printf("Se�iminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1: ders_ekle(); break;
            case 2: ders_birak(); break;
            case 3: secilen_dersleri_goster(); break;
            case 4: tum_dersleri_goster(); break;
            case 5: printf("��k�� yap�l�yor...\n"); break;
            default: printf("Ge�ersiz se�im.\n");
        }
    } while (secim != 5);

    return 0;
}

