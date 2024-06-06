#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, k;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end());
    
    std::cin >> k;
    for(int i = 0; i < k; ++i) {
        int x, y; 
        int idx1 = n, idx2 = 0;
        std::cin >> x >> y;
        int left = 0, right = n-1;
            while(left < right) {
                int med = (left + right) / 2;
                if(nums[med] >= x) right = med;
                else left = med + 1;
            }
            if(nums[left] >= x) idx1 = left;
            left = 0, right = n -1;
            while(left < right) {
                int med = (left + right + 1) / 2;
                if(nums[med] > y) right = med - 1;
                else left = med;
            }
            if(nums[left] <= y) idx2 = left + 1;
        if(idx2 <= idx1)
            idx1 = idx2 = 0;
        std::cout << idx2 - idx1 << std::endl;
    }


    return 0;
}
