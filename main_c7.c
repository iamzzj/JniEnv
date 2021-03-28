#include <stdio.h>
#include <stdlib.h>

/*int main() {
    // 打开文件 （文件名，模式）mode r(读) w(写) rb(作为二进制读) wb
    FILE *file = fopen("../Simple.txt", "r");

    if (!file) {
        return -1;
    }

    char buffer[10];

    // 缓存区buffer， 长度10， 文件指针
    while (fgets(buffer, 10, file)) {
        printf("%s",buffer);
    }

    fclose(file);
    return 0;
}*/

/**
 * 文件写入
 *
 * @return
 */
/*int main() {
    // 打开文件 （文件名，模式）mode r(读) w(写) rb(作为二进制读) wb
    FILE *file = fopen("../Simple1.txt", "w");

    if (!file) {
        return -1;
    }

    fputs("hello", file);

    fclose(file);
    return 0;
}*/

/**
 * 文件复制
 *
 * @return
 */
/*int main() {
    // 打开文件 （文件名，模式）mode r(读) w(写) rb(作为二进制读) wb
    FILE *file = fopen("../Simple.txt", "rb");
    FILE *fileCopy = fopen("../SimpleCopy.txt", "wb");

    if (!file || !fileCopy) {
        return -1;
    }

    int buffer[512];
    int len;
    while (len = fread(buffer, sizeof(int), 512, file)) {
        printf("len %d\n", len);
        fwrite(buffer, sizeof(int), len, fileCopy);
    }

    fclose(file);
    fclose(fileCopy);
    return 0;
}*/

/**
 * 获取文件大小
 * @return
 */
/*
int main() {
    // 打开文件 （文件名，模式）mode r(读) w(写) rb(作为二进制读) wb
    FILE *file = fopen("../Simple.txt", "rb");
    if (!file) {
        return -1;
    }

    //没有一个函数可以直接拿文件大小
    //将文件的指针移动到最后,然后再去计算偏移量
    fseek(file, 0, SEEK_END);

    //计算偏移位置,从0开始统计到当前
    long fileSize = ftell(file);
    printf("fileSize %ld", fileSize);

    fclose(file);
    return 0;
}*/

/**
 * 文件加密
 * 为了防止图片泄密
 *
 * @return
 */
int main() {
    // 打开文件 （文件名，模式）mode r(读) w(写) rb(作为二进制读) wb
    FILE *file = fopen("../Simple.txt", "rb");
    FILE *fileEncode = fopen("../SimpleEncode.txt", "wb");

    if (!file || !fileEncode) {
        return -1;
    }

    // 思路：把每个字节拿出来，对每一个字节进行处理
    // 10^5 异或
    // 1010
    // 0101
    // 1111

    // 解密 同样的异或
    int c;
    while ((c = fgetc(file)) != EOF){
        fputc(c ^ 5, fileEncode);
    }

    fclose(file);
    fclose(fileEncode);
    return 0;
}
