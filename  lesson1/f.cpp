#include <iostream>
#include <string>

int main()
{
    int x, num;
    int res = 0;
    std::cin >> x;
    std::string str = "";
    std::cin >> res;
    --x;
    while (x > 0) {
        std::cin >> num;
        if(num % 2) {
            if(res % 2) {
                str += 'x';
            } else {
                str += '+';
                res = 1;
            }
        } else {
            str += '+';
        }
        --x;
    }
    std::cout << str;
    
}