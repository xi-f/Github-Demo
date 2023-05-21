#include "Sort.h"

void SortFunction::InsertionSort(int *a,int Length, int OYN=0)
{
    // (增量法)
    // (1) 将第一待排序序列第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。
    // (2) 从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。
    // （如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。）
    
    int i,j;//循环控制
    int temp;
    int OYN_iter=1;
    //算法主体                              代价(Ci)         次数(Ni)
    for(i = 0;i<Length;i++)                 //  c1           Length
    {
        j = i-1;                            //  c2           Length-1
        temp = a[i];                        //  c3           Length-1
        while(j>-1 && a[j]>temp)//升序
        //while(j>-1 && a[j]<temp)//降序 
        {                   
            a[j+1] = a[j];//后移        //  c5           \sum_{i=1}^{Length-1}{T_i-1}  
            j=j-1;                      //  c6           \sum_{i=1}^{Length-1}{T_i-1}
        }
        a[j+1] = temp;                      //  c7           Length-1


        if(OYN==1)                          //输出排序过程
        {
            cout<<"## "<<OYN_iter<<")\t";
            Output(a,Length);
            OYN_iter++;
        }
    }
    // 运行时间T(n) = sum(Ci*Ni)
    // 最佳：事先有序：T_i=0：T(n) = (c1+c2+c3+c4+c7)Length-(c2+c3+c4+c7) = a*Length+b : 线性
    // 最坏：事先反序：T_i=i: T(n) = ... = a*Length^2+b*Length+c：二次函数;
    // 阶：Theta_{n^2}
}

void SortFunction::BubbleSort(int *a,int Length, int OYN=0)
{
    // 重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。
    // 走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。

    // 算法步骤：
    // (1) 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
    // (2) 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
    // (3) 针对所有的元素重复以上的步骤，除了最后一个。
    // (4) 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

    
    int i,j;//循环控制
    int temp;//临时变量
    int OYN_iter=1;

    for(i=0;i < Length-1;i++) //(1)(2)
    {
        for(j=0;j < Length-1-i;j++)
            if(a[j]>a[j+1])   // Increase
                Swap(a[j],a[j+1]);
    
        if(OYN==1)                      //输出排序过程
        {
            cout<<"## "<<OYN_iter<<")\t";
            Output(a,Length);
            OYN_iter++;
        }
    }
}

void SortFunction::SelectSort(int *a,int Length, int OYN=0)
{
    // 算法步骤：
    // (1) 首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
    // (2) 再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
    // (3) 重复第二步，直到所有元素均排序完毕。

    
    int i,j;//循环控制
    int loc;//最小(大)元素下标
    int OYN_iter=1;
    for(i=0;i<Length-1;i++)//不需要完全遍历
    {
        loc = i;
        for(j=i+1;j<Length;j++)//(3)
            if(a[j]<a[loc])//(2) Increase
                loc = j;
        Swap(a[i],a[loc]);
        
        if(OYN==1)                      //输出排序过程
        {
            cout<<"## "<<OYN_iter<<")\t";
            Output(a,Length);
            OYN_iter++;         
        }       
    }
}  

void SortFunction::ShellSort(int *a,int Length, int OYN=0)
{
    // 基本思想是：
    // 先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录"基本有序"时，再对全体记录进行依次直接插入排序。

    // 算法步骤:
    // (1) 选择一个增量序列 t1，t2，……，tk，其中 ti > tj, tk = 1；
    // (2) 按增量序列个数 k，对序列进行 k 趟排序；
    // (3) 每趟排序，根据对应的增量 ti，将待排序列分割成若干长度为 m 的子序列，分别对各子表进行直接插入排序。
    // 仅增量因子为 1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
    int h = 1;
    int OYN_iter = 1;
    int i,j;//循环控制
    while (h < Length / 3) //(1)
        h = 3 * h + 1;
    while (h >= 1) //(2)
    {
        for (i = h; i < Length; i++) //分割子列
            for (j = i; j >= h ; j -= h) //直接插入
                if(a[j] < a[j-h]) // Increase 
                //if(a[j] > a[j-h]) // Decrease 
                    Swap(a[j], a[j - h]);
        if(OYN==1)                      //输出排序过程
        {
            cout<<"## "<<OYN_iter<<")\t";
            Output(a,Length);
            OYN_iter++;         
        }
        h = h/3;
    }
}    

void SortFunction::MergeSort(int *a,int Length, int OYN=0)
{
    // (1) 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
    // (2) 设定两个指针，最初位置分别为两个已经排序序列的起始位置；
    // (3) 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
    // (4) 重复步骤 3 直到某一指针达到序列尾；
    // (5) 将另一序列剩下的所有元素直接复制到合并序列尾。
    
    int start = 0;
    MergeSort_Loop(a,start,Length-1);
}

void SortFunction::MergeSort_Loop(int *a,int start,int end)
{
    if(start<end)
    {
        int mid = (start+end)/2;
        MergeSort_Loop(a,start,mid); //跳出时有序
        MergeSort_Loop(a,mid+1,end); //跳出时有序
        Merge(a,start,mid,end);
    }
    //start = end 时，跳出递归，数组长度都为0或1有序，
}

void SortFunction::Merge(int *a,int p,int q,int r)
{
    //p <= q <= r
    //a[p, ... ,q] & a[q+1, ... ,r] 已排好序
    //函数作用：合并为有序数组 代替 a[p, ... ,r]
    int n1 = q-p+1;
    int n2 = r-q;
    int *L = (int*)malloc((n1+1)*sizeof(int));
    int *R = (int*)malloc((n2+1)*sizeof(int));
    int i,j,k;
    for(i=0 ; i<n1 ; i++)   // L = a[p  , ... ,q]
        L[i]=a[p+i];
    for(i=0 ; i<n2 ;i++)    // R = a[q+1, ... ,r]
        R[i]=a[q+i+1];
    L[n1] = DEFAULT_MAX;    // 减少判空 以简化算法
    R[n2] = DEFAULT_MAX;
    i = 0; j = 0;
    for(k = p ; k <=r ; k++)// 不删重合并
    {
        if(L[i]<=R[j])
            a[k]=L[i++];
        else
            a[k]=R[j++];
    }
}

void SortFunction::QuickSort(int *a,int Length, int OYN=0)
{
    // (1) 从数列中挑出一个元素，称为 "基准"（pivot）;
    // (2) 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
    // (3) 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序；
    int OYN_iter=1;
    Quick(a,0,Length-1,OYN,OYN_iter);

}   

void SortFunction::Quick(int *a,int begin,int end,int &OYN,int &OYN_iter){
    if(begin>end) return;
    int pivot = a[begin];
    int i = begin;
    int j = end;
    while(i < j){
        while(a[j]>=pivot && i<j)
            j--;
        while(a[i]<=pivot && i<j)
            i++;
        if(i<j)
            Swap(a[i],a[j]);
    }
    Swap(a[begin],a[i]);
    if(OYN==1)                      //输出排序过程
    {
        cout<<"## "<<OYN_iter<<")\t";
        Output(a,begin,end);
        OYN_iter++;         
    }
    Quick(a,begin,i-1,OYN,OYN_iter); // left
    Quick(a,i+1,end,OYN,OYN_iter);   // right
}

void SortFunction::HeapSort(int *a,int Length, int OYN=0)
{
    // (1) 创建一个堆 H[0……n-1]；
    // (2) 把堆首（最大值）和堆尾互换；
    // (3) 把堆的尺寸缩小 1，并调用 shift_down(0)，目的是把新的数组顶端数据调整到相应位置；
    // (4) 重复步骤 2，直到堆的尺寸为 1。

    int heapSize = Length;
    int OYN_iter = 1;
    CreateMaxHeap(a,heapSize);
    while(heapSize>1){
        Swap(a[0],a[--heapSize]);
        AdjustMaxHeap(a,0,heapSize);

        if(OYN==1)                      //输出排序过程
        {
            cout<<"## "<<OYN_iter<<")\t";
            Output(a,Length);
            OYN_iter++;         
        }
    }
}      

void SortFunction::CreateMaxHeap(int *a, int heapSize){
    int i = heapSize-1;
    if(i%2 == 1){
        if(a[i] > a[i/2])
            Swap(a[i],a[i/2]);
        i--;
    }
    for(; i > 0;i = i-2){
        if(a[i] > a[i-1] && a[i] > a[(i-1)/2]){//右孩子最大
            Swap(a[i],a[(i-1)/2]);
            AdjustMaxHeap(a,i,heapSize);
        }
        if(a[i] < a[i-1] && a[i-1] > a[(i-1)/2]){//左孩子最大
            Swap(a[i-1],a[(i-1)/2]);
            AdjustMaxHeap(a,i-1,heapSize);
        }
    }
}

void SortFunction::AdjustMaxHeap(int*a,int start,int heapSize){
    int loc = start;
    int left = 2*loc+1;
    int right = 2*loc+2;
    while (right<heapSize)
    {
        if(a[left]<=a[right] && a[loc]<a[right])
        {    
            Swap(a[loc],a[right]);
            loc=right;
        }
        else if(a[left]>=a[right] && a[loc]<a[left])
        {
            Swap(a[loc],a[left]);
            loc=left;
        }    
        else
            break;
        left = 2*loc+1;
        right = 2*loc+2;
    }
    if(left<heapSize && a[loc]<a[left]){
        Swap(a[loc],a[left]);
    }
}

void SortFunction::CountingSort(int *a,int Length, int OYN=0)
{
    // （1）找出待排序的数组中最大和最小的元素
    // （2）统计数组中每个值为i的元素出现的次数，存入数组C的第i项
    // （3）对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
    // （4）反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1
}  

void SortFunction::BucketSort(int *a,int Length, int OYN=0)
{
    // 桶排序是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。为了使桶排序更加高效，我们需要做到这两点：

    // 在额外空间充足的情况下，尽量增大桶的数量
    // 使用的映射函数能够将输入的 N 个数据均匀的分配到 K 个桶中
    // 同时，对于桶中元素的排序，选择何种比较排序算法对于性能的影响至关重要。  
}    

void SortFunction::RadixSort(int *a,int Length, int OYN=0)
{
    // 基数排序是一种非比较型整数排序算法，其原理是将整数按位数切割成不同的数字，然后按每个位数分别比较。由于整数也可以表达字符串（比如名字或日期）和特定格式的浮点数，所以基数排序也不是只能使用于整数。

    // 1. 基数排序 vs 计数排序 vs 桶排序
    // 基数排序有两种方法：

    // 这三种排序算法都利用了桶的概念，但对桶的使用方法上有明显差异：

    // 基数排序：根据键值的每位数字来分配桶；
    // 计数排序：每个桶只存储单一键值；
    // 桶排序：每个桶存储一定范围的数值；
}     

void SortFunction::Swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SortFunction::Output(int *a,int Length)
{
    int iter_i;
    for(iter_i=0;iter_i<Length;iter_i++)
        cout<<a[iter_i]<<", ";
    cout<<endl;
}

void SortFunction::Output(int *a,int begin,int end){
    int iter_i;
    for(iter_i=0;    iter_i<begin;iter_i++)
        cout<<"    ";
    for(iter_i=begin;iter_i<=end; iter_i++)
        cout<<a[iter_i]<<", ";
    cout<<endl;
}
