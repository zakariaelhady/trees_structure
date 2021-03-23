#include <stdio.h>
#include <stdlib.h>
#include"arbre.h"
#include<stdlib.h>
typedef char ch15 [16];
int menu(){
printf ("\n\n GESTION D'ARBRES \n\n");
printf ("\n\n ARBRES BINAIRES \n\n");
printf (" 0 - Fin du programme\n");
printf ("\n");
printf (" 1 - Creation de l'arbre genealogique\n");
printf (" 2 - Creation de l'arbre de l'expression arithmetique\n");
printf ("\n");
printf (" 3 - Parcours prefixe\n");
printf (" 4 - Parcours infixe\n");
printf (" 5 - Parcours postfixe\n");
printf ("\n");
printf (" 6 - Rechercher un noeud \n");
printf (" 7 - Parcours en largeur \n");
printf (" 8 - La taille de l'arbre \n");
printf (" 9 - Le nombre des feuilles\n");
printf (" 10 -Parcours des feuilles \n");
printf (" 11 -La hauteur de l'arbre\n");
printf (" 12 -tester l'egalite entre les deux arbres\n");
printf ("Votre choix ? ");
int cod; scanf ("%d", &cod); getchar();
printf ("\n");
return cod;
}

main(){
Arbre*arbreArith;
Arbre*arbreGene;
bool fini=false;
while(!fini){
	switch(menu()){
		case 0 :
            fini=true;
        break;
        case 1 :{
        	arbreGene=creerArbreGene();
            printf("l'arbre genealogique a ete cree ");
           }
        break;
        case 2 :{
        	arbreArith=creerArbreBinaires();
        	printf("\n l'arbre de l'expression arithmetique a ete cree \n");
        
            }
        break;
        case 3 :{
        	prefixe(arbreArith->racine,afficher);
			}
        break;
        case 4 :{
        	infixe(arbreArith->racine,afficher);
			}
        break;
        case 5 :{
            postfixe(arbreArith->racine,afficher);
			}
        break;
		case 6 :{
            printf("\n entrer l'objet du noeud a rechercher:");
            ch15 obj;
            scanf("%s",&obj);
            Noeud* ndcherche=trouverNoeud(arbreGene->racine,obj,comparer);
            if(ndcherche!=NULL){printf("\n le noeud cherche a ete trouve ");
            	if(estFeuille(ndcherche)) printf("\n le noeud cherche est une feuille ");
            	else printf("\n le noeud cherche n'est pas une feuille ");
			}
			else printf("\n le noeud cherche n'a pas ete trouve ");
			}
        break;
        case 7 :{
            enLargeur(arbreGene->racine,afficher);
			}
        break;
        case 8 :{
            printf("\n la taille de l'arbre est: %d",taille(arbreGene->racine));
			}
        break;
        case 9 :{printf("\n le nombre des feuilles de l'arbre est: %d",nbFeuilles(arbreGene->racine));
			}
        break;
        case 10 :{
            listerFeuilles(arbreGene->racine,afficher);
			}
        break;
        case 11 :{
            printf("\n la hauteur de l'arbre est: %d",hauteur(arbreGene->racine));
			}
        break;
        case 12 :{
            if(egaliteArbre(arbreGene->racine,arbreArith->racine,comparer))
					printf("\n les deux arbres sont egaux");
			else printf("\n les deux arbres ne sont pas egaux");
			}
        break;
		}}
}
