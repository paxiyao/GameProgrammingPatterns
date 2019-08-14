#ifndef LOCATOR_H
#define LOCATOR_H

#include "nullAudio.h"
#include "consoleAudio.h"
#include "loggedAudio.h"

class Locator
{
public:
	static void initialize() { _service = &_nullAudio; }
	// ������ע�⵽����������ͨ�����ö�����ָ�뷵�ط�������c++�е�����(������!)�Ӳ�Ϊ�գ����Է������öԴ�����û���˵��һ����ʾ�����ǿ����������Ƿ���һ����Ч�Ķ���
	// ��һ����Ҫע��������ǣ�������provide()�����м��NULL�������Ǽ�����������Ҫ�����Ǿ������initialize()����ȷ����λ�������ȷ��Ĭ��Ϊ���ṩ����
	// ��Ϊ�ر���������֧�Ƴ�getAudio()���⽫��ÿ�η��ʷ���ʱΪ���ǽ�ʡ�������ڡ�
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
