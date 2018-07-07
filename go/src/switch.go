package main

import (
	"fmt"
	"encoding/json"
)

func main(){
	li:=[]interface{}{1, 'a', "abc", true, 6.4}
	fmt.Println(li)
	for i,v:=range li{
		switch tv:=v.(type){
			case bool:
				fmt.Printf("#%d<%T>=%v\n",i,tv,tv)
			case rune:
				fmt.Printf("#%d<%T>=%v\n",i,tv,tv)
			case string:
				fmt.Printf("#%d<%T>=%v\n",i,tv,tv)
			case int:
				fmt.Printf("#%d<%T>=%v\n",i,tv,tv)
			case float64:
				fmt.Printf("#%d<%T>=%v\n",i,tv,tv)
		}
	}
	MA:=[]byte(`{"name":"lxl","age":10}`)
	fmt.Println(MA)
	var object map[string]interface{}
	err:=json.Unmarshal(MA, &object)
	fmt.Println(object, err)
	fmt.Printf("%T,%T\n",object["name"],object["age"])
	var ti interface{}
	ti =20
	fmt.Printf("%T\n",ti)
}
