#include <iostream>
using namespace std;

const int N = 1000010;
int n;
int q[N], tmp[N];

void quick_sort(int q[], int l, int r)
{
    if(l >= r)return;
    int mid = q[l + r >> 1];
    int i = l - 1, j = r + 1;
    
    while(i < j )
    {
        do i++; while(q[i] < mid);
        do j--; while(q[j] > mid);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j); quick_sort(q, j + 1, r);
    
}

void merge_sort(int q[], int l, int r)
{
    if(l >= r)return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if(q[i] < q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    
    for(int i=l, j=0; i<=r; i++, j++) q[i] = tmp[j];
}


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quick_sort(q, 0, n-1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
}
