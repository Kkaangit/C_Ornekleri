    int main(){
int *k;
int a=10;
k=&a;
        printf("'a' degeri   : %d\n",a); // 'a' degeri   : 10
        printf("a'nin adresi   : %p\n",&a); // a'nin adresi   : 0000003784bffb64
        printf("'k' degeri   : %p\n",k); // 'k' degeri   : 0000003784bffb64
        printf("'k'nin adresi : %p\n",&k); //'k'nin adresi : 0000003784bffb68
        printf("'a' degeri   : %d\n",*k); // 'a' degeri   : 10 , k değeri a'nın pointer adresini tutuyor *k yaparak o pointerda ki değeri yazar veya okur.
return 0;
}
