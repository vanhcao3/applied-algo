#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int min_x = 101, min_y = 101;
    int max_x = -1, max_y = -1;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // Ensure x1 <= x2 and y1 <= y2
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        
        min_x = min(min_x, x1);
        min_y = min(min_y, y1);
        max_x = max(max_x, x2);
        max_y = max(max_y, y2);
    }

    int width = max_x - min_x;
    int height = max_y - min_y;
    int area = width * height;

    cout << area << endl;

    return 0;
}
