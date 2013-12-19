#ifndef AlgoTP7_bellmanford_h
#define AlgoTP7_bellmanford_h

    #include "graphe.h"

    void sourceUniqueInitialisation(Graphe* g,Sommet* s);
    void relacher(Sommet* u, Sommet* v, int poids);
    int Bellman_Ford(Graphe* g, Sommet* s);
    void afficherBellman_Ford(Graphe* g, int depart);

#endif
