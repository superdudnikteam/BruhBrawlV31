#include "bytestrimer.cpp"
class LoginOKMessage
{
	public:
	ByteStream bs;
	void encode(int sock);
};
void LoginOKMessage::encode(int sock)
{
	bs.add(4,0);
	bs.add(4,1);
	bs.add(4,0);
	bs.add(4,1);
	bs.writeString("A");
	bs.write(20104, sock);
}