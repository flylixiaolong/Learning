package main

import "fmt"

func main() {
	go func(){
		for {
			fmt.Println("go S")
		}
	}()
	go func(){
		for {
			fmt.Println("go A")
		}
	}()
	go func(){
		for {
			fmt.Println("go A")
		}
	}()
	go func(){
		for {
			fmt.Println("go A")
		}
	}()
	go func(){
		for {
			fmt.Println("go A")
		}
	}()
	go func(){
		for {
			fmt.Println("go A")
		}
	}()
	for {
		fmt.Println("go M")
	}
}
