#include "bytestrimer.cpp"
#pragma once 
class AllianceDataMessage
{
	public:
	ByteStream bs;
	void encode(int sock);
};
void AllianceDataMessage::encode(int sock)
{
	bs.writeVInt(0);
	bs.add(4,0);
	bs.add(4,1);
	bs.writeString("CPP BRAWL = SHITTY CODE BRUH!");
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
	bs.writeString("CPP BRAWL = WORST SERVER IN THE WORLD\nS.B. SUCKS BIG HUDE COCK!!!");
	bs.writeVInt(1);//lox
	{
		bs.add(4,0);
		bs.add(4,1);
		bs.writeVInt(2);
		bs.writeVInt(0);
		bs.writeVInt(2);
		bs.writeVInt(0);
		bs.writeVInt(0);
		bs.writeString("S.B. SUCKS!");
		bs.writeVInt(1);
		bs.writeVInt(28000000);
		bs.writeVInt(43000000);
		bs.writeVInt(0);
	}
	bs.write(24301, sock);
}