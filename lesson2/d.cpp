#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> board(10, std::vector<int>(10, 0));
    int x, y;
    for(int i = 0; i < n; ++i) {
        std::cin >> x >> y;
        board[x][y] = 1;
    }
    std::vector<int> dx = {-1, 0, 1, 0};
    std::vector<int> dy = {0, -1, 0, 1};
    int perimeter = 0;
    for(int i = 1; i < 9; ++i) {
        for(int j = 1; j < 9; ++j) {
            if(board[i][j] == 1) {
                for(int k = 0; k < 4; ++k){
                    if(board[i + dx[k]][j + dy[k]] == 0) {
                        ++perimeter;
                    }
                }
            }  
        }
    }
    std::cout << perimeter << std::endl;
}