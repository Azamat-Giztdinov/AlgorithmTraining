#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> length(n);
    int max = 0;
    int idx = 0;
    for(int i = 0; i < n; ++i) {
        std::cin >> length[i];
        if(length[i] > max) {
            max = length[i];
            idx = i;
        }
    }
    
    int sum = 0;
    for(int i = 0; i < n; ++ i) {
        if(i != idx) sum += length[i];
    }
    
    int len;
    if(sum < length[idx]) len = length[idx] - sum;
    else len = sum + length[idx];
    std::cout << len;
}