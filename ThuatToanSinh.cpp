#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a(101, 0);

void result(){
    for(int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << "\n";
}

bool SinhNhiPhan(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0) return false;   // đã là cấu hình cuối cùng
    a[i] = 1;
    return true;               // không in ở đây
}

bool SinhToHop(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i) i--;
    if(i == 0) return false;

    a[i]++;
    for(int j = i + 1; j <= k; j++){
        a[j] = a[j - 1] + 1;
    }

    return true;
}

bool SinhHoanVi(){
    int i = n - 1;
    while(i >= 1 && a[i] > a[i + 1]) i--;
    if(i == 0) return false;

    int j = n;
    while(a[j] < a[i]) j--;
    swap(a[i], a[j]);
    //
    reverse(a.begin() + i + 1, a.begin() + n + 1);
    //
    // int k = i + 1, l = n;
    // while(k < l){
    //     swap(a[k], a[l]);
    //     k++; l--;
    // }
    return true;
}

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     cin >> n;
//     do{
//         result();
//     } while(sinh());

//     return 0;
// }


//Sinh hoán vị thuận
// int main(){
//     cin >> n;
//     for(int i = 1; i <= n; i++) a[i] = i;
//     do{
//         result();
//     } while(next_permutation(a.begin() + 1, a.begin() + n + 1));
// }

// Sinh hoán vị ngược
// int main(){
//     cin >> n;
//     for(int i = 1; i <= n; i++) a[i] = n - i + 1;
//     do{
//         result();
//     } while(prev_permutation(a.begin() + 1, a.begin() + n + 1));
// }