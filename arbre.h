#ifndef ARBRE_H_included
#define ARBRE_H_included
#include<stdbool.h>
typedef void Objet;

typedef struct noeud{
	Objet* reference;
	struct noeud* gauche;
	struct noeud* droite;
}Noeud;

char* afficher(Objet* objet);
int comparer(Objet* objet1,Objet* objet2);

typedef struct {
Noeud* racine;
char* (*afficher)(Objet*);
int (*comparer)(Objet*,Objet*);
}Arbre;

Noeud*cNd(Objet*objet,Noeud*gauche,Noeud*droite);
Noeud*cF(Objet*objet);
void initArbre(Arbre*arbre,Noeud*racine,
		char*(*afficher)(Objet*),int(*comparer)(Objet*,Objet*));
Arbre*creerArbre(Noeud*racine,char*(*afficher)(Objet*),
		int(*comparer)(Objet*,Objet*));
Arbre*creerArbreGene();
Arbre*creerArbreBinaires();
void prefixe(Noeud*racine,char*(*afficher)(Objet*));
void infixe(Noeud*racine,char*(*afficher)(Objet*));
void postfixe(Noeud*racine,char*(*afficher)(Objet*));
Noeud* trouverNoeud(Noeud*racine,Objet*objet,
					int(*comparer)(Objet*,Objet*));
					
void enLargeur(Noeud*racine,char*(*afficher)(Objet*));
int taille(Noeud*racine);
bool estFeuille(Noeud* racine);
int nbFeuilles(Noeud* racine);
void listerFeuilles(Noeud*racine,char*(*afficher)(Objet*));
int hauteur(Noeud*racine);
bool egaliteArbre(Noeud* racine1,Noeud*racine2,
			int(*comparer)(Objet*,Objet*));

#endif
