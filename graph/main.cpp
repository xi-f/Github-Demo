#include <iostream>
#include <utility>
#include <vector>
#include "maze.h"
using namespace std;
/*
    此迷宫算法的条件：仅有一条路径可以到达终点
*/

int main() {

    Maze newMaze;
    newMaze.process();
    newMaze.print();
    return 0;
}
// 64 位输出请用 printf("%lld")