#include <iostream>
#include <limits.h>
#include <cmath>
int main()
{
    double L, x1, v1, x2, v2;
    std::cin >> L >> x1 >> v1 >> x2 >> v2;
    if(v1 < 0) {
        v1 = -v1;
        x1 = L - x1;
    }
    if(v2 < 0) {
        v2 = -v2;
        x2 = L - x2;
    }
    double t = 0;
	std::cout << std::fixed;
	std::cout.precision(9);
	if(std::abs(x1 - x2) <= 1e-9 || std::abs(L - x1 - x2) <= 1e-9) {
	    std::cout << "YES\n" << t;
	} else if(v1 != 0 && v2 != 0) {
        for(int i = 1; i < 10; ++i) {
            double x11 = (v1 * (i * L - x2) + v2 * x1) / (v2 + v1);
            double x22 = v2 * (x11 - x1) / v1 + x2;
            t = (x11- x1) / v1;
            x11 = (v2 * x1 - v1 * x2) / (v2 -v1);
            t =  (x11- x1) / v1 < t && (x11- x1) / v1 > 0 ? (x11- x1) / v1: t;
            if(t > 0) break;
        }
        if(t > 0) std::cout << "YES\n" << t;
        else std::cout << "NO";
    } else if(v1 == 0 && v2 == 0) {
        std::cout << "NO";
    } else {
        double start = v1 != 0? x1: x2;
        double end = v1 != 0? x2: x1;
        if(start < L - end && end > L - end)  {
            end = L - end;
        }
        else if(end < start) end +=L;
        double v = v1? v1: v2;
        t = (end - start) / v;
        std::cout << "YES\n" << t;
    }
    return 0;
}