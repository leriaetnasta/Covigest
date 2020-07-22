#include"hopitaux.h"
#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
//**************************************Ajouter un hopital******************************************************//
 hopital* Nouveauhopital(){
     int c;
 char ch;
 hopital* h=malloc(sizeof(hopital));
 system("cls");
        box();
		box_III();
		gotoxy(40,3);
		printf("AJOUT HOPITAL ");
		gotoxy(10,8);
		printf("NOM                : ");
		gotoxy(59,8);
		printf("ADRESSE            : ");
		gotoxy(10,12);
		printf("COMMUNE            : ");
		gotoxy(59,12);
		printf("VILLE              : ");
		gotoxy(10,16);
		printf("CODEPOSTAL         : ");
		gotoxy(59,16);
		printf("UNITES             : ");
		gotoxy(10,20);
		printf("LITS DISPO EN REA  : ");
		gotoxy(59,20);
		printf("LITS DISPO AILLEURS: ");
		gotoxy(10,24);
		printf("SALLES             : ");
		gotoxy(59,24);
		printf("MEDECINS           : ");
		gotoxy(10,28);
		printf("POLES              : ");

		gotoxy(33,8);
        scanf("%s",&h->nom);
        // debut: pour que fgets fonctionne apres scanf
        do{
        c = getchar();
        }while(c != EOF && c != '\n'); // fin
        gotoxy(82,8);
		fgets(h->Adresse.adresse, sizeof(h->Adresse.adresse), stdin);
		gotoxy(33,12);
		fgets(h->Adresse.commune, sizeof(h->Adresse.commune), stdin);
		gotoxy(82,12);
		scanf("%s",&h->Adresse.ville);
		gotoxy(33,16);
		scanf("%d",&h->Adresse.codepostal);
		gotoxy(82,16);
		scanf("%d",&h->nombre_unite);
		gotoxy(33,20);
		scanf("%d",&h->litsrea_dispo);
		gotoxy(82,20);
		scanf("%d",&h->litsnormal_dispo);
		gotoxy(33,24);
		scanf("%d",&h->nombre_salles );
		gotoxy(82,24);
		scanf("%d",&h->nombre_med);
		gotoxy(33,28);
		scanf("%d",&h->nombre_pole);
        system("cls");
        gotoxy(20,20);
        printf("hopital ajoute!");

return h;
}
void Fichehopital(hopital H){
char reponse[3];
system("cls");
        gotoxy(40,3);
        box();
		box_III();
		gotoxy(40,3);
		printf("FICHE HOPITAL");
		gotoxy(10,8);
		printf("NOM                : ");
		gotoxy(59,8);
		printf("NOMBRE DES POLES   : ");
		gotoxy(10,12);
		printf("NOMBRE DES UNITES  : ");
		gotoxy(59,12);
		printf("NOMBRE DES SALLES  : ");
		gotoxy(10,16);
		printf("NOMBRE DES MEDECINS: ");
		gotoxy(59,16);
		printf("ADRESSE            : ");
		gotoxy(10,20);
		printf("COMMUNE            : ");
		gotoxy(59,20);
		printf("VILLE              : ");
		gotoxy(10,24);
		printf("CODEPOSTAL         : ");
		gotoxy(33,8);
        printf(" %s.",H.nom);
        gotoxy(82,8);
		printf(" %d.",H.nombre_pole);
		gotoxy(33,12);
		printf(" %d.",H.nombre_unite);
		gotoxy(82,12);
		printf(" %d.",H.nombre_salles);
        gotoxy(33,16);
        printf(" %d.",H.nombre_med);
		gotoxy(82,16);
        printf(" %s.",H.Adresse.adresse);
		gotoxy(33,20);
		printf(" %s.",H.Adresse.commune);
		gotoxy(82,20);
		printf(" %s.",H.Adresse.ville);
		gotoxy(33,24);
        printf(" %d.",H.Adresse.codepostal);
		gotoxy(10,26);

  }
void Afficherhopital(hopital H, int i){

	   gotoxy(4,i);
       printf(" %s", H.nom);
       gotoxy(13,i);
       printf(" %d", H.nombre_pole);
       gotoxy(20,i);
       printf(" %d", H.nombre_unite);
       gotoxy(27,i);
       printf(" %d", H.nombre_salles);
       gotoxy(34,i);
       printf(" %d", H.nombre_med);
       gotoxy(41,i);
       printf(" %d", H.litsnormal_dispo+H.litsrea_dispo);
       gotoxy(50,i);
       printf(" %d", H.Adresse.codepostal);
       gotoxy(63,i);
       printf(" %s", H.Adresse.ville);
       gotoxy(75,i);
       printf(" %s", H.Adresse.commune);
       gotoxy(88,i);
       printf(" %s", H.Adresse.adresse);




  }
LDCH* initialiserLDCH(){
  LDCH *LH=(LDCH*)malloc(sizeof(LDCH));
 Node_H*N=(Node_H*)malloc(sizeof(Node_H));

 if(LH==NULL || N==NULL){exit(-1);}

 N->data=*Nouveauhopital();
 N->next=NULL;
 N->prev=NULL;
 LH->head=N;
  return LH;
  }
void ajouterFinLDCH(LDCH*LH){
   /*allouer le noeud*/
  Node_H *newnode=(Node_H*)malloc(sizeof(Node_H));
  Node_H*last=LH->head;

  if(LH==NULL || newnode==NULL){exit(-1);}
  newnode->data=*Nouveauhopital(); // mettre les données
  newnode->next=NULL; // newnode va être le dernier noeud

  // si la liste est vide , --> mettre le newnode comme head

  if(LH->head==NULL){
  newnode->prev=NULL;
  LH->head=newnode;
  }
  // else traverser jusqu'au dernier noeud;

  while(last->next!=NULL){

 last=last->next;
 }
 // changer le next du dernier noeud
 last->next=newnode;
 // mettre le dernier noeud comme prev de newnode

 newnode->prev=last;
 }
void afficherLDCH(LDCH LH){
  Node_H*tmp=LH.head;
  int i=14;
  if (LH.head==NULL){ printf("\033[34m\n        La liste est vide pour le moment.\n\n\033[0m"); }
  I_box();
	   box_IV();
	   gotoxy(60,3);
	   printf("LISTE");
	   gotoxy(58,4);
	   printf("DES HOPITAUX");
	   gotoxy(4,7);
	   printf("==================================================================================================================");
	   gotoxy(5,8);
	   printf("        NOMBRE NOMBRE NOMBRE NOMBRE NOMBRE");
	   gotoxy(5,9);
       printf("NOM      DE     DE     DE     DE      LITS    CODEPOSTAL   VILLE       COMMUNE      ADRESSE                      ");
	   gotoxy(5,10);
	   printf("        POLES UNITES SALLES MEDECINS DISPO");
	   gotoxy(4,11);
	   printf("==================================================================================================================");
  while(tmp!=NULL){
  Afficherhopital(tmp->data,i);
  tmp=tmp->next;
  i=i+2;
  }
  getch();
  }
void hopitaux_lisrea_dispo(LDCH LH){
  Node_H*tmp=LH.head;
  int i=0;
  if (LH.head==NULL){ printf("La liste est vide pour le moment."); }
  system("cls");
               gotoxy(55,17);
	            printf("Liste des hopitaux disponibles.");
	            gotoxy(80,17);

                 for(i=0;i<=6;i++)
                {
            Sleep(300);
            gotoxy(67+i,17);
            printf(".");
                }
  while(tmp!=NULL){
        if(tmp->data.litsrea_dispo>0){

                Fichehopital(tmp->data); i++;
                gotoxy(10,24);
                printf("Appuyez sur n'importe quelle touche pour continuer.");
                getch();}
  tmp=tmp->next;
  }
  if(tmp==NULL&& i==0){
    printf("Aucun hopital disponible pour le moment.");
  }
  }
void hopitaux_lisnorm_dispo(LDCH LH){
  Node_H*tmp=LH.head;
  int i=0;
  if (LH.head==NULL){ printf("La liste est vide pour le moment."); }
  system("cls");
               gotoxy(55,17);
	            printf("Liste des hopitaux disponibles.");
	            gotoxy(80,17);

                 for(i=0;i<=6;i++)
                {
            Sleep(300);
            gotoxy(67+i,17);
            printf(".");
                }
  while(tmp!=NULL){

        if(tmp->data.litsnormal_dispo>0){Fichehopital(tmp->data); i++;
        gotoxy(10,24);
                printf("Appuyez sur n'importe quelle touche pour continuer.");
                getch();}
  tmp=tmp->next;
  }
  if(tmp==NULL&& i==0){
    printf("Aucun hopital disponible pour le moment.");
    getch();
  }
  }
Node_H* rechercheHP_CP_L_NORMAL(LDCH* LH, int cp){
  Node_H*tmp=LH->head;
  if (LH->head==NULL){ printf("Aucun hopital n'est disponible pour le moment."); }
  while(tmp!=NULL){
  if(tmp->data.litsnormal_dispo>0){
  if(tmp->data.Adresse.codepostal==cp){
        Fichehopital(tmp->data);
    return tmp;
  }}

  tmp=tmp->next;
  }
  if(tmp==NULL){
  printf("ERREUR.");}
  return NULL;
  }
Node_H* rechercheHP_CP_L_REA(LDCH* LH, int cp){
  Node_H*tmp=LH->head;
  int i=0;
  if (LH->head==NULL){ printf("Aucun hopital n'est disponible pour le moment."); }
  while(tmp!=NULL){
  if(tmp->data.litsrea_dispo>0){
  if(tmp->data.Adresse.codepostal==cp){
        Fichehopital(tmp->data);
        i++;
    return tmp;
  }}

  tmp=tmp->next;
  }
  if(tmp==NULL && i==0){
  printf("              ERREUR.   \n");}
  return NULL;
  }
void SupprimerHopital(LDCH *LH, Node_H*H){
    Node_H*next;
    Node_H*prev;
    if(LH==NULL || H==NULL){exit(-1);}

    if(LH->head==H){
    LH->head=H->next;
    }
    if(H->next!=NULL){
    next=H->next;
    next->prev=H->prev;
    }
    if(H->prev!=NULL)
    prev=H->prev;
    prev->next=H->next;

    free(&H->data);
    free(H);
     }
void Modification_hopital(PH*LPH,LDCH* LH){
    int choix,s=0;
    char nom[10];
    system("cls");
             box();
             box_III();
             gotoxy(41,3);
             printf("oMODIFIERo");
             gotoxy(30,10);
             printf("1. Supprimer un hopital.");
             gotoxy(30,12);
             printf("2. Modifier le nombre delits disponibles en reanimation.");
             gotoxy(30,14);
             printf("3. Modifier le nombre de lits disponibles ailleurs.");
             gotoxy(30,16);
             printf("4. Modifier le nombre de salles disponibles.");
             gotoxy(30,18);
	      	 printf("Entrer la selection :");
	      	 gotoxy(50,18);
	      	 scanf(" %d", &choix);
        if(choix==1){
            system("cls");
            box();
            gotoxy(30,12);
            printf("Donner le nom de l'hopital.");
            gotoxy(30,13);
            scanf("%s",&nom);
            Node_H*H=LH->head;
        while(H!=NULL){
        if(rechercherhopitaldansHP(*LPH,nom)==NULL){ // <-fct return NULL is l'hopital n'a aucun patient.

            SupprimerHopital(LH,H);s++;
         }
            H=H->next;
        }
        if(H==NULL && s==0)
            {printf("Impossible d'effectuer cette operation, cet hopital a des patients Covid-19");}

        }
    if(choix==2){
            system("cls");
            box();
            gotoxy(30,12);
            printf("Donner le nom de l'hopital.");
            gotoxy(30,13);
            scanf("%s",&nom);
            Node_H*H=LH->head;
         while(H!=NULL){

        if(stricmp(H->data.nom,nom)==0){
                gotoxy(30,14);
            printf("Donner le nouveau nombre de lits en reanimation.");
            gotoxy(30,15);
            scanf("%d",&H->data.litsrea_dispo);}
            H=H->next;
        }
            }
    if(choix==3){
            system("cls");
            box();
            gotoxy(30,12);
            printf("Donner le nom de l'hopital.");
            gotoxy(30,13);
            scanf("%s",&nom);
            Node_H*H=LH->head;
         while(H!=NULL){

        if(stricmp(H->data.nom,nom)==0){
            gotoxy(30,14);
            printf("Donner le nouveau nombre de lits normal.");
            gotoxy(30,15);
            scanf("%d",&H->data.litsnormal_dispo);}
            H=H->next;
                       }
               }
    if(choix==4){
            system("cls");
            box();
            gotoxy(30,12);
            printf("Donner le nom de l'hopital.");
            gotoxy(30,13);
            scanf("%s",&nom);
            Node_H*H=LH->head;
         while(H!=NULL){

        if(stricmp(H->data.nom,nom)==0){
                gotoxy(30,14);
            printf("Donner le nouveau nombre de salles.");
            gotoxy(30,15);
            scanf("%d",&H->data.nombre_salles);}
            H=H->next;
                       }
        }


}
void WriteListToFile(LDCH *start) {
	FILE *pFile;
	pFile = fopen("myList.bin", "ab");

	if(pFile != NULL) {
		Node_H *currentHopital = start->head ;

		Node_H *holdNext = NULL;
		Node_H *holdPrevious = NULL;

		while(currentHopital != NULL) {
			holdNext = currentHopital->next;
			holdPrevious = currentHopital->prev;

			currentHopital->next = NULL;
			currentHopital->prev = NULL;

			fseek(pFile, 0, SEEK_END);
			fwrite(currentHopital, sizeof(Node_H), 1, pFile);

			printf("Writing:%s to file\n",currentHopital->data.nom);

			currentHopital->next = holdNext;
			currentHopital->prev= holdPrevious;

			holdNext = NULL;
			holdPrevious = NULL;

			currentHopital = currentHopital->next;
		}
		fclose(pFile);
		pFile = NULL;
	} else {
		printf("FILE OPEN ERROR\n");
	}
}
void CleanUp(LDCH *start) {

	Node_H *freeMe = start->head;
	Node_H *holdMe = NULL;
	while(freeMe != NULL) {
		holdMe = freeMe->next;
		printf("free Name:%s",
			freeMe->data.nom);
		free(&freeMe->data);
        free(freeMe);
		freeMe = holdMe;
	}
}
LDCH *ReadNextFromFile(LDCH *start, FILE *pFile) {
	size_t returnValue;
	if(start->head == NULL) {
		Node_H *starting = malloc(sizeof(Node_H));
		returnValue = fread(starting, sizeof(Node_H), 1, pFile);
		starting->next = NULL;
		starting->prev = NULL;
		start->head=starting;
	} else {
		Node_H *indexHopital = start->head;
		Node_H *newhopital = malloc(sizeof(Node_H));
		while(indexHopital->next != NULL) {
			indexHopital = indexHopital->next;
		}
		returnValue = fread(newhopital, sizeof(Node_H), 1, pFile);
		indexHopital->next = newhopital;
		newhopital->next = NULL;
		newhopital->prev = indexHopital;
	}
	return start;
}
LDCH *ReadListIn(LDCH *start) {

	FILE *pFile;
	pFile = fopen("myList.bin", "rb");
	if(pFile != NULL) {

      CleanUp(start);
      start->head=NULL;

		fseek(pFile, 0, SEEK_END);
		long fileSize = ftell(pFile);
		rewind(pFile);

		int numajout = (int)(fileSize / (sizeof(Node_H)));
		printf("numajout:%d\n",numajout);

		int i = 0;
		for(i=0; i < numajout; ++i) {
			fseek(pFile, (sizeof(Node_H) * i), SEEK_SET);
			start= ReadNextFromFile(start, pFile);
		}
	}  else {
		printf("FILE OPEN ERROR FOR READ\n");
	}

	return start;

}

