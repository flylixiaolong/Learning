package main

import (
	"fmt"
	"sort"
)

type Int int
type SInt []int

type String string

func TInt(i Int){
	fmt.Println(i)
}
func Tint(i int){
	fmt.Println(i)
}

func Tstring(i string){
	fmt.Println(i)
}
func TString(i String){
	fmt.Println(i)
}
func main(){
	fmt.Println()
	a:=1
	var b Int = 1
	s:=SInt{1,2,3,5}
	s=append(s,4)
	Tint(a)
	TInt(b)
	fmt.Println(s)
	TString("a")
	Tstring("a")
	sort.Ints(s)
	fmt.Println(s)
}
