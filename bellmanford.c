#include <stdio.h>
#include <stdlib.h>
#include "bellmanford.h"

void souce_Initialisation(Graphe* g, Sommet* s)
{
    int i;
    for(i=0; i < g->nbrSommet; i++){
        Sommet* v = g->tabSommet[i];
        if (s->cle == v->cle)
            v->distance = 0;
        else
            v->distance = 10000;
        v->pere = NULL;
	}
}

void relacherArete(Sommet* u, Sommet* v, int poids){
	if(v->distance > (u->distance + poids)){
		v->distance = u->distance + poids;
		v->pere=u;
	}
}

int Bellman_Ford(Graphe* g, Sommet* s)
{
    int i,j,k,l;
	
	// Création tableaux aretes
	int* tabAreteIndX = NULL;
	int* tabAreteIndY = NULL;
	int* tabAreteVal = NULL;
    
	k=0;
	for(i=0;i<g->nbrSommet;i++){
		for(j=0;j<g->nbrSommet;j++){
			if(g->tabAretes[i][j].poids != 0){
				k++;
			}
            
		}
	}
	tabAreteIndX = malloc(sizeof(int) * k);
	tabAreteIndY = malloc(sizeof(int) * k);
	tabAreteVal = malloc(sizeof(int) * k);
    
	l=0;
	for(i=0;i<g->nbrSommet;i++){
		for(j=0;j<g->nbrSommet;j++){
			if(g->tabAretes[i][j].poids !=0 ){
				tabAreteIndX[l]=i;
				tabAreteIndY[l]=j;
				tabAreteVal[l]= g->tabAretes[i][j].poids;
				l++;
			}
		}
	}
    
    /* Initialisation */
    souce_Initialisation(g, s);
    
    /* Relachement des arcs */
    for (i=0; i < g->nbrSommet-1 ; i++)
    {
        for(j=0;j<k;j++){
			relacherArete(g->tabSommet[tabAreteIndX[j]],g->tabSommet[tabAreteIndY[j]],tabAreteVal[j]);
		}
    }
    
    /* Cherche cycle absorbant */
    for(j=0;j<k;j++){
		if(g->tabSommet[tabAreteIndY[j]]->distance > (g->tabSommet[tabAreteIndX[j]]->distance + tabAreteVal[j]))
			return -1;
	}
    
	return 0;
}

void afficherBellman_Ford(Graphe* g, int depart){
    int i;
	printf("Bellman-Ford : \n");
	printf("Sommet de depart : %d\n\n",depart);
	for(i=0;i<g->nbrSommet;i++){
		printf("Sommet %d :\t distance %d \t pere : ",g->tabSommet[i]->cle,g->tabSommet[i]->distance);
		if(g->tabSommet[i]->pere == NULL)
			printf("aucun\n");
		else
			printf("%d\n",g->tabSommet[i]->pere->cle);
	}
	printf("\n\n");
}