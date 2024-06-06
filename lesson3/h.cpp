#include <iostream>
#include <vector>
#include <set>
#include <map>

int main()
{
    int n;
    std::cin >> n;
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> v(n);
        for (int i = 0; i < n; ++i) {
            int x, y, x2, y2;
            std::cin >> x >> y >> x2 >> y2;
            if (x < x2 || (x == x2 && y < y2))
                v[i] = { {x,y}, {x2,y2} };
            else
                v[i] = { {x2,y2}, {x,y} };
        }
        std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> s_end;
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> v_end(n);
        for (int i = 0; i < n; ++i) {
            int x, y, x2, y2;
            std::cin >> x >> y >> x2 >> y2;
            if (x < x2 || (x == x2 && y < y2)) {
                v_end[i] = { {x,y}, {x2,y2} };
                s_end.insert({ {x,y}, {x2,y2} });
            }
            else {
                v_end[i] = { {x2,y2}, {x,y} };
                s_end.insert({ {x2,y2}, {x,y} });
            }
        }

        int count_max = 0;
        std::map<std::pair<int, int>, int> pairs;
        for (auto& i : v) {
            for (auto& j : v_end) {
                int x = j.first.first - i.first.first;
                int y = j.first.second - i.first.second;
                if (j.second.first - i.second.first == x &&
                    j.second.second - i.second.second == y )
                {
                    if (pairs.find({ x,y }) == pairs.end())
                        pairs[{ x, y }] = 1;
                    else
                        pairs[{x, y}]++;
                    count_max = std::max(count_max, pairs[{x, y}]);
                }
            }
        }
        std::cout << n - count_max << std::endl;
    return 0;
}