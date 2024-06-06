#include <iostream>

int main()
{
    int K;
    std::cin >> K;
    int minX, maxX, minY, maxY;
    int x, y;
    for(int i = 0; i < K; ++i) {
        std::cin >> x >> y;
        if(i == 0) {
            minX = maxX = x;
            minY = maxY = y;
        }
        if(x > maxX) maxX = x;
        if(x < minX) minX = x;
        if(y > maxY) maxY = y;
        if(y < minY) minY = y;
    }
    std::cout << minX << ' ' << minY << ' ' << maxX << ' ' << maxY;
}