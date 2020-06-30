package main
import "fmt"

func main() {
    
    sum := 0

    for i := 0; i <= 10; i++ {
        sum += i
    }
    
    fmt.Println(sum)

    /*
    sum := 1
    for ; sum <= 10; {
        sum += sum
    }
    fmt.Println(sum)

    // 这样写也可以，更像 While 语句形式
    for sum <= 10 {
        sum += sum
    }
    fmt.Println(sum)
    */

    strings := []string{"google", "baidu", "tencent"}
    for i, s := range strings {
        fmt.Println(i, s)
    }

    numbers := [6]int{1, 2, 3, 5}
    for i, n := range numbers {
        fmt.Println(i, n)
    }
}
