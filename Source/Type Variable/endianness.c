#include <stdio.h>

int main(void){
    unsigned int x = 0x01020304;
    unsigned char *p = (unsigned char *)&x;
    printf("Byte dau tien x = 0x%X\n", p[0]);
    if(p[0] == 0x01)
        printf("He thong: Big endian\n");
    else if(p[0] == 0x04)
        printf("He thong: Little endian\n");
    else
        printf("He thong: Không xác định\n");

    return 0;
}