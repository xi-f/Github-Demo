#include <iostream>
#include <time.h>

using namespace std;

int main(){
    time_t *start = new time_t();
    time(start);
    while(true){

    }
    cout<<start<<endl<<ctime(start);
    return 0;
}