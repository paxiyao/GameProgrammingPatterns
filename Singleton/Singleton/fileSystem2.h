// �ŵ�: 1.����Ҫ��ʱ���ٽ��г�ʼ��,������ǰռ���ڴ�
// c++11�±�׼: �ֲ���̬��Աֻ���ʼ��һ��(��ʹ�ǲ�����),�������ֳ�ʼ����ʽ���̰߳�ȫ��
// ע��: ����˵���ǵ����ĳ�ʼ���̰߳�ȫ,�����������������̰߳�ȫ

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

class FileSystem
{
public:
	static FileSystem& instance()
	{
		static FileSystem* _instance = new FileSystem();

		return *_instance;
	}
private:
	FileSystem() { }
};

#endif // !FILESYSTEM_H
