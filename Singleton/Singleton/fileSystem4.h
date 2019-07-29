/// ��������ǰ(main����ִ��ǰ)��ʼ��
/// �ŵ�:  1.����Ҫ��̬�����ڴ�,��ǰ�����ͼ���,ʹ��Ϸ�������������֡
///		  2.��Ϸͨ����Ҫ�ϸ�����ڴ��ڶ��еĲ��֣��Ա����ڴ���Ƭ

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <assert.h>

//class FileSystem
//{
//public:
//	static FileSystem& instance()
//	{
//		return _instance;
//	}
//
//private:
//	FileSystem() { }
//	static FileSystem _instance;
//};
//
//FileSystem FileSystem::_instance = *(new FileSystem());

/// ʹ�þ�̬��(������ĳ�Ա�ͷ������Ǿ�̬��)��ʵ������ǰ��ʼ���ĵ���ģʽ
//class FileSystem
//{
//public:
//	static char* readFile(char* path);
//	static void writeFile(char* path, char* contents);
//};

/// ���Ƶ���ֻ��ĳ��������ʻ���˽��
class FileSystem
{
public:
	FileSystem ()
	{
		assert(!_instantiated);	
		_instantiated = true;
	}

	~FileSystem()
	{
		_instantiated = false;
	}
private:
	static bool _instantiated;
};

bool FileSystem::_instantiated = false;

#endif // !FILESYSTEM_H
