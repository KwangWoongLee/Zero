class Client : public Engine
{
public:
	static bool StaticInit();

	virtual int Run();

protected:

	Client();

	virtual void	DoFrame() override;


};