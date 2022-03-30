#include "../Server/LoginFailedMessage.cpp"
#include "../Server/LoginOKMessage.cpp"
#include "../Server/OwnHomeData.cpp"
#include "../Server/MyAlliance.cpp"
#include "../Server/AllianceData.cpp"
#include "bytestrimer.cpp"
class LoginMessage
{
	public:
	ByteStream bs;
	char buffer[256];
	void decode(int sock);
	void process(int sock);
};
void LoginMessage::decode(int sock)
{
	bs.buffer.insert(bs.buffer.end(), std::begin(buffer), std::end(buffer));
	bs.read(4);
	int lowID = bs.read(4);
	std::string token = bs.readString();
	int major = bs.read(4);
	if (major != 31)
	{
		LoginFailedMessage fail;
		fail.encode(sock, "Unsupported version!");
		return;
	}
	LoginOKMessage ok;
	ok.encode(sock);
	OwnHomeDataMessage ohd;
	ohd.encode(sock);
	MyAlliance mya;
	mya.encode(sock);
	AllianceDataMessage adata;
	adata.encode(sock);
}