#ifndef LOCATOR_H
#define LOCATOR_H

#include "nullAudio.h"
#include "consoleAudio.h"
#include "loggedAudio.h"

class Locator
{
public:
	static void initialize() { _service = &_nullAudio; }
	// 您可能注意到，我们正在通过引用而不是指针返回服务。由于c++中的引用(理论上!)从不为空，所以返回引用对代码的用户来说是一个提示，他们可以期望总是返回一个有效的对象。
	// 另一件需要注意的事情是，我们在provide()函数中检查NULL，而不是检查访问器。这要求我们尽早调用initialize()，以确保定位器最初正确地默认为空提供程序。
	// 作为回报，它将分支移出getAudio()，这将在每次访问服务时为我们节省几个周期。
	static Audio& getAudio() { return *_service; }
	static void provide(Audio* service)
	{
		if (service == NULL)
		{
			// revert to null service
			_service = &_nullAudio;
		}
		else
		{
			_service = service;
		}
	}
	static void enableAudioLogging()
	{
		// Decorate the existing service.
		Audio *service = new LoggedAudio(Locator::getAudio());

		// Swap it in.
		Locator::provide(service);
	}
private:
	static Audio* _service;
	static NullAudio _nullAudio;
};

Audio* Locator::_service = nullptr;
NullAudio Locator::_nullAudio;

#endif // LOCATOR_H
