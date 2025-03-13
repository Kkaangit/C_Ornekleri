/* ders */
#include <stdio.h>
#include <stdlib.h>

int main(){
    float kenar1, kenar2, alan ;
    printf("  Dörtgen 1.kenarını girin  ");
    scanf("%f",&kenar1);
    printf("   Dörtgen 2.kenarını girin ");
    scanf("%f",&kenar2);
    alan = kenar1*kenar2;
    printf("alan: %f", alan);
      return 0;
}
