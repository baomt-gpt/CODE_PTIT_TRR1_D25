#include <bits/stdc++.h>
using namespace std;

// n: số đồ vật, b: sức chứa túi
// delta: tổng giá trị hiện tại, fopt: giá trị lớn nhất
int n, b, delta = 0, fopt = 0;

// w[i]: khối lượng, c[i]: giá trị
// index[i]: vị trí ban đầu của đồ vật
// x[i]: quyết định chọn (1) hoặc không chọn (0)
// xopt[i]: phương án tối ưu
int w[105], c[105], index[105], x[105], xopt[105];

// Sắp xếp đồ vật theo tỷ lệ giá trị/khối lượng giảm dần
bool cmp(array<int, 3> p, array<int, 3> q){
    return (double)p[1] / p[0] > (double)q[1] / q[0];
}

// Hàm quay lui có nhánh cận, k là đồ vật đang xét
void Try(int k){

    // Thử chọn trước (1), không chọn sau (0)
    for(int i = 1; i >= 0; i--){

        // Nếu chọn mà vượt sức chứa thì bỏ qua
        if(i * w[k] > b) continue;

        x[k] = i;                  // Lưu quyết định
        delta += c[k] * i;        // Cập nhật tổng giá trị
        b -= w[k] * i;            // Cập nhật sức chứa còn lại

        if(k == n){

            // Nếu tìm được phương án tốt hơn thì cập nhật
            if(delta > fopt){
                fopt = delta;
                memcpy(xopt, x, sizeof(x));
            }

        } else {

            // Tính giới hạn trên để quyết định có xét tiếp hay không
            double g = delta + (double)c[k + 1] / w[k + 1] * b;

            // Chỉ xét tiếp nếu nhánh còn khả năng tốt hơn
            if(g > fopt) Try(k + 1);
        }

        // Khôi phục trạng thái để thử nhánh tiếp theo
        delta -= c[k] * i;
        b += w[k] * i;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> b;

    // Lưu khối lượng, giá trị và vị trí ban đầu
    vector<array<int, 3>> d(n);
    for(int i = 0; i < n; i++){
        cin >> d[i][0] >> d[i][1];
        d[i][2] = i + 1;
    }

    // Sắp xếp theo tỷ lệ giá trị/khối lượng
    sort(d.begin(), d.end(), cmp);

    // Đưa dữ liệu đã sắp xếp vào các mảng
    for(int i = 0; i < n; i++){
        w[i + 1] = d[i][0];
        c[i + 1] = d[i][1];
        index[i + 1] = d[i][2];
    }

    // Bắt đầu quay lui từ đồ vật thứ nhất
    Try(1);

    // Khôi phục phương án về thứ tự đồ vật ban đầu
    int kq[105] = {};
    for(int i = 1; i <= n; i++){
        kq[index[i]] = xopt[i];
    }

    // In giá trị lớn nhất và phương án chọn đồ vật
    cout << fopt << "\n";
    for(int i = 1; i <= n; i++){
        cout << kq[i] << " ";
    }

    return 0;
}
