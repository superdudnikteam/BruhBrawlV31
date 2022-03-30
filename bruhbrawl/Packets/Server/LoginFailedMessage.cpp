#include "bytestrimer.cpp"
class LoginFailedMessage
{
	public:
	ByteStream bs;
	void encode(int sock, std::string error);
};
void LoginFailedMessage::encode(int sock, std::string error)
{
	bs.add(4, 8);//error code
	bs.writeString("");
	bs.writeString("");
	bs.writeString("");//patch url
	bs.writeString("");//update url
	bs.writeString(error);//error message
	bs.add(4,3600);
	bs.add(1,0);
	bs.write(20103, sock);
}