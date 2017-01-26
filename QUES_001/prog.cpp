/*=======================================================|
|                 AUTHOR :-                              |
|    RAVI SHANKAR KUMAR,SITAMARHI(BIHAR).                |
|    NIT JALANDHAR, CSE PRE-FINAL YEAR                   |
|=======================================================*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll md=1e9+7;
ll fac(ll n)
{
    if(n==0) return 1;
    for(ll i=n-1;i>=1;i--)
      n=(n*i)%md;
    return n;
}
ll findSmall(string A,int pos)
{
    ll cnt=0;
    for(int i=pos+1;i<A.length();i++)
      if(A[i]<A[pos]) cnt++;
    return cnt;
}
int findRank(string A) {
    ll ans=1;
    for(ll i=0;i<A.length();i++)
        ans=(ans+(findSmall(A,i)*fac(A.length()-i-1)%md))%md;
    
    return (int)ans;
}
int main()
{
   string a;
   cout<<"Enter a string : ";
   cin>>a;
   cout<<"Rank of this string is : "<<findRank(a)<<endl;
   return 0;
}
