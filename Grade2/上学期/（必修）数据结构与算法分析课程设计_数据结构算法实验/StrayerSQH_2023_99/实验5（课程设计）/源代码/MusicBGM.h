#ifndef MUSICBGM_H
#define MUSICBGM_H

#include <SFML/Audio.hpp>
#include <string>

class MusicBGM {
private:
    sf::Music music;
    std::string musicBGMFile;

public:
    MusicBGM(const std::string& file);

    bool loadMusic();

    void play();

    void stop();

    void setLoop(bool loop);
};

#endif  // MUSICONE_H