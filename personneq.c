#include"hopitaux.h"
#include"hotel.c"
//**************************************Ajouter personneQ******************************************************//
personneQ* NouveaupersonneQ(){

            int n,c,np;
        char reponse[3],b[3],e[10],g[1] ;
        personneQ *p=malloc(sizeof(personneQ));
 GetLocalTime(&p->debut);
 GetLocalTime(&p->FIN);
		system("cls");
		box();
		box_III();
		gotoxy(40,3);
		printf("AJOUT PERSONNE");
		gotoxy(40,4);
		printf("EN QUARANTAINE");
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
            printf("                                                   ");
            goto invalid;

} //fin  maladie

//contact
        gotoxy(10,30);
        printf("La personne etait-elle en contact direct avec quelqu'un?");
        gotoxy(66,30);
        scanf("%s",reponse);

        C*LC=NULL;
        if (reponse[0]=='o'||reponse[0]=='O'){


        gotoxy(10,31);
		printf("Avec combien de personnes ? ");
		gotoxy(38,31);
        scanf("%d",&np);

        if(np!=0){ for(int i=0;i<np;i++)
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
        gotoxy(50,42);
        printf("Personne ajoute.");


return p;

}
/*personneQ* NouveaupersonneQ(){

      int n,c,np;
      char reponse[3],b[3],e[10],g[1] ;
 personneQ *p=malloc(sizeof(personneQ));
 printf("              FICHE :  \n");
 printf("\033[34m             -----------  \033[0m ");
 printf("\033[34m\n\n\tDonner le nom.\033[0m\n");
 printf("\033[34m      ->\033[0m"); scanf("%s",&p->nom);
  printf("\033[34m\n\n\tDonner le prenom.\033[0m\n");
 printf("\033[34m      ->\033[0m"); scanf("%s",&p->prenom);
 printf("\033[34m\n\n\tDonner le genre.\033[0m [\033[34mH\033[0m/\033[34mF\033[0m] \n");
 printf("\033[34m      ->\033[0m"); scanf("%s",&g);
 if (g[0]=='F'||g[0]=='f'){ p->genre=true;}
 else {p->genre=false;}
 printf("\033[34m\n\n\tDonner le CIN.\033[0m\n");
 printf("\033[34m      ->\033[0m"); scanf("%s",&p->CIN);
 GetLocalTime(&p->debut);
 GetLocalTime(&p->FIN);
 // debut: pour que fgets fonctionne apres scanf
        do{
        c = getchar();
        }while(c != EOF && c != '\n'); // fin

 printf("\033[34m\n\n\tDonner l'adresse.\033[0m\n");
 printf("\033[34m      ->\033[0m"); fgets(p->Adresse.adresse, sizeof(p->Adresse.adresse), stdin);
 printf("\033[34m\n\n\tDonner la commune.\033[0m\n");
 printf("\033[34m      ->\033[0m"); fgets(p->Adresse.commune, sizeof(p->Adresse.commune), stdin);
 printf("\033[34m\n\n\tDonner la ville.\033[0m\n");
 printf("\033[34m      ->\033[0m"); scanf("%s",&p->Adresse.ville);
  printf("\033[34m\n\n\tDonner le code postal.\033[0m\n");
 printf("\033[34m      ->\033[0m"); scanf("%d",&p->Adresse.codepostal);
 printf("\033[34m\n\n\tDonner l'age.\033[0m\n");
 printf("\033[34m      ->\033[0m"); scanf("%d",&p->age);
 printf("\033[34m\n\n\t De combien de maladies chroniques la personne souffre-t-il?\033[0m\n");
 printf("\033[34m      ->\033[0m"); scanf("%d",&n);
L*LD=NULL;

if(n==0){
    p->L.top=NULL;
}
if(n==1){
    LD=initialiserLmd();
    p->L=*LD;
}
if(n==2){
    LD=initialiserLmd();
    ajouterFin(LD);
    p->L=*LD;
}

if(n==3){
    LD=initialiserLmd();
    ajouterFin(LD);
    ajouterFin(LD);
    p->L=*LD;
}
if(n>3){
    printf("\033[34m\n\n\t Impossible d'entrer plus que 3 maladies chroniques par personne.\033[0m\n");
}
 //fin  maladie
//debut: contact


     printf(" \n");
     printf("\033[34m\n\n\t La personne etait-il en contact direct avec quelqu'un?\033[0m\n");
     printf("\033[34m      ->\033[0m"); scanf("%s",reponse);

     C*LC=NULL;

	if (reponse[0]=='o'||reponse[0]=='O'){



		printf("\033[34m\n\n\t Avec combien de personnes ? \033[0m\n");
        printf("\033[34m      ->\033[0m"); scanf("%d",&np);

   if(np!=0){ for(int i=0;i<np;i++)
        {



        if(i==0){
        LC=initialiserLContact();
        }else{
        ajouterCONTACTFin(LC);


        }
        }
        p->C=*LC;}
  }
  else
  {
      p->C.top=NULL;

  } //fin  info contact
//contamination
        printf("\033[34m\n\n\t La contamination a-t-elle ete introduite ? \033[0m  [\033[34mOui\033[0m/\033[34mNon\033[0m] \n");
        printf("\033[34m      ->\033[0m");scanf("%s",b);
 if (b[0]=='o'||b[0]=='O'){ p->contintroduite=true;}
 else {p->contintroduite=false;}
//FIN:nature de contamination



return p;
}*/
LDCQ* initialiserLDCQ(){
  LDCQ *LQ=(LDCQ*)malloc(sizeof(LDCQ));
 NodeQ*N=(NodeQ*)malloc(sizeof(NodeQ));

 if(LQ==NULL || N==NULL){exit(-1);}

 N->data=*NouveaupersonneQ();
 N->next=NULL;
 N->prev=NULL;
 LQ->head=N;
  return LQ;
  }
void ajouterFinLDCQ(LDCQ*LQ){
   /*allouer le noeud*/
  NodeQ *newnode=(NodeQ*)malloc(sizeof(NodeQ));
  NodeQ*last=LQ->head;

  if(LQ==NULL || newnode==NULL){exit(-1);}
  newnode->data=*NouveaupersonneQ(); // mettre les données
  newnode->next=NULL; // new_node va être le dernier noeud

  // si la liste est vide , --> mettre le new_node comme head

  if(LQ->head==NULL){
  newnode->prev=NULL;
  LQ->head=newnode;
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
void Fichepersonne(personneQ p){
    system("cls");
        gotoxy(40,3);
        box();
		box_III();
		gotoxy(40,3);
		printf("FICHE PERSONNE");
		gotoxy(40,4);
		printf("EN QUARANTAINE");
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
        printf("DATE DEBUT DE CONFINEMENT : %d/%d/%d",p.debut.wDay,p.debut.wMonth,p.debut.wYear);
        gotoxy(12,37);
        printf("DATE FIN DE CONFINEMENT   : %d/%d/%d",p.FIN.wDay+20,p.FIN.wMonth,p.FIN.wYear);
  getch();

  }
void Afficherpersonne(personneQ p,int i){
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
        printf(" %d/%d/%d ",p.debut.wDay,p.debut.wMonth,p.debut.wYear);

        gotoxy(107,i);
        printf(" %d/%d/%d ",p.debut.wDay+20,p.debut.wMonth,p.debut.wYear);

}
void afficherLDCQ(LDCQ LQ){
  NodeQ*tmp=LQ.head;
  int i=14;
  I_box();
	   box_IV();
	   gotoxy(60,3);
	   printf("LISTE");
	   gotoxy(58,4);
	   printf("DES PATIENTS");
       gotoxy(3,8);
       printf("===================================================================================================================");
	   gotoxy(83,9);
       printf("CONTAMINATION");
       gotoxy(4,10);
       printf("NOM       PRENOM     AGE    GENRE  CIN      VILLE      CODEPOSTAL    COMMUNE    INTRODUITE    DEBUT     FIN");
       gotoxy(86,11);
       printf("LOCAL");
       gotoxy(3,12);
	   printf("===================================================================================================================");
  while(tmp!=NULL){

  Afficherpersonne(tmp->data,i);
  tmp=tmp->next;
  i=i+2;
  }
  getch();
  }
NodeQ* Recherchequarantaine_nom(LDCQ *LQ){
  NodeQ*tmp=LQ->head;
  char nom[10],R[3];
  int i=0;
  if(LQ==NULL){ exit(-1);}
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
    printf("LA PERSONNE NE FIGURE PAS DANS LA LISTE.");
    gotoxy(10,16);
    printf("VOULEZ-VOUS L'AJOUTER ? [Oui/Non]");
    gotoxy(50,16);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')

    {
        ajouterFinLDCQ(LQ);
    }

    }
    gotoxy(10,18);
    printf("VOULEZ-VOUS EFFECTUER UNE AUTRE RECHERCHE ?  [Oui/Non]");
    gotoxy(76,18);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')
    {
    menu_recherche_quarantaine(LQ);
    }

    else
    {
    menu_utilisateur();
    }
  return NULL;
  }
NodeQ* Recherchequarantaine_nometprenom(LDCQ* LQ){
  NodeQ*tmp=LQ->head;
  int i=0;
  char nom[20],prenom[20],R[3];
  if(LQ==NULL){ exit(-1);}
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
  while(tmp!=NULL){
    if(stricmp(tmp->data.nom,nom)==0 && stricmp(tmp->data.prenom,prenom)==0){
        return tmp;
        i++;
      }
      tmp=tmp->next;
  }if(tmp==NULL && i==0)
    {
    gotoxy(10,14);
    printf("LA PERSONNE NE FIGURE PAS DANS LA LISTE.");
    gotoxy(10,16);
    printf("VOULEZ-VOUS L'AJOUTER ? [Oui/Non]");
    gotoxy(50,16);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')

    {
        ajouterFinLDCQ(LQ);
    }

    }
    gotoxy(10,18);
    printf("VOULEZ-VOUS EFFECTUER UNE AUTRE RECHERCHE ?  [Oui/Non]");
    gotoxy(76,18);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')
    {
    menu_recherche_quarantaine(LQ);
    }

    else
    {
    menu_utilisateur();
    }
  return NULL;
  }
NodeQ* Recherchequarantaine_CIN(LDCQ *LQ){
  NodeQ*tmp=LQ->head;
  char CIN[10],R[3];
  int i=0;
  if(LQ==NULL){ exit(-1);}
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
    printf("LA PERSONNE NE FIGURE PAS DANS LA LISTE.");
    gotoxy(10,16);
    printf("VOULEZ-VOUS L'AJOUTER ? [Oui/Non]");
    gotoxy(50,16);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')

    {
        ajouterFinLDCQ(LQ);
    }

    }
    gotoxy(10,18);
    printf("VOULEZ-VOUS EFFECTUER UNE AUTRE RECHERCHE ?  [Oui/Non]");
    gotoxy(76,18);
    scanf("%s",R);

    if (R[0]=='o'||R[0]=='O')
    {
    menu_recherche_quarantaine(LQ);
    }

    else
    {
    menu_utilisateur();
    }
  return NULL;
  }
   //**************************************Recherche par maladie******************************************************//
/*void Recherchequarantaine_MALADIE(LDCQ LQ, char maladie){
  NodeQ*tmp=LQ.head;
  while(tmp!=NULL){
      if(tmp1!=NULL){
          maladie *tmp1=tmp->data.L.top;
        while(tmp1!=NULL){
                if(stricmp(tmp1->nom,maladie)==0)
        {Afficherpersonne(tmp->data);}
            tmp1=tmp1->next;
        }
      }

  tmp=tmp->next;
  }
  return NULL;
  }*/
NodeQ* personnehotel_CIN(LDCQ *LQ,char CIN[10]){
  NodeQ*tmp=LQ->head;
  int i=0, a;
  char R[3],x[10];
  if(LQ==NULL){ exit(-1);}
  while(tmp!=NULL){
    strcpy(x,tmp->data.CIN);
    a=stricmp(x,CIN);
    if(a==0){
         printf("2\n");
            Fichepersonne(tmp->data);
        return tmp;
        i++;
      }
      tmp=tmp->next;
  }
  if(tmp==NULL && i==0){
  printf("              ERREUR.   \n");}
  return NULL;
  }
