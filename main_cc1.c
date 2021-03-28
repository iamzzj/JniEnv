#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 打印数组
 *
 * 数组作为参数传递的时候为什么获取不到长度
 *
 * 数组作为参数传递，会退化为一个指针，传的是首地址（高效）
 *
 * 必须传一个数组长度
 *
 * @param arr
 */
void print(int arr[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }

}

typedef int int32;

/**
 * 数组的大小
 *
 * 数据类型的本质：内存上的一块固定类型的空间
 * int 告诉c/c++开辟一块4个字节的空间
 *
 * 数据类型的别名：int32_t 可以对基础数据类型取别名
 * void 任意类型
 *
 * 变量的本质：一块连续大小的内存空间，通过变量可以取操作一块内存上的数据
 * 变量的三要素：内存大小，名称，作用域
 *
 * 内存四驱模型：
 *
 * 程序运行的流程：
 * 1.操作系统会把物理硬盘的代码load到内存
 * 2.加载到内存后，会把c代码分为4个区
 * 3.然后系统会找到main函数的入口去执行
 *
 * 四驱模型：
 * 1.栈区：由编译器自动分配的，存放一些局部变量值和函数，这个里面的内存会自动进行回收的
 * 2.堆区：自己手动去开辟的内存malloc/new，需要手动释放free/delete
 * 3.全局区/静态区：静态的一些常量，字符串等
 * 4.程序代码区：存放的是函数体的二进制代码
 *
 * 栈的开口方向：
 * int a = 10;
 * int b = 10;
 *
 *  &a > &b 开口向下
 *  &b > &a 开口向上
 *
 *  buffer数据类型跟栈的开口方向无关（都是向上）
 *
 *
 *  指针的强化:
 *  指针也是一种数据类型，为什么指针要有类型
 *  虽然只占用4个字节，但是有数据类型
 *
 * @return
 */
int main() {

    int arr[] = {1, 2, 3, 4, 5, 6};
    int32 size = sizeof(arr) / sizeof(int);

    printf("size: %d\n", size);

    print(arr, size);

    // arr 数据类型的内存空间大小
    // arr + 1 int类型大小是4
    // &arr + 1 arr的内存大小是24
    printf("%d, %d, %d, %d", arr, arr + 1, &arr, &arr + 1);

    // void*代表任意类型的指针
    void *mlc = malloc(100);
    free(mlc);

    // memcpy() 拷贝内存

    return 0;
}
