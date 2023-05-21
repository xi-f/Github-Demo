#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Maze{
public:
    Maze();
    void process(int& i, int& j, int& lineNum, int& columnNum,vector<vector<int>>& maze, vector<pair<int, int>>& combine, vector<pair<int, int>>& res);
    void process();
    void print();
private:
    vector<vector<int>> maze;

    int lineNum;
    int columnNum;
    
    vector<pair<int, int>> combine;
    vector<pair<int, int>> res;
};



#endif