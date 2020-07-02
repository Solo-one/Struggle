package main
import "fmt"

/*
* 实现类似c++ 面向对下，方法
*
*/

type Circle struct {
    radius float64
}

func main() {
    var c Circle
    fmt.Println(c.radius)

    c.radius = 10.0
    fmt.Println(c.radius)
    fmt.Println(getArea(c.radius))
    fmt.Println(c.getArea())

    c.change(11.0)
    fmt.Println(c.getArea())
}

// 函数
func getArea(r float64) float64 {
    return 3.14 * r * r
}

// Cicre对象 方法
func (c Circle) getArea() float64 {
    return 3.14 * c.radius * c.radius
}

// 注意如果想要更改成功c的值，这里需要传指针
func (c *Circle) change(r float64) {
    c.radius = r
}
