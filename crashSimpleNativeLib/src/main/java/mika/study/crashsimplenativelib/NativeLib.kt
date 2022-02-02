package mika.study.crashsimplenativelib

class NativeLib {

    /**
     * A native method that is implemented by the 'crashsimplenativelib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun crash()

    companion object {
        // Used to load the 'crashsimplenativelib' library on application startup.
        init {
            System.loadLibrary("crashsimplenativelib")
        }
    }

}