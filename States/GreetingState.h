#ifndef GREETING_STATE_H__
#define GREETING_STATE_H__

#include "State.h"

extern State greetingState;

void greetingStateEntry();

void greetingStateDo();

void greetingStateExit();

#endif // GREETING_STATE_H__