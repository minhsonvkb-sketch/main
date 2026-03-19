#include <bits/stdc++.h>

using namespace std;

const int nm=5001;

int C[nm][nm], A[nm],B[nm],D[nm], N,V,i,j;

int main()
{
    

    cin>>N>>V;
    for(i=1;i<=N;i++){
        cin>>A[i]>>B[i];
    }

    for(i=0;i<=N;i++)
    {
        for(j=0;j<=V;j++)
        {
            if(i==0||j==0) C[i][j]=0;
            else if(A[i]>j) C[i][j]=C[i-1][j];
            else C[i][j]=max(C[i-1][j], C[i-1][j-A[i]]+B[i]);
        }
    }

    i=N;j=V;
    while(i>0)
    {
        if(C[i][j]==C[i-1][j])i--;
        else
        {
            D[i]=1;
            j=j-A[i];
            i--;
        }
    }

    cout<<C[N][V]<<"\n";
    for(i=0;i<=N;i++)
        if(D[i]==1)cout<<i<<" ";
    return 0;
}
