#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::string first;
    std::string second;
    std::cin >> first >> second;
    std::unordered_map<char, int> mp;

    for(auto i: first) {
        if(mp.find(i) == mp.end()) mp[i] = 1;
        else ++mp[i];
    }
    for(auto i: second) {
        if(mp.find(i) == mp.end()) {
            mp[i] = 1;
            break;
        } else {
            --mp[i];
            if(mp[i] == 0) mp.erase(i);
        }
    }
    if(mp.size()) std::cout << "NO";
    else std::cout << "YES";
    return 0;
}