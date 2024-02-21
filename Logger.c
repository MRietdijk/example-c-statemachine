#include "Logger.h"
#include "Statemachine.h"
#include <stdio.h>

void logInfo(const char *message) {
  const char *stateString = stateIdToString(currentState.id);

  printf("%s: %s\n", stateString, message);
}