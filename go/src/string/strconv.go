package main

import (
    "strconv"
	"fmt"
)

func main() {
	var s []byte
	s=strconv.AppendBool(s,true)
	s=strconv.AppendQuote(s,"sm")
	s=strconv.AppendQuoteRune(s,'m')
	s=strconv.AppendQuoteRuneToASCII(s,'m')
	fmt.Printf("%s\n",string(s))
}
