//
// Created by chendong on 2018/1/22.
//

#include <jni.h>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_ndk_as3_myapplication_MainActivity_sayHelloWorld(JNIEnv *env, jobject instance) {
    return env->NewStringUTF("Hello World");
}