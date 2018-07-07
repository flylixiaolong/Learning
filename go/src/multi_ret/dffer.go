func query() data string, err error{
	iconn,err :=CreateConnection(...)
	defer conn.Close()
	...//qita操作
	return data, err
}
