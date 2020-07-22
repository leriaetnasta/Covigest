#include"patient.c"
patienthopital* data_nump_hopital(LDC* LD,LDCH*LH){

  patienthopital* Ph= malloc(sizeof(patienthopital));
  char nom[15],prenom[15],CIN[10],R[3];
  if(Ph==NULL){
  exit(-1);
  }
    system("cls");

    Covigest_border();
	gotoxy(41,10);
    printf("Cette interface propose l'hopital qui");
    gotoxy(41,12);
    printf("est a la fois proche et disponible");
    gotoxy(41,13);
    printf("en fonction de l'etat du patient.");
    gotoxy(30,20);
    printf("Donner le CIN du patient.");
    gotoxy(60,20);
    scanf("%s",&CIN);
    NodeP* P=patienthopital_CIN(LD,CIN); // recherche s'il exist
    Node_H*H=NULL;
    if(P!=NULL){
    strcpy(Ph->nompatient,P->data.nom);
    strcpy(Ph->prenompatient,P->data.prenom);
    if(P->data.etat==0){H=rechercheHP_CP_L_REA(LH,P->data.Adresse.codepostal); }//critique: cet fct recherche l'hopital le plus proche a l'aide du codepostal + le plus dispo en fctnalite de besoin du patient
    if(P->data.etat==1){H=rechercheHP_CP_L_NORMAL(LH,P->data.Adresse.codepostal);}//normal Même chose ^^^^^^^^^^^^
    if(H!=NULL){ //si la fct précédent a trouvé un hôpital proche + dispo
       strcpy(Ph->nomhopital,H->data.nom);
       gotoxy(10,26);
       printf("Patient enregistre.");}
    else if(H==NULL){// si la fct return NULL cela signifie que la fct précédent n'a pas pu trouver un hôpital à la fois proche et disponible
       if(P->data.etat==0){hopitaux_lisrea_dispo(*LH);}
       if(P->data.etat==1){hopitaux_lisnorm_dispo(*LH);}
       gotoxy(10,26);
       printf("Donner le nom de l'hopital.");
       scanf("%s",Ph->nomhopital);
  }getch();}
  else if(P==NULL){
  printf("Le CIN que vous avez entre(e) n'appartient a aucun patient.");
  getch();
  menu_utilisateur();}


  return Ph; }
PH* initialiserdatapatienthopital(LDC* LD, LDCH* LH){
  PH *Ph=(PH*)malloc(sizeof(PH));
  Element*E=(Element*)malloc(sizeof(Element));

  if(Ph==NULL || E==NULL){exit(-1);}

  E->data=*data_nump_hopital(LD,LH);
  E->next=NULL;
  E->prev=NULL;
  Ph->head=E;
  return Ph;
  }
void Affecter_PATIENT_HOPITAL_(LDC*LD,PH *LPH, LDCH* LH){ // cette fonction affect un patient a un hopital, elle fait appel a la fct datanumphopital


  Element *new_node=(Element*)malloc(sizeof(Element));
  Element*last=LPH->head;

  if(LPH==NULL || new_node==NULL){exit(-1);}
  new_node->data=*data_nump_hopital(LD,LH);
  new_node->next=NULL; // new_node va être le dernier noeud

  // si la liste est vide , --> mettre le new_node comme head

  if(LPH->head==NULL){
  new_node->prev=NULL;
  LPH->head=new_node;
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
void Afficherdataph(patienthopital Ph, int i){
    gotoxy(14,i);
    printf("-Le patient %s %s est dans l'hopital %s.",Ph.prenompatient, Ph.nompatient,Ph.nomhopital);
  }
void afficherListePH(PH LPH){
  Element*tmp=LPH.head;
  Element* last;
  int i=7;
  gotoxy(10,5);
  printf("ce qui suit est une liste de patients qui sont admis dans un hopital");
  while(tmp!=NULL){
  Afficherdataph(tmp->data,i);
  tmp=tmp->next;
  i=i+2;
  }
  if(tmp==NULL&&i==7){
      printf("Erreur: la liste est encore vide");
  }
getch();
  }
void Rechercher_patient_hopital(PH LPH,patient p){ // cette fonction recherche un patient en particulier
  Element*tmp=LPH.head;
  int i=0,j=13;
  while(tmp!=NULL){
        if(stricmp(p.nom,tmp->data.nompatient)==0 && stricmp(p.prenom,tmp->data.prenompatient)==0){
        Afficherdataph(tmp->data,j);j=j+2;i++;}
  tmp=tmp->next;
  }
  if(tmp==NULL && i==0){
    printf("Le patient %s %s n'est pas encore affecte a un hopital, veuillez l'ajouter ulterieurement.",p.nom,p.prenom);
  }

  }
void supprimerpatienthopital(PH *LPH, Element*E){
    Element*next;
    Element*prev;
    if(LPH==NULL || E==NULL){exit(-1);}
    /* si le E est le head*/
    if(LPH->head==E){
    LPH->head=E->next;
    }
    if(E->next!=NULL){
    next=E->next;
    next->prev=E->prev;
    }
    if(E->prev!=NULL)
    prev=E->prev;
    prev->next=E->next;

    free(&E->data);
    free(E);
    }
int compterPATIENTHOPITAL(PH*LPH){
    int cpt=0;
    Element*tmp=LPH->head;

    if(LPH==NULL){exit(-1);}

    while(tmp!=NULL){
    cpt++;
    tmp=tmp->next;
    }
    return cpt;
    }
Element* rechercherhopitaldansHP(PH LPH,char nom[10]){ // cette fonction recherche un patient en particulier
  Element*tmp=LPH.head;
  int i=0;
  while(tmp!=NULL){
        if(stricmp(nom,tmp->data.nomhopital)==0){
        return tmp;i++;}
  tmp=tmp->next;

  }
  if(tmp==NULL && i==0)
  return NULL;
  }
