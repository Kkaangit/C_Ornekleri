//Uzunluk seçilir ve kalıcı olur. Program bitene kadar değiştirilemez.
//Dosya adı kullanıcı tarafından seçilir.
#include <stdio.h>
#include <stdlib.h>
typedef enum {
    metre =1, santimetre, milimetre
}birim;

void secenek(birim sayi);
const char *Cevir(birim tur);

int main() {
    birim sayi;
    int parca_sayisi = 0;
    float *uzunluk_1 =NULL, *uzunluk_2 = NULL, *alan = NULL;
    char devam;
    printf("uzunluk cinsi sec : secenekler metre icin 1'e santimetre icin 2'ye milimetre icin 3'e basiniz\n");
    scanf("%d",&sayi);
    printf("uzunluk birimi olarak:\t");
    secenek(sayi);
    printf("secildi\n");
    do {
        uzunluk_1 = (float*)realloc(uzunluk_1,sizeof(float)*(parca_sayisi + 1));
        uzunluk_2 = (float*)realloc(uzunluk_2,sizeof(float)*(parca_sayisi + 1));
        alan = (float*)realloc(alan,sizeof(float)*(parca_sayisi + 1));
        if (uzunluk_1 == NULL || uzunluk_2 == NULL || alan == NULL) {
            printf("Bellek hatasi!\n");
            exit(0);
        }
        printf("%d. parca icin alan\n",parca_sayisi+1);
        printf("ilk uzunluk\n");
        scanf("%f",&uzunluk_1[parca_sayisi]);
        printf("ikinci bir uzunluk\n ");
        scanf("%f",&uzunluk_2[parca_sayisi]);
        alan[parca_sayisi] = uzunluk_1[parca_sayisi] * uzunluk_2[parca_sayisi];
        printf("islemi onayliyorsaniz enter basin\n");
        getchar();
        getchar();
        printf("ilk girilen sayi %.3f\t son girilen sayi %.3f\n",uzunluk_1[parca_sayisi],uzunluk_2[parca_sayisi]);
        printf("sonuc %.3f\n",alan[parca_sayisi]);
        parca_sayisi++;
        printf("devam etmek istiyormusnuz E/H\n");
        scanf("%c",&devam);
    }while (devam =='E' || devam =='e');

        printf("dosyaniza bir isim verin\n");
        char *dosya;
        scanf("%s",&dosya);
        FILE *toplam = fopen(&dosya, "w");
        if (toplam == NULL) {
            printf("Bellek hatasi!\n");
            exit(1);
        }
            for (int i = 0; i < parca_sayisi; i++) {
                fprintf(toplam, "%d. parca\n", i+1);
                fprintf(toplam,"seçilen uzunluk birimi: %s\n",Cevir(sayi));
                fprintf(toplam,"ilk girilen deger : %.3f   ikinci girilen deger: %.3f\n",uzunluk_1[i],uzunluk_2[i]);
                fprintf(toplam,"toplam %.3f\n\n",alan[i]);
            }
            fclose(toplam);
    free(uzunluk_1); free(uzunluk_2); free(alan);
    return 0;
}

void secenek(birim sayi) {
        if (sayi == metre) { printf("metre "); }
        else if (sayi == santimetre) { printf("santimetre "); }
        else if (sayi == milimetre) {printf("milimetre "); }
    else { printf("yanlis veya hattali girdiniz"); exit(1); }
}

const char *Cevir(birim tur) {
    switch (tur) {
        case metre: return "metre";
        case santimetre: return "santimetre";
        case milimetre: return "milimetre";
    }
}
