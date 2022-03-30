#include "bytestrimer.cpp"
class AllianceChatResponse
{
	public:
	ByteStream bs;
	void encode(int sock);
};
void AllianceChatResponse::encode(int sock)
{
	bs.writeVInt(2);
	bs.writeVInt(0);
	bs.writeVInt(1);
	bs.writeVInt(1);
	bs.writeVInt(1);
	bs.writeString("BruhBrawlV31");
	bs.writeVInt(2);
	bs.writeVInt(0);
	bs.writeVInt(0);
	bs.writeString("S.B. lox");
	bs.write(24312, sock);
}