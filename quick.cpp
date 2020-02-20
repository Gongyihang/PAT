#include <stdio.h>
#include <string.h>
int patition(int A[], int left, int right)
{
    int temp = A[left];
    while (left < right)
    {
        while (A[right] > temp && left < right)
        {
            right--;
        }
        A[left] = A[right];
        while (A[left] <= temp && left < right)
        {
            left++;
        }
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}
void qiucksort(int A[], int left, int right)
{
    while (left < right)
    {
        int mid = patition(A, left, right);
        qiucksort(A, mid + 1, right);
        qiucksort(A, left, mid + 1);
    }
}
int main()
{
    int A[5] = {9, 8, 6, 4, 8};
    qiucksort(A, 0, 4);
    for (int i = 0; i < 4; i++)
    {
        printf("%d", A[i]);
    }
    return 0;
}
