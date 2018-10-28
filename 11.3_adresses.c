// adresses.c -- 字符串的地址
#define MSG "I'm special"
#include <stdio.h>
int main(void)
{
    char ar[] = MSG;
    const char *pt = MSG;
    printf("adress of \"I'm special\": %p \n", "I'm special");
    printf("       adress ar: %p\n", ar);
    printf("       adress pt: %p\n", pt);
    printf("       adress of MSG: %p\n", MSG);
    printf("adress of \"I'm special\": %p \n", "I'm special");
    
    return 0;
}
