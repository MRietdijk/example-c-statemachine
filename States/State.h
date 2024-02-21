#ifndef STATE_H__
#define STATE_H__

#include <stdint.h>

/**
 * @brief State struct with id of State, entry/do/exit function pointers.
 *
 */
typedef struct {
  uint8_t id;
  void (*entryFunc)();
  void (*doFunc)();
  void (*exitFunc)();
} State;

/**
 * @brief All state ids
 *
 */
typedef enum {
  START_STATE_ID,
  INIT_SUB_SYSTEMS_STATE_ID,
  WAITING_FOR_INPUT_STATE_ID
} StateId;

char *stateIdToString(StateId id);

#endif // STATE_H__