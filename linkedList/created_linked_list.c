#include <stdlib.h>
#include <stdio.h>
int main (void)
{
    typedef struct island {
        char *name;
        char *open;
        char *close;
        char *next_parade;
        struct island *next;

    } island;

    island amity = {"Amity", "09:00", "17:00", "Craggy", NULL};
    island craggy = {"Craggy", "09:00", "17:00", "Isla Nublar", NULL};
    island isla_nublar = {"Isla_nulblar", "09:00", "17:00", "Shutter", NULL};
    island shutter = {"Shutter", "09:00", "17:00", "Aiport back", NULL};

    amity.next = &craggy;
    craggy.next = &isla_nublar;
    isla_nublar.next = &shutter;

    island skull = {"Skull", "09:00", "17:00", "Shutter", NULL};
    
    isla_nublar.next = &skull, isla_nublar.next_parade = "Skull";
    skull.next =  &shutter;

    printf("Data: name: %s, times: %s - %s next parade: %s", amity.name, amity.open, amity.close, amity.next_parade);
}
