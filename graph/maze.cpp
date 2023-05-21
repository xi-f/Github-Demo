#include "maze.h"

Maze::Maze(){
    cin >> lineNum >> columnNum;
    maze.resize(lineNum,vector<int>(columnNum,0));
    for (int i = 0; i < lineNum; i++) {
        for (int j = 0; j < columnNum; j++) {
            cin >> maze[i][j];
        }
    }
    combine.emplace_back(0,0);
}

void Maze::process(int& i, int& j, int& lineNum, int& columnNum,vector<vector<int>>& maze, vector<pair<int, int>>& combine, vector<pair<int, int>>& res) {
    if (i == lineNum - 1 && j == columnNum - 1) {
        res = combine;
        return;
    }
    if (i + 1 < lineNum && maze[i + 1][j] == 0 ) {
        i++;
        maze[i][j] = 1;
        combine.emplace_back(i, j);
        process(i, j, lineNum, columnNum, maze, combine, res);
        combine.pop_back();
        i--;
    }
    if (j + 1 < columnNum && maze[i][j + 1] == 0 ) {
        j++;
        maze[i][j] = 1;
        combine.emplace_back(i, j);
        process(i, j, lineNum, columnNum, maze, combine, res);
        combine.pop_back();
        j--;
    }
    if (i  > 0 && maze[i - 1][j] == 0 ) {
        i--;
        maze[i][j] = 1;
        combine.emplace_back(i, j);
        process(i, j, lineNum, columnNum, maze,combine, res);
        combine.pop_back();
        i++;
    }
    if (j  > 0 && maze[i][j - 1] == 0) {
        j--;
        maze[i][j] = 1;
        combine.emplace_back(i, j);
        process(i, j, lineNum, columnNum, maze,  combine, res);
        combine.pop_back();
        j++;
    }
}

void Maze::process(){
    int i =0,j=0;
    process(i,j,lineNum,columnNum,maze,combine,res);
}

void Maze::print(){
    for(auto i : res){
        cout<<'('<<i.first<<','<<i.second<<')'<<endl;
    }
}