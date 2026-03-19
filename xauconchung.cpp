#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
long c[N][N];
int i, j;
string a, b, s;

void taobang() {
    a = "@" + a;
    b = "@" + b;
    c[0][0] = 0;
    for (i = 1; i < a.length(); i++)
        for (j = 1; j < b.length(); j++)
            if (a[i] == b[j]) 
                c[i][j] = c[i - 1][j - 1] + 1;
            else 
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
}

void truyhoi() {
    i = a.length() - 1; 
    j = b.length() - 1;
    s = "";
    while (c[i][j] > 0) {
        if (c[i][j] == c[i - 1][j]) 
            i--;
        else if (c[i][j] == c[i][j - 1]) 
            j--;
        else {
            s = a[i] + s;
            i--;
            j--;
        }
    }
}

int main() {
   
    cin >> a >> b;
    taobang();
    truyhoi();
    cout << s;
    return 0;
}
