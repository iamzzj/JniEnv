#include <stdio.h>

typedef struct JNINativeInterface *JNIEnv;

struct JNINativeInterface {
    char *(*NewStringUTF)(JNIEnv *, char *)
};

char *NewStringUTF(JNIEnv *env, char *str) {
    // str -> jstring
    return str;
}

char *Java_com_java_simple_getSingnature(JNIEnv *env, char *str) {
    return (*env)->NewStringUTF(env, str);
}

int main() {
    struct JNINativeInterface jniNativeInterface;
    jniNativeInterface.NewStringUTF = NewStringUTF;

    JNIEnv env = &jniNativeInterface;
    JNIEnv *jniEnv = &env;

    char *jstring = Java_com_java_simple_getSingnature(jniEnv, "hello");

    printf("%s", jstring);

    return 0;
}
