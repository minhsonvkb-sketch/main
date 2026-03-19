#include <bits/stdc++.h>
using namespace std;
using lli=long long;
const lli INF=1e9;
void ffopen(const string& file)
{
    if(file.empty())return;
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
    lli n,m;
    cin>>n>>m;
        vector<lli> a(n);
    for(lli i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<lli> f(m+1,INF);
    vector<lli> truyvet(m+1);
    f[0]=0;
    for(lli i=1;i<=m;i++)
    {
        for(lli j=0;j<n;j++)
        {
            if(a[j]<=i&&f[i-a[j]]!=INF)
            {
                if(f[i]>f[i-a[j]]+1)
                {
                    f[i]=f[i-a[j]]+1;
                    truyvet[i]=j;
                }
            }
        }
    }
    cout<<f[m]<<'\n';
    vector<lli> dem(n,0);
    lli tien=m;
    while(tien!=0)
    {
        lli idx=truyvet[tien];
        dem[idx]++;
        tien-=a[idx];
    }
    for(lli i=0;i<n;i++)
    {
        cout<<dem[i]<<" ";
    }
}
