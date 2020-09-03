class NetworkManager
{
public:
	static const uint32_t	tHello = 0;
	static const uint32_t	tWelcome = 1;

	NetworkManager();
	virtual ~NetworkManager();

	bool	Init(uint16_t inPort);
	void	ProcessIncomingPackets();

	virtual void	ProcessPacket(InputMemoryBitStream& inInputStream, const SocketAddress& inFromAddress) = 0;

	void	SendPacket(const OutputMemoryBitStream& inOutputStream, const SocketAddress& inFromAddress);


protected:


private:

	class ReceivedPacket
	{
	public:
		ReceivedPacket(float inReceivedTime, InputMemoryBitStream& inInputMemoryBitStream, const SocketAddress& inAddress);

		const	SocketAddress& GetFromAddress()	const { return mFromAddress; }
		float					GetReceivedTime()	const { return mReceivedTime; }
		InputMemoryBitStream& GetPacketBuffer() { return mPacketBuffer; }

	private:

		float					mReceivedTime;
		InputMemoryBitStream	mPacketBuffer;
		SocketAddress			mFromAddress;

	};

	UDPSocketPtr	mSocket;


};


