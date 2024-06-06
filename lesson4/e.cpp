#include <iostream>
#include <cstdint>

uint64_t check(uint64_t x, uint64_t &sum) {
    uint64_t i = 0;
    while (sum < x) {
        i++;
        sum +=i;
    }
    sum -=(i);
    return i;
}

int main() {
    uint64_t n;
    std::cin >> n;
    uint64_t sum = 0;
    uint64_t minNum = check(n, sum);
    uint64_t x = 1, y = 1;
    if(minNum % 2) y = minNum;
    else x = minNum;
   	n -= (sum + 1);
    if((x+ y) % 2 == 0) x+=n,y-=n;
    else x-=n, y+= n;
    std::cout << x << '/' << y;
    return 0;
}

