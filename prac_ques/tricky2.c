#include <stdio.h>
#include <stdlib.h>
double simple_interest(int P, int R, int T)
{
    return (P*R*T)/100;
}
int main()
{
    int P, R, T;
    printf("Enter the principal amount1\n");
    scanf("%d", &P);
    printf("Enter the rate of interest\n");
    scanf("%d", &R);
    printf("Enter the time\n");
    scanf("%d", &T);

    double SI = simple_interest(P, R, T);
    printf("The Simple interest = %lf", SI);
    return 0;
}