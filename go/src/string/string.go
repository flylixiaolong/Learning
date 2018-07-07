package main

import "fmt"

func main(){
	a:="\nabc\t123\ndef\n"
	b:="和abc😢"
	c:=240
	fmt.Println(a, b, c)
	fmt.Println(len(a), len(b))
	fmt.Println(len([]rune(a)), len([]rune(b)))
	for index ,char := range b {
		fmt.Println("%%%%%%")
		fmt.Println(b[index], index, char, string(char), []byte(string(char)))
		fmt.Printf("%c %d %c %s %X\n", b[index], index, char, string(char), []byte(string(char)))
		fmt.Printf("%T %T %T %T %T\n", b[index], index, char, string(char), []byte(string(char)))
	}
	d:=1
	e:=2
	f:="a"
	g:='c'
	fmt.Print(d,e,f,g,d,g)

	r:="abc"
	s:=1
	t:="男abc😊"
	w:=[]string{"a", "bc", "男"}
	y:="	 \a\n\t"
	fmt.Println()
	fmt.Printf("%q,%q,%q,%q,%q",r,s,t,w,y)
	fmt.Println()
	fmt.Printf("%#q,%#q,%#q,%#q,%#q",r,s,t,w,y)
	fmt.Println()

	mp:=make(map[string]int)
	mp["a"]+=1
	mp["a"]+=1
	fmt.Println(mp)

	as:="12345"
	for i:=range as {
		fmt.Println(i)
	}
	fmt.Println(len(as),len([]byte(as)))
	cm:=1.0+1i
	fmt.Printf("%T,%v",cm,cm)
}
