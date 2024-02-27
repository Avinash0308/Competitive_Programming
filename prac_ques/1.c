#include <stdio.h>
int minimum(int arr[], int n)
{
    int a = 6000;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < a)
        {
            a = arr[i];
        }
    }
    return a;
}
void solveit(int arr1[], int arr2[], int n)
{
    int q = 0;
        int a[10000] ;
        int  ans = 0;
        int b = 1;
        while (minimum(arr1, n) > -1)
        {
            a[q] = minimum(arr1, n);
            for (int i = 0; i < n; i++)
            {
                if (arr1[i] != a[q])
                {
                    if (arr1[i] >= arr2[i])
                    {
                        int x = (arr1[i] - a[q]) / arr2[i];
                        arr1[i] -= arr2[i] * x;
                        ans += x;
                    }
                }
            }
            if(q>0){
                if(a[q] == a[q-1]){

                    int set;
                    set = arr1[0];
                    for (int i = 1; i < n; i++)
                    {
                        if (arr1[i] != set)
                        {
                            goto end;
                        }
                    }
                    break;
                }
            }
            q++;
        }
        printf("%l\n", ans);
        b = 0;
end:
    if (b)
    {
        printf("-1\n");
    }
}

int main()
{
    int a1;
    scanf("%d", &a1);
    int a[a1], b[a1];
    for (int i = 0; i < a1; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < a1; i++)
    {
        scanf("%d", &b[i]);
    }
    solveit(a, b, a1);
    return 0;
}