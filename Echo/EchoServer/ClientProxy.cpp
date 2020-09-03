#include "ServerPch.h"


ClientProxy::ClientProxy(const SocketAddress& inSocketAddress, const string& inName, int inPlayerId) :
	mSocketAddress(inSocketAddress),
	mName(inName),
	mPlayerId(inPlayerId)
{
}

