#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod;
vector<vector<ll> >matmul(vector<vector<ll> >&a,vector<vector<ll> >&b)
{
   int n=a.size(),i,j,k;
   vector<vector<ll> >c(n,vector<ll>(n));
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
         for(k=0;k<n;k++)
            c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
   return c;
}
vector<vector<ll> >matpow(vector<vector<ll> >&a,ll x)
{
   int n=a.size(),i;
   vector<vector<ll> >b(n,vector<ll>(n));
   for(i=0;i<n;i++) b[i][i]=1; //Identity Matrix
   while(x>0)
   {
      if(x%2) b=matmul(b,a);
      x/=2;
      a=matmul(a,a);
   }
   return b;
}
int main()
{
     ll ab,n;
     cin>>ab>>n>>mod;
     int x=1,temp=ab;
     while(temp) x=x*10,temp/=10;
     //First Matrix Setup
     vector<vector<ll> >a(2,vector<ll>(2));
     a[0][0]=x%mod,a[0][1]=a[1][1]=1,a[1][0]=0;
     a=matpow(a,n-1);
     cout<<((a[0][0]+a[0][1])%mod*ab)%mod<<endl;
  return 0;
}
