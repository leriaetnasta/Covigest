#include"hopitaux.h"
#include"maladie.c"
#include"contact.c"
patient* Nouveaupatient(){

            int n,c,np;
        char reponse[3],b[3],e[10],g[1] ;
        patient *p=malloc(sizeof(patient));

		system("cls");
		box();
		box_III();
		gotoxy(40,3);
		printf("AJOUT PATIENT ");
		gotoxy(10,8);
		printf("NOM         : ");
		gotoxy(59,8);
		printf("PRENOM      : ");
		gotoxy(10,12);
		printf("CIN         : ");
		gotoxy(59,12);
		printf("GENRE       : ");
		gotoxy(10,16);
		printf("ADRESSE     : ");
		gotoxy(59,16);
		printf("COMMUNE     : ");
		gotoxy(10,20);
		printf("VILLE       : ");
		gotoxy(59,20);
		printf("CODE POSTAL : ");
		gotoxy(10,24);
		printf("AGE         : ");

		gotoxy(33,8);
        scanf("%s",&p->nom);
        gotoxy(82,8);
		scanf("%s",&p->prenom);
		gotoxy(33,12);
		scanf("%s",&p->CIN);
		gotoxy(82,12);
		scanf("%s",&g);
		if (g[0]=='F'||g[0]=='f'){ p->genre=true;}
        else {p->genre=false;}


		 GetLocalTime(&p->consultation);
// debut: pour que fgets fonctionne apres scanf
        do{
        c = getchar();
        }while(c != EOF && c != '\n');

        // fin

        gotoxy(33,16);
		fgets(p->Adresse.adresse, sizeof(p->Adresse.adresse), stdin);
		gotoxy(82,16);
		fgets(p->Adresse.commune, sizeof(p->Adresse.commune), stdin);
		gotoxy(33,20);
		scanf("%s",&p->Adresse.ville);
		gotoxy(82,20);
		scanf("%d",&p->Adresse.codepostal);
		gotoxy(33,24);
		scanf("%d",&p->age);
		//maladies
		invalid:
		gotoxy(10,26);
		printf("De combien de maladies chroniques le patient souffre-t-il?");
		gotoxy(77,26);
        scanf("%d",&n);
        L*LD=NULL;
        gotoxy(12,27);
            if(n==0){
            p->L.top=NULL;}

            if(n==1){
            LD=initialiserLmd();
            p->L=*LD;}

            if(n==2){
            LD=initialiserLmd();
            gotoxy(12,28);
            ajouterFin(LD);
            p->L=*LD;
}

            if(n==3){
            LD=initialiserLmd();
            gotoxy(12,28);
            ajouterFin(LD);
            gotoxy(12,29);
            ajouterFin(LD);
            p->L=*LD;
}
            if(n>3){
            printf("Impossible d'entrer plus que 3 maladies chroniques.");
            goto invalid;

} //fin  maladie

//contact
        gotoxy(10,30);
        printf("Le patient etait-il en contact direct avec quelqu'un?");
        gotoxy(66,30);
        scanf("%s",reponse);

        C*LC=NULL;
        if (reponse[0]=='o'||reponse[0]=='O'){


        gotoxy(10,31);
		printf("Avec combien de personnes ? ");
		gotoxy(38,31);
        scanf("%d",&np);

        if(np!=0){
        for(int i=0;i<np;i++)
        {

        gotoxy(12,32);
        if(i==0){
        LC=initialiserLContact();

        }else{
            gotoxy(12,32+i);
        ajouterCONTACTFin(LC);

        }
        }
        p->C=*LC;}
  }
  else
  {
      p->C.top=NULL;

  } //fin  info contact

        gotoxy(12,38);
        //contamination
        printf("La contamination a-t-elle ete introduite ?  [Oui/Non] \n");
        gotoxy(72,38);
        scanf("%s",b);
        if (b[0]=='o'||b[0]=='O'){ p->contintroduite=true;}
        else {p->contintroduite=false;}
        //FIN:nature de contamination


        //etat du patient
        gotoxy(12,39);
        printf("Quel est l'etat du patient? [Normal/Critique]   \n ");
        gotoxy(72,39);
        scanf("%s",e);
        if (e[0]=='N'||e[0]=='n'){ p->etat=true;}
        else {p->etat=false;}
        gotoxy(50,42);
        printf("Patient ajoute.");


return p;

}
void Afficherpatient(patient p,int i){
    char ch;

	   gotoxy(3,i);
       printf(" %s",p.nom );
       gotoxy(13,i);
       printf(" %s",p.prenom);
       gotoxy(24,i);
       printf(" %d",p.age);
       gotoxy(32,i);
       if(p.genre==1){printf("Femme");}else{printf("Homme");}
       gotoxy(38,i);
       printf(" %s",p.CIN);
       gotoxy(47,i);
       printf(" %s",p.Adresse.ville);
       gotoxy(58,i);
       printf(" %d",p.Adresse.codepostal);
       gotoxy(72,i);
       printf(" %s",p.Adresse.commune);
       gotoxy(84,i);
       if(p.contintroduite==1)
        {
        printf("INTRODUITE");
        }else
        {
      printf("  LOCAL");
        }
        gotoxy(97,i);
        if(p.etat==1)
        {
      printf(" NORMAL");
        }else
        {
      printf("CRITIQUE");
        }
       gotoxy(106,i);
       printf(" %d/%d/%d",p.consultation.wDay,p.consultation.wMonth,p.consultation.wYear);


}
void Fichepatient(patient p){
        system("cls");
        gotoxy(40,3);
        box();
		box_III();
		gotoxy(40,3);
		printf("FICHE PATIENT");
		gotoxy(10,8);
		printf("NOM         : ");
		gotoxy(59,8);
		printf("PRENOM      : ");
		gotoxy(10,12);
		printf("CIN         : ");
		gotoxy(59,12);
		printf("GENRE       : ");
		gotoxy(10,16);
		printf("ADRESSE     : ");
		gotoxy(59,16);
		printf("COMMUNE     : ");
		gotoxy(10,20);
		printf("VILLE       : ");
		gotoxy(59,20);
		printf("CODE POSTAL : ");
		gotoxy(10,24);
		printf("AGE         : ");
		gotoxy(33,8);
        printf("%s.", p.nom);
        gotoxy(82,8);
		printf("%s.", p.prenom);
		gotoxy(33,12);
		printf("%s.", p.CIN);
		gotoxy(82,12);
		if(p.genre==1){printf("Femme.");}else{printf("Homme.");}
        gotoxy(33,16);
        printf("%s.", p.Adresse.adresse);
		gotoxy(82,16);
        printf("%s.", p.Adresse.commune);
		gotoxy(33,20);
		printf("%s.", p.Adresse.ville);
		gotoxy(82,20);
		printf("%d.", p.Adresse.codepostal);
		gotoxy(33,24);
		printf("%d.", p.age);
		gotoxy(10,26);
		afficherLDC(p.L);
		gotoxy(59,26);
        afficherLContact(p.C);
        gotoxy(12,33);
        if(p.contintroduite==1)
        {
      printf("CONTAMINATION :  INTRODUITE. ");
        }else
        {
      printf("CONTAMINATION :   LOCAL.  ");
        }
        gotoxy(12,35);

        if(p.etat==1)
        {
      printf("ETAT DU PATIENT :  NORMAL. ");
        }else
         {
      printf("ETAT DU PATIENT : CRITIQUE.  ");
        }
        gotoxy(12,37);
      printf("DATE DU CONSULTATION : %d/%d/%d",p.consultation.wDay,p.consultation.wMonth,p.consultation.wYear);
  getch();

  }
LDC* initialiserLDCP(){
  LDC *LD=(LDC*)malloc(sizeof(LDC));
 NodeP*N=(NodeP*)malloc(sizeof(NodeP));

 if(LD==NULL || N==NULL){exit(-1);}
 N->data=*Nouveaupatient();
 N->next=NULL;
 N->prev=NULL;
 LD->head=N;
  return LD;
  }
void ajouterFinLDC(LDC*LD){
   /*allouer le noeud*/
  NodeP *newnode=(NodeP*)malloc(sizeof(NodeP));
  NodeP*last=LD->head;

  if(LD==NULL || newnode==NULL){exit(-1);}
  newnode->data=*Nouveaupatient(); // mettre les données
  newnode->next=NULL; // new_node va être le dernier noeud

  // si la liste est vide , --> mettre le new_node comme head

  if(LD->head==NULL){
  newnode->prev=NULL;
  LD->head=newnode;
  }
  // else traverser jusqu'au dernier noeud;

  while(last->next!=NULL){

 last=last->next;
 }
 // changer le next du dernier noeud
 last->next=newnode;
 // mettre le dernier noeud comme prev de new_node

 newnode->prev=last;
 }
void afficherLDCP(LDC LD){
    int i=14;
     system("cls");
	   I_box();
	   box_IV();
	   gotoxy(60,3);
	   printf("LISTE");
	   gotoxy(58,4);
	   printf("DES PATIENTS");
       gotoxy(3,8);
       printf("===================================================================================================================");
	   gotoxy(83,9);
       printf("CONTAMINATION   ETAT");
       gotoxy(4,10);
       printf("NOM       PRENOM     AGE    GENRE  CIN      VILLE      CODEPOSTAL    COMMUNE    INTRODUITE    NORMAL  CONSULTATION");
       gotoxy(86,11);
       printf("LOCAL      CRITIQUE");
       gotoxy(3,12);
	   printf("===================================================================================================================");


  NodeP*tmp=LD.head;

  while(tmp!=NULL){

  Afficherpatient(tmp->data, i);
  tmp=tmp->next;
  i=i+2;
  }
getch();
  }
NodeP* recherchepatient_nom(LDC* LD){
  NodeP*tmp=LD->head;

    char nom[20],R[3];
    int i=0;

    if(LD==NULL){ exit(-1);}

    system("cls");
    box();
    gotoxy(30,12);
    printf("ENTRER LE NOM :");
    gotoxy(45,12);
    scanf("%s",&nom);

    while(tmp!=NULL)
    {

    if(stricmp(tmp->data.nom,nom)==0)
      {
        return tmp;
        i++;
      }

      tmp=tmp->next;
    }

    if(tmp==NULL && i==0)
    {
    gotoxy(10,14);
    printf("LE PATIENT NE FIGURE PAS DANS LA LISTE.");
    gotoxy(10,16);
    printf("VOULEZ-VOUS L'AJOUTER ? [Oui/Non]");
    gotoxy(50,16);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')

    {
        ajouterFinLDC(LD);
    }

    }
    gotoxy(10,18);
    printf("VOULEZ-VOUS EFFECTUER UNE AUTRE RECHERCHE ?  [Oui/Non]");
    gotoxy(76,18);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')
    {
    menu_recherche_patient(LD);
    }

    else
    {
    menu_utilisateur();
    }
  return NULL;
  }
NodeP* recherchepatient_age(LDC* LD){
    NodeP*tmp=LD->head;

    int age,i=0;
    char R[3];

    if(LD==NULL){ exit(-1);}

    system("cls");
    box();
    gotoxy(30,12);
    printf("ENTRER L'AGE :");
    gotoxy(45,12);
    scanf("%d",&age);

    while(tmp!=NULL)
    {

    if(tmp->data.age==age)
      {
        return tmp;
        i++;
      }

      tmp=tmp->next;
    }

    if(tmp==NULL && i==0)
    {
    gotoxy(10,14);
    printf("LE PATIENT NE FIGURE PAS DANS LA LISTE.");
    gotoxy(10,16);
    printf("VOULEZ-VOUS L'AJOUTER ? [Oui/Non]");
    gotoxy(50,16);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')

    {
        ajouterFinLDC(LD);
    }

    }
    gotoxy(10,18);
    printf("VOULEZ-VOUS EFFECTUER UNE AUTRE RECHERCHE ?  [Oui/Non]");
    gotoxy(76,18);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')
    {
    menu_recherche_patient(LD);
    }

    else
    {
    menu_utilisateur();
    }
  return NULL;
  }
NodeP* recherchepatient_maladie(LDC* LD){
   NodeP*tmp=LD->head;

   int i=0;
   char nom[20],R[3];

   if(LD==NULL){printf("-1"); exit(-1);}

   system("cls");
   box();
   gotoxy(30,12);
   printf("ENTRER LA MALADIE :   ");
   gotoxy(55,12);
   scanf("%s",&nom);
   while(tmp!=NULL){
        maladie *aide=tmp->data.L.top;
    if(aide!=NULL){
            while(aide!=NULL){
                if(stricmp(aide->nom,nom)==0){
                    return tmp;
                    i++;
                }
                aide=aide->next;
            }
            }
            tmp=tmp->next;
      }if(tmp==NULL && i==0)
    {
    gotoxy(10,14);
    printf("LE PATIENT NE FIGURE PAS DANS LA LISTE.");
    gotoxy(10,16);
    printf("VOULEZ-VOUS L'AJOUTER ? [Oui/Non]");
    gotoxy(50,16);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')

    {
        ajouterFinLDC(LD);
    }

    }
    gotoxy(10,18);
    printf("VOULEZ-VOUS EFFECTUER UNE AUTRE RECHERCHE ?  [Oui/Non]");
    gotoxy(76,18);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')
    {
    menu_recherche_patient(LD);
    }

    else
    {
    menu_utilisateur();
    }
return NULL;
  }
NodeP* recherchepatient_nometprenom(LDC* LD){
  NodeP*tmp=LD->head;
  int i=0;
  char nom[20],prenom[20],R[3];
  if(LD==NULL){ exit(-1);}

    system("cls");
    box();
    gotoxy(30,12);
    printf("ENTRER LE NOM :");
    gotoxy(45,12);
    scanf("%s",&nom);
    gotoxy(30,14);
    printf("ENTRER LE PRENOM :");
    gotoxy(50,14);
    scanf("%s",&prenom);

    while(tmp!=NULL)
    {

    if(stricmp(tmp->data.nom,nom)==0 && stricmp(tmp->data.prenom,prenom)==0)
    {

        return tmp;
        i++;
    }
      tmp=tmp->next;
    }

    if(tmp==NULL && i==0)
    {
    gotoxy(10,16);
    printf("LE PATIENT NE FIGURE PAS DANS LA LISTE.");
    gotoxy(10,18);
    printf("VOULEZ-VOUS L'AJOUTER ? [Oui/Non]");
    gotoxy(50,18);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')

    {
        ajouterFinLDC(LD);
    }

    }
    gotoxy(10,20);
    printf("VOULEZ-VOUS EFFECTUER UNE AUTRE RECHERCHE ?  [Oui/Non]");
    gotoxy(66,20);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')
    {
    menu_recherche_patient(LD);
    }

    else
    {
    menu_utilisateur();
    }
  return NULL;
  }
NodeP* recherchepatient_nometprenometage(LDC* LD){
  NodeP*tmp=LD->head;
  int i=0, age;
  char nom[20],prenom[20],R[3];
  if(LD==NULL){ exit(-1);}
    system("cls");
    box();
    gotoxy(30,12);
    printf("ENTRER LE NOM :");
    gotoxy(47,12);
    scanf("%s",&nom);
    gotoxy(30,14);
    printf("ENTRER LE PRENOM :");
    gotoxy(49,14);
    scanf("%s",&prenom);
    gotoxy(30,16);
    printf("ENTRER L'AGE :");
    gotoxy(45,16);
    scanf("%s",&age);

    while(tmp!=NULL)
    {
    if(stricmp(tmp->data.nom,nom)==0 && stricmp(tmp->data.prenom,prenom)==0 && tmp->data.age==age)
    {
        return tmp;
        i++;
    }
      tmp=tmp->next;
    }if(tmp==NULL && i==0)
    {
    gotoxy(10,20);
    printf("LE PATIENT NE FIGURE PAS DANS LA LISTE.");
    gotoxy(10,22);
    printf("VOULEZ-VOUS L'AJOUTER ? [Oui/Non]");
    gotoxy(50,22);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')

    {
        ajouterFinLDC(LD);
    }

    }
    gotoxy(10,24);
    printf("VOULEZ-VOUS EFFECTUER UNE AUTRE RECHERCHE ?  [Oui/Non]");
    gotoxy(66,24);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')
    {
    menu_recherche_patient(LD);
    }

    else
    {
    menu_utilisateur();
    }
  return NULL;
  }
NodeP* recherchepatient_CIN(LDC *LD){
  NodeP*tmp=LD->head;
  char CIN[10],R[3];
  int i=0;
  if(LD==NULL){ exit(-1);}

    system("cls");
    box();
    gotoxy(30,12);
    printf("ENTRER LE CIN :");
    gotoxy(48,12);
    scanf("%s",&CIN);
    while(tmp!=NULL)
    {
        if(stricmp(tmp->data.CIN,CIN)==0)
        {
            return tmp;
        }
       tmp=tmp->next;
    }
  if(tmp==NULL && i==0)
    {
    gotoxy(10,14);
    printf("LE PATIENT NE FIGURE PAS DANS LA LISTE.");
    gotoxy(10,16);
    printf("VOULEZ-VOUS L'AJOUTER ? [Oui/Non]");
    gotoxy(50,16);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')

    {
        ajouterFinLDC(LD);
    }

    }
    gotoxy(10,18);
    printf("VOULEZ-VOUS EFFECTUER UNE AUTRE RECHERCHE ?  [Oui/Non]");
    gotoxy(76,18);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')
    {
    menu_recherche_patient(LD);
    }

    else
    {
    menu_utilisateur();
    }
  return NULL;
  }
NodeP* recherchepatient_genreetage(LDC* LD){
  NodeP*tmp=LD->head;
  int i=0,age;
  char g[3],R[3];
  bool genre;
  if(LD==NULL){ exit(-1);}
  system("cls");
    box();
    gotoxy(30,12);
    printf("ENTRER LE GENRE :");
    gotoxy(50,12);
    scanf("%s",&g);
    if (g[0]=='F'||g[0]=='f'){ genre=true;}
    else {genre=false;}
    gotoxy(30,12);
    printf("ENTRER L'AGE :");
    gotoxy(50,12);
    scanf("%d",&age);

    while(tmp!=NULL){
    if(tmp->data.genre==genre && tmp->data.age==age){
        return tmp;
        i++;
      }
      tmp=tmp->next;
    }
    if(tmp==NULL && i==0)
    {
    gotoxy(10,14);
    printf("LE PATIENT NE FIGURE PAS DANS LA LISTE.");
    gotoxy(10,16);
    printf("VOULEZ-VOUS L'AJOUTER ? [Oui/Non]");
    gotoxy(50,16);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')

    {
        ajouterFinLDC(LD);
    }

    }
    gotoxy(10,18);
    printf("VOULEZ-VOUS EFFECTUER UNE AUTRE RECHERCHE ?  [Oui/Non]");
    gotoxy(76,18);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')
    {
    menu_recherche_patient(LD);
    }

    else
    {
    menu_utilisateur();
    }
  return NULL;
  }
void patient_etatnormal(LDC* LD){
  NodeP*tmp=LD->head;
  char nom[20],R[3];
  int i=0,j=16;
  if(LD==NULL){ exit(-1);}
    system("cls");
    box();
    gotoxy(30,12);
    printf("LISTES DES PATIENTS EN ETAT NORMAL :");
    while(tmp!=NULL){
    if(tmp->data.etat==1){
            gotoxy(40,j);
            printf("NOM COMPLET : ");
            gotoxy(50,j);
            printf(" %s %s.",tmp->data.nom,tmp->data.prenom);
            i++;
            j++;
      }
      tmp=tmp->next;
     }
     if(tmp==NULL && i==0)
     {
     gotoxy(30,16);
     printf("AUCUN PATIENT EN ETAT NORMAL.");}
     else
     {
     gotoxy(10,++j);
     printf("Avez-vous besoin de plus d'information sur un de ces patients ? [Oui/Non]");
     gotoxy(70,++j);
     scanf("%s",R);
     if (R[0]=='o'||R[0]=='O')
     {
     NodeP* node=recherchepatient_nometprenom(LD);
     Fichepatient(node->data);
     }
     }
     menu_utilisateur();

    }
void patient_etatcritique(LDC* LD){
  NodeP*tmp=LD->head;
  char nom[20],R[3];
  int i=0,j=16;
  if(LD==NULL){ exit(-1);}
    system("cls");
    box();
    gotoxy(30,12);
    printf("LISTES DES PATIENTS EN ETAT NORMAL :");
    while(tmp!=NULL){
    if(tmp->data.etat==0){
            gotoxy(40,j);
            printf("NOM COMPLET : ");
            gotoxy(50,j);
            printf(" %s %s.",tmp->data.nom,tmp->data.prenom);
            i++;
            j++;
      }
      tmp=tmp->next;
     }
     if(tmp==NULL && i==0)
     {
     gotoxy(30,16);
     printf("AUCUN PATIENT EN ETAT NORMAL.");}
     else
     {
     gotoxy(10,++j);
     printf("Avez-vous besoin de plus d'information sur un de ces patients ? [Oui/Non]");
     gotoxy(70,++j);
     scanf("%s",R);
     if (R[0]=='o'||R[0]=='O')
     {
     NodeP* node=recherchepatient_nometprenom(LD);
     Fichepatient(node->data);
     }
     }
     menu_utilisateur();
  }
void supprimerpatient(LDC *LD, NodeP*P){
 NodeP*next;
 NodeP*prev;
 if(LD==NULL || P==NULL){exit(-1);}
 if(LD->head==P){
 LD->head=P->next;
 }
 if(P->next!=NULL){
 next=P->next;
 next->prev=P->prev;
 }
 if(P->prev!=NULL)
 prev=P->prev;
 prev->next=P->next;
 free(&P->data);
 free(P);
 }
void modification_etat_patient(LDC *LD){
  system("cls");
    char etat[20];
    box();
    gotoxy(30,12);
    printf("ENTRER L'ETAT ACTUEL DU PATIENT:   [Critique/Normal/Mort/Gueri]");
    gotoxy(30,13);
    scanf("%s",&etat);
    if(etat[0]=='G' ||etat[0]=='g'){
    NodeP *node=recherchepatient_nometprenom(LD);
    gotoxy(30,16);
    printf("MODIFICATION D'ETAT DU PATIENT %s %s.",node->data.nom,node->data.prenom);
    supprimerpatient(LD, node);
    gotoxy(30,18);
    printf("Le patient a ete supprime de la liste de patients.");
    getch();
    }
    if (etat[0]=='M'||etat[0]=='m'){
    NodeP *node=recherchepatient_nometprenom(LD);
    gotoxy(30,16);
    printf("MODIFICATION D'ETAT DU PATIENT %s %s.",node->data.nom,node->data.prenom);
    supprimerpatient(LD, node);
    gotoxy(40,18);
    printf("Le patient a ete supprime de la liste de patients.");
    getch();
    }
    if (etat[0]=='N'||etat[0]=='n'){
    NodeP *node=recherchepatient_nometprenom(LD);
    printf("MODIFICATION D'ETAT DU PATIENT %s %s. ",node->data.nom,node->data.prenom);
        node->data.etat=true;
    gotoxy(40,18);
    printf("ETAT MODIFIE AVEC SUCCES");
        getch();
    }
    if (etat[0]=='C'||etat[0]=='c'){
    NodeP *node=recherchepatient_nometprenom(LD);
    gotoxy(30,16);
    printf("MODIFICATION D'ETAT DU PATIENT %s %s. ",node->data.nom,node->data.prenom);
        node->data.etat=false;
    gotoxy(40,18);
    printf("ETAT MODIFIE AVEC SUCCES");
        getch();
    }
    system("cls");

}
NodeP* patienthopital_CIN(LDC* LD,char CIN[10]){
  NodeP*tmp=LD->head;
  int i=0, a;
  char R[3],x[10];
  if(LD==NULL){ exit(-1);}
  while(tmp!=NULL){
    strcpy(x,tmp->data.CIN);
    a=stricmp(x,CIN);
    if(a==0){
        return tmp;
        i=15;
      }
      tmp=tmp->next;
  }
  if(tmp==NULL && i==0){
  printf("ERREUR.");}
  return NULL;
  }
/*NO* affectation_patient(LDC LD, LDCH *LH){

  NodeP*tmp=LD.head;
  NO *LN=NULL;
  int track=0;

  while(tmp!=NULL){
  LN=affectation(LH,tmp->data,track);
  tmp=tmp->next;
  track++;
  }
return LN;
}*/
