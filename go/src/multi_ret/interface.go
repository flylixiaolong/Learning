package main

import "fmt"

type Singer interface {
	Sing()
}
type Animal struct {
	name string
}
type Cat struct {
	Animal
	age int
}
type Dog struct {
	Animal
	master string
}
func (cat *Cat) Sing() {
	fmt.Println(cat.name, "miao...miao")
}
func (dog *Dog) Sing() {
	fmt.Println(dog.name, "wang...wang")
}
func sing(ani Singer){
	ani.Sing()
}
func main() {
	cat :=Cat{Animal{"mm"},1}
	dog :=Dog{Animal{"ww"},"Junce"}
	sing(&cat)
	sing(&dog)
}


