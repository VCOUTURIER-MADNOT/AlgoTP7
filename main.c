#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include <stdbool.h>
#include "file.h"
#include "outilsGraphe.h"

int main(){
	
    Graphe* graphe = creerGraphe("graphe3.txt");
    
    afficherListesAdjacences(graphe);
    afficherMatriceAdjacences(graphe);
    
    return 0;
}