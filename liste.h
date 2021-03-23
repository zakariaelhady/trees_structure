
#ifndef Liste_H_included
#define Liste_H_included
#include<stdbool.h>


typedef void Objet;

typedef struct element{
	Objet* reference;
	struct element* suivant;
}Element;

char* afficher(Objet* objet);
int comparer(Objet* objet1,Objet* objet2);

typedef struct {
Element* premier;
Element* courant;
Element* dernier;
int nbElt;
int type;
char* (*afficher)(Objet*);
int (*comparer)(Objet*,Objet*);
}Liste;

void initListe(Liste* li,int type,char*(*afficher)(Objet*),
				int(*comparer)(Objet*,Objet*));
				
Liste* creerListe(int type,char*(*afficher)(Objet*),
					int(*comparer)(Objet*,Objet*));
					
bool listeVide(Liste*li);

int nbElement(Liste*li);

static Element* creerElement();

void insererEnTeteDeListe(Liste* li,Objet* objet);

static void insererApres(Liste* li,Element* precedent,Objet* objet);

void insererEnFinDeListe(Liste* li,Objet* objet);

void ouvrirListe(Liste*li);

bool finListe(Liste*li);

static Element* elementCourant(Liste*li);

Objet* objetCourant(Liste* li);

void listerListe(Liste* li);

Objet* chercherUnObjet(Liste* li,Objet*objetCherche);

Objet* extraireEnTeteListe(Liste* li);

static Objet* extraireApres(Liste* li,Element*precedent);

Objet* extraireEnFinListe(Liste* li);

bool extraireUnObjet(Liste*li,Objet*objet);

void detruireListe(Liste* li);

#endif
