#include "Sort.h"
#include <vector>
#include <cstring>
#include <string>
using namespace std;

void Output(int *array,int Length); //output the array

int main()
{
    int array[10]={40,30,20,40,80,60,30,60,50,70};    
    int length = 10;
    cout<<"## Original Array:\t";
    Output(array,length);
    int key,OYN = 0;
    SortFunction sort;

    cout<<"## This is the test program for sort.h"<<endl;

    cout<<"## If you want input the new array:(Y:1/N:0/Exit:-1): OYN = ";
    cin >> OYN;
    while(OYN !=1 && OYN !=0 && OYN !=-1)
    {
        cout<<"## Error Input(OYN)!"<<endl;
        cout<<"## If you want input the new array:(Y:1/N:0/Exit:-1): OYN = ";
        cin >> OYN;
    }
    if(OYN == -1) {cout<<"Good Bye!"<<endl;exit(0);}
    if(OYN == 1){
        cout<<"## Please input the new array splitted by ',' (count <= 10)"<<endl;
        cout<<"## Your Input:";
        string strIn;
        char* str = const_cast<char*>(strIn.c_str());
        cin>>strIn;
        char* splitted = strtok(str,",");
        length = 0;
        while(splitted != NULL && length<10){
            array[length++] = stoi(string(splitted));
            splitted = strtok(NULL,",");
        }
        int count = length;
        while(count<10){
            array[count++] = '\0';
        }
    }

    cout<<"## Choose method to sort the array:"<<endl;
    cout<<"## 1) Insertion Sort; "<<endl;
    cout<<"## 2）Selection Sort; "<<endl;
    cout<<"## 3) Bubble Sort; "<<endl;
    cout<<"## 4) Shell Sort; "<<endl;
    cout<<"## 5) Merge Sort"<<endl;
    cout<<"## 6) Quick Sort;"<<endl;
    cout<<"## 7) Heap Sort;"<<endl;


    OYN = 1;
    cout<<"## Your Choice: key = ";
    cin >> key;


    cout<<"## Output the process of Sorting?(Y:1/N:0/Exit:-1): OYN = ";
    cin >> OYN;
    cout<< endl;
    while(OYN !=1 && OYN !=0 && OYN !=-1){
        cout<<"## Error Input(OYN)!"<<endl;
        cout<<"## Output the process of Sorting?(Y:1/N:0/Exit:-1): OYN = ";
        cin >> OYN;
    }
    if(OYN == -1) {cout<<"Good Bye!"<<endl;exit(0);}


    cout<<endl<<"## Ori:\t";
    Output(array,length);
    switch(key)
    {
        case 1:
            sort.InsertionSort(array,length,OYN);
            break;
        case 2:
            sort.SelectSort(array,length,OYN);
            break;
        case 3:
            sort.BubbleSort(array,length,OYN);
            break;
        case 4:
            sort.ShellSort(array,length,OYN);
            break;
        case 5:
            sort.MergeSort(array,length,OYN);
            break;
        case 6:
            sort.QuickSort(array,length,OYN);
            break;    
        case 7:
            sort.HeapSort(array,length,OYN);
            break;    
        default:
            cout<<"## Error Input(key)!"<<endl;
            exit(0);
    }
    cout<<"## Res:\t";
    Output(array,length);
}