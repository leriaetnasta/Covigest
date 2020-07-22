#include"hopitaux.h"
 L*initialiserLmd(){
 L *LD=(L*)malloc(sizeof(L));
 maladie*N=(maladie*)malloc(sizeof(maladie));

 if(LD==NULL || N==NULL){exit(-1);}

 printf("La maladie       :");
 scanf("                          %s",&N->nom);
 N->next=NULL;
 LD->top=N;
  return LD;
  }
void ajouterFin(L*LD){
   /*allouer le maladie*/
  maladie *newmaladie=(maladie*)malloc(sizeof(maladie));
  maladie*top=LD->top;

  if(LD==NULL || newmaladie==NULL){exit(-1);}
  printf("La maladie       :");
  scanf("                          %s",&newmaladie->nom);
  newmaladie->next=NULL; // newmaladie va être le dernier maladie



  if(LD->top==NULL){
  LD->top=newmaladie;
  }

  while(top->next!=NULL){

 top=top->next;
 }
 // changer le next du dernier maladie
 top->next=newmaladie;
 // mettre le dernier maladie comme prev de new_maladie

 }
void afficherLDC(L LD){
  maladie*tmp=LD.top;
  int i=26;
  printf("LISTE DES MALADIES :");

   if (LD.top==NULL)
    {
    gotoxy(22,27);
    printf("La liste est vide");
    gotoxy(22,28);
    printf("cette personne ne souffre");
    gotoxy(22,29);
    printf("d'aucune maladie chronique.");
    }
    {
  while(tmp!=NULL){
  gotoxy(32,i);
  printf(" %s.", tmp->nom);
  i++;
  tmp=tmp->next;}
  }

  }
