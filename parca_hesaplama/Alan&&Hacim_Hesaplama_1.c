//Kullanıcıdan alan veya hacim hesap türü bilgisi alıyor. Geometrik şekil için bilgi alıyor ve ölçü birimi bilgisi alıyor. Bu bilgiler kalıcı olur ve program bitene kadar değişmez
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    alan = 1, hacim
}cins;

typedef enum {
    dörtgen=1, daire, küre_A, silindir_A
}ikiBoyut;

typedef enum {
    küp=1, dikdörtgen_prizma, küre_H, silindir_H
    }üçBoyut;

typedef enum {
    metre =1, santimetre, milimetre
}birim;

void secenek(birim sayi);
const char *Cevir(birim tur);
float Talan(ikiBoyut, float a, float b);
float Thacim(üçBoyut, float a, float b);
const char *Dosya_2D(ikiBoyut geometrik);
const char *Dosya_3D(üçBoyut geometrik);

int main() {
    birim sayi;
    cins cins;
    ikiBoyut ikiboyut;
    üçBoyut ucboyut;
    int parca_sayisi = 0;
    float *uzunluk_1 =NULL, *uzunluk_2 = NULL, *sonuc = NULL;
    char devam;

    printf("alan olcumu icin 1 hacim olcumu icin 2'ye basiniz\n");
    scanf("%d", &cins);
    if (cins == alan) {
        printf("sekil sec dortgenler icin 1'e daire icin 2'ye kure icin 3'e silindir icin 4'e basiniz\n");
        scanf("%d", &ikiboyut);
        if (ikiboyut != dörtgen && ikiboyut != daire && ikiboyut != küre_A && ikiboyut != silindir_A) {
            perror("yanlis veya hatali secim"); exit(1);
        }
    }else if (cins == hacim) {
        printf("sekil sec kup icin 1'e dikdortgen prizma icin 2'ye kure icin 3'e basiniz silindir icin 4'e basiniz\n");
        scanf("%d", &ucboyut);
        if (ucboyut != küp && ucboyut != dikdörtgen_prizma && ucboyut != küre_H && ucboyut != silindir_H) {
            perror("yanlis ve hatali secim"); exit(1);
        }
    }else{perror("yanlis veya hatali secim"); exit(1);}

    printf("uzunluk cinsi sec : secenekler metre icin 1'e santimetre icin 2'ye milimetre icin 3'e basiniz\n");
    scanf("%d",&sayi);
    printf("uzunluk birimi olarak:\t");
    secenek(sayi);

    do {
        uzunluk_1 = (float*)realloc(uzunluk_1,sizeof(float)*(parca_sayisi + 1));
        uzunluk_2 = (float*)realloc(uzunluk_2,sizeof(float)*(parca_sayisi + 1));
        sonuc = (float*)realloc(sonuc,sizeof(float)*(parca_sayisi + 1));
        if (uzunluk_1 == NULL || uzunluk_2 == NULL || sonuc == NULL) {
            printf("Bellek hatasi!\n");
            exit(0);
        }
        printf("%d. parca icin alan\n",parca_sayisi+1);
        printf("ilk uzunluk\n");
        scanf("%f",&uzunluk_1[parca_sayisi]);
        if ((cins == alan && (ikiboyut == dörtgen || ikiboyut == silindir_A)) ||
            (cins == hacim && (ucboyut == dikdörtgen_prizma || ucboyut == silindir_H))){
            printf("ikinci bir uzunluk\n ");
            scanf("%f",&uzunluk_2[parca_sayisi]);
            }
        else {
            uzunluk_2[parca_sayisi] = 0.000;
        }
        if (cins == alan) {
            sonuc[parca_sayisi] = Talan(ikiboyut, uzunluk_1[parca_sayisi], uzunluk_2[parca_sayisi]);
        } else {
            sonuc[parca_sayisi] = Thacim(ucboyut, uzunluk_1[parca_sayisi], uzunluk_2[parca_sayisi]);
        }

        printf("islemi onayliyorsaniz enter basin\n");
        getchar();
        getchar();
        printf("ilk girilen sayi %.3f\t son girilen sayi %.3f\n",uzunluk_1[parca_sayisi],uzunluk_2[parca_sayisi]);
        printf("sonuc %.3f\n",sonuc[parca_sayisi]);
        parca_sayisi++;
        printf("devam etmek istiyormusnuz E/H\n");
        scanf("%c",&devam);
    }while (devam =='E' || devam =='e');

    char *dosya = "toplam.txt";
    FILE *toplam = fopen(dosya, "w");
    if (toplam == NULL) {
        printf("Bellek hatasi!\n");
        exit(1);
    }

    for (int i = 0; i < parca_sayisi; i++) {
        fprintf(toplam, "%d. parça\n", i+1);
        fprintf(toplam,"seçilen uzunluk birimi: %s\n",Cevir(sayi));
        fprintf(toplam,"ilk girilen değer : %.3f   ikinci girilen değer: %.3f\n",uzunluk_1[i],uzunluk_2[i]);
        fprintf(toplam,"sonuç %.3f\n\n",sonuc[i]);
    }
    fprintf(toplam,"Toplam parça sayısı : %d\n",parca_sayisi);
    if (cins == alan) {
        fprintf(toplam,"Alan ölçümü yapıldı\n");
    fprintf(toplam,"Seçilen geometrik şekil: %s",Dosya_2D(ikiboyut));
}
    else {
        fprintf(toplam,"Hacim ölçümü yapıldı\n");
        fprintf(toplam,"Secilen geometrik şekil: %s", Dosya_3D(ucboyut));
    }
            fclose(toplam);

    free(uzunluk_1); free(uzunluk_2); free(sonuc);
    return 0;
}

void secenek(birim sayi) {
        if (sayi == metre) { printf("metre secildi\n"); }
        else if (sayi == santimetre) { printf("santimetre secildi\n"); }
        else if (sayi == milimetre) {printf("milimetre secildi\n"); }
    else { perror("yanlis veya hattali girdiniz"); exit(1); }
}

const char *Cevir(birim tur) {
    switch (tur) {
        case metre: return "metre";
        case santimetre: return "santimetre";
        case milimetre: return "milimetre";
    }
}

float Talan(ikiBoyut ikiboyut , float a, float b) {
    switch (ikiboyut){
        case dörtgen: return a * b;
        case daire: return  3.1415 * a * a;
        case küre_A: return 4 * 3.1415 * a * a;
        case silindir_A: return 2 * 3.1415 * a * b;
    }
}

float Thacim(üçBoyut ucboyut, float a, float b) {
    switch (ucboyut){
        case küp: return a * a * a;
        case dikdörtgen_prizma: return  a * a * b;
        case küre_H: return (4.0/3.0) * 3.1415 * a * a * a;
        case silindir_H: return  3.1415 * a * a * b;
    }
}

const char *Dosya_2D(ikiBoyut geometrik) {
    switch (geometrik) {
        case dörtgen: return "Dörtgen";
        case daire: return "Daire";
        case küre_A: return "küre";
        case silindir_A: return "silindir";
    }
}

const char *Dosya_3D(üçBoyut geometrik) {
    switch (geometrik) {
        case küp: return "Küp";
        case dikdörtgen_prizma: "Dikdörtgen_prizma";
        case küre_H: return "Küre";
        case silindir_H: return "Silindir";
    }
}
