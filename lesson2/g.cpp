#include <iostream>
#include <vector>

int main()
{
    int t;
    std::cin >> t;
    for(int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        int count = 0;
        int min = 0;
        int x =0;
        int sum = 0;
        std::vector<int> res;
        for(int j = 0; j < n; ++j) {
            std::cin >> x;
            if(min == 0) min = x;
            if(x < sum || sum + 1 > min || sum + 1 > x) {
                res.push_back(sum);
                count++;
                min = x;
                sum = 1;
            } else {
                min = min > x? x: min;
                sum++;
            }
            if(j + 1 == n) {
                count++;
                res.push_back(sum);
            }
        }
        std::cout << count << std::endl;
        for(int i : res) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
