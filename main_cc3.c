#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    int format;
} AndroidBitmapInfo;

int getAndroidBitmapInfo(AndroidBitmapInfo *androidBitmapInfo) {
    if (androidBitmapInfo == NULL) {
        return -1;
    }
    androidBitmapInfo->width = 100;
    androidBitmapInfo->height = 200;
}

/**
 * 设计一个C项目
 * 1.确定你的参数，传递指针
 * 2.一定要考虑健壮性
 * 3.对错误进行抛出说明
 * 4.不要轻易的去改变创建者给你的指针
 *
 * @return
 */
int main() {
    AndroidBitmapInfo *androidBitmapInfo = malloc(sizeof(AndroidBitmapInfo));

    if (androidBitmapInfo != NULL) {
        free(androidBitmapInfo);
        androidBitmapInfo = NULL;
    }

    int ret = getAndroidBitmapInfo(androidBitmapInfo);

    if (ret != 0) {
        return -1;
    }

    printf("width: %d,height: %d\n",
           androidBitmapInfo->width,
           androidBitmapInfo->height);

    return 0;
}
