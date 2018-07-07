package main

import (
    "os"
	"fmt"
	"path/filepath"
)

type Student struct {
	Age int
	Name string
}

type my_string string

func fs(str string) (r_str string) {
	str+=str+"sh"
	r_str=str+"ce"
	return r_str
}

func main(){
   fmt.Println(os.Args)	
   fmt.Println(len(os.Args))
   fmt.Println(filepath.Base(os.Args[0]))
   fmt.Println(filepath.FromSlash("\\name\\file\\"))
   student1 :=Student{}
   var student2 Student
   fmt.Println(student1)
   fmt.Println(student2)
   str:="hellow"
   fmt.Println(str)
   fmt.Println(len(str))
   str+=" world"
   fmt.Println(str)
   fmt.Println(len(str))
   str+=" li_xiaolong"
   fmt.Println(str)
   fmt.Println(len(str))
   r_str:=fs(str)
   fmt.Println(str)
   fmt.Println(r_str)
   a:=237
   fmt.Printf("%p,%#p,%x,%#x,%X,%#X",&a,&a,a,a,a,a)
   fmt.Printf("%p,%#p,%x,%#x,%X,%#X",&a,&a,a,a,a,a)
   b:=new(int)
   c:=&[]int{10,11}
   fmt.Println()
   fmt.Println(b)
   fmt.Printf("%p",c)
   a1:=[]int{1,2,3,4}
   a2:=[...]int{1,2,3,4}
   fmt.Printf("\n%T\n",a1)
   fmt.Println(len(a1),cap(a1),a1)
   fmt.Printf("\n%T\n",a2)
   fmt.Println(len(a2),cap(a2),a2)



   str1:="abcdefg"
   for i := range str1 {
	   fmt.Println(i)
   }
   for _,i := range str1 {
	   fmt.Println(i)
   }

   sts := []Student{{10,"abc"},{20,"def"},{30,"ghi"}}
   for _,i := range sts {
	   fmt.Println(i)
   }

   sts1 := []*Student{{10,"abc"},{20,"def"},{30,"ghi"}}
   for _,i := range sts1 {
	   fmt.Println(i)
   }

   sts2 := []*Student{&student1,&student2}
   for _,i := range sts2 {
	   fmt.Println(i)
   }

   var m_str my_string = "test"
   fmt.Println(m_str)
   m_str=fs(m_str)
   fmt.Println(m_str)
   
}
