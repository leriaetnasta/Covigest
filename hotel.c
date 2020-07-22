#include"hopitaux.h"
hotel* Nouveauhotel(){

        int c;
        hotel* h=malloc(sizeof(hopital));
        system("cls");
        box();
		box_III();
		gotoxy(40,3);
		printf("AJOUT HOTEL ");
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
		printf("CHAMBRES DISPO     : ");
		gotoxy(10,20);

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
		scanf("%d",&h->nombre_chambre_dispo);
        system("cls");
        gotoxy(20,20);
        printf("hopital ajoute!");


return h;
}
H* initialiserH(){
 H *LH=(H*)malloc(sizeof(H));
 NodeH*h=(NodeH*)malloc(sizeof(NodeH));
int c;

 if(LH==NULL || h==NULL){exit(-1);}
 h->data=*Nouveauhotel();
 h->next=NULL;
 h->prev=NULL;
 LH->head=h;
  return LH;
  }
void ajouterFinH(H*LH){
   /*allouer l'hotel*/
  NodeH *newhotel=(NodeH*)malloc(sizeof(NodeH));
  NodeH*top=LH->head;
  int c;
  if(LH==NULL || newhotel==NULL){exit(-1);}
  newhotel->data=*Nouveauhotel();
  newhotel->next=NULL; // newhotel va être le dernier hotel

  if(LH->head==NULL){
  newhotel->prev=NULL;
  LH->head=newhotel;
  }

  while(top->next!=NULL){

 top=top->next;
 }
 // changer le next du dernier hotel
 top->next=newhotel;
 // mettre le dernier hotel comme prev de newhotel
 newhotel->prev=top;
 }
void Afficherhotel(hotel h, int i){

	   gotoxy(3,i);
       printf(" %s",h.nom);
       gotoxy(21,i);
       printf(" %s",h.Adresse.ville);
       gotoxy(38,i);
       printf(" %d",h.Adresse.codepostal);
       gotoxy(57,i);
       printf(" %s",h.Adresse.commune);
       gotoxy(76,i);
       printf(" %s",h.Adresse.adresse);
       gotoxy(108,i);
       printf(" %d",h.nombre_chambre_dispo);
       gotoxy(5,i+1);


}
void Fichehotel(hotel h){

system("cls");
        gotoxy(40,3);
        box();
		box_III();
		gotoxy(40,3);
		printf("FICHE HOTEL");
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
		printf("NOMBRE DE CHAMBRES : ");
		gotoxy(33,8);
        printf(" %s.", h.nom);
        gotoxy(82,8);
		printf(" %s.",h.Adresse.adresse);
		gotoxy(33,12);
		printf(" %s.",h.Adresse.commune);
		gotoxy(82,12);
		printf(" %s.",h.Adresse.ville);
        gotoxy(33,16);
        printf(" %d.",h.Adresse.codepostal);
		gotoxy(82,16);
        printf(" %d.",h.nombre_chambre_dispo);
		gotoxy(33,20);
  }
void afficherH(H LH){
  NodeH*tmp=LH.head;
  system("cls");
	   I_box();
	   box_IV();
	   gotoxy(60,3);
	   printf("LISTE");
	   gotoxy(58,4);
	   printf("DES HOTELS");
       gotoxy(3,9);
       printf("===================================================================================================================");
	   gotoxy(4,10);
	   printf("NOM               VILLE            CODEPOSTAL         COMMUNE            ADRESSE                       NOMBRE ");
	   gotoxy(103,11);
	   printf("DE CHAMBRES");
	   gotoxy(3,12);
	   printf("===================================================================================================================");
  int i=14;
  while(tmp!=NULL){
  Afficherhotel(tmp->data,i);
  tmp=tmp->next;
  i=i+2;
  }
  }
void supprimerhotel(H *LH, NodeH*H){
 NodeH*next;
 NodeH*prev;
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
NodeH* rechercherhoteldispoetproche(H *LH,int cp){
NodeH*tmp=LH->head;

while(tmp!=NULL){
        if(tmp->data.nombre_chambre_dispo>0){
            return tmp;
        }
    tmp=tmp->next;
}
if(tmp==NULL){
    printf("erreur");
}
}
void Afichage_HopitalDispo(H *LH, int cp){
  NodeH*tmp=LH->head;
  system("cls");


  while(tmp!=NULL){

            if(tmp->data.nombre_chambre_dispo>0){
                    Fichehotel(tmp->data);
                    gotoxy(10,24);
                    printf("Appuyez sur n'importe quelle touche pour continuer.");
                    getch();}
            }

  tmp=tmp->next;


  if(tmp==NULL){
  printf("ERREUR.");}
  }
