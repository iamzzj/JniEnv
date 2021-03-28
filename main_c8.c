#include <stdio.h>

/**
 * 常量指针，指针常量
 * @return
 */
int main() {

    int number1 = 100;
    int number2 = 200;

    int const *np1 = &number1;
    int *const np2 = &number2;
    printf("p1:%p, p2:%p\n", np1, np2);

    // 常量指针 const 在*之前
    // 被修饰的变量不能再次赋值
    //*np1 = 234;
    // 指针的的地址可以再次赋值
    np1 = &number2;

    // 指针常量
    // 执政常量的地址不能再次赋值
    //np2 = &number1;
    // 修饰的常量可以再次赋值
    *np2 = 43;

    printf("p1:%p, p2:%p\n", np1, np2);

    return 0;
}
