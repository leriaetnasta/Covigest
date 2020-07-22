#include"personneq.c"
personnehotel* NOM_Prenom_HOTEL(LDCQ* LQ,H*LH){

  personnehotel* Ph= malloc(sizeof(personnehotel));
  char nom[15],prenom[15],CIN[10],R[3];
  int c;
  if(Ph==NULL){
  exit(-1);
  }
  system("cls");

    Covigest_border();
	gotoxy(41,11);
    printf("Cette interface propose l'hotel qui");
    gotoxy(41,13);
    printf("est a la fois proche et disponible");
    gotoxy(30,20);
    printf("Donner la CIN de la personne.");
    gotoxy(30,22);
    scanf("%s",&CIN);
    NodeQ* P;
    P=personnehotel_CIN(LQ,CIN);
    if(P!=NULL){
  NodeH *hot=rechercherhoteldispoetproche(LH,P->data.Adresse.codepostal);
  strcpy(Ph->nom,P->data.nom);
  strcpy(Ph->prenom,P->data.prenom);
  Fichehotel(hot->data);
  if(hot!=NULL){
  strcpy(Ph->hotel,hot->data.nom);}

  else if(hot==NULL){
        Afichage_HopitalDispo(LH, P->data.Adresse.codepostal);
        gotoxy(10,26);
        printf("Entrer un hotel.");
       // debut: pour que fgets fonctionne apres scanf
        do{
        c = getchar();
        }while(c != EOF && c != '\n'); // fin
        fgets(Ph->hotel,sizeof(Ph->hotel),stdin);
  }  }
  if(P==NULL){
  printf("Le CIN que vous avez entre(e) ne correspond a aucune personne. \n");
  exit(-1);}


  return Ph;

   }
PQH* initialiserDATA_NOMPRENOMHOTEL(LDCQ* LQ,H*LH){
  PQH *Ph=(PQH*)malloc(sizeof(PQH));
  ElementPQH*E=(ElementPQH*)malloc(sizeof(ElementPQH));

  if(Ph==NULL || E==NULL){exit(-1);}

  E->data=*NOM_Prenom_HOTEL(LQ,LH);
  E->next=NULL;
  E->prev=NULL;
  Ph->head=E;
  return Ph;}
void Affecter_PerQ_HOTEL_(LDCQ* LQ,PQH*LH){ // cette fonction affect une personne a un hotel, elle fait appel a la fct nomprenomhotel


  ElementPQH *new_node=(ElementPQH*)malloc(sizeof(ElementPQH));
  ElementPQH*last=LH->head;

  if(LH==NULL || new_node==NULL){exit(-1);}
  new_node->data=*NOM_Prenom_HOTEL(LQ,LH);
  new_node->next=NULL; // new_node va être le dernier noeud

  // si la liste est vide , --> mettre le new_node comme head

  if(LH->head==NULL){
  new_node->prev=NULL;
  LH->head=new_node;
  }
  // else traverser jusqu'au dernier noeud;

  while(last->next!=NULL){

  last=last->next;
  }
  // changer le next du dernier noeud
  last->next=new_node;
  // mettre le dernier noeud comme prev de new_node

  new_node->prev=last;
  }
void AfficherunepersonneQthotel(personnehotel Ph){

    printf("La personne %s %s est dans l'hotel %s.",Ph.nom, Ph.prenom,Ph.hotel);

  }
void affichertoutlespersonnesQHotel(PQH LPH){
  ElementPQH*tmp=LPH.head;
  ElementPQH* last;

  while(tmp!=NULL){
  AfficherunepersonneQthotel(tmp->data);
  tmp=tmp->next;
  }
  getch();
  }
void Rechercher_personne_hotel(PQH LPH,personneQ p){ // cette fonction recherche une personne en particulier
  ElementPQH*tmp=LPH.head;
  int i=0;
  while(tmp!=NULL){
        if(stricmp(p.nom,tmp->data.nom)&&stricmp(p.prenom,tmp->data.prenom)){
        AfficherunepersonneQthotel(tmp->data);i++; getch();}
  tmp=tmp->next;
  }
  if(tmp==NULL && i==0){
        gotoxy(10,10);
    printf("%s %s ne figure pas dans la liste de personne confine a un hotel.",p.nom,p.prenom);
    getch();
  }

  }
