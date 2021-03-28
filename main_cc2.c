#include <stdio.h>
#include <string.h>

int main() {
    //char buffer[] = {'1', '2', '3', '4', '5', '6'};//len 6， size 6
    //char buffer[100] = {0};
    //char buffer[100];// 值不确定
    //char buffer[] = "123456"; //len是6，size是7，后面默认跟\0
    // 相当于 char buffer[] = {'1', '2', '3', '4', '5', '6', '\0'};

    char* buffer = "123456";//len: 6, size: 8（应该为指针长度）

    //char buffer[] = "123456"   char* buffer = "123456"  malloc
    //字符串可以在任何地方栈区，堆区，常量区

    int len = strlen(buffer);
    int size = sizeof(buffer);

    printf("len: %d, size: %d\n", len, size);

    printf("%d, %d, %d, %d\n", buffer[0], buffer[66], buffer[77], buffer[99]);

    return 0;
}
