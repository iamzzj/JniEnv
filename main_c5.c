#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*int main() {
    char str[] = {'D', 'a', 'r', 'r', 'e', 'n', '\0'};
    str[2] = 'y';
    printf("%s\n", str);// 字符串的结尾是\0

    // 第二种
    char* str1 = "Darren";
    printf("%s\n", str1);

    // 区别，一个能改，一个不能改

    return 0;
}*/


int strlen_(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
        str++;
    }

    return i;
}

/**
 * 字符串长度
 *
 * @return
 */
/*int main() {
    char* name = "Devin";

    printf("name length is %d\n", strlen(name));
    printf("name length is %d\n", strlen_(name));
}*/

/**
 * 类型转换
 *
 * @return
 */
/*int main() {
    char *number_str = "12xx";
    // 如果不能转换，就会变成0， 后面不是数字会剔除
    int number = atoi(number_str);
    printf("number is %d\n", number);
    printf("float is %f\n", atof("32.43"));
    printf("double is %lf\n", strtod("32.43", NULL));
}*/

/**
 * 字符串的比较
 *
 * @return
 */
/*int main() {
    char *str1 = "Darren";
    char *str2 = "darren";

    // 区分大小写比较 strcmp
    // 不区分大小写比较 strcasecmp
    int rc = strcasecmp(str1, str2);

    if (rc == 0) {
        printf(" = ");
    } else {
        printf(" != ");
    }

    return 0;
}*/

/**
 * 截取
 *
 * @param str
 * @param start
 * @param end
 * @return
 */
char *substr(char *str, int start, int end) {
    int len = end - start;
    char *sub = (char *) malloc(len * sizeof(char) + 1);
    //char sub[len];

    int i = 0;
    str += start;
    for (; i < len; i++) {
        sub[i] = *str;
        str++;
    }

    sub[len] = '\0';
    return sub;
}

/**
 * 字符串的查找，包含，拼接，截取，大小写转换
 * @return
 */
/*int main() {

    char *str = "name is Darren";
    char *sub = "is";
    // 字符串第一次出现的位置指针
    char *pos = strstr(str, sub);

    printf("%s\n", pos);
    printf("第一次出现的位置是：%d\n", pos - str);

    //包含？pos是否为空
    if (pos) {
        printf("包含\n");
    } else {
        printf("不包含\n");
    }

    //strcpy() 拷贝
    char cpy[strlen(str) + 1];
    char *str_cpy = strcpy(cpy, str);
    printf("copy cpy is %s, ctr_cpy is %s\n", cpy, str_cpy);
    printf("copy str address %p, ctr_cpy address %p\n", str, str_cpy);

    //拼接 strcat
    char *str1 = " cat";
    char *cat = strcat(cpy, str1);
    printf("cat is %s\n", cat);

    //截取
    char *subS = substr(str, 0, 3);

    //一定要free，但是开发过程中并不会这么做，自己的方法尽量自己处理好内存
    printf("subS is %s\n", subS);
    free(subS);

    return 0;
}*/

/**
 *  大小写的转换
 *
 * @param dest 用来存放结果，大小自己指定
 * @param source 需要转换的字符串
 */
void lower(char *dest, char *source) {
    while (*source != '\0') {
        char ch = *source;
        *dest = tolower(ch);

        dest++;
        source++;
    }

    *dest = '\0';
}

/**
 * 大小写的转换
 *
 * @return
 */
/*
int main() {
    char *name = "darRenSDFD";
    char dest[strlen(name) + 1];
    lower(dest, name);

    printf("dest is %s\n", dest);
}
*/

/**
 * 字符串替换
 *
 * @param str
 * @param src
 * @param dst
 * @return
 */
char *str_replace(char *str, char *src, char *dst) {
    // 1.有没有src
    char *pos = strstr(str, src);

    if (!pos) {
        return str;
    }

    // 2.计算新的数组大小
    int newArrSize = strlen(str) - strlen(src) + strlen(dst);
    char *result = (char *) malloc(sizeof(char) * newArrSize);

    // 3.进行拼接
    // aa之前
    int start_end_position = pos - str;
    char *start = substr(str, 0, start_end_position);

    // aa之后
    int end_start_position = start_end_position + strlen(src);
    char *end = substr(str, end_start_position, strlen(str));

    //拼接
    strcpy(result, start);
    strcat(result, dst);
    strcat(result, end);

    free(start);
    free(end);

    return str_replace(result, src, dst);
}

int main() {
    char *str = str_replace("aabbaabbaabb", "aa", "ccc");

    printf("replace is %s\n", str);
    return 0;
}
