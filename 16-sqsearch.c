#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sqsearch(int arr[], int n, int target) // int arr[] <=> int *arr
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
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

    return 0;
}
