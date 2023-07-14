#include <bits/stdc++.h>
using namespace std;
void done(vector<int> &arr, int low, int high, int mid)
{
    int i, j, k;
    vector<int> a(arr.size()+1);
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            a[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            a[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        a[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        a[k] = arr[j];
        j++;
        k++;
    }
    for (int x = low; x <= high; x++)
    {
        arr[x] = a[x];
    }
}
void merge(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge(arr, low, mid);
        merge(arr, mid + 1, high);
        done(arr, low, high, mid);
    }
}
int main()
{
    vector<int> v;
    v.push_back(23);
    v.push_back(3);
    v.push_back(32);
    v.push_back(13);
    v.push_back(232);
    v.push_back(223);
    merge(v, 0, 5);
    for(int i = 0; i<6 ; i++){
        cout<<v[i]<<endl;
    }
}