"-Wall",            
                "-Wextra",// 开启额外警告
                "-Wno-deprecated-register",
                "-Wshadow", // 当一个局部变量遮盖住了另一个局部变量，或者全局变量时，给出警告。
                "-Wpointer-arith", // 对函数指针或者 void * 类型的指针进行算术操作时给出警告。
                "-Wcast-qual", // 当强制转化丢掉了类型修饰符时给出警告。
                "-Wunrechable-code", // 如果编译器探测到永远不会执行到的代码，就给出警告。
     