#include <iostream>
#include <vector>

int main()
{
    int n, m;
    std::cin >> n >> m;
    int max_ = 0;
    std::pair<int, int> res = {0,0};
    std::vector<std::pair<int, int>> pairs;
    std::vector<std::vector<int>> strength(n + 1, std::vector<int>(m + 1, 0));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
           std::cin >> strength[i][j];
           if(max_ < strength[i][j]) {
                max_ = strength[i][j];
                res = {i, j};
           }
        }
    }
    pairs.push_back(res);
    max_ = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(i != pairs[0].first && j != pairs[0].second && max_ < strength[i][j]) {
                max_ = strength[i][j];
                res = {i,j};
            }
        }
    }
    pairs.push_back(res);
    pairs.push_back({pairs[0].first, pairs[1].second});
    pairs.push_back({pairs[1].first, pairs[0].second});
    std::vector<int> min_values;
    int idx = 0;
    for(auto [race, clas]: pairs) {
        
        max_ = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(i != race && j != clas && max_ < strength[i][j]) {
                    max_ = strength[i][j];
                    res = {i,j};
                }
            }
        }
        min_values.push_back(max_);
        if(min_values[min_values.size() - 1] < min_values[idx]) idx = min_values.size() - 1;
    }
    std::cout << pairs[idx].first << ' ' << pairs[idx].second << std::endl;
    return 0;
}