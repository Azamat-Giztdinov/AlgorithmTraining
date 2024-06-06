#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
int main()
{
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> ships(n);
    for(int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        ships[i] = {x - 1,y - 1};
    }
    std::sort(ships.begin(), ships.end(), [](std::pair<int, int> a, std::pair<int, int> b) {return a.first < b.first;});
    int min_sum = 0;
    int idx = 0;
    for(int i = 0; i < n; ++i) {
        int sum = 0;
        for(auto& a: ships) {
            sum +=std::abs(i - a.second);
        }
        if(i == 0) min_sum = sum;
        if(sum < min_sum) {
            idx = i;
            min_sum = sum;
        };
    }
    
    int count = 0;
    for(int i = 0; i < n; ++i) {
        count += (std::abs(ships[i].first - i) + std::abs(ships[i].second - idx));
    }
    std::cout << count << std::endl;
    return 0;
}