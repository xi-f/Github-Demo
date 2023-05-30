#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool finishTheSudoku(vector<vector<int>>& soduku,
                     vector<unordered_map<int, bool>>& linePoss,
                     vector<unordered_map<int, bool>>& columnPoss,
                     vector<unordered_map<int, bool>>& squarePoss,
                     int& i, int& j) {
    if (i > 8 || j > 8) return true;
    int itemp = i, jtemp = j;
    if (soduku[i][j] != 0) {
        if (j == 8) {
            i++;
            j = 0;
            if(finishTheSudoku(soduku, linePoss, columnPoss, squarePoss, i, j)) return true;
        } else {
            j++;   
            if(finishTheSudoku(soduku, linePoss, columnPoss, squarePoss, i, j)) return true;
        }
        i=itemp,j=jtemp;
        return false;
    } else {
        for (int val = 1; val <= 9; val++) {
            if (linePoss[i].find(val) == linePoss[i].end() ||
                    columnPoss[j].find(val) == columnPoss[j].end() || 
                    squarePoss[(i/3)*3+j/3].find(val) == squarePoss[(i/3)*3+j/3].end()) {
                continue;
            }
            soduku[i][j] = val;
            linePoss[i].erase(val);
            columnPoss[j].erase(val);
            squarePoss[(i/3)*3+j/3].erase(val);
            if (j == 8) {
                i++;
                j = 0;
                if(finishTheSudoku(soduku, linePoss, columnPoss, squarePoss, i, j)) return true;
            } else {
                j++;
                if(finishTheSudoku(soduku, linePoss, columnPoss, squarePoss, i, j)) return true;
            }
            i=itemp,j=jtemp;
            soduku[i][j] = 0;
            linePoss[i][val] = true;
            columnPoss[j][val] = true;
            squarePoss[(i/3)*3+j/3][val] = true;
        }
    }
    if (soduku[i][j] == 0) return false;
    return true;
}

int main() {
    vector<vector<int>> soduku(9, vector<int>(9, 0));
    unordered_map<int, bool> sample = {
        {1, true}, {2, true}, {3, true},
        {4, true}, {5, true}, {6, true},
        {7, true}, {8, true}, {9, true}
    };
    vector<unordered_map<int, bool>> linePoss(9, sample);
    vector<unordered_map<int, bool>> columnPoss(9, sample);
    vector<unordered_map<int, bool>> squarePoss(9, sample);
    cout<<"Please input Orginal : "<<endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> soduku[i][j];
            linePoss[i].erase(soduku[i][j]);
            columnPoss[j].erase(soduku[i][j]);
            squarePoss[(i/3)*3+j/3].erase(soduku[i][j]);
        }
    }
    int i =0,j=0;
    cout<<"Res:"<<endl;
    finishTheSudoku(soduku,linePoss,columnPoss,squarePoss,i,j);
    for (int i = 0; i < 9; i++) {
        if(i%3==0)  cout<<"========================="<<endl;
        for (int j = 0; j < 9; j++) {
            if(j%3==0) cout<<"= ";
            cout << soduku[i][j] << ' ';
        }
        cout<<"="<<endl;
    }
    cout<<"========================="<<endl;
    return 0;

}
// 64 位输出请用 printf("%lld")