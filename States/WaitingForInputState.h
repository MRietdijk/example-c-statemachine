#ifndef WAITING_FOR_INPUT_STATE_H__
#define WAITING_FOR_INPUT_STATE_H__
#include "State.h"

extern State waitingForInputState;

void waitingForInputStateEntry();

void waitingForInputStateDo();

void waitingForInputStateExit();

#endif // WAITING_FOR_INPUT_STATE_H__