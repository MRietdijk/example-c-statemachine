#include "Statemachine.h"
#include "States/InitSubSystemsState.h"
#include "States/StartState.h"
#include "States/WaitingForInputState.h"
#include "eventQueue.h"

State currentState;
// clang-format off
const State *eventLookupTable[][3] = {
                            /* EMPTY */         /* SYSTEM_BOOTED_UP */      /* SUBSYSTEM_INITIALIZED */
  /* STARTSTATE */          {NULL,              &InitSubSystemsState,       NULL},
  /* INITSUBSYSTEMSSTATE */ {NULL,              NULL,                       &waitingForInputState}
};

// clang-format on

void runStatemachine() {
  // Set current state to first state in statemachine. And run entry function.
  currentState = startState;
  currentState.entryFunc();

  // The actual statemachine.
  while (true) {
    currentState.doFunc();
    checkEvents();
  }
}

void transition(State nextState) {
  // Checks if exit function exists.
  if (currentState.exitFunc) {
    currentState.exitFunc();
  }

  currentState = nextState;

  // Checks if entry function exists.
  if (currentState.entryFunc) {
    currentState.entryFunc();
  }
}

void checkEvents() {
  Event nextEvent = getNextEvent();

  if (nextEvent == EMPTY) {
    return;
  }

  const State *nextState = eventLookupTable[currentState.id][nextEvent];

  if (!nextState) {
    return;
  }

  transition(*nextState);
  popFront();
}