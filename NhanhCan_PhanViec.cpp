#include <bits/stdc++.h>
using namespace std;

// n: So luong nguoi va so luong cong viec
// c[i][j]: Chi phi giao cong viec i cho nguoi j
int n, c[105][105];

// cmin: Chi phi phan cong nho nhat trong ma tran chi phi
int cmin = 1e9;

// vs[i] = 1: Cong viec i da duoc giao cho mot nguoi
// vs[i] = 0: Cong viec i chua duoc giao
int vs[105] = {0};

// x[k]: Cong viec duoc giao cho nguoi k trong phuong an hien tai
// xopt[k]: Cong viec duoc giao cho nguoi k trong phuong an toi uu
// fopt: Tong chi phi phan cong nho nhat tim duoc
// delta: Tong chi phi cua phuong an phan cong dang xet
int x[105], xopt[105], fopt = 1e9, delta = 0;


// Ham Try(k): Tim cong viec de giao cho nguoi thu k
// Su dung thuat toan quay lui ket hop nhanh can
void Try(int k){

    // Thu lan luot cac cong viec tu 1 den n
    for(int i = 1; i <= n; i++){

        // Neu cong viec i chua duoc giao cho nguoi nao
        if(vs[i] == 0){

            // Gan cong viec i cho nguoi thu k
            x[k] = i;

            // Cong them chi phi giao cong viec i cho nguoi k
            delta += c[i][k];

            // Danh dau cong viec i da duoc giao
            vs[i] = 1;

            // Neu k == n, nghia la da phan cong xong cho tat ca n nguoi
            if(k == n){

                // Neu tong chi phi phuong an hien tai nho hon
                // tong chi phi nho nhat da tim duoc
                if(delta < fopt){

                    // Cap nhat tong chi phi phan cong nho nhat
                    fopt = delta;

                    // Luu lai phuong an phan cong tot nhat
                    // xopt[k] cho biet nguoi k duoc giao cong viec nao
                    memcpy(xopt, x, sizeof(x));
                }
            }
            else{

                // Tinh can duoi cua phuong an phan cong hien tai
                // delta: Chi phi da phan cong cho k nguoi
                // n-k: So nguoi con lai chua duoc phan cong
                // cmin: Chi phi nho nhat cua mot lan phan cong
                int g = delta + (n - k) * cmin;

                // Neu can duoi nho hon chi phi toi uu hien tai
                // thi phuong an nay van co kha nang cho ket qua tot hon
                // Tiep tuc phan cong cho nguoi tiep theo
                if(g < fopt)
                    Try(k + 1);
            }

            // QUAY LUI:
            // Huy viec cong chi phi phan cong cong viec i cho nguoi k
            // Dua tong chi phi delta ve trang thai truoc do
            delta -= c[i][k];

            // Bo danh dau cong viec i
            // De cong viec i co the duoc thu giao cho nguoi khac
            vs[i] = 0;
        }
    }
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Nhap so luong nguoi va so luong cong viec
    cin >> n;

    // Nhap ma tran chi phi phan cong
    // Dong thoi tim chi phi phan cong nho nhat
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){

            // Chi phi giao cong viec i cho nguoi j
            cin >> c[i][j];

            // Cap nhat chi phi phan cong nho nhat
            if(c[i][j] < cmin){
                cmin = c[i][j];
            }
        }
    }

    // Bat dau tim phuong an phan cong tu nguoi thu nhat
    Try(1);

    // In ra tong chi phi phan cong nho nhat
    cout << fopt << "\n";

    // In ra phuong an phan cong toi uu
    // Nguoi k duoc giao cong viec xopt[k]
    for(int i = 1; i <= n; i++){
        cout << xopt[i] << " ";
    }

    return 0;
}
