#include "ClientPch.h"

NetworkManagerClient* NetworkManagerClient::sInstance;

NetworkManagerClient::NetworkManagerClient()
{
}

void NetworkManagerClient::StaticInit(const SocketAddress& inServerAddress, const string& inName)
{
	sInstance = new NetworkManagerClient();
	return sInstance->Init(inServerAddress, inName);
}

void NetworkManagerClient::Init(const SocketAddress& inServerAddress, const string& inName)
{
	NetworkManager::Init(0);

	
	mState = NCS_SayingHello;
	mServerAddress = inServerAddress;
	mName = inName;
}



void NetworkManagerClient::ProcessPacket(InputMemoryBitStream& inInputStream, const SocketAddress& inFromAddress)
{
	uint32_t packetType;
	inInputStream.Read(packetType);

	if(packetType == NCS_SayingHello)
	{ 
		mState = NCS_Welcomed;
	}
	else
	{
		string content;
		inInputStream.Read(content);

		LOG("%s", content.c_str());
	}
	
}

void NetworkManagerClient::SendOutgoingPackets()
{
	OutputMemoryBitStream helloPacket;

	helloPacket.Write(mState);

	if (mState == NCS_SayingHello)
	{
		LOG("%s", "클라이언트가 서버에 인사보냄");
		string name = mName;
		helloPacket.Write(name);
	}
	else
	{
		string content = "인사받았어";
		helloPacket.Write(content);
	}

	SendPacket(helloPacket, mServerAddress);
}

