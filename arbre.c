#include<stdio.h>
#include"arbre.h"
#include<stdlib.h>
#include<stdbool.h>
#include"liste.h"
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
Noeud*cNd(Objet*objet,Noeud*gauche,Noeud*droite){
	Noeud*nouveau=(Noeud*)malloc(sizeof(Noeud));
	nouveau->reference=objet;
	nouveau->gauche=gauche;
	nouveau->droite=droite;
	return nouveau;
}
Noeud*cF(Objet*objet){
	return cNd(objet,NULL,NULL);
}
void initArbre(Arbre*arbre,Noeud*racine,
		char*(*afficher)(Objet*),int(*comparer)(Objet*,Objet*)){
	arbre->racine=racine;
	arbre->afficher=afficher;
	arbre->comparer=comparer;		
}
Arbre*creerArbre(Noeud*racine,char*(*afficher)(Objet*),
		int(*comparer)(Objet*,Objet*)){
	Arbre* arbre=(Arbre*)malloc(sizeof(Arbre))	;
	initArbre(arbre,racine,afficher,comparer);
	return arbre;	
}
Arbre*creerArbreGene(){
	Noeud*racine=
	cNd("Samir",
		cNd("Kamal",
			cNd("yassine",NULL,cNd("Hind",NULL,cF("Yasmine"))
			),cNd("sarah",cF("Karim"),NULL)),NULL);
	creerArbre(racine,afficher,comparer);
}
Arbre*creerArbreBinaires(){
	Noeud*racine=cNd("-",cNd("*",
					cNd("+",cF("a"),
				       cF("b")),
					cNd("-",cF("c"),
					   cF("d"))),
				cF("e"));
	return creerArbre(racine,afficher,comparer);
}
void prefixe(Noeud*racine,char*(*afficher)(Objet*)){
	if(racine!=NULL)
	{
		printf("%s",afficher(racine->reference));
		prefixe(racine->gauche,afficher);
		prefixe(racine->droite,afficher);	}
}	
void infixe(Noeud*racine,char*(*afficher)(Objet*)){
	if(racine!=NULL){
		infixe(racine->gauche,afficher);
		printf("%s",afficher(racine->reference));
		infixe(racine->droite,afficher);}
}
void postfixe(Noeud*racine,char*(*afficher)(Objet*)){
	if(racine!=NULL){
		postfixe(racine->gauche,afficher);
		postfixe(racine->droite,afficher);
		printf("%s",afficher(racine->reference));}
}
Noeud* trouverNoeud(Noeud*racine,Objet*objet,
					int(*comparer)(Objet*,Objet*)){
	Noeud* pNom;
	if(racine==NULL){
		pNom=NULL;
	}
	else if(comparer(racine->reference,objet)==0){
		pNom=racine;
	}
	else{
		pNom=trouverNoeud(racine->gauche,objet,comparer);
		if(pNom==NULL){
			pNom=trouverNoeud(racine->droite,objet,comparer);}
	}
	return pNom;		
}
void enLargeur(Noeud*racine,char*(*afficher)(Objet*)){
	Liste*li=creerListe(0,afficher,comparer);
	insererEnFinDeListe(li,racine);
	while(!listeVide(li))
	{
    Noeud* extrait=(Noeud*)extraireEnTeteListe(li);
	printf("%s ",afficher(extrait->reference));
	if(extrait->gauche!=NULL)
		insererEnFinDeListe(li,extrait->gauche);
	if(extrait->droite!=NULL)
		insererEnFinDeListe(li,extrait->droite);	}}
int taille(Noeud*racine){
	if(racine==NULL)
		return 0;
	else 
		return 1+taille(racine->gauche)+taille(racine->droite);
}
bool estFeuille(Noeud* racine){
	return(racine->gauche==NULL)&&(racine->droite==NULL);
}
int nbFeuilles(Noeud* racine){
	if(racine==NULL)
		return 0;
	else if(estFeuille(racine))
		return 1;
	else
		return nbFeuilles(racine->gauche)+nbFeuilles(racine->droite);
}
void listerFeuilles(Noeud*racine,char*(*afficher)(Objet*)){
	if(racine!=NULL){
		if(estFeuille(racine)) 
			printf("%s ",afficher(racine->reference));
		else {
		listerFeuilles(racine->gauche,afficher);
		listerFeuilles(racine->droite,afficher);
		}}}
int hauteur(Noeud*racine){
	if(racine==NULL)
		return 0;
	else
		return 1+max(hauteur(racine->gauche),hauteur(racine->droite));
}
bool egaliteArbre(Noeud* racine1,Noeud*racine2,
			int(*comparer)(Objet*,Objet*)){
	bool resu=false;
	if((racine1==NULL)&&(racine2==NULL))	
		resu=true;
	else if((racine1!=NULL)&&(racine2!=NULL)){
		if(comparer(racine1->reference,racine2->reference)==0)
			{
			if(egaliteArbre(racine1->gauche,racine2->gauche,comparer))
				resu=egaliteArbre(racine1->droite,racine2->droite,comparer);
			}
	}return resu;	
}
