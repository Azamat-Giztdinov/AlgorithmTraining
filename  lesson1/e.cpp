#include <iostream>

int main()
{
    long long int n, k, d;
    std::cin >> n >> k >> d;
    std::string str;
    while(d > 0) {
        int x = (n * 10) % k;
        if(x && k - x > 9) {
            str = "-1";
            break;
        } else if (x){
            n = n * 10 + ((k - x));
            str = std::to_string(n);
        } else {
            str = std::to_string(n);
            while(d > 0) {
                str += '0';
                --d;
            }
        }
        --d;
    }
    std::cout << str;
    return 0;
}