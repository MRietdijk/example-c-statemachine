#ifndef STATEMACHINE_H__
#define STATEMACHINE_H__

#include "States/State.h"

extern State currentState;

/**
 * @brief runs the statemachine.
 *
 */
void runStatemachine();

/**
 * @brief Transitions to the new state. User does not need to call this
 * function. User needs to add an event to the queue.
 *
 * @param nextStatePtr The pointer to the next state
 */
void transitionToNextState(const State *nextStatePtr);

/**
 * @brief Checks the eventQueue, if a new event happend.
 *
 */
void checkEvents();

#endif // STATEMACHINE_H__