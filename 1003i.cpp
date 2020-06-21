#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char a[100], n;
    gets(a);
    scanf("%c", &n);
    int count = 0, i;

    for (i = 0; a[i] != '\0'; i++) {
        if (a[i] == n) {
            count++;
        }
    }
    printf("%d", count);
    system("pause");
    return 0;
}