/*ders*/
#include <stdio.h>
int main1() {
    printf("main 1\n");
    int x = 4;
    int y = 5;
    return x * y ; // Geri dönüş yok işlem yapıldı
}
int main2() {
    printf("main 2      ");
    int x = 4;
    int y = 5;
    printf("%d\n",x * y);
    return 0; // İşlem düzgün çalıştı sonuç ekrana yazıldı 
}
    int main(){
        main1();
        main2();
        return 0;
    }
/* İlk main fonksiyonunda da ikinci main foksiyonunda da çarpma işlemi yapılır ancak main1'de yapılan işlemde bir geri
 * dönüş sağlanmaz main2'de ise yapılan işlem sonucu ekrana yazılır ve return 0; ile işlem sorunsuz bir şekilde
 * çalıştığını işletim sistemine bildirir */
