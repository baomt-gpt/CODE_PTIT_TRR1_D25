#include <bits/stdc++.h>
using namespace std;

int n, c[105][105], x[105], fopt, xopt[105];

int main(){
    fopt = 1e9;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        x[i] = i;
    }

    do{
        int S = c[x[n]][1];
        for(int i = 1; i < n; i++){
            S += c[x[i]][x[i + 1]];
        }
        if(S < fopt){
            fopt = S;
            memcpy(xopt, x, sizeof(x));
        }

    } while(next_permutation(x + 2, x + n + 1));

    cout << fopt << "\n";
    for(int i = 1; i <= n; i++){
        cout << xopt[i] << " ";
    }

    return 0;
}