#include <bits/stdc++.h>
using namespace std;

int n, b, x[25], xopt[25], fopt = -1;
int w[25], c[25];

void Try(int i){
    if(i > n){
        int W = 0, V = 0;
        for(int k = 1; k <= n; k++){
            W += x[k] * w[k];
            V += x[k] * c[k];
        }
        if(W <= b && V > fopt){
            fopt = V;
            memcpy(xopt, x, sizeof(x));
        }
        return;
    }
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        Try(i + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> b;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> c[i];
    }

    Try(1);

    cout << fopt << "\n";
    for(int i = 1; i <= n; i++){
        cout << xopt[i] << " ";
    }

    return 0;
}