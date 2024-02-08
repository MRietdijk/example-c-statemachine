#include "InitSubSystemsState.h"
#include "../EventQueue.h"
#include <stdio.h>

State InitSubSystemsState = {.id = INIT_SUB_SYSTEMS_STATE_ID,
                             .entryFunc = &InitSubSystemsStateEntry,
                             .doFunc = &InitSubSystemsStateDo,
                             .exitFunc = &InitSubSystemsStateExit};

void InitSubSystemsStateEntry() {
  printf("Inside InitSubSystemsStateEntry()\n");
}

void InitSubSystemsStateDo() {
  printf("Inside InitSubSystemsStateDo()\n");
  addEvent(SUBSYSTEM_INITIALIZED);
}

void InitSubSystemsStateExit() { printf("Inside InitSubSystemsStateExit()\n"); }