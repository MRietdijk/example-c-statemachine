#include "GreetingState.h"
#include <stdio.h>
#include "../EventQueue.h"

State greetingState = {.id = GREETING_STATE_ID,
                    .entryFunc = &greetingStateEntry,
                    .doFunc = &greetingStateDo,
                    .exitFunc = &greetingStateExit};

void greetingStateEntry()
{
    printf("Inside greetingStateEntry()\n");
}

void greetingStateDo()
{
    printf("Hello Goodmorning\n");
    addEvent(GREETED);
}

void greetingStateExit()
{
    printf("inside greetingStateExit()\n");
}