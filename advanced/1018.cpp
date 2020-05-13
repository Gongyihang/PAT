#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

#define max(a, b, c) (a > b ? (a > c ? a : c) : (b > c ? b : c))

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    int count_tie = 0, count_win = 0;
    int count_c1 = 0, count_j1 = 0, count_b1 = 0;
    int count_c2 = 0, count_j2 = 0, count_b2 = 0;
    for (int i = 0; i < n; i++) {
        char a, b;
        scanf("%c %c", &a, &b);
        getchar();
        if (a == b) {
            count_tie++;
        } else if (a == 'C' && b == 'J') {
            count_c1++;
        } else if (a == 'C' && b == 'B') {
            count_b2++;
        } else if (a == 'J' && b == 'C') {
            count_c2++;
        } else if (a == 'J' && b == 'B') {
            count_j1++;
        } else if (a == 'B' && b == 'C') {
            count_b1++;
        } else if (a == 'B' && b == 'J') {
            count_j2++;
        }
    }
    count_win = count_c1 + count_j1 + count_b1;

    printf("%d %d %d\n", count_win, count_tie, n - count_win - count_tie);
    printf("%d %d %d\n", n - count_win - count_tie, count_tie, count_win);

    int max_a = max(count_c1, count_j1, count_b1);
    int max_b = max(count_c2, count_j2, count_b2);

    if (max_a == count_b1) {
        printf("%c ", 'B');
    } else if (max_a == count_c1) {
        printf("%c ", 'C');
    } else if (max_a == count_j1) {
        printf("%c ", 'J');
    }

    if (max_b == count_b2) {
        printf("%c", 'B');
    } else if (max_b == count_c2) {
        printf("%c", 'C');
    } else if (max_a == count_j2) {
        printf("%c", 'J');
    }

    system("pause");
    return 0;
}