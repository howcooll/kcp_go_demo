//============================================================================
// Name        : TestKCP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <unistd.h>

#include "ikcp.h"
#include "kcp_client_wrap.hpp"

using namespace asio_kcp;

class Client {
public:
	Client() :
			last_conv_(0), last_event_type_(eCountOfEventType), last_var_(NULL) {
	}
	static void client_event_callback(kcp_conv_t conv, eEventType event_type,
			const std::string& msg, void* var) {
		((Client*) var)->do_client_event_callback(conv, event_type, msg, var);
	}

	void do_client_event_callback(kcp_conv_t conv, eEventType event_type,
			const std::string& msg, void* var) {
		std::cout << "event_type: " << event_type << " msg: " << msg
				<< std::endl;
		last_conv_ = conv;
		last_event_type_ = event_type;
		last_msg_ = msg;
		last_var_ = var;
	}

	kcp_conv_t last_conv_;
	eEventType last_event_type_;
	std::string last_msg_;
	void* last_var_;
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	asio_kcp::kcp_client_wrap net;
	Client client;
	net.set_event_callback(Client::client_event_callback, (void*) (&client));
	net.connect(0, "127.0.0.1", 33199);
	//EXPECT_EQ(ret, 0);
	net.start_workthread();
	//EXPECT_FALSE(net.workthread_stopped_);
	//EXPECT_TRUE(net.workthread_start_);
	for (int i = 0; i < 10; ++i) {
		sleep(1);
		net.send_msg(std::string("1234567890"));

	}

	//millisecond_sleep(1000);
	sleep(2);
	std::cerr << std::endl << "after millisecond_sleep" << std::endl;
	//EXPECT_EQ(client.last_conv_, net.kcp_client_.p_kcp_->conv);
	//EXPECT_EQ(client.last_event_type_, eRcvMsg);
	//EXPECT_EQ(client.last_msg_, std::string("1234567890"));
	//EXPECT_EQ(client.last_var_, (void*)(&client));

	return 0;
}
