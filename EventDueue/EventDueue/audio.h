#ifndef AUDIO_H
#define AUDIO_H

#include <assert.h>
#include <algorithm>

typedef int SoundId;

struct PlayMessage
{
	SoundId id;
	int volume;
};

class Audio
{
public:
	static void init()
	{
		_head = 0;
		_tail = 0;
	}
	static void playSound(SoundId id, int volume)
	{
		assert((_tail + 1) % MAX_PENDING == _head);

		// 同一帧如果有相同声音要播放,只取音量最大的声音
		for (int i = _head; i < _tail; i = (i + 1) % MAX_PENDING)
		{
			if (_pending[i].id == id)
			{
				_pending[i].volume = std::max(volume, _pending[i].volume);

				// Don't need to enqueue.
				return;
			}
		}

		// Add to the end of the list.
		_pending[_tail].id = id;
		_pending[_tail].volume = volume;
		_tail = (_tail + 1) % MAX_PENDING;
	}
	static void update()
	{
		// If there are no pending requests, do nothing.
		if (_head == _tail) return;

		//ResourceId resource = loadSound(pending_[head_].id);
		//int channel = findOpenChannel();
		//if (channel == -1) return;
		//startSound(resource, channel, pending_[head_].volume);

		_head++;
	}
private:
	static const int MAX_PENDING = 16;
	static PlayMessage _pending[MAX_PENDING];
	static int _head;
	static int _tail;
};

#endif // AUDIO_H
