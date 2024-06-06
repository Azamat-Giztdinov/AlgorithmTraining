#include <iostream>
#include <vector>

int main()
{
    long n;
    std::cin >> n;
    std::vector<int> sectors(n);
    int max_value = 0;
    for(int i = 0; i < n; ++i) {
        std::cin >> sectors[i];
        if(max_value < sectors[i]) max_value = sectors[i];
    }
    int max_win = -1;
    long min_w, max_w, w;
    std::cin >> min_w >> max_w >> w;
    
    if(max_w > w) {
        if(max_w - min_w > n * w) max_win = max_value;
        else {
            for(int i = min_w; i <= max_w; i += w) {
                int count = i / w;
                if(i % w == 0) count--;
                if(count >= n) count %= n;
                if(count != 0 && sectors[n - count] > sectors[count]) count = n - count;
                int win = sectors[count];
                if(i == min_w) max_win = win;
                max_win = max_win < win? win: max_win;
            }
        }
        std::cout << max_win << std::endl;
    } else {
        std::cout << sectors[0] << std::endl;
    }
}