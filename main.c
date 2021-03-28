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

    /*//获取jclass
    jclass j_class = env->GetObjectClass(j_object);

    //GetFieldID(jclass clazz, const char* name, const char* sig)
    //sig属性的签名
    jfieldID j_fieldId = env->GetFieldID(j_class, "name", "Ljava/lang/String");
    env->GetStaticFieldID //静态

    //获取name属性的fild
    jstring
    j_string = (jstring)
    env->GetObjectField(j_object, j_fieldId);
    env->GetStaticObjectField(j_object, j_fieldId);//静态

     //获取方法
     env->CallVoidMethod()

    //打印字符串 jstring -> c str
    const char *c_str = env->GetStringUTFChars(j_string, NULL);
    printf("name: %s", c_str);

    //修改成jack
    jstring jackName = env->NewStringUTF("Jack");
    env->SetObjectField(j_object, j_fieldId, jackName);*/

    return 0;
}
