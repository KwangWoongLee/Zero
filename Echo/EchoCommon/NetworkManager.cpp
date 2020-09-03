#include "CommonPch.h"

NetworkManager::NetworkManager()
{
}

NetworkManager::~NetworkManager()
{
}

bool NetworkManager::Init(uint16_t inPort)
{

	//채팅서버이므로 UDP로 해본다.
	mSocket = SocketUtil::CreateUDPSocket(INET);
	SocketAddress ownAddress(INADDR_ANY, inPort);
	mSocket->Bind(ownAddress);

	if (mSocket == nullptr)
	{
		return false;
	}

	if (mSocket->SetNonBlockingMode(true) != NO_ERROR)
	{
		return false;
	}

	return true;
}

void NetworkManager::ProcessIncomingPackets()
{
	char packetMem[1500];
	int packetSize = sizeof(packetMem);
	InputMemoryBitStream inputStream(packetMem, packetSize * 8);
	SocketAddress fromAddress;

	int readByteCount = mSocket->ReceiveFrom(packetMem, packetSize, fromAddress);

	int receivedPackedCount = 0;
	if (readByteCount > 0)
	{
		inputStream.ResetToCapacity(readByteCount);
		++receivedPackedCount;
		ProcessPacket(inputStream, fromAddress);

	}

}



void NetworkManager::SendPacket(const OutputMemoryBitStream& inOutputStream, const SocketAddress& inFromAddress)
{
	int sentByteCount = mSocket->SendTo(inOutputStream.GetBufferPtr(), inOutputStream.GetByteLength(), inFromAddress);
}


NetworkManager::ReceivedPacket::ReceivedPacket(float inReceivedTime, InputMemoryBitStream& ioInputMemoryBitStream, const SocketAddress& inFromAddress) :
	mReceivedTime(inReceivedTime),
	mFromAddress(inFromAddress),
	mPacketBuffer(ioInputMemoryBitStream)
{
}
