class ClientProxy
{
public:

	ClientProxy(const SocketAddress& inSocketAddress, const string& inName, int inPlayerId);

	const	SocketAddress& GetSocketAddress()	const { return mSocketAddress; }
	int				GetPlayerId()		const { return mPlayerId; }
	const	string& GetName()			const { return mName; }



private:

	SocketAddress	mSocketAddress;
	string			mName;
	int				mPlayerId;

};

typedef shared_ptr< ClientProxy >	ClientProxyPtr;