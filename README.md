## 编译Android对应breakpad
1. 修改 breakpad\android\google_breakpad 为jni

2. 在 breakpad\android 目录执行ndk-build命令

3. 会在 breakpad\android\obj\local 下生成对应的libbreakpad_client.a文件

4. 通过CMake文件为c++程序添加libbreakpad_client.a库
    ```
    set(PLUGIN_NAME "breakpad")
   
    add_library(
    breakpad_client 
    STATIC
    IMPORTED
    )
   
    set_target_properties(
    breakpad_client 
    PROPERTIES
    IMPORTED_LOCATION 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main/clibs/${ANDROID_ABI}/libbreakpad_client.a
    )
    ```

## 解析dump文件
1. 从传入的path 获取 .dump文件

2. 使用 minidump_stackwalk 工具解析.dump文件 
   - minidump_stackwalk工具在ndk\resources\iidb\bin 目录下
   - 命令 minidump_stackwalk dump文件目录 > 1.txt
   
3. 可以得到 crash 线程，so库名称，crash位置和寄存器信息， 使用addr2line解析
   - 命令arm-linux-androideabi-addr2line -f -C -e ${.so path} 0xxxxx(地址)    
   例如： 
      - 输入：
         ```
         i686-linux-android-addr2line -f -C -e C:\Users\mika\Desktop\study'\native_dump\dump_file\2\libcrashsimplenativelib.so 0x8f0b
         ```
      - 输出： 
         ```
         Java_mika_study_crashsimplenativelib_NativeLib_crash 
         .../crashsimplenativelib.cpp:15
         ```
   
