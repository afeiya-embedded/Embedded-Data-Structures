#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sqsearch(int arr[], int n, int target) // int arr[] <=> int *arr
{
    for (int i = 0; i < n; i++)
    {
        printf("查找1次\n");
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        printf("查找1次:mid=%d\n", mid);
        if (arr[mid] == target)
        { // 找到目标元素
            return mid;
        }
        else if (arr[mid] < target)
        { // 目标元素在mid右侧
            left = mid + 1;
        }
        else
        { // 目标元素在mid左侧
            right = mid - 1;
        }
    }
    return -1; // 没找到目标元素
}
int main(int argc, char const *argv[])
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int value = 7;
    int index = sqsearch(a, 10, value);
    if (index < 0)
    {
        printf("没有找到\n");
        exit(-1);
    }
    printf("目标元素 %d 的下标为:%d\n", value, index);

    index = binary_search(a, 10, value);
    if (index < 0)
    {
        printf("没有找到\n");
        exit(-1);
    }
    printf("目标元素 %d 的下标为:%d\n", value, index);

    return 0;
}
