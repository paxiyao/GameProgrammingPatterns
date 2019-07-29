// �ӳٳ�ʼ��,�ڵ�һ��ʹ�õ�ʱ����г�ʼ��
// �ŵ�: 1.�ڵ�һ��ʹ�õ�ʱ����г�ʼ��,����ǰռ���ڴ�

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

class FileSystem
{
public:
	static FileSystem& instance()
	{
		if (_instance == nullptr)
			_instance = new FileSystem();
		
		return *_instance;
	}

private:
	FileSystem() { }
	static FileSystem* _instance;	
};

#endif // !FILESYSTEM_H
