#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "bytestrimer.cpp"
#include "Packets/Factory.cpp"
void exec(int client)
{
	Factory factory;
	factory.sock = client;
	ByteStream bs;
	while (true)
	{
		bs.buffer.resize(7);
		if (recv(client, bs.buffer.data(), 7,0)>0)
		{
			int id = bs.read(2);
			int len = bs.read(3);
			int ver = bs.read(2);
			std::cout << "Packet ID: " << id << " || length: " << len << " || version: " << ver << "\n";
			bs.buffer.resize(len);
			recv(client, bs.buffer.data(),len,0);
			memcpy(factory.buffer, bs.buffer.data(), len);
			factory.ProcessById(id);
			memset(factory.buffer, 0, 512);
			bs.buffer.clear();
		}
		bs.buffer.clear();
	}
}
int main()
{
	int sock,sockopt,port,dud;
	struct sockaddr_in lox;
	dud = sizeof(lox);
	sockopt = 1;
	port = 9339;
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &sockopt, sizeof(sockopt));

	lox.sin_family = AF_INET;
	lox.sin_addr.s_addr = INADDR_ANY;
	lox.sin_port = htons(port);

	bind(sock, (struct sockaddr *)&lox, sizeof(lox));
	std::cout << "Server running at " << port << " port\n";
	// we have to keep the thread saved in memory

	while (true)
	{
		listen(sock, 1);
		int client = accept(sock, (struct sockaddr *)&lox, (socklen_t *)&dud);
		std::cout << "OMG!!! CLIENT CONNECTED!!!\n";
		std::thread th(exec, client);
		th.detach();
	}
}
