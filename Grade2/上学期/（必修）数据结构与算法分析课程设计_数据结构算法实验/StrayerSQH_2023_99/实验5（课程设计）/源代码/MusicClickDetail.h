#ifndef MUSICCLICKDETAIL_H
#define MUSICCLICKDETAIL_H

#include "MusicClick.h"

class Arch : public MusicClick {
public:
	sf::Music musicAchClick;
	std::string musicAchClickFile;
	Arch(const std::string& file);

	bool ArchLoadMusic();

	void ArchPlay();

	void ArchStop();
};

#endif // !MUSICCLICKDETAIL_H
