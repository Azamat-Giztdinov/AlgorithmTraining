#include <iostream>
#include <cstdint>

int main()
{
    int p , v , q , m ;
    std::cin >> p >> v;
    std::cin >> q >> m;
    int sum = 0;
    int maxP = std::max(p + v, q + m);
    int minP = std::min(p - v, q - m);
    for(int i = minP; i <= maxP; ++i) {
        if( (i >= p - v && i <= p + v) || (i >= q - m && i <= q + m) )
            ++sum;
    }
    std::cout << sum;
    return 0;
}