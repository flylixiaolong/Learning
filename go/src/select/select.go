package main

import (
	"fmt"
	"runtime"
)

func test_add(data []int, result chan int, done chan bool, start int, step int, max int){
	i:=start
	finish:=false
	for !finish{
		result <- i
		i += step
		if i>max {
			finish=true
		}
	}
	done <- true
}
func main(){
	runtime.GOMAXPROCS(2)
	data:=[]int{}
	i:=1000
	doneCount:=0
	for i<1000 {
		data=append(data,i)
	}
	dataA:=make(chan int)
	dataB:=make(chan int)
	done:=make(chan bool)
	go test_add(data, dataA, done, 1, 2, 1000000)
	go test_add(data, dataB, done, 1, 2, 1000000)

	for doneCount != 2 {
		var which string
		var result int
		select {
			case result = <- dataA:
				which = "A"
			case result = <- dataB:
				which = "B"
			case <- done:
				doneCount ++
		}
		if which != "" {
			fmt.Printf("%c-->%d\n", which, result)
		}
	}
	fmt.Println("end ..........")
}
