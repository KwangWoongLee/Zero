class NetworkManagerServer : public NetworkManager
{
public:
	static NetworkManagerServer* sInstance;

	static bool				StaticInit(uint16_t inPort);



	virtual void	ProcessPacket(InputMemoryBitStream& inInputStream, const SocketAddress& inFromAddress) override;



private:
	NetworkManagerServer();

	typedef unordered_map< SocketAddress, string >	AddressToClientMap;

	AddressToClientMap		mAddressToClientMap;

	int				mNewPlayerId;
	int				mNewNetworkId;

};


