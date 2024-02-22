#include "MusicState.h"

#include <stdio.h>

State musicState = {.id = MUSIC_STATE_ID,
                    .entryFunc = &musicStateEntry,
                    .doFunc = &musicStateDo,
                    .exitFunc = &musicStateExit};

void musicStateEntry()
{
    printf("Inside musicStateEntry()\n");
}

void musicStateDo()
{
    printf("playing music now....\n");
}

void musicStateExit()
{
    printf("Inside musicStateExit()\n");
}