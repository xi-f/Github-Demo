#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define DEFAULT_MAX 99999999;

class SortFunction{
    public:
        void InsertionSort(int *a,int Length , int OYN); //插入排序 
        void BubbleSort(int *a,int Length, int OYN);    //冒泡排序 
        void SelectSort(int *a,int Length, int OYN);    //选择排序 
        void ShellSort(int *a,int Length, int OYN);     //希尔排序 
        void MergeSort(int *a,int Length, int OYN);     //归并排序
        void QuickSort(int *a,int Length, int OYN);     //快速排序 
        void HeapSort(int *a,int Length, int OYN);      //堆排序
        void CountingSort(int *a,int Length, int OYN);  //计数排序
        void BucketSort(int *a,int Length, int OYN);    //桶排序
        void RadixSort(int *a,int Length, int OYN);     //基数排序
    private:
        void MergeSort_Loop(int *a,int start,int end);  // 归并排序 递归子函数
        void Merge(int *a,int p,int q,int r);           // 归并排序 合并子函数
        void Quick(int *a,int begin,int end,int &OYN,int &OYN_iter);// 快速排序 递归子函数
        void CreateMaxHeap(int *a, int heapSize);       //创建大顶堆
        void AdjustMaxHeap(int*a,int start, int heapSize);         //调整堆元素
        void Output(int *a,int Length);        //输出数组
        void Output(int *a,int begin,int end);
        void Swap(int &a,int &b);              //交换函数
};






