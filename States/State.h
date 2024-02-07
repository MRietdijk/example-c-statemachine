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

#endif // STATE_H__