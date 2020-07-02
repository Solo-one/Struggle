package main
import "fmt"

// 函数闭包
func main() {
    add_func := add(1, 2)
    fmt.Println(add_func())
    fmt.Println(add_func())
    fmt.Println(add_func())

}

func add(x1, x2 int) func()(int, int) {
    i := 0
    return func() (int, int) {
        i++
        return i, x1 + x2
    }

}

