#include <bits/stdc++.h>
using namespace std;

int n, b, delta = 0, fopt = 0;
int w[105], c[105], index[105], x[105], xopt[105];

bool cmp(array<int, 3> p, array<int, 3> q){
    return (double)p[1] / p[0] > (double)q[1] / q[0]; 
}

void Try(int k){
    for(int i = 1; i >= 0; i--){
        if(i * w[k] > b) continue;
        x[k] = i;
        delta += c[k] * i;
        b -= w[k] * i;

        if(k == n){
            if(delta > fopt){
                fopt = delta;
                memcpy(xopt, x, sizeof(x));
            }
        } else{
            int g = delta + (double)c[k + 1] / w[k + 1] * b;
            if(g > fopt) Try(k + 1);
        }

        delta -= c[k] * i;
        b += w[k] * i;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> b;
    //w, c, index
    vector<array<int, 3>> d(n);
    for(int i = 0; i < n; i++){
        cin >> d[i][0] >> d[i][1];
        d[i][2] = i + 1;
    }

    sort(d.begin(), d.end(), cmp);

    for(int i = 0; i < n; i++){
        w[i + 1] = d[i][0];
        c[i + 1] = d[i][1];
        index[i + 1] = d[i][2];
    }

    Try(1);

    int kq[105] = {};
    for(int i = 1; i <= n; i++){
        kq[index[i]] = xopt[i];
    }
    cout << fopt << "\n";
    for(int i = 1; i <= n; i++){
        cout << kq[i] << " ";
    }

    return 0;
}