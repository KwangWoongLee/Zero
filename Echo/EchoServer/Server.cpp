#include "ServerPch.h"

bool Server::StaticInit()
{
	sInstance.reset(new Server());
	return true;
}

Server::Server()
{
	InitNetworkManager();
}

int Server::Run()
{
	return Engine::Run();
}


bool Server::InitNetworkManager()
{
	string portString = StringUtils::GetCommandLineArg( 1 );
	uint16_t port = stoi(portString);

	return NetworkManagerServer::StaticInit(port);
}

void Server::DoFrame()
{
	NetworkManagerServer::sInstance->ProcessIncomingPackets();

	Engine::DoFrame();

}
