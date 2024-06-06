#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<char>> board(8, std::vector<char>(8, '*'));
    char ch;
    int count = 0;
    int sum = 64;
    while(count < sum) {
        std::cin >> ch;
        if(ch == '*' || ch == 'R' || ch == 'B') {
            int i = count / 8;
            int j = count % 8;
            board[i][j] = ch;
            ++count;
        }
    }
    
    for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 'R') {
                for(int k = i - 1, g = i + 1;; --k, ++g) {
                    if(k >= 0 && (board[k][j] == '*' || board[k][j] == '#')) {
                        board[k][j] = '#';
                    } else {
                        k = -1;
                    }
                    if(g < 8 && (board[g][j] == '*' || board[g][j] == '#')) {
                        board[g][j] = '#';
                    } else {
                        g = 8;
                    }
                    if(k < 0 && g >= 8) break;
                }
                for(int k = j - 1, g = j + 1;; --k, ++g) {
                    if(k >= 0 && (board[i][k] == '*' || board[i][k] == '#')) {
                        board[i][k] = '#';
                    } else {
                        k = -1;
                    }
                    if(g < 8 && (board[i][g] == '*' || board[i][g] == '#')) {
                        board[i][g] = '#';
                    } else {
                        g = 8;
                    }
                    if(k < 0 && g >= 8) break;
                }
                
            } else if (board[i][j] == 'B') {
                std::vector<int> tmp = {1,1,1,1};
                for(int k = 1; k < 8; ++k) {
                    if(i - k >= 0 && j -k >= 0 && (board[i-k][j-k] == '*' || board[i-k][j-k] == '#') &&
                    tmp[0]) {
                        board[i-k][j-k] = '#';
                    } else {
                        tmp[0] = 0;
                    }
                    
                    if(i + k < 8 && j -k >= 0 && (board[i+k][j-k] == '*' || board[i+k][j-k] == '#') &&
                    tmp[1]) {
                        board[i+k][j-k] = '#';
                    } else {
                        tmp[1] = 0;
                    }
                    
                    if(i - k >= 0 && j + k < 8 && (board[i-k][j+k] == '*' || board[i-k][j+k] == '#') &&
                    tmp[2]) {
                        board[i-k][j+k] = '#';
                    } else {
                        tmp[2] = 0;
                    }
                    
                    if(i + k <  8 && j + k < 8 && (board[i+k][j+k] == '*' || board[i+k][j+k] == '#') &&
                    tmp[3]) {
                        board[i+k][j+k] = '#';
                    } else {
                        tmp[3] = 0;
                    }
                    
                }
            }
        }
    }
    for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board[i].size(); ++j) {
            if(board[i][j] != '*') --sum;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
