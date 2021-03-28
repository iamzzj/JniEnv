#include <cstdio>

/*int main() {
    int i = 100;

    printf("i address is: %p\n", &i);

    printf("int sizeof: %d\n", sizeof(int));
    printf("double sizeof: %d\n", sizeof(double));
    printf("char sizeof: %d\n", sizeof(char));
    return 0;
}*/

/**
 * 获取变量和获取地址的值
 * @return
 */
/*int main(){
    int i = 100;
    printf("i is: %d\n", i);
    // 通过*获取值
    int* p = &i;
    printf("i is: %d\n", *p);
    return 0;
}*/

/**
 * 通过指针修改值
 * @return
 */
/*int main(){
    int i = 12;
    int* p = &i;
    *p = 13;

    printf("i is: %d\n", i);
    printf("&i is: %p\n", &i);
    printf("p is: %p\n", p);
    printf("&p is: %p\n", &p);
    printf("*p is: %d\n", *p);
}*/

/**
 * 修改i
 * @return
 */
void change(int* p) {
    printf("i change* address is %d\n", p);
    *p = 200;
}

void change(int& i){
    printf("i change& address is %d\n", &i);
    i = 300;
}

int main() {
    int i = 100;
    printf("i address is %d\n", &i);
    printf("i is %d\n", i);

    change(&i);
    printf("i change is %d\n", i);

    change(i);
    printf("i change is %d\n", i);
}
