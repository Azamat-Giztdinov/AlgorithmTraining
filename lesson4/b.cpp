#include <iostream>
#include <vector>

long int sum(int x, long int & num) {
    long int sum = x+1 + num;
    num +=(x+1);
    return sum;
}
int main() {
    long int n;
    std::cin >> n;
    int res = 0;
    long int num = 0;
    long int j = -1;
    for(long int i = 1; i <= n; ++i) {
        j += sum(i, num);
    	if(j > n) break;
        res = i;
    }
    std::cout << res << std::endl;

    return 0;
}
