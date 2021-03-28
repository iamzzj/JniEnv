#include <stdio.h>

/*
int main() {
    int arr[] = {1, 2, 3, 4};

    */
/*int i = 0;
    for (; i < 4; i++) {
        printf("%d is %d\n", i, arr[i]);
    }*//*


    // 看到一种现象，arr的值 = arr地址的值 = arr[0]地址的值
    printf("arr = %p\n", arr);
    printf("arr& = %p\n", &arr);
    printf("arr[0]& = %p\n", &arr[0]);

    // 如何获取数组的指针 arr_p[0] = *arr_p;
    int *arr_p = arr;
    */
/**
     * app_p = arr
     * app_p[0] = arr[0] = *app_p = *arr
     *//*


    // 做一系列的操作
    printf("*arr_p = %d\n", *arr_p);
    printf("arr_p = %p\n", arr_p);

    // 对指针进行++
    arr_p++;

    printf("*arr_p = %d\n", *arr_p);
    printf("arr_p = %p\n", arr_p);

    return 0;
}
*/

/**
 * 指针为什么要有类型，而且它的值也都差不多
 * */
/*
int main() {
    double dnum = 12.9;
    double *dp = &dnum;
    printf("dp is %p\n", dp);

    int num = 12;
    int *p = &num;
    printf("p is %p\n", p);
}*/

/**
 * 函数指针，回调
 *
 * */
void add(int num1, int num2) {
    printf("num1 + num2 = %d\n", (num1 + num2));
}

void opreate(void(*method)(int, int), int num1, int num2) {
    (*method)(num1, num2);
}

int main() {
    add(1, 2);
    void (*add_p)(int, int) = add;
    opreate(add_p, 2, 4);

    return 0;
}



