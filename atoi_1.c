#include <stdio.h>
#include <stdlib.h>

int main(int argsay, char *argvek[]){
    int toplam;
    if (argsay < 3) {
        printf("Eksik paremetre:!\n ");
        exit(1);
    }
    if (argsay > 3) {
        printf("Cok fazla paremetre !\n");
        exit(1);
    }
    toplam = atoi(argvek[1]) + atoi(argvek[2]);
    printf("toplam = %d\n",toplam);

      return 0;
}
