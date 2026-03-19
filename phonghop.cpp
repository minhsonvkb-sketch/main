#include <bits/stdc++.h>
using namespace std;

int main(){
    

    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }

    sort(a.begin(),a.end(),[](pair<int,int> x, pair<int,int> y){
        if(x.second==y.second) return x.first<y.first;
        return x.second<y.second;
    });

    int dem=0;
    int last=0;

    for(int i=0;i<n;i++){
        if(a[i].first>=last){
            dem++;
            last=a[i].second;
        }
    }

    cout<<dem;
}
