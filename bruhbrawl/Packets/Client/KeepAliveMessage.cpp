#include "../Server/KeepAliveOKMessage.cpp"
class KeepAlive
{
	public:
	char buffer[256];
	void decode(int sock);
	void process(int sock);
};
void KeepAlive::decode(int sock)
{
	KeepAliveOKMessage aliveok;
	aliveok.encode(sock);
}