#include "fileSystem3.h"

#define PLAYSTATION3 1
#define WII 2
#define PLATFORM PLAYSTATION3

FileSystem& FileSystem::instance()
{
	#if PLATFORM == PLAYSTATION3
		static FileSystem* instance = new PS3FileSystem();
	#elif PLATFORM == WII
		static FileSystem* instance = new WiiFileSystem();
	#endif 
	return *instance;
}