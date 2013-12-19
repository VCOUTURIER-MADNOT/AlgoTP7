#include <stdio.h>
#include <stdlib.h>
#include "bellmanford.h"

int main(){
	
    Graphe* graphe = creerGraphe("graphe3.txt");
    
    Bellman_Ford(graphe, graphe->tabSommet[0]);
    
    afficherBellman_Ford(graphe, 0);
    
    return 0;
}