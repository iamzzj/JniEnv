#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*int main() {
    // 可以随机运行，但是每次数据都一样

    //初始化随机发生器
    srand((unsigned) time(NULL));

    int i;
    for (i = 0; i < 10; i++) {
        printf("random %d\n", rand() % 100);
    }
    return 0;
}*/

/**
 * 静态开辟
 */
void staticlloc() {
    int arr[5];// 静态开辟
    int i = 0;
    for (; i < 5; i++) {
        arr[i] = i;
        printf("%d, %p\n", *(arr + i), arr + i);
    }
}

/**
 * 动态类型开辟
 * @return
 */
void dynamiclloc() {
    int *arr = (int *) malloc(10 * 1024 * 1024 * sizeof(int));
    free(arr);
}

/**
 * 重点，内存的开辟
 * @return
 */
/*
int main() {
    // 数组大小10M，int4个字节，占用内存40M
    //int arr[1 * 1024];

    // 栈：占用内存空间最大值 2M， 开辟内存是静态内存开辟，方法结束会自动回收
    // 堆：占用内存空间最大值 80%， 开辟内存的方式是动态开辟，不会自动回收，必须手动回收

    //staticlloc();

    //dynamiclloc();

    int num;
    printf("intput a num:");
    scanf("%d", &num);

    int *arr = (int *) malloc(num * sizeof(int));

    int i = 0;
    int print_num;
    for (i = 0; i < num; i++) {
        printf("input %d value:", i);
        scanf("%d", &print_num);

        arr[i] = print_num;
    }

    printf("\n");
    for (i = 0; i < num; i++) {
        printf("in %d point:%p\n", i, arr + i);
        printf("in %d value:%d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}*/

/**
 * 改变内存空间大小
 * @return
 */
int main() {
    int num;
    printf("intput a num:");
    scanf("%d", &num);

    int *arr = (int *) malloc(num * sizeof(int));
    int i;
    for (i = 0; i < num; i++) {
        arr[i] = i;
    }
    for (i = 0; i < (num); i++) {
        printf("%p is %d\n", arr + i, arr[i]);
    }
    printf("\n");

    // 再加一点内存
    int new_num;
    printf("intput add num:");
    scanf("%d", &new_num);
    int *new_arr = (int *) realloc(arr, (num + new_num) * sizeof(int));
    // 原来的内存地址不用重新赋值
    for (i = num; i < (num + new_num); i++) {
        new_arr[i] = i;
    }

    printf("%p is %d\n", new_arr + num + new_num, new_arr[num + new_num]);

    if (new_arr != NULL) {
        free(new_arr);
        new_arr = NULL;
    }else{
        free(arr);
        arr = NULL;
    }

    return 0;
}

