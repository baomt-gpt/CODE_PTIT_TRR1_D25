#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a(101);

bool SinhNhiPhan(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0) return false;
    a[i] = 1;
    return true;
}

bool check(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 1){
            cnt++;
            if(cnt >= k) return true;
        } else cnt = 0;
    }
    return false;
}

void result(){
    for(int i = 1; i <= n; i++) cout << a[i];
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) a[i] = 0;

    do {
        if(check()) result();
    } while(SinhNhiPhan());

    return 0;
}