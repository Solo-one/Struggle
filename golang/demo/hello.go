package main

import "fmt"

var x, y int
var ( // 这种因式分解关键字的写法一般用于声明全局变量
    aaa int
    bbb float32
)

// 这种不带声明格式的只能在函数体中出现
//g, h := 123, "hello"

func main() {
    fmt.Println("hello world!")

    // var identifier1, identifier2 type
    var a string = "fxm"
    fmt.Println(a)

    var b, c int = 1, 2
    fmt.Println(b, c)

    // default value
    var i int
    var f float64
    var bb bool
    var s string
    fmt.Printf("%v %v %v %q\n", i, f, bb, s)

    ss := "fxm"
    fmt.Println(ss)
}
