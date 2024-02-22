#include "Statemachine.h"
#include "Logger.h"
#include "States/InitSubSystemsState.h"
#include "States/StartState.h"
#include "States/WaitingForInputState.h"
#include "States/GreetingState.h"
#include "States/MusicState.h"
#include "eventQueue.h"

State currentState;
// clang-format off
const State *eventLookupTable[][5] = {
  /* EVENTS: */             /* EMPTY */         /* SYSTEM_BOOTED_UP */      /* SUBSYSTEM_INITIALIZED */     /* GREETED */           /* LEFT_EAR_PRESSED */
  /* STARTSTATE */          {NULL,              &InitSubSystemsState,       NULL,                           NULL,                   NULL},
  /* INITSUBSYSTEMSSTATE */ {NULL,              NULL,                       &greetingState,                 NULL,                   NULL},
  /* GREETINGSTATE */       {NULL,              NULL,                       NULL,                           &waitingForInputState,  NULL},
  /* WAITINGFORINPUTSTATE */{NULL,              NULL,                       NULL,                           NULL,                   &musicState},
  /* MUSICSTATE */          {NULL,              NULL,                       NULL,                           NULL,                   NULL}
};

// clang-format on

void runStatemachine() {
  // Set current state to first state in statemachine.
  transitionToNextState(&startState);

  // The actual statemachine.
  while (true) {
    currentState.doFunc();
    checkEvents();
  }
}

void transitionToNextState(const State *nextStatePtr) {
  // Checks if exit function exists.
  if (currentState.exitFunc) {
    logInfo("Calling exitFunc()");
    currentState.exitFunc();
  }

  currentState = *nextStatePtr;

  // Checks if entry function exists.
  if (currentState.entryFunc) {
    logInfo("Calling entryFunc()");
    currentState.entryFunc();
  }
}

void checkEvents() {
  Event nextEvent = getNextEvent();

  if (nextEvent == EMPTY) {
    return;
  }

  // checks what the next state should be.
  const State *nextState = eventLookupTable[currentState.id][nextEvent];

  if (!nextState) {
    return;
  }

  transitionToNextState(nextState);
  popFront();
}