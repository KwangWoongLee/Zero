#include "ServerPch.h"

NetworkManagerServer* NetworkManagerServer::sInstance;

NetworkManagerServer::NetworkManagerServer() :
	mNewPlayerId(1),
	mNewNetworkId(1)
{
}

bool NetworkManagerServer::StaticInit(uint16_t inPort)
{
	sInstance = new NetworkManagerServer();
	return sInstance->Init(inPort);
}

void NetworkManagerServer::ProcessPacket(InputMemoryBitStream& inInputStream, const SocketAddress& inFromAddress)
{
	uint32_t paketType; 
	inInputStream.Read(paketType);

	if (paketType == tHello){
		auto it = mAddressToClientMap.find(inFromAddress);
		if (it == mAddressToClientMap.end())
		{
			string name;
			inInputStream.Read(name);

			mAddressToClientMap[inFromAddress] = name;

			OutputMemoryBitStream inOutputStream;
			inOutputStream.Write(tHello);
			string content = "반갑습니다.";
			inOutputStream.Write(content);

			SendPacket(inOutputStream, inFromAddress);
		}
	}
	//기존 접속자가 알린다면 할말을 보냄.
	else
	{
		string content;
		inInputStream.Read(content);

		LOG("%s", content);

		unordered_map< SocketAddress, string>::iterator iter;
		unordered_map< SocketAddress, string>::iterator iterEnd = mAddressToClientMap.end();

		for (iter = mAddressToClientMap.begin(); iter != iterEnd; ++iter)
		{
			OutputMemoryBitStream inOutputStream;
			inOutputStream.Write(paketType);
			inOutputStream.Write(content);

			SendPacket(inOutputStream, (*iter).first);
		}
	}
}