package mika.study.breakpad

object BreakpadLoader {

    init {
        System.loadLibrary("breakpad")
    }

    fun init(path: String) {
        initNative(path)
    }

    private external fun initNative(path : String)

}