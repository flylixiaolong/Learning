package main

import (
	"fmt"
)

func main() {
	msg1 := make(chan int, 3)
	msg2 := make(chan int, 3)
	defer close(msg1)
	defer close(msg2)
	go func (){
	//	msg1 <- 2
	}()
	var result int
	select {
		case result=<-msg1:
			fmt.Println("msg1")
		case result=<-msg2:
			fmt.Println("msg2")
		default:
			fmt.Println("default")
	}
	fmt.Println(result)
}
