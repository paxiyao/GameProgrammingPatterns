// ֧�ֶ�̬��,�鷽��������ʵ��
// ֧���˲�ͬƽ̨���ļ�����

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

class FileSystem
{
public:
	static FileSystem& instance();
	virtual ~FileSystem() { }
	virtual char* readFile(char* path) = 0;
	virtual void writeFile(char* path, char* contents) = 0;
protected:
	FileSystem() { }
};

class PS3FileSystem : public FileSystem
{
public:
	virtual char* readFile(char* path)
	{
		// Use Sony file IO API...
	}

	virtual void writeFile(char* path, char* contents)
	{
		// Use sony file IO API...
	}
};

class WiiFileSystem : public FileSystem
{
public:
	virtual char* readFile(char* path)
	{
		// Use Nintendo file IO API...
	}

	virtual void writeFile(char* path, char* contents)
	{
		// Use Nintendo file IO API...
	}
};

#endif // !FILESYSTEM_H
