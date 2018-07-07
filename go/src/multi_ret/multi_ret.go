package main

import "fmt"

func multi_ret() (str1 string,  str2 string) {
	str1="hello"
	str2="world!"
	return str1,str2 
}

func main() {
	str1,str2:=multi_ret()
	fmt.Println(str1,str2)
}

