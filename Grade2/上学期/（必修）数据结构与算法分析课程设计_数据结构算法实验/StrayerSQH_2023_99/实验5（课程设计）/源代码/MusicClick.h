#ifndef MUSICCLICK_H
#define MUSICCLICK_H

#include <SFML/Audio.hpp>
#include <string.h>

class MusicClick {
public:
	sf::Music musicClick;
	std::string musicClickFile;
	MusicClick(const std::string& file);

	bool loadMusic();

	void play();

	void stop();

};

#endif // !MUSICCLICK_H
