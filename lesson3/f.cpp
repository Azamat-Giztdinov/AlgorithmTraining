#include <iostream>
#include <unordered_set>
#include <sstream>


int main()
{
    std::unordered_set<std::string> dict;
    std::string str;
    std::getline(std::cin, str);
    std::stringstream dictStream(str);
    std::string word;
    while(dictStream >> word) {
        dict.insert(word);
    }
    std::string res;
    std::getline(std::cin, str);
    std::stringstream strStream(str);
    while(strStream >> word) {
        str = "";
         for(size_t i = 0; i < word.length(); ++i) {
            str += word[i];
            if(dict.find(str) != dict.end()) break;
        }
        res += str + " ";
    }
    std::cout << res << std::endl;
    return 0;
}
