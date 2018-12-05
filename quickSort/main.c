#include <stdio.h>
#include <stdlib.h>
/*
void quickSort(int a[], int low, int high)
{
    int mid;
    mid = a[low];
    int i = low;
    int j = high;
    if(i>=j)    return;
    while(i < j){
        while(a[j]>=mid && i<j) j--;
        if(i < j){
            a[i] = a[j];
            i++;
        }

        while(a[i]<=mid && i<j) i++;
        if(i < j){
            a[j] = a[i];
            j--;
        }
    }
    a[i] = mid;
    quickSort(a, low, i-1);
    quickSort(a, i+1, high);
}//递归算法
*/

int position(int a[], int low, int high)
{
    int mid;
    mid = a[low];
    int i = low;
    int j = high;

    while(i < j){
        while(a[j]>=mid && i<j) j--;
        if(i < j){
            a[i] = a[j];
            i++;
        }

        while(a[i]<=mid && i<j) i++;
        if(i < j){
            a[j] = a[i];
            j--;
        }
    }
    a[i] = mid;
    return i;
}
/*分步的递归*/
void quickSort(int a[], int low, int high)
{
    int i;
    int pos;
    if(low < high)
    {
        pos = position(a, low, high);
        quickSort(a, low, pos-1);
        quickSort(a, pos+1, high);
    }
}

int main()
{
    int i;
    int a[10]={30,5,6,34,85,38,354,681,3,20};
    quickSort(a, 0, 9);

    for(i=0; i<10; i++)
    {
        printf("%d,",a[i]);
    }
    printf("\n");
    return 0;
}

//30,5,6,34,85,38,354,681,3
