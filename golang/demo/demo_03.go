package main
//import "fmt"
//import "math"
import (
    "math" 
    "fmt"
)


func main() {
    var a int = 10;
    var b int = 20;

    fmt.Printf("%v, %v\n", a, b)

    swap(&a, &b)

    fmt.Printf("%v, %v\n", a, b)

    
    // 简洁方法
    c := 100
    d := 200

    fmt.Printf("%v, %v\n", c, d)
    c, d = d, c // 直接交互 
    fmt.Printf("%v, %v\n", c, d)

    // 实参函数, 申明函数变量
    getSquareRoot := func(x float64) float64 {
        return math.Sqrt(x)
    }
    fmt.Println(getSquareRoot(9))
}

func swap(x *int, y *int) {
    var temp int
    temp = *x
    *x = *y
    *y = temp
}


