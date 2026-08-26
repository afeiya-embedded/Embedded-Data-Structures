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

// 希尔排序
// arr : 排序数组的地址
// n  : 参与排序的元素个数
void shell_sort(int arr[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    { // 初始间隔为 n/2，每次除以 2
        for (i = gap; i < n; i++)
        { // 对每个分组进行插入排序
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
            {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[N] = {0};
    input_array(a, N);
    print_array(a, N);
    shell_sort(a, N);
    print_array(a, N);

    return 0;
}
