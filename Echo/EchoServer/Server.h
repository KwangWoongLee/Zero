class Server : public Engine
{

public:
	static bool StaticInit();

	virtual int Run();

protected:
	Server();


	bool	InitNetworkManager();
	virtual void DoFrame() override;

};

