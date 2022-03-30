#include "bytestrimer.cpp"
class KeepAliveOKMessage
{
	public:
	ByteStream bs;
	void encode(int sock);
};
void KeepAliveOKMessage::encode(int sock)
{
	bs.writeVInt(1);
	bs.write(20108, sock);
}