#include <map>
#include "Client/LoginMessage.cpp"
#include "Client/KeepAliveMessage.cpp"
#include "Server/AllianceData.cpp"
#include "Client/AllianceChat.cpp"
class Factory
{
	public:
	int sock;
	char buffer[512];
	void ProcessById(int id);
};
void Factory::ProcessById(int id)
{
	//i know its a bad method but I have no desire to leak the method using std map with function pointers...
	if (id == 10101)
	{
		LoginMessage l;
		memcpy(l.buffer,buffer, 256);
		l.decode(sock);
	}
	else if (id == 10108)
	{
		KeepAlive alive;
		alive.decode(sock);
	}
	else if (id == 14302)
	{
		AllianceDataMessage adata;
		adata.encode(sock);
	}
	else if (id == 14315)
	{
		AllianceChat chat;
		chat.decode(sock);
	}
}