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
    "Ýnkýlap Tarihi"
};

int secilen_dersler[TOPLAM_DERS] = {0}; 
int secilen_sayisi = 0;

void tum_dersleri_goster() {
    printf("Mevcut Dersler:\n");
    for (int i = 0; i < TOPLAM_DERS; i++) {
        printf("%d. %s%s\n", i + 1, tum_dersler[i], secilen_dersler[i] ? " [SEÇÝLDÝ]" : "");
    }
}

void secilen_dersleri_goster() {
    printf("Seçtiðiniz Dersler:\n");
    int bos = 1;
    for (int i = 0; i < TOPLAM_DERS; i++) {
        if (secilen_dersler[i]) {
            printf("- %s\n", tum_dersler[i]);
            bos = 0;
        }
    }
    if (bos) {
        printf("Henüz hiç ders seçilmedi.\n");
    }
}

void ders_ekle() {
    if (secilen_sayisi >= MAX_DERS) {
        printf("Maksimum %d ders seçebilirsiniz.\n", MAX_DERS);
        return;
    }

    tum_dersleri_goster();
    int secim;
    printf("Eklemek istediðiniz dersin numarasýný girin: ");
    scanf("%d", &secim);

    if (secim < 1 || secim > TOPLAM_DERS) {
        printf("Geçersiz seçim.\n");
        return;
    }

    if (secilen_dersler[secim - 1]) {
        printf("Bu dersi zaten seçmiþsiniz.\n");
        return;
    }

    secilen_dersler[secim - 1] = 1;
    secilen_sayisi++;
    printf("%s dersi eklendi.\n", tum_dersler[secim - 1]);
}

void ders_birak() {
    if (secilen_sayisi == 0) {
        printf("Hiç seçili ders yok.\n");
        return;
    }

    secilen_dersleri_goster();
    int secim;
    printf("Býrakmak istediðiniz dersin numarasýný girin (1-6): ");
    scanf("%d", &secim);

    if (secim < 1 || secim > TOPLAM_DERS || !secilen_dersler[secim - 1]) {
        printf("Bu ders seçilmemiþ veya geçersiz numara.\n");
        return;
    }

    secilen_dersler[secim - 1] = 0;
    secilen_sayisi--;
    printf("%s dersi býrakýldý.\n", tum_dersler[secim - 1]);
}

int main() {
    int secim;

    do {
        printf("\n--- DERS EKLEME / BIRAKMA SÝSTEMÝ ---\n");
        printf("1. Ders Ekle\n");
        printf("2. Ders Býrak\n");
        printf("3. Seçilen Dersleri Görüntüle\n");
        printf("4. Tüm Dersleri Görüntüle\n");
        printf("5. Çýkýþ\n");
        printf("Seçiminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1: ders_ekle(); break;
            case 2: ders_birak(); break;
            case 3: secilen_dersleri_goster(); break;
            case 4: tum_dersleri_goster(); break;
            case 5: printf("Çýkýþ yapýlýyor...\n"); break;
            default: printf("Geçersiz seçim.\n");
        }
    } while (secim != 5);

    return 0;
}

