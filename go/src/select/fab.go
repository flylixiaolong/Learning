package main

import "fmt"


func Fab(i int64) int64 {
	if i<=2 {
		return 1
	}
	return Fab(i-1)+Fab(i-2)
}

type memFab func(int64) int64

func Mem(i int64, f memFab) int64 {
	cache:=make(map[string] int64)
	key:=fmt.Sprint(i)
	if v, e := cache[key]; e {
		return v
	}
	v:=f(i)
	cache[key]=v
	return v
}

func main(){
	// fmt.Println(Fab(45))
	fmt.Println(Mem(45, Fab))
}
