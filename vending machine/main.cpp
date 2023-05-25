#include <iostream>
#include "seller.h"

using namespace std;

int main(){
    Seller *seller;
    string command;
    char cur;
    while(cin>>noskipws>>cur){
        command.push_back(cur);
        if(cur == ';'){
            seller->analyze(command);
            command.clear();
        }
    }
    return 0;
}