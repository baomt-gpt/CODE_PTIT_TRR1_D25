#include <bits/stdc++.h>
using namespace std;

// n: số lượng thành phố
// c[i][j]: chi phí di chuyển từ thành phố i đến thành phố j
// x[i]: thành phố được đi qua ở vị trí thứ i trong hành trình
// fopt: tổng chi phí nhỏ nhất tìm được
// xopt[i]: lưu hành trình có tổng chi phí nhỏ nhất
int n, c[105][105], x[105], fopt, xopt[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // Khởi tạo giá trị tối ưu ban đầu là một số rất lớn
    // để dễ dàng cập nhật khi tìm được hành trình có chi phí nhỏ hơn
    fopt = 1e9;

    // Nhập số lượng thành phố
    cin >> n;

    // Nhập ma trận chi phí di chuyển giữa các thành phố
    // c[i][j] là chi phí đi từ thành phố i đến thành phố j
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }

    // Khởi tạo hành trình ban đầu:
    // x[i] = i nghĩa là thứ tự các thành phố là 1, 2, 3, ..., n
    // Thành phố 1 được cố định ở vị trí đầu tiên
    for(int i = 1; i <= n; i++){
        x[i] = i;
    }

    // Duyệt tất cả các hoán vị của các thành phố từ vị trí thứ 2 đến n
    // Giữ nguyên x[1] = 1 để tránh xét các hành trình trùng nhau
    // do chỉ khác nhau ở điểm bắt đầu
    do{

        // S: tổng chi phí của hành trình hiện tại

        // Tính chi phí quay trở về thành phố 1 từ thành phố cuối cùng
        int S = c[x[n]][1];

        // Tính chi phí di chuyển giữa các thành phố liên tiếp
        // Ví dụ: x[1] -> x[2] -> ... -> x[n]
        for(int i = 1; i < n; i++){
            S += c[x[i]][x[i + 1]];
        }

        // Kiểm tra xem hành trình hiện tại có tốt hơn phương án tối ưu
        // đã tìm được trước đó hay không
        if(S < fopt){

            // Cập nhật tổng chi phí nhỏ nhất
            fopt = S;

            // Sao chép hành trình hiện tại vào mảng xopt
            // để lưu lại hành trình có chi phí nhỏ nhất
            memcpy(xopt, x, sizeof(x));
        }

    // Sinh hoán vị tiếp theo của các thành phố từ vị trí 2 đến n
    // next_permutation trả về false khi không còn hoán vị nào tiếp theo
    } while(next_permutation(x + 2, x + n + 1));

    // In ra tổng chi phí nhỏ nhất của hành trình tìm được
    cout << fopt << "\n";

    // In ra thứ tự các thành phố trong hành trình tối ưu
    // xopt[1] -> xopt[2] -> ... -> xopt[n]
    for(int i = 1; i <= n; i++){
        cout << xopt[i] << " ";
    }

    // In thành phố 1 để thể hiện hành trình quay trở về điểm xuất phát
    cout << 1;

    return 0;
}
