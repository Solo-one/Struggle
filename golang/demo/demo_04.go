package main
import "fmt"

// 声明cb 函数类型
type cb func(x int) int

// 函数作为参数传递，实现回调
func main() {
    
    testCallBack(1, callBack)


    testCallBack(2, func(x int) int {
        fmt.Printf("%v\n", x)
        return x
    })

}

func testCallBack(x int, f cb) {
    f(x)
}

func callBack(x int) int {
    fmt.Println(x)
    return x
}
