#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> res;
    std::unordered_map<std::string, int> mp;
    for(int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        for(int j = 0; j < k; ++j) {
            std::string music;
            std::cin >> music;
            if(mp.find(music) == mp.end()) {
                mp[music] = 1;
            } else ++mp[music];
            if(mp[music] == n) res.push_back(music);
        }
    }
    std::cout << res.size() << '\n';
    std::sort(res.begin(), res.end());
    for(auto& i: res) {
        std::cout << i << ' ';
    }
    return 0;
}