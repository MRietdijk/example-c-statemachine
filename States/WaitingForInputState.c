#include "WaitingForInputState.h"
#include "../EventQueue.h"
#include <stdio.h>

State waitingForInputState = {.id = WAITING_FOR_INPUT_STATE_ID,
                              .entryFunc = waitingForInputStateEntry,
                              .doFunc = waitingForInputStateDo,
                              .exitFunc = waitingForInputStateExit};

void waitingForInputStateEntry() { printf("Inside WaitingForInputEntry()\n"); }

void waitingForInputStateDo() {
  printf("Inside WaitingForInputDo()\n");
  addEvent(LEFT_EAR_PRESSED);
}

void waitingForInputStateExit() { printf("Inside WaitingForInputExit()\n"); }