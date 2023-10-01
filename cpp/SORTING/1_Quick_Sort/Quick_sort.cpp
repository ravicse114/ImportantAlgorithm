//#=======================================================#
//#   AUTHOR :- RAVI SHANKAR KUMAR	                  #
//#   FROM :- SITAMARHI(BIHAR) , 843317	                  #
//#   NIT JALANDHAR, CSE PRE-FINAL YEAR                   #
//#=======================================================#
/*Quick Sort using First element as pivot.*/
#include <bits/stdc++.h>
using namespace std;
int part(int arr[],int start,int last)
{
    int pivot=arr[start],i=start+1,j=last,temp;
    while(i<=j)
        {
        while(arr[j]>pivot) j--;
        while(arr[i]<pivot && i<last) i++;
        if(i<j)
          { 
          	temp=arr[j]; arr[j]=arr[i]; arr[i]=temp;
            i++;  j--;
           }
        else i++;
        }
     arr[start]=arr[j]; arr[j]=pivot;
    return j;
}
void quicksort(int arr[],int start,int last)
{
    if(start>=last) return;
    int i,pivot=part(arr,start,last);
    quicksort(arr,start,pivot-1);
    quicksort(arr,pivot+1,last);
}
//Write Main Method Here.
int main()
{
    int n; scanf("%d",&n);
    int arr[n],i; 
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    quicksort(arr,0,n-1);
    for(i=0;i<n;i++) printf("%d ",arr[i]);
}
