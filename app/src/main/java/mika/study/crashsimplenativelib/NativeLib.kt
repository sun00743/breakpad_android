package mika.study.crashsimplenativelib

object NativeLib {

    init {
        System.loadLibrary("crashsimplenativelib")
    }

    @Suppress("KotlinJniMissingFunction")
    external fun crash()

}