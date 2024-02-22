#ifndef MUSIC_STATE_H__
#define MUSIC_STATE_H__

#include "State.h"

extern State musicState;

void musicStateEntry();

void musicStateDo();

void musicStateExit();

#endif // MUSIC_STATE_H__