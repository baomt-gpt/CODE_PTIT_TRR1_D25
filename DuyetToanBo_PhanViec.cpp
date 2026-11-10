#include <bits/stdc++.h>
using namespace std;

// n: số lượng người và số lượng công việc
// fopt: tổng chi phí nhỏ nhất tìm được
// x[i]: công việc được phân cho người i
// c[i][j]: chi phí giao công việc j cho người i
// xopt[i]: lưu phương án phân công tối ưu
int n, fopt, x[105], c[105][105], xopt[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fopt = 1e9;
    // Nhập số lượng người và công việc
    cin >> n;

    // Nhập ma trận chi phí phân công
    // c[i][j] là chi phí giao công việc j cho người i
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }

    // Khởi tạo hoán vị ban đầu
    // Ban đầu người i được phân công công việc i
    // x = [1, 2, 3, ..., n]
    for(int i = 1; i <= n; i++){
        x[i] = i;
    }

    // Liệt kê tất cả các hoán vị của mảng x
    // Mỗi hoán vị tương ứng với một phương án phân công
    do{

        // S: tổng chi phí của phương án phân công hiện tại
        int S = 0;

        // Tính tổng chi phí phân công
        // Người i được giao công việc x[i]
        // Nên chi phí tương ứng là c[i][x[i]]
        for(int i = 1; i <= n; i++){
            S += c[i][x[i]];
        }

        // Nếu phương án hiện tại có tổng chi phí nhỏ hơn
        // phương án tối ưu đã tìm được thì cập nhật
        if(S < fopt){

            // Cập nhật tổng chi phí nhỏ nhất
            fopt = S;

            // Lưu lại phương án phân công tốt nhất
            memcpy(xopt, x, sizeof(x));
        }

    // Sinh hoán vị tiếp theo
    // Duyệt tất cả hoán vị từ x[1] đến x[n]
    } while(next_permutation(x + 1, x + n + 1));

    // In ra tổng chi phí phân công nhỏ nhất
    cout << fopt << "\n";

    // In ra phương án phân công tối ưu
    // xopt[i] là công việc được giao cho người i
    for(int i = 1; i <= n; i++){
        cout << xopt[i] << " ";
    }

    return 0;
}
