class NetworkManagerClient : public NetworkManager
{
	enum NetworkClientState
	{
		NCS_SayingHello,
		NCS_Welcomed
	};

public:
	static NetworkManagerClient* sInstance;

	static	void	StaticInit(const SocketAddress& inServerAddress, const string& inName);

	void	SendOutgoingPackets();

	virtual void	ProcessPacket(InputMemoryBitStream& inInputStream, const SocketAddress& inFromAddress) override;

private:
	NetworkManagerClient();
	void Init(const SocketAddress& inServerAddress, const string& inName);

	void	UpdateSayingHello();
	void	SendHelloPacket();


	void	UpdateSendingInputPacket();
	void	SendInputPacket();


	SocketAddress		mServerAddress;
	uint32_t			mState;
	string				mName;

};