#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::string res = "NO";
    std::unordered_map<int, int> m;
    std::queue<int> q;
    int x = 0;
    for(int i = 0; i < n; ++i) {
        std::cin >> x;
        if(res == "NO"){
            if(m.find(x) == m.end()) m[x] = 1;
            else ++m[x];
            if(q.size() == k + 1) {
                m[q.front()]--;
                q.pop();
                q.push(x);
            } else {
                q.push(x);
            }
            if(m[x] == 2) res = "YES";
        }
        
    }
    std::cout << res << std::endl;
    return 0;
}