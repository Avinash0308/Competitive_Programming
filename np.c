#include<stdio.h>
int r(){
    static int num = 7;
    printf("I'm here %d\n",num);
    return num--;
}
int main(){
    for(r();r();r())
    printf("%d\n",r());
    return 0;
}