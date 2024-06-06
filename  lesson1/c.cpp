#include <iostream>
#include <cstdint>

int main()
{
    uint64_t sum = 0;
    uint64_t n, a;
    std::cin >> n;
    while( n > 0 ) {
        std::cin >> a;
        sum += (a / 4);
        if(a % 4 == 3) {
            sum += 2;
        } else if ( a % 4) {
            sum +=(a % 4);
        }
        --n;
    }
    std::cout << sum;
    return 0;
}