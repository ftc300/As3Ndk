//
// Created by chendong on 2018/1/22.
//
#include <jni.h>
#include <string>
#include <android/log.h>


#define  LOGTAG "JNILOG"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOGTAG,__VA_ARGS__) // 定义LOGD类型
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOGTAG,__VA_ARGS__) // 定义LOGI类型
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOGTAG,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOGTAG,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOGTAG,__VA_ARGS__) // 定义LOGF类型



extern "C"
JNIEXPORT void JNICALL
Java_com_ndk_as3_myapplication_MainActivity_operateArrary(JNIEnv *env, jobject instance,
                                                          jintArray args_) {
    jint *args = env->GetIntArrayElements(args_, NULL);
//    int *p = NULL;
//    *p = 100;
    jint len = env->GetArrayLength(args_);
    for (int i = 0; i < len; ++i) {
        LOGE("jni arg before   %d",args[i]);
        args[i] *= 2;
        LOGE("jni arg after   %d",args[i]);
    }

    env->ReleaseIntArrayElements(args_, args, 0);
}