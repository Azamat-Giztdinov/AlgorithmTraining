#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<int> nums(n);
    std::unordered_map<int, int> map_nums;
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
            if(map_nums.find(nums[i]) == map_nums.end()) {
                map_nums[nums[i]] = 1;
            } else 
            map_nums[nums[i]]++;

    }
    int count_max = 0;
    for (auto& i : map_nums) {
        int count = i.second;
        int x = 1 - std::abs(i.first);
        int num = 0;
        if (map_nums.find(-x) != map_nums.end()) {
            num = map_nums[-x];
        }
        if (map_nums.find(x) != map_nums.end()) {
            num = std::max(num, map_nums[x]);
        }
        count_max = std::max(count_max, count + num);
    }
    std::cout << n - count_max;
    return 0;
}