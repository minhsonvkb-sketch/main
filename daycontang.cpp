#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define vect vector
#define bend(v) v.begin(),v.end()
#define ms ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MaxN = 10005;

int n;
int a[MaxN];
int dp[MaxN], trace[MaxN];

int main(){
    ms;
    
    

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        trace[i] = 0;
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                }
                else if(dp[j] + 1 == dp[i] && j > trace[i]){
                    trace[i] = j;
                }
            }
        }
    }

    int len = 0, pos = 0;
    for(int i = 1; i <= n; i++){
        if(dp[i] > len || (dp[i] == len && i > pos)){
            len = dp[i];
            pos = i;
        }
    }

    vect<int> res;
    while(pos){
        res.pb(a[pos]);
        pos = trace[pos];
    }
    reverse(bend(res));

    cout << len << '\n';
    for(int x : res) cout << x << ' ';
    return 0;
}
