#include "WaitingForInputState.h"
#include "../EventQueue.h"
#include <stdio.h>

State waitingForInputState = {.id = 2,
                              .entryFunc = waitingForInputStateEntry,
                              .doFunc = waitingForInputStateDo,
                              .exitFunc = waitingForInputStateExit};

void waitingForInputStateEntry() { printf("Inside WaitingForInputEntry()\n"); }

void waitingForInputStateDo() {
  printf("Inside WaitingForInputDo()\n");
  addEvent(GREETED);
}

void waitingForInputStateExit() { printf("Inside WaitingForInputExit()\n"); }