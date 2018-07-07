package main

import "fmt"

type memFunc func(int, ...int) interface{}

var Fib memFunc

func init(){
	Fib = Memoize(func(x int, xs ...int) interface{} {
		if x < 2 {
			return x
		}
		return Fib(x-1).(int) + Fib(x-2).(int)
	})
}

func Memoize(memFunc) memFunc{
	return func(int, ...int) interface{} {
		fmt.Println("a")
		return 0
	}
}


func tt(sts *[]string) {
	*sts=append(*sts, "hellow")
}


type Test struct{
	name string
	sub []string
}

func main(){
	var f func(int)
	f = func (i int){
		if i < 1 {
			return
		}
		fmt.Println(i)
		f(i-1)
	}
	
	f(10)

	sts:=[]string{"ab","cd"}
	tt(&sts)
	fmt.Println(sts)

	ab:=Test{"lxl",[]string{"test","abc"}}
	fmt.Println(ab)
	t1:=&ab
	t2:=*t1
	t3:=t2.sub
	t4:=&t1.sub
	fmt.Println(ab)
	fmt.Println(t3)
	fmt.Println(t4)
	t3=append(t3, "ef")
	fmt.Println(ab)
	fmt.Println(t3)
	fmt.Println(t4)
	*t4=append(*t4, "hi")
	fmt.Println(ab)
	fmt.Println(t3)
	fmt.Println(t4)
}
