//#=======================================================#
//#   AUTHOR :- RAVI SHANKAR KUMAR	                  #
//#   FROM :- SITAMARHI(BIHAR) , 843317	                  #
//#   NIT JALANDHAR, CSE PRE-FINAL YEAR                   #
//#=======================================================#
//Merge Sort Implementation
#include<bits/stdc++.h>
using namespace std;
#define size 1000
#define ll long long int
void mrg(ll arr[],ll r[],ll left,ll mid,ll right)
{
    ll i,last,ln,temp;
    last=mid-1; temp=left; ln=right-left+1;
    while((left<=last)&&(mid<=right))
    {
        if(arr[left]<=arr[mid])
        {
            r[temp]=arr[left]; temp=temp+1; left=left+1;
        }
        else
        {
            r[temp]=arr[mid]; temp=temp+1; mid=mid+1;
        }
    }
    while(left<=last)
    {
        r[temp]=arr[left]; temp=temp+1; left=left+1;
    }
    while(mid<=right)
    {
        r[temp]=arr[mid]; mid=mid+1; temp=temp+1;
    }
    for(i=0;i<=ln;i++)
    {
        arr[right]=r[right];
        right=right-1;
    }
    return;
}
void merge_srt(ll arr[],ll r[],ll left,ll right)
{
    ll mid;
    if(right>left)
    {
        mid=(right+left)/2;
        merge_srt(arr,r,left,mid);
        merge_srt(arr,r,mid+1,right);
        mrg(arr,r,left,mid+1,right);
    }
    return;
}
//MAIN FUNCTION START HERE.
int main()
{
    cout<<"Enter the size of array : ";
    ll n,i; cin>>n;
    ll arr[n],r[n];
    cout<<"Enter "<<n<<" elements of array :\n";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        r[i]=arr[i];
    }
    merge_srt(arr,r,0,n-1);
    cout<<"After sorting array is :\n";
    for(i=0;i<n;i++) cout<<arr[i]<<" ";
 return 0;
}
