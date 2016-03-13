// main
package main

import (
	"fmt"
	//"net"
	"time"

	. "github.com/xtaci/kcp-go"
)

const port = ":33199"

func server() {
	l, err := Listen(MODE_NORMAL, port)
	if err != nil {
		panic(err)
	}
	for {
		s, err := l.AcceptUDPSession()
		if err != nil {
			panic(err)
		}

		go handle_client(s)
	}
}

func init() {

}

func handle_client(conn *UDPSession) {
	fmt.Println("new client", conn.RemoteAddr())

	//udpsession := conn.(UDPSession)
	fmt.Println("new client", conn.GetConv())
	buf := make([]byte, 65536)
	count := 0
	for {
		conn.SetReadDeadline(time.Now().Add(10 * time.Second))
		n, err := conn.Read(buf)
		fmt.Println("new client read", n)
		if err != nil {
			fmt.Println("new client read err", n)
			conn.Close()
			return
		}
		count++
		conn.Write(buf[:n])
	}
}

func main() {
	server()
}
