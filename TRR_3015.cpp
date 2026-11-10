//TRR1_3015 — Liệt kê một phần xâu nhị phân sử dụng phương pháp sinh thuận

#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> a(101);

void result(){
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> t;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= t; i++){
        SinhNhiPhan();
        result();
    }

    return 0;
}