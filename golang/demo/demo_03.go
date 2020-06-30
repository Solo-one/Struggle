package main
import "fmt"

func main() {
    var a int = 10;
    var b int = 20;

    fmt.Printf("%v, %v\n", a, b)

    swap(&a, &b)

    fmt.Printf("%v, %v\n", a, b)

    
    // 简介方法
    c := 100
    d := 200

    fmt.Printf("%v, %v\n", c, d)
    c, d = d, c 
    fmt.Printf("%v, %v\n", c, d)
}

func swap(x *int, y *int) {
    var temp int
    temp = *x
    *x = *y
    *y = temp
}
