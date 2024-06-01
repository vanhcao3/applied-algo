#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Cấu trúc để lưu thông tin mỗi kho báu
struct Treasure {
    long long x, y, c;
};

// Hàm so sánh để sắp xếp các kho báu theo tọa độ x, sau đó là y
bool compare(const Treasure& a, const Treasure& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

long long max_gold(int n, vector<Treasure>& treasures) {
    // Sắp xếp các kho báu theo tọa độ x, sau đó là y
    sort(treasures.begin(), treasures.end(), compare);
    
    // Tạo mảng dp để lưu trữ tổng lượng vàng lớn nhất có thể thu thập được đến mỗi kho báu
    vector<long long> dp(n, 0);
    
    // Khởi tạo dp với lượng vàng tại mỗi kho báu
    for (int i = 0; i < n; ++i) {
        dp[i] = treasures[i].c;
    }
    
    // Áp dụng lập trình động để tìm lộ trình tối ưu
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (treasures[j].x <= treasures[i].x && treasures[j].y <= treasures[i].y) {
                dp[i] = max(dp[i], dp[j] + treasures[i].c);
            }
        }
    }
    
    // Kết quả là giá trị lớn nhất trong mảng dp
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cin >> n;
    
    vector<Treasure> treasures(n);
    for (int i = 0; i < n; ++i) {
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].c;
    }
    
    cout << max_gold(n, treasures) << endl;
    
    return 0;
}
