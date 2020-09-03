#include "ClientPch.h"

bool Client::StaticInit()
{
	Client* client = new Client();


	sInstance.reset(client);

	return true;
}

int Client::Run()
{
	return Engine::Run();
}


Client::Client()
{
	string destination = "127.0.0.1:45000";
	string name = "A";

	SocketAddressPtr serverAddress = SocketAddressFactory::CreateIPv4FromString(destination);

	NetworkManagerClient::StaticInit(*serverAddress, name);
}


void Client::DoFrame()
{
	Engine::DoFrame();

	NetworkManagerClient::sInstance->ProcessIncomingPackets();

	NetworkManagerClient::sInstance->SendOutgoingPackets();
}
