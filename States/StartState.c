#include "StartState.h"
#include "../EventQueue.h"
#include <stdio.h>

State startState = {.id = 0,
                    .entryFunc = &startStateEntry,
                    .doFunc = &startStateDo,
                    .exitFunc = &startStateExit};

void startStateEntry() { printf("Inside StartStateEntry()\n"); }

void startStateDo() {
  printf("Inside StartStateDo()\n");
  addEvent(SYSTEM_BOOTED_UP);
}

void startStateExit() { printf("Inside StartStateExit()\n"); }