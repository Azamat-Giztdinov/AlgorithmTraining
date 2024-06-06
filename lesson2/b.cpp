#include <iostream>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> prices(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }
    int max = 0;
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n && j <= i + k; ++j) {
            if(prices[j] - prices[i] > max) max = prices[j] - prices[i];
        }
    }
    std::cout << max;
}