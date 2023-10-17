//programa de adivinacion porcentual de artefactos
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void num_substats ();
void next_substats ();
void difine_substats ();


//difines the type of artefact used
typedef struct{
    char name_stat [4];
    int range_stat [4];
} artefacts_substats_complete;

typedef struct{
    char name_stat [3];
    int range_stat [3];
} artefacts_substats_incomplete;

void num_substats ()
{
    int num_substats;
    printf ("Elige el numero de substats del artefacto");
    scanf("%d", &num_substats);
    if (num_substats = 3)
    {
        next_substats (num_substats);
    }
    else
    {
        difine_substats();
    }
}

void next_substats ();
{

}


int main ()
{
    num_substats ();
    return 0;

}
