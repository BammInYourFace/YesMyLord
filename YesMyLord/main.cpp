#include <iostream>
#include <cstdio>
#include <SFML\Network.hpp>

int main(){
	std::string message;
	std::cout << "Enter Message for Server: ";
	std::getline(std::cin, message);

	sf::IpAddress  ip = "127.0.0.1";
	unsigned short port = 9000;
	unsigned short respPort = 9001;
	

	sf::UdpSocket socket;
	socket.bind(respPort);
	
	

	/*
	sf::Socket::Status status = socket.connect(ip, port);
	if (status != sf::Socket::Done)
	{
		std::cout << "An Error occured while connecting!" << std::endl;
	}
	*/
	

	if (socket.send(message.c_str(), message.size(), ip, port) != sf::Socket::Done)
	{
		std::cout << "An Error occured while sending!" << std::endl;
	}
	else
	{	
		char buffer[512];      // The buffer to store raw response data in
		sf::IpAddress respIP;  // The ip address where the response came from
		size_t respSize;     // The amount of data actually written to buffer
		socket.receive(buffer, 512, respSize, respIP, port);
		socket.unbind();

		std::string response(buffer, respSize);
		std::cout << response << std::endl;
		std::getchar();
	}
	

	return 0;
}