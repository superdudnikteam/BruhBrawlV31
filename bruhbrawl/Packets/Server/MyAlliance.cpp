#include "bytestrimer.cpp"
class MyAlliance
{
	public:
	ByteStream bs;
	void encode(int sock);
};
void MyAlliance::encode(int sock)
{
	bs.writeVInt(1);
	bs.writeVInt(1);
	bs.writeVInt(25);
	bs.writeVInt(2);
	bs.add(4,0);
	bs.add(4,1);
	bs.writeString("S.B. SUCKS\nCPP BRAWL = SHITTY CODE BRUH!");
	bs.writeVInt(8);
	bs.writeVInt(1);
	bs.writeVInt(1);
	bs.writeVInt(1);
	bs.writeVInt(777);
	bs.writeVInt(99);
	bs.writeVInt(0);
	bs.writeString("UA");
	bs.writeVInt(0);
	bs.writeVInt(1);
	bs.write(24399, sock);
}