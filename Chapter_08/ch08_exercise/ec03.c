#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> // 使用布尔类型需要包含此头文件

#define SIZE 10

int main(void) {
    char grid[SIZE][SIZE];
    int row = 0, col = 0; // 起始坐标 (0,0)
    char current_letter = 'A';
    int dir;
    
    // 1. 初始化 10x10 网格，全部填充为 '.'
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    // 播下随机数种子，保证每次运行生成的路线都不一样
    srand((unsigned)time(NULL));

    // 在起点放入字母 'A'
    grid[row][col] = current_letter;

    // 2. 核心循环：尝试放入 'B' 到 'Z'
    for (current_letter = 'B'; current_letter <= 'Z'; current_letter++) {
        
        // 【关键步骤：侦查四周】判断四周是否还有合法空位
        bool up_ok    = (row - 1 >= 0   && grid[row - 1][col] == '.');
        bool down_ok  = (row + 1 < SIZE && grid[row + 1][col] == '.');
        bool left_ok  = (col - 1 >= 0   && grid[row][col - 1] == '.');
        bool right_ok = (col + 1 < SIZE && grid[row][col + 1] == '.');

        // 如果上下左右全部无路可走，被堵死了，就跳出循环提前结束
        if (!up_ok && !down_ok && !left_ok && !right_ok) {
            break;
        }

        // 3. 开始随机移动，直到找到一个合法的方向
        while (1) {
            dir = rand() % 4; // 0:上, 1:下, 2:左, 3:右

            if (dir == 0 && up_ok) {
                row--;        // 向上移动一格
                break;        // 找到了有效移动，跳出 while(1) 的瞎转悠
            } else if (dir == 1 && down_ok) {
                row++;        // 向下移动一格
                break;
            } else if (dir == 2 && left_ok) {
                col--;        // 向左移动一格
                break;
            } else if (dir == 3 && right_ok) {
                col++;        // 向右移动一格
                break;
            }
        }
        
        // 移动成功后，在新位置留下当前字母
        grid[row][col] = current_letter;
    }

    // 4. 打印最终的随机步法迷宫图
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}