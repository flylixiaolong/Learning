type Item struct {
	id string
	price float64
	quantity int
}
func (item *Item) Cost() float64 {
	return item.price * float64(item.quantity)
}
type SpecialItem struct {
	Item //匿名字段（嵌入）
	catalogId int //具名字段（聚合）
}
special := SpecialItem{Item{"green",3,5},207}
fmt.Println(special.id,special.price,special.quantity,special.catalogId)
fmt.Println(special.Cost())
