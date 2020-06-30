package main
import "fmt"

func main() {
    fmt.Println("Hello World, 您好")

    fmt.Println(numbers)
    fmt.Println(numbers())
   
    /*
        只获取函数返回值的后两个
        实际上是一个只写变量，你不能得到它的值。
        这样做是因为 Go 语言中你必须使用所有被声明的变量，
        但有时你并不需要使用从一个函数得到的所有返回值。
    */
    _, bb, cc := numbers()
    fmt.Println(bb, cc)
    fmt.Printf("%v %v\n", bb, cc)
}

// 一个可以返回多个值的函数
func numbers()(int, int, string) {
    a, b, c := 1, 2, "fxm"
    return a, b, c
}
