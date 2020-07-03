package main
import "fmt"

func main() {
    var numbers = make([]int, 3, 5)

    printSlice(numbers)

    // 声明集合，默认nil
    var countryCapitalMap map[string]string
    if (countryCapitalMap == nil) {
        fmt.Println("是空集合")
    }
    // 初始化
    countryCapitalMap = make(map[string]string)

    countryCapitalMap["France"] = "巴黎"
    countryCapitalMap["Italy"] = "罗马"
    countryCapitalMap["Japan"] = "东京"
    countryCapitalMap["India"] = "新德里"
    
    for k, v := range countryCapitalMap {
        fmt.Println(k, v)
    }

    // 查找key
    capital, ok := countryCapitalMap["American"]
    if (ok) {
        fmt.Println("American 的首都是", capital)
    } else {
        fmt.Println("American 的首都不存在")
    }
}

func printSlice(x []int) {
    fmt.Printf("len:%d, cap:%d, slice=%v\n", len(x), cap(x), x)
}
