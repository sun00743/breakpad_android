#include <jni.h>
#include <android/log.h>

#include "breakpad/client/linux/handler/exception_handler.h"

#define LOG_TAG "crash_dumper"

#define ALOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define ALOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define ALOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define ALOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

static bool dumpCallback(
        const google_breakpad::MinidumpDescriptor &descriptor,
        void *context,
        bool succeeded
) {
    ALOGD("Dump path: %s\n", descriptor.path());
    return succeeded;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    ALOGI("JNI_OnLoad");
    JNIEnv *env;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
    ALOGI("JNI_OnUnload");
}


extern "C"
JNIEXPORT void JNICALL
Java_mika_study_breakpad_BreakpadLoader_initNative(JNIEnv *env, jobject thiz, jstring path_) {
    ALOGI("Dump init");
    const char *path = env->GetStringUTFChars(path_, 0);

    google_breakpad::MinidumpDescriptor descriptor(path);
    static google_breakpad::ExceptionHandler handler(descriptor, nullptr, dumpCallback, nullptr,
                                                     true, -1);
    env->ReleaseStringUTFChars(path_, path);
}