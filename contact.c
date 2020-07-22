#include"hopitaux.h"
//**************************************initialiser un CONTACT******************************************************//
C* initialiserLContact(){
  C *LC=(C*)malloc(sizeof(C));
 contact*C=(contact*)malloc(sizeof(contact));

 if(LC==NULL || C==NULL){exit(-1);}


        printf("CONTACT NOM ET PRENOM:         :      ");
		scanf("            %s    %s",&C->nom,&C->prenom);
 C->next=NULL;
 LC->top=C;
  return LC;
  }
void ajouterCONTACTFin(C*LC){
   /*allouer le CONTACT*/
 contact *newcontact=(contact*)malloc(sizeof(contact));
  contact*top=LC->top;

  if(LC==NULL || newcontact==NULL){exit(-1);}
        printf("CONTACT NOM ET PRENOM:         :      ");
		scanf("            %s    %s",&newcontact->nom,&newcontact->prenom);

  newcontact->next=NULL; // newcontact va être le dernier contact
  if(LC->top==NULL){
  LC->top=newcontact;
  }

  while(top->next!=NULL){

 top=top->next;
 }
 // changer le next du dernier Contact
 top->next=newcontact;
 // mettre le dernier contact comme prev de newcontact

 }
void afficherLContact(C LC){
  contact*tmp=LC.top;
  int i=26;

  printf("CONTACT :  ");

  if (LC.top==NULL){
        gotoxy(62,27);
        printf("La liste est vide");
        gotoxy(62,28);
        printf("personne n'etait en contact");
        gotoxy(62,29);
        printf("direct avec cette personne.");}
  {
  while(tmp!=NULL){
  gotoxy(70,i);
  printf(" %s %s.", tmp->nom, tmp->prenom);
  tmp=tmp->next;
  i++;
  }
  printf(" \n");}

  }
/*void Ajoutdepersonne_q(C LC, ){
  contact*tmp=LC.top;
  contact* top;

  printf("\n              CONTACT :  \n");
  printf("\033[34m             ---------- \033[0m \n");

  if (LC.top==NULL){
    printf("\033[34m\n      Personne n'etait en contact direct avec le patient.\n\n\033[0m");
    //ajouter au top

    }
  {
  while(tmp!=NULL){
  printf("\033[34m\t\n         Nom et prenom : \033[0m\n\n");
  printf("\033[34m      -->\033[0m");printf(" %s %s.", tmp->nom, tmp->prenom);
  top=tmp;
  tmp=tmp->next;
  }
  printf(" \n");}

  } */
