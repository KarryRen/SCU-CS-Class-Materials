#include "MusicClick.h"

MusicClick::MusicClick(const std::string& file) : musicClickFile(file) {};

bool MusicClick::loadMusic()
{
	if (musicClick.openFromFile(musicClickFile))
	{
		return true;
	}
	return false;
}

void MusicClick::play()
{
	musicClick.setVolume(100);
	musicClick.play();
}

void MusicClick::stop()
{
	musicClick.stop();
}