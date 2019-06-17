#include "GenericPlayer.h"
#include <string>
class ComputerPlayer : public GenericPlayer
{
public:
    ComputerPlayer(std::string name, GenericPlayer::token t);
    virtual ~ComputerPlayer();

    void Roll(unsigned roll);
};
