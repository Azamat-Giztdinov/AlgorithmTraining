#include <iostream>
#include <map>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> week = {"Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday", "Sunday"
    };
    std::map<std::string, int> week_ = {{"Monday", 0}, {"Tuesday",1}, {"Wednesday", 2},
        {"Thursday",3}, {"Friday", 4}, {"Saturday",5}, {"Sunday",6}
    };
    std::vector<int> week_days(7, 0);
    std::vector<std::string> months = {"January", "February", "March", 
        "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };

    std::map<std::string, int> months_days = {{"January", 31}, {"February", 28}, {"March", 31}, 
        {"April", 30}, {"May", 31}, {"June", 30}, {"July", 31},
        {"August", 31}, {"September", 30}, {"October", 31}, {"November", 30}, {"December", 31}
    };
    int n;
    std::cin >> n;
    int year;
    std::cin >> year;
    int count = 365;
    if(year % 400 == 0 || (year % 4 ==0 && year % 100)) {
        months_days[months[1]] = 29;
        ++count;
    }
    for(int i = 0; i < n; ++i) {
        int day;
        std::string month;
        std::cin >> day >> month;
        int days = 0;
        for(int j = 0; j < 12; ++j) {
            if(months[j] == month) break;
            days += months_days[months[j]];
        }
        days += (day - 1);
        days %= 7;
        week_days[days]++;
    }
    std::string week_day;
    std::cin >> week_day;
    int bias = week_[week_day];

    for (int i = 0; i < bias ; i++){
        int temp = week_days[week_days.size() - 1];
        for (int j = week_days.size() - 2; j >= 0; --j) {
            week_days[j + 1] = week_days[j];
        }
        week_days[0] = temp;
    }

    std::vector<int> weekend_count(7, count / 7);
    for(int i = 0; i < 7 ; ++i) {
        if(bias == i) weekend_count[i] ++;
        if(count == 366 && i == (bias + 1)%7) weekend_count[i]++;
    }
    
    int best = 0, worst = 0;
    int max = 0, min = count / 7 + 2;
    for(int i = 0; i < 7; ++i) {
        int m = weekend_count[i];
        for(int j = 0; j < 7; ++j) {
            if(j != i) m +=week_days[j];
        }
    	if(i == 0) min = m;
        if(m > max) {
            best = i;
            max = m;
        }
        if(m < min) {
            worst = i;
            min = m;
        }
    } 
    std::cout << week[best] << " " << week[worst];    
}