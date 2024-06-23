#include<iostream>
using namespace std;
int partation(int arr[],int start,int end)
{
    int pivot=arr[start];
    int cnt=0;
    for(int i=start+1;i<=end;i++)
    {
        if(arr[i]<=pivot)
        {
            cnt++;
        }
    }
    int pivitIndex=start+cnt;
    swap(arr[start],arr[pivitIndex]);
    int i=start,j=end;
    while(i <pivitIndex && j>pivitIndex)
    {
        while(arr[i]<pivot)
        {
            i++;
        }
        while(j>pivot)
        {
            j--;
        }
        swap(arr[i],arr[j]);
        i++,j--;

    }
    return pivitIndex;


}
void quicksort(int arr[],int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int p=partation(arr,start,end);
    quicksort(arr,start,p-1);
    quicksort(arr,p+1,end);
}
int main()
{
    int arr[5]={10,80,30,90,40};
    int n=5;
    quicksort(arr,0,n-1);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<endl;
    }


}