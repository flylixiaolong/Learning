package main
import "fmt"

type BitFlag int;

const (
	i int = 1 << iota
	j BitFlag = 1 << iota
	k int = 1 << iota
)

const limit = 512
var limts = 234

func main(){
	a := 3*limit
	b := 3*a
	c := 3*i
	flag := i|k
	fmt.Printf("%T\n",flag)
	fmt.Printf("%T\n",limit)
	fmt.Printf("%T\n",a)
	fmt.Printf("%T\n",b)
	fmt.Printf("c is %T\n",c)
	fmt.Printf("%T,%T,%T ",i,j,k)
	fmt.Printf("%T,%T",limit, limts)
	var s float64 = limit *3
	var s2 float64 = limts *3
}

