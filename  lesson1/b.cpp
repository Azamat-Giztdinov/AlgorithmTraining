#include <iostream>

int main()
{
    int g1, g2, v1, v2, qual;
    char ch;
    std::cin >> g1 >> ch >> g2;
    std::cin >> v1 >> ch >> v2;
    std::cin >> qual;
    int res = 0;
    if(g1 + v1 < g2 + v2) {
        res = (g2 + v2) - (g1 + v1);
        if(qual == 1 && res + v1 <= g2) {
            ++res;
        } else if(qual == 2 && g1 <= v2) {
            ++res;
        }
    } else if(g1 + v1 == g2 + v2) {
        if((qual == 1 && v1 <= g2) || (qual == 2 && g1 <= v2)) {
            res = 1;
        }
    }
    std::cout << res;
    return 0;
}