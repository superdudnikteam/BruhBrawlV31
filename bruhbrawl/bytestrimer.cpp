#pragma once
#include <vector>
#include <iterator>
#include<sys/socket.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class ByteStream 
{
	public:
	std::vector<char> buffer;
	void add(int lox, int data);
	int read(int lox);
	void writeVInt(int i);
	void writeString(std::string s);
	void writeStringRef(std::string s);
	void write(int ID, int sock);	
	int readVInt();
	std::string readString();
};
void ByteStream::add(int lox, int data)
{
	/*
	lox = length | data = data
	use add(4,data) for write Int32(data) | add(1,data) for writeByte(data), etc... (max length = 4)
	*/
	int shift[] = {24, 16, 8, 0};//MORE ARRAYS!!!
	for (int i = 4-lox; i < 4; i++)
	{
		auto byte = (data>>shift[i]) & 0xFF;
		buffer.push_back(byte);//add to stream
	}
}
int ByteStream::read(int lox)
{
	/*
	lox = length
	use int var = read(4); for read Int32 | read(2) for read short int, etc... (max length = 4)
	*/
	int integer = 0;
	int shift[] = {24, 16, 8, 0};//MORE ARRAYS!!!
	for (int i = 4-lox; i < 4; i++)
	{
		integer += (buffer[0]<<shift[i]);
		buffer.erase(buffer.begin());//remove from stream
	}
	return integer;
}
void ByteStream::writeString(std::string s)
{
	if (s == "")
	{
		add(4, -1);
		return;
	}
	add(4, s.length());
	std::copy(s.begin(), s.end(), std::back_inserter(buffer));
}
void ByteStream::writeStringRef(std::string s)
{
	add(2,0);
	writeVInt(s.length());
	std::copy(s.begin(), s.end(), std::back_inserter(buffer));
}
std::string ByteStream::readString()
{
	int len = read(4);
	if (len == -1 || len == 65535)
	{
		return "";
	}
	std::string s;
	std::copy(buffer.begin(), buffer.begin()+len, std::back_inserter(s));
	buffer.erase(buffer.begin(), buffer.begin()+len);
	return s;
}
void ByteStream::writeVInt(int i)
{
	bool rotate = true;if (i == 0){add(1,0);return;}i = (i << 1) ^ (i >> 31);while (i)
	{int tmp = i & 0x7f;if (i >= 0x80){tmp |= 0x80;}if (rotate == true){rotate = false;int l = tmp & 0x1;int b = (tmp & 0x80) >> 7;tmp >>= 1;tmp = tmp & ~0xC0;tmp = tmp | (b << 7) | (l << 6);};buffer.push_back(tmp & 0xFF);i >>= 7;}//dudnik methods but ok
}
int ByteStream::readVInt()
{
	int result = 0,shift = 0,r,msb,bit7;while (true){int b = read(1);if (shift == 0){bit7 = (b & 0x40) >> 6;msb = (b & 0x80) >> 7;r = b << 1;r = r & ~0x181;b = r | (msb << 7) | bit7;}result |= (b & 0x7f) << shift;shift += 7;if (!(b & 0x80)){break;}}result = (result >> 1) ^ (-(result & 1));return result;
}
void ByteStream::write(int ID, int sock)
{
	auto packet = buffer;
	buffer.clear();
	add(2,ID);
	add(3,packet.size());
	add(2,0);
	buffer.insert(buffer.end(), packet.begin(), packet.end());
	add(2, 65535);
	add(4, 0);
	add(1,0);
	send(sock, buffer.data(), buffer.size(), 0);
	std::cout << "Packet with ID " << ID << " sended.\n";
}
//int main()
//{
//	ByteStream bs;
//	bs.buffer = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x1d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc8, 0x0, 0x0, 0x0, 0x28, 0x31, 0x36, 0x36, 0x30, 0x61, 0x39, 0x36, 0x36, 0x64, 0x61, 0x61, 0x33, 0x31, 0x61, 0x34, 0x39, 0x38, 0x62, 0x65, 0x65, 0x35, 0x39, 0x61, 0x37, 0x38, 0x36, 0x37, 0x30, 0x63, 0x38, 0x39, 0x65, 0x66, 0x34, 0x33, 0x36, 0x34, 0x62, 0x30, 0x35, 0x0, 0x0, 0x0, 0x3, 0x21, 0x21, 0x21, 0x2, 0x2, 0x0, 0x0, 0x0, 0x5, 0x72, 0x75, 0x2d, 0x52, 0x55, 0x0, 0x0, 0x0, 0x2, 0x31, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x62, 0x61, 0x6e, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x32, 0x39};
//	bs.read(4);
//	bs.read(4);
//	bs.readString();
//	std::cout << bs.read(4);
//}