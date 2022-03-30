#include "../Server/AllianceChatResponse.cpp"
class AllianceChat
{
	public:
	char buffer[256];
	void decode(int sock);
	void process(int sock);
};
void AllianceChat::decode(int sock)
{
	AllianceChatResponse resp;
	resp.encode(sock);
}