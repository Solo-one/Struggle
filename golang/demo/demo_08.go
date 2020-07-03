package main
import "fmt"

// 定义接口
type Phone interface {
    call()
}

type NokiaPhone struct {

}

type IPhone struct {

}

func (nokia NokiaPhone) call() {
    fmt.Println("I am Nokia, I can call you!")
}

func (iphone IPhone) call() {
    fmt.Println("I am IPhone, I can call you!")
}

func main() {
    var phone Phone
    phone = new(NokiaPhone)
    phone.call()

    phone = new(IPhone)
    phone.call()
}
 
 
 
