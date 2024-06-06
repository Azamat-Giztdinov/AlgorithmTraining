#include <iostream>
#include <map>
#include <unordered_set>

int main()
{
    std::unordered_set<int> s;
    std::map<int,int> m;
    for(int i = 0; i < 3; ++i) {
        int n;
        std::cin >> n;
        int x = 0;
        for(int j = 0; j < n; ++j) {
            std::cin >> x;
            s.insert(x);
        }
        for(auto num: s) {
            m[num]++;
        }
        s.clear();
    } 
    for(auto i : m) {
        if(i.second >= 2) std::cout << i.first << ' ';
    }
}