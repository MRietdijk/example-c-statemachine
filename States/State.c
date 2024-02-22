#include "State.h"

char *stateIdToString(StateId id) {
  switch (id) {
  case START_STATE_ID:
    return "START_STATE";
    break;
  case INIT_SUB_SYSTEMS_STATE_ID:
    return "INIT_SUB_SYSTEM_STATE";
    break;
  case WAITING_FOR_INPUT_STATE_ID:
    return "WAITING_FOR_INPUT_STATE";
    break;
  case GREETING_STATE_ID:
    return "GEETING_STATE";
    break;
  case MUSIC_STATE_ID:
    return "MUSIC_STATE";
    break;
  default:
    return "Undefined";
    break;
  }
}