#include <bits/stdc++.h>
using namespace std;

// n: So luong thanh pho
// c[i][j]: Chi phi di tu thanh pho i den thanh pho j
// cmin: Chi phi nho nhat giua hai thanh pho khac nhau
int n, c[105][105], cmin = 1e9;

// vs[i] = 1: Thanh pho i da duoc tham
// vs[i] = 0: Thanh pho i chua duoc tham
int vs[105] = {0};

// fopt: Tong chi phi nho nhat cua hanh trinh tim duoc
// delta: Tong chi phi cua hanh trinh dang xay dung
int fopt = 1e9, delta = 0;

// x[k]: Thanh pho o vi tri thu k trong hanh trinh hien tai
// xopt[k]: Thanh pho o vi tri thu k trong hanh trinh toi uu
int x[105], xopt[105];

// Ham Try(k): Tim thanh pho o vi tri thu k
// Su dung quay lui ket hop nhanh can
void Try(int k){

    // Thu lan luot cac thanh pho tu 2 den n
    // Vi thanh pho 1 da duoc co dinh lam diem xuat phat
    for(int i = 2; i <= n; i++){

        // Neu thanh pho i chua duoc tham thi co the chon
        if(vs[i] == 0){

            // Chon thanh pho i vao vi tri thu k
            x[k] = i;

            // Danh dau thanh pho i da duoc tham
            vs[i] = 1;

            // Cap nhat chi phi tu thanh pho truoc do den thanh pho i
            delta += c[x[k - 1]][i];

            // Neu k == n nghia la da di qua tat ca n thanh pho
            if(k == n){

                // Tinh them chi phi tu thanh pho cuoi cung quay ve thanh pho 1
                // Neu tong chi phi nho hon ket qua tot nhat hien tai
                // thi cap nhat ket qua
                if(delta + c[k][1] < fopt){

                    // Luu tong chi phi nho nhat
                    fopt = delta + c[k][1];

                    // Sao chep hanh trinh hien tai vao mang xopt
                    memcpy(xopt, x, sizeof(x));
                }
            }
            else{

                // Tinh can duoi g cua nhanh hien tai
                // delta: Chi phi da di
                // cmin: Chi phi nho nhat cua mot canh
                // n-k+1: So canh con phai di, bao gom canh quay ve thanh pho 1
                int g = delta + cmin * (n - k + 1);

                // Neu can duoi nho hon chi phi tot nhat hien tai
                // thi nhanh nay van co kha nang tim duoc ket qua tot hon
                // Goi de quy de tiep tuc chon thanh pho tiep theo
                if(g < fopt)
                    Try(k + 1);
            }

            // QUAY LUI:
            // Tru lai chi phi cua canh vua them vao delta
            delta -= c[x[k - 1]][i];

            // Bo danh dau thanh pho i de cac nhanh khac co the su dung
            vs[i] = 0;
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){

            // Chi phi di tu thanh pho i den thanh pho j
            cin >> c[i][j];

            // Khong xet duong di tu mot thanh pho den chinh no
            // Cap nhat chi phi nho nhat giua hai thanh pho khac nhau
            if(i != j && c[i][j] < cmin){
                cmin = c[i][j];
            }
        }
    }

    // Co dinh thanh pho dau tien la thanh pho 1
    x[1] = 1;

    // Danh dau thanh pho 1 da duoc tham
    vs[1] = 1;

    // Bat dau tim hanh trinh tu vi tri thu 2
    Try(2);

    // In ra tong chi phi nho nhat
    cout << fopt << "\n";

    // In ra hanh trinh co tong chi phi nho nhat
    for(int i = 1; i <= n; i++){
        cout << xopt[i] << " ";
    }

    // Quay tro lai thanh pho xuat phat 1
    cout << 1;

    return 0;
}
