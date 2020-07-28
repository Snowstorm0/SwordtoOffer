

//快速排序的基本实现
//1、从数列中取出一个数作为基准数（枢轴，pivot）。 
//2、将数组进行划分(partition)，将比基准数大的元素都移至枢轴右边，
//    将小于等于基准数的元素都移至枢轴左边。
//3、再对左右的子区间重复第二步的划分操作，直至每个子区间只有一个元素。
//快速排序时间复杂度
//快速排序的时间复杂度在最坏情况下是O(N2)，平均的时间复杂度是O(N*logN)。
//假设被排序的数列中有N个数。遍历一次的时间复杂度是O(N)，需要遍历至少log(N+1)次，最多N次。
//为什么最少是log(N+1)次？快速排序是采用的分治法进行遍历的，
//我们将它看作一棵二叉树，它需要遍历的次数就是二叉树的深度，而根据完全二叉树的定义，它的深度至少是log(N+1)。因此，快速排序的遍历次数最少是log(N+1)次。
//为什么最多是N次？这个应该非常简单，还是将快速排序看作一棵二叉树，
//它的深度最大是N。因此，快读排序的遍历次数最多是N次。





int partition(int arr[], int left, int right)  //找基准数 划分
{
    int i = left + 1 ;
    int j = right;
    int temp = arr[left];

    while(i <= j)
    {
        while (arr[i] < temp)
        {
            i++;
        }
        while (arr[j] > temp )
        {
            j--;
        }
        if (i < j)
            swap(arr[i++], arr[j--]);
        else i++;
    }
    swap(arr[j], arr[left]);
    return j;

}

void quick_sort(int arr[], int left, int right) 
{
    if (left > right)
        return;
    int j = partition(arr, left, right);
    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}
