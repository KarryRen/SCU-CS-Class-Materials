#include "MusicClickDetail.h"

Arch::Arch(const std::string& file) : MusicClick(file) {}

bool Arch::ArchLoadMusic()
{
    if (musicClick.openFromFile(musicClickFile))
    {
        return true;
    }
    return false;
}

void Arch::ArchPlay()
{
    musicClick.setVolume(100);
    musicClick.play();
    while (musicClick.getStatus() == sf::SoundSource::Playing)
    {
        sf::sleep(sf::milliseconds(0.01));
    }
}

void Arch::ArchStop()
{
    musicClick.stop();
}