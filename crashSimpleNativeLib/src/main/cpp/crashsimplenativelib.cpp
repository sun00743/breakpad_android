#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_mika_study_crashsimplenativelib_NativeLib_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT void JNICALL
Java_mika_study_crashsimplenativelib_NativeLib_crash (JNIEnv *, jobject) {
    volatile int *a = nullptr;
    *a = 1;
}