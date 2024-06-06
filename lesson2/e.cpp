#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::pair<int,int>> pair(n);
    std::vector<int> res;
    int maxlast =0;
    int idxmax = -1;
    for(int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        pair[i] = {a, b};
        // differ[i] = a - b;
        if(maxlast < pair[i].second && a - b > 0) {
            maxlast = pair[i].second;
            idxmax = i;
        }
   }
    std::vector<int> maxE(n, 0);
    long int max = 0;
    int idx = 0;
    for(int j = 0; j < n; ++j) {
        max = 0;
        if(j != idxmax && pair[j].first - pair[j].second > max && maxE[j] == 0 ) {
            res.push_back(j);
            maxE[j] = 1;
        }
    }

    if(idxmax != -1) {
        res.push_back(idxmax);
        maxE[idxmax] = 1;
    }

    max = 0;
    for(int i = 0; i < n; ++i) {
       if(maxE[i] == 0 && max< pair[i].first) {
           max = pair[i].first;
           idx = i;
       } 
    }
    if(max) {
        res.push_back(idx);
        maxE[idx] = 1;
    }
    for(int i = 0; i < n; ++i) {
        if(maxE[i] == 0) {
            res.push_back(i);
        }
    }
    long int sum = 0;
    max = 0;
    for(int i = 0; i < n; ++i) {
        sum +=pair[res[i]].first;
        max = sum > max? sum: max;
        sum -=pair[res[i]].second;
    }
    std::cout << max << std::endl;
    for(auto& i: res) {
        std::cout << i+1 << " ";
    }
    return 0;
}
