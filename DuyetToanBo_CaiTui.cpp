#include <bits/stdc++.h>
using namespace std;

// n: số lượng đồ vật
// b: sức chứa tối đa của chiếc túi
// x[i]: biến quyết định, x[i] = 1 nếu chọn đồ vật i, = 0 nếu không chọn
// Xopt[i]: lưu phương án chọn đồ vật tối ưu nhất
// fopt: tổng giá trị lớn nhất tìm được
int n, b, x[105], xopt[105], fopt = -9999;

// w[i]: khối lượng của đồ vật i
// c[i]: giá trị của đồ vật i
int w[105], c[105];

// Hàm quay lui Try(i) dùng để xét việc chọn hoặc không chọn đồ vật i
void Try(int i) {

    // Nếu i == n, nghĩa là đã quyết định xong cho tất cả n đồ vật
    // (các đồ vật được đánh số từ 0 đến n - 1)
    if (i > n) {

        // W: tổng khối lượng của các đồ vật được chọn
        // V: tổng giá trị của các đồ vật được chọn
        int W = 0, V = 0;

        // Duyệt qua tất cả đồ vật để tính tổng khối lượng và tổng giá trị
        for (int k = 1; k <= n; k++) {

            // Nếu x[k] = 1 thì cộng khối lượng đồ vật k
            // Nếu x[k] = 0 thì không cộng khối lượng
            W += x[k] * w[k];

            // Tương tự, tính tổng giá trị của các đồ vật được chọn
            V += x[k] * c[k];
        }

        // Kiểm tra phương án hiện tại:
        // 1. Tổng khối lượng W không vượt quá sức chứa b
        // 2. Tổng giá trị V lớn hơn giá trị tối ưu đã tìm được
        if (W <= b && V > fopt) {

            // Cập nhật giá trị tối ưu mới
            fopt = V;

            // Sao chép phương án hiện tại x sang Xopt
            // để lưu lại cách chọn đồ vật có giá trị tốt nhất
            memcpy(xopt, x, sizeof(x));
        }

        // Đã xét xong một phương án, kết thúc nhánh đệ quy này
        return;
    }

    // Thử cả hai khả năng đối với đồ vật i:
    // j = 0: không chọn đồ vật i
    // j = 1: chọn đồ vật i
    for (int j = 0; j <= 1; j++) {

        // Gán quyết định chọn hoặc không chọn cho đồ vật i
        x[i] = j;

        // Chuyển sang xét đồ vật tiếp theo
        Try(i + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i];
    }

    // Bắt đầu quay lui từ đồ vật đầu tiên, có chỉ số 1
    Try(1);

    // In ra tổng giá trị lớn nhất tìm được
    cout << fopt << "\n";

    // In phương án tối ưu:
    // Xopt[i] = 1 nghĩa là chọn đồ vật i
    // Xopt[i] = 0 nghĩa là không chọn đồ vật i
    for (int i = 1; i <= n; i++) {
        cout << xopt[i] << " ";
    }

    return 0;
}
