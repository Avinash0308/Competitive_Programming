#include<stdio.h>
int main(){
    int age = 23;
    int *ptr = &age;
    int _age = *ptr;
    printf("%p\n",&age);
    /*printf("%p\n",ptr);
    printf("%p\n",&ptr);*/
    return 0;
}