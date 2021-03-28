#include <stdio.h>

/**
 * 二级指针和多级指针
 * @return
 */
int main() {

    int num = 12;

    int* p = &num;

    int** pp = &p;

    printf("p is %p\n", p);
    printf("pp is %p\n", pp);
    printf("**pp is %d\n", **pp);

    return 0;
}
