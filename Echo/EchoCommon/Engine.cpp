#include "CommonPch.h"

std::unique_ptr< Engine >	Engine::sInstance;



Engine::Engine() :
	mShouldKeepRunning(true)
{
	SocketUtil::StaticInit();
}

Engine::~Engine()
{
}




int Engine::Run()
{
	return DoRunLoop();
}

int Engine::DoRunLoop()
{

	MSG msg;
	//�޽��� �⺻����
	bool quit = false;

	while (!quit && mShouldKeepRunning)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}

		else // ���� ����
		{
			DoFrame();
		}
	}

	return (int)msg.wParam;
}

void Engine::DoFrame()
{
}
