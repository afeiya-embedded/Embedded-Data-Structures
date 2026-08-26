#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 7
int input_array(int pa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d个数>:", i + 1);
        scanf("%d", &pa[i]);
    }
    return 0;
}

int print_array(int pa[], int n)
{
    printf("数组的内容为>:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", pa[i]);
    }
    printf("\n");
    return 0;
}

// arr : 排序数组的地址
// n  : 参与排序的元素个数
void insertion_sort(int arr[], int n)
{
    int i, j, key; // key 保存
    for (i = 1; i < n; ++i)
    {
        key = arr[i]; // 取出下一个元素
        j = i - 1;    // j 指向i的前一个元素

        // 将已排序的元素比 key 大的元素后移
        // arr[j] > key , 让数组的前i-1个元素都和key进行比较， 比key的时候结束循环。
        // 循环到j==0时退出循环
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // 让arr[j] 往后移动
            j--;
        }
        arr[j + 1] = key; // 插入到正确位置
    }
}

int main(int argc, char const *argv[])
{
    int a[N] = {0};
    input_array(a, N);
    print_array(a, N);
    insertion_sort(a, N);
    print_array(a, N);

    return 0;
}
