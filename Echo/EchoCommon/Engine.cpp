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
	//메시지 기본루프
	bool quit = false;

	while (!quit && mShouldKeepRunning)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}

		else // 실제 로직
		{
			DoFrame();
		}
	}

	return (int)msg.wParam;
}

void Engine::DoFrame()
{
}
