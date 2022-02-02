package mika.study.breakpad

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import mika.study.crashsimplenativelib.NativeLib
import java.io.File

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val file = File(filesDir, "crashDump")
        if (!file.exists()) file.mkdirs()
        BreakpadLoader.init(file.absolutePath)

        findViewById<View>(R.id.carsh).setOnClickListener {
            NativeLib.crash()
        }
    }

}