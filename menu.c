#include"hopitaux.h"
#include"patienthopital.c"
#include"personnehotel.c"
#include"esthetique.c"
void Covigest_start(){
        system("color FB");
        char ch;
do{
        Covigest_border();
		gotoxy(41,10);
        printf("\033[34m Bienvenu sur Covigest");
        gotoxy(41,12);
        printf("Covigest est une application de gestion");
        gotoxy(41,13);
        printf("Des patients porteurs ou suspectes");
        gotoxy(41,14);
        printf("D'etre infectes par le Covid-19.");
        box_I();
        box_II();
        gotoxy(30,17);
        printf("Utilisateur");
        gotoxy(79,17);
        printf("Administrateur");
        gotoxy(99,6);
        printf("Exit(X)");
        gotoxy(35,30);
		printf("Appuyez sur le premier caractere ou sur X pour Quitter.");

		ch=toupper(getche());
		switch(ch)
		{
			case 'U': menu_utilisateur(0);
				 break;
			case 'A': connection();
			          menu_utilisateur(1);
				 break;
			case 'X':gotoxy(23,20);
			printf("Voulez-vous quitter maintenant? O / N :");
			ch=toupper(getche());
			if(ch=='O')
			{
			    gotoxy(20,90);
				exit(-1);
			}
			else
			{
			    system("cls");

			    Covigest_start();
			}

			default:
			gotoxy(15,34);
			alert_requete_invalide();
			getch();}
	}while(ch!='X');


gotoxy(41,60);

}
void affichage_menu_utilisateur(){
system("color F1");
		system("cls");
		gotoxy(16,5);
		printf("1.Patient");
		gotoxy(35,4);
		printf("Personne");
		gotoxy(33,5);
		printf("2.En quarantaine");
		gotoxy(56,5);
		printf("3.Hopital");
		gotoxy(75,5);
		printf("4.Hotel");
		gotoxy(89,5);
		printf("5.Exit");
		main_border();}
void connection(){
system("cls");
char log[10],mdp[10],login[25]="Covigest",MOTDEPASSE[15]="123456789";
int tentatives=0;

do
{
    Covigest_border();
    gotoxy(50,10);
    printf("ME CONNECTER :");
    gotoxy(50,11);
    printf("\033[34m----------------");
    gotoxy(41,12);
    printf("LOGIN:");
	gotoxy(41,13);
    printf("MOT DE PASSE:");
	gotoxy(48,12);
	scanf("%s",&log);
	gotoxy(55,13);
	scanf("%s",&mdp);

	if (stricmp(log,login)==0 && strcmp(mdp,MOTDEPASSE)==0) //stricmp =strcmp+ tolower
	{
	    gotoxy(55,16);
	    printf("LOGIN ET MOT DE PASSE CORRECT. ");
	    gotoxy(55,17);
	    printf("\033[34mREDIRECTION. \n");
	    gotoxy(67,17);
	    for(i=0;i<=6;i++)
        {
            Sleep(300);
            gotoxy(67+i,17);
            printf("\033[34m.");
        }
        //menu admin
		system("cls");
		break;
	}
	else
	{
	    gotoxy(40,17);
	    char buf[1024];
        snprintf(buf, 1024, "IL VOUS RESTE %d TENTATIVES.", 2-tentatives);
        MessageBox(0, buf, "LOGIN OU MOT DE PASSE INCORRECTES", 0);
		tentatives++;
		system("cls");}
    }while(tentatives<=2);

if(tentatives>2)
	{
    printf("\n\n\033[34m              VOUS AVEZ DEPASSE LE NOMBRE DE TENTATIVES. \n");
    printf("\n\033[34m              VEUILLEZ REESSAYER ULTERIEUREMENT.\n");
	Sleep(1000);
    exit(-1);
	}

system("cls");
}
void menu_utilisateur(){

    system("cls");
    int selection,choix=0,in=0,i=0,j=0,k=0,l=0;
    char nom[20],prenom[20], ch;
    LDCQ*LQ; // liste des personnes en quarantaine
    LDC*LD; // liste des patients
    H*LHT; // liste des hotels
    LDCH*LH; // liste des hopitaux
    PH*LPH; // patient-hotel
    NodeQ *pq; // personne en quarantaine
    PQH* LPQH; // personne-hotel
	do
	{
		affichage_menu_utilisateur();

		gotoxy(16,40);
		printf("Entrer votre choix.");
		ch=getche();
		switch(ch)
		{
			case '1':
	//==========================================Case: Patient =====================================================//
			    {system("cls");

                affichage_menu_utilisateur();
			    gotoxy(39,10);
                printf("1.Ajouter");
                gotoxy(39,14);
                printf("2.Liste des patients.");
                gotoxy(39,18);
                printf("3.Rechercher un patient selon des criteres.");
                gotoxy(39,22);
                printf("4.Modification dans l'etat d'un patient.");
                gotoxy(39,28);
                printf("Entrer la selection:");
	    	    gotoxy(59,28);
	    	    selection=getche();

		switch(selection) {
		    case '1': system("cls");
			        if(i==0){ system("cls"); LD=initialiserLDCP();i++;} //Initialiser la liste de patients.
                    else {system("cls"); ajouterFinLDC(LD);} // Ajouter un patient.
			    break;
			case '2': system("cls");
			        afficherLDCP(*LD);//Afficher la liste de patients.
			    break;
            case '3':
                    system("cls");
                    system("color FB");
                    menu_recherche_patient(LD);// menu de recherche P
				break;
			case '4':
                    system("cls");
                    system("color FB");
                    modification_etat_patient(LD);// l'option de changer l'etat + supprimer un patient (si l'etat == mort || == gueri).


                break;
			default:
                    alert_requete_invalide();
                    break;
				}}

				 break;
	//=========================================Fin Patient=====================================================//
			case '2':
	//=========================================Case: Personne en quarantaine=====================================================//
			    {system("cls");
                affichage_menu_utilisateur();
			    gotoxy(30,10);
                printf("1.Ajouter");
                gotoxy(30,14);
                printf("2.Liste des personnes en quarantaine.");
                gotoxy(30,18);
                printf("3.Rechercher une personne en quarantaine selon des criteres.");
                gotoxy(30,22);
                printf("Entrer la selection:");
	    	    gotoxy(59,22);selection=getche();

		switch(selection) {
		    case '1': system("cls");
			        if(l==0) {system("cls"); LQ=initialiserLDCQ();l++;}//Initialiser la liste de pq.
                    else {system("cls"); ajouterFinLDCQ(LQ);}//Ajouter une pq
			    break;
			case '2': system("cls");
			        afficherLDCQ(*LQ);//Afficher la liste de personne en Q
			    break;
            case '3':
                    system("cls");
                    affichage_menu_utilisateur();
                    menu_recherche_quarantaine(LQ); // menu de recherche PQ
				break;
			default:
                    alert_requete_invalide();
                    break;
				}}
				 break;
	//=========================================Fin Personne en quarantaine=====================================================//
			case '3':{
	//===============================================Case: Hopital=====================================================//
			    system("cls");

                affichage_menu_utilisateur();
			    gotoxy(30,10);
                printf("1.Ajouter");
                gotoxy(30,14);
                printf("2.Listes des hopitaux.");
                gotoxy(30,18);
                printf("3.Affecter un patient a un hopital.");
                gotoxy(30,22);
                printf("4.Modification dans les donnees d'un Hopital.");
                gotoxy(30,26);
                printf("5.Consulter la liste des donnees PATIENT-HOPITAL");
                gotoxy(30,30);
                printf("Entrer la selection:");
	    	    gotoxy(59,30);selection=getche();
		switch(selection) {
		    case '1': system("cls");
                    affichage_menu_utilisateur();
			        if(j==0) {system("cls"); LH=initialiserLDCH();j++; } //Initialiser la liste d'hopitaux.
                    else {system("cls"); ajouterFinLDCH(LH);}//Ajouter un nv hopital.
			    break;
			case '2': system("cls");
			        afficherLDCH(*LH);//Afficher la liste d'hopitaux.
			    break;
            case '3':
                    system("cls");
                    affichage_menu_utilisateur();
                    if(in==0)
                    LPH=initialiserdatapatienthopital(LD,LH);//Affectation d’un patient a un hopital.
                    else
                    Affecter_PATIENT_HOPITAL_(LD,LPH,LH);
				break;
			case '4':
                    system("cls");
                    affichage_menu_utilisateur();
                    Modification_hopital(LPH,LH); // supprimer un hopital (si aucun patient n'est affecté a cet hopital) + changer les donnees de l'hopital

                break;
            case '5':
                    system("cls");
                    Menu_patient_hopital(LD,LH,LPH);
                    break;
			default:
                    alert_requete_invalide();
                    break;}
				}
				 break;
  //=================================================Fin Hopital=====================================================//
			case '4':
  //==================================================Case: Hotel==========================================================//
			    {system("cls");

                affichage_menu_utilisateur();
			    gotoxy(30,10);
                printf("1.Ajouter");
                gotoxy(30,14);
                printf("2.Liste des hotels.");
                gotoxy(30,18);
                printf("3.Affectation d'une personne a un hotel.");
                gotoxy(30,22);
                printf("4.Consulter la liste des donnees PERSONNE-HOTEL.");
                gotoxy(30,26);
                printf("Entrer la selection:");
	    	    gotoxy(59,26);selection=getche();
		switch(selection) {
		    case '1': system("cls");
			        if(k==0) {system("cls"); LHT=initialiserH();k++;}//Initialiser la liste d'hotels.
                    else {system("cls"); ajouterFinH(LHT);}// Ajouter un hotel.
			    break;
			case '2': system("cls");
			        afficherH(*LHT);//Afficher la liste d'hotels.
			        getch();
			    break;
            case '3':
                    system("cls");
                    affichage_menu_utilisateur();
                    if(i==0){LPQH=initialiserDATA_NOMPRENOMHOTEL(LQ,LHT);}
                    //Affectation d’une personne a un hotel.
                    else{Affecter_PerQ_HOTEL_(LQ,LH);}
                     // cette fonction affect une personne a un hotel
				break;
			case '4':

                    system("cls");
                    choix=0;
             box();
             box_III();
             gotoxy(38,3);
             printf("PQ-HOTEL");
             gotoxy(30,10);
             printf("1. Afficher les personnes qui sont en quarantaine dans un hotel.");
             gotoxy(30,12);
             printf("2. Rechercher une personne en particulier.");
             gotoxy(30,14);
             scanf("%d", &choix);
                if(choix==1){system("cls"); affichertoutlespersonnesQHotel(*LPQH);}
                if(choix==2){system("cls"); pq=Recherchequarantaine_CIN(LQ);
                Rechercher_personne_hotel(*LPQH,pq->data);}
                break;
			default:
                    alert_requete_invalide();
                    break;}
				}
//======================================================Fin Hotel=====================================================//
				 break;
			case '5':{
            gotoxy(23,20);
			printf("Voulez-vous quitter maintenant? [Oui/Non] ");
			Sleep(100);
			ch=toupper(getche());
			Sleep(1000);
			if(ch=='O')
			{
			    gotoxy(20,90);
				exit(0);
			}
			else
			{
			    system("cls");
				//menu
			}} break;
			default:
			gotoxy(15,34);
			printf("Requete Invalid.");
			getch();}
	}while(ch!='E');
}


void menu(){
    system("cls");
    int selection,choix=0,in=0,i=0,j=0,k=0,l=0;
    char nom[20],prenom[20];
    LDCQ*LQ; // liste des personnes en quarantaine
    LDC*LD; // liste des patients
    H*LHT; // liste des hotels
    LDCH*LH; // liste des hopitaux
    PH*LPH; // patient-hotel
    NodeQ *pq; // personne en quarantaine
    PQH* LPQH; // personne-hotel
while(1) {
             printf("\n                                              o MENU PRINCIPRAL o  \n");
             printf("\033[34m                                              ------------------  \033[0m");
             printf("\n\n\t                         1.\033[34m Ajouter\033[0m");
             printf("\n\n\t                         2.\033[34m Afficher.\033[0m");
             printf("\n\n\t                         3.\033[34m Affectation d'un patient a un hopital. \033[0m");
             printf("\n\n\t                         4.\033[34m Affectation d'une personne a un hotel. \033[0m");
             printf("\n\n\t                         5.\033[34m Rechercher un patient selon des criteres. \033[0m");
             printf("\n\n\t                         6.\033[34m Rechercher une personne en quarantaine selon des criteres. \033[0m");
             printf("\n\n\t                         7.\033[34m Modification dans l'etat d'un patient.\033[0m");
             printf("\n\n\t                         8.\033[34m Modification dans les donnees d'un Hopital. \033[0m");
             printf("\n\n\t                         9.\033[34m Consulter la liste des donnees PATIENT-HOPITAL.  \033[0m");
             printf("\n\n\t                         10.\033[34mConsulter la liste des donnees PERSONNE-HOTEL.  \033[0m");
             printf("\n\n\t                         11.\033[34mQuittez. \033[0m");
	      	 printf("\n\n\t                         Entrer la selection\033[34m:\033[0m");
	    	 printf("\033[34m-\033[0m");scanf("%d", &selection);

		switch(selection) {
			case 1:
			    system("cls");
			    choix=0;
			 printf("\n\n\t                         1.\033[34m Ajouter un patient. \033[0m");
             printf("\n\n\t                         2.\033[34m Ajouter un hopital. \033[0m");
             printf("\n\n\t                         3.\033[34m Ajouter une personne en quarantaine. \033[0m");
             printf("\n\n\t                         4.\033[34m Ajouter un hotel. \033[0m");
             printf("\033[34m\n\n\t                         - \033[0m");scanf("%d", &choix);
             if(choix==1){
                    if(i==0){ system("cls"); LD=initialiserLDCP();i++;} //Initialiser la liste de patients.
                    else {system("cls"); ajouterFinLDC(LD);}} // Ajouter un patient.
             if(choix==2){
                    if(j==0) {system("cls"); LH=initialiserLDCH();j++;WriteListToFile(LH);} //Initialiser la liste d'hopitaux.
                    else {system("cls"); ajouterFinLDCH(LH);}WriteListToFile(LH);}//Ajouter un nv hopital.
             if(choix==3){
                    if(k==0) {system("cls"); LHT=initialiserH();k++;}//Initialiser la liste d'hotels.
                    else {system("cls"); ajouterFinH(LHT);}} // Ajouter un hotel.
             if(choix==4){
                   if(l==0) {system("cls"); LQ=initialiserLDCQ();l++;}//Initialiser la liste de pq.
                   else {system("cls"); ajouterFinLDCQ(LQ);}}//Ajouter une pq
				break;
			case 2:
			    system("cls");
			    choix=0;
			 printf("\n\n\t                         1.\033[34m Afficher la liste des patients.\033[0m");
             printf("\n\n\t                         2.\033[34m Afficher la liste des hopitaux.\033[0m");
             printf("\n\n\t                         3.\033[34m Afficher la liste de personne en quarantaine.\033[0m");
             printf("\n\n\t                         4.\033[34m Afficher la liste des hotel.\033[0m");
             printf("\033[34m\n\n\t                         - \033[0m");scanf("%d", &choix);
			    if(choix==1){system("cls"); afficherLDCP(*LD);}//Afficher la liste de patients.
			    if(choix==2){system("cls"); LH=ReadListIn(LH); afficherLDCH(*LH);}//Afficher la liste d'hopitaux.
			    if(choix==3){system("cls"); afficherLDCQ(*LQ);//Afficher la liste de personne en Q
			    Sleep(5000);}
			    if(choix==4){system("cls"); afficherH(*LHT);}//Afficher la liste d'hotels.
			    break;
            case 3:
			    system("cls");
			    if(in==0)
			    LPH=initialiserdatapatienthopital(LD,LH);//Affectation d’un patient a un hopital.
			    else
                Affecter_PATIENT_HOPITAL_(LD,LPH,LH);
			    break;
			case 4:
			    system("cls");
			    if(i==0)
			    LPQH=initialiserDATA_NOMPRENOMHOTEL(LQ,LH);//Affectation d’une personne a un hotel.
			    else
                Affecter_PerQ_HOTEL_(LQ,LH); // cette fonction affect une personne a un hotel
				break;
            case 5:
                system("cls");
			    menu_recherche_patient(LD);// menu de recherche P
				break;
			case 6:
			    system("cls");
			    menu_recherche_quarantaine(LQ); // menu de recherche PQ
				break;
            case 7:
                system("cls");
                modification_etat_patient(LD); // l'option de changer l'etat + supprimer un patient (si l'etat == mort || == gueri).
				break;
            case 8:
                system("cls");
                Modification_hopital(LPH,LH); // supprimer un hopital (si aucun patient n'est affecté a cet hopital) + changer les donnees de l'hopital
				break;
            case 9:
                system("cls");
				Menu_patient_hopital(LD,LH,LPH);
				break;
            case 10:
                system("cls");
			    choix=0;
             printf("\n\n                                        o DONEES DES PERSONNE EN QUARANTAINE DANS UN HOTEL o  \n");
			 printf("\n\n\t                         1.\033[34m Afficher les personnes qui sont en quarantaine dans un hotel. \033[0m");
             printf("\n\n\t                         2.\033[34m Rechercher une personne en particulier. \033[0m");
             printf("\033[34m\n\n\t                         - \033[0m");scanf("%d", &choix);
                if(choix==1){system("cls"); affichertoutlespersonnesQHotel(*LPQH);}
                if(choix==2){system("cls"); pq=Recherchequarantaine_CIN(LQ);
                Rechercher_personne_hotel(*LPQH,pq->data);}
				break;
            case 11:
				exit(-1);
				break;
			default:
			    printf("\033[34m                         Requete invalide\n\033[0m");}
				}
	return EXIT_SUCCESS;}
void menu_recherche_patient(LDC* LD){
    system("cls");
    system("color FB");
    NodeP* node;
    int choix;
    while(1) {
             box();
             box_III();
             gotoxy(39,3);
             printf("oMENU RECHERCHEo");
             gotoxy(20,10);
             printf("1. Recherche par nom.");
             gotoxy(20,12);
             printf("2. Recherche par nom complet.");
             gotoxy(20,14);
             printf("3. Recherche par age.");
             gotoxy(20,16);
             printf("4. Recherche par genre et age.");
             gotoxy(20,18);
             printf("5. Recherche par nom complet et age.");
             gotoxy(20,20);
             printf("6. Recherche par maladie.");
             gotoxy(20,22);
             printf("7. Recherche par CIN.");
             gotoxy(20,24);
             printf("8. Afficher la liste des patient en etat normal.");
             gotoxy(20,26);
             printf("9. Afficher la liste des patient en etat critique.");
             gotoxy(20,28);
             printf("10.Retour au menu.");
             gotoxy(20,30);
	      	 printf("Entrer la selection :");
	      	 gotoxy(50,30);
	      	 scanf(" %d", &choix);

		switch(choix) {
		    case 1:
			    node=recherchepatient_nom(LD);
                Fichepatient(node->data);
                system("cls");
				break;
			case 2:
                node=recherchepatient_nometprenom(LD);
                Fichepatient(node->data);
                system("cls");
				break;
            case 3:
                node=recherchepatient_age(LD);
                Fichepatient(node->data);
                system("cls");
				break;
			case 4:
                node=recherchepatient_genreetage(LD);
                Fichepatient(node->data);
                system("cls");
            case 5:
                node=recherchepatient_nometprenometage(LD);
                Fichepatient(node->data);
                system("cls");
				break;
			case 6:
			    system("cls");
                node=recherchepatient_maladie(LD);
                Fichepatient(node->data);
                 system("cls");
				break;
            case 7:
                 system("cls");
                node=recherchepatient_CIN(LD);
                Fichepatient(node->data);
                 system("cls");
				break;
            case 8:
			    system("cls");
			    patient_etatnormal(LD);
			     system("cls");
				break;
			case 9:
			    system("cls");
			    patient_etatcritique(LD);
			     system("cls");
			    break;
            case 10:
                system("cls");
                system("color FB");
				menu_utilisateur();
				break;
			default:
			    printf("Requete invalide.");}
				}
	return EXIT_SUCCESS;}
void menu_recherche_quarantaine(LDCQ* LQ){
    system("cls");
    system("color FB");
    NodeQ *p;
    int choix;
    while(1) {
             system("cls");
             box();
             box_III();
             gotoxy(39,3);
             printf("oMENU RECHERCHEo");
             gotoxy(30,10);
             printf("1. Recherche par nom.");
             gotoxy(30,12);
             printf("2. Recherche par nom complet.");
             gotoxy(30,14);
             printf("3. Recherche par CIN.");
             gotoxy(30,16);
             printf("4. Retour au menu.");
             gotoxy(30,18);
	      	 printf("Entrer la selection :");
	      	 gotoxy(50,18);
	      	 scanf(" %d", &choix);
		switch(choix) {
		    case 1:
		        p=Recherchequarantaine_nom(LQ);
		        Fichepersonne(p->data);
				break;
            case 2:
		        p=Recherchequarantaine_nometprenom(LQ);
		        Fichepersonne(p->data);
				break;
            case 3:
		        p=Recherchequarantaine_CIN(LQ);
		        Fichepersonne(p->data);
				break;
            case 4:
				menu_utilisateur();
				break;
			default:
			    printf("\033[34m\n\t                         Requete invalide\n. \033[0m");}
				}
	return EXIT_SUCCESS;}
void Menu_patient_hopital(LDC* LD,LDCH*LH,PH *LPH){
    system("cls");
    NodeP* node;
    int choix;
    char nom[10];
    Element* E;
    while(1) {
            system("cls");
             box();
             box_III();
             gotoxy(38,3);
             printf("oPATIENT-HOPITALo");
             gotoxy(30,10);
             printf("1. Afficher les patients qui sont affecte a un hopital.");
             gotoxy(30,12);
             printf("2. Rechercher un patient en particulier.");
             gotoxy(30,14);
             printf("3. Supprimer un patient de la liste.");
             gotoxy(30,16);
             printf("4. Retour au menu.");
             gotoxy(30,18);
	      	 printf("Entrer la selection :");
	      	 gotoxy(50,18);
	      	 scanf("%d", &choix);

		switch(choix) {
		    case 1:
		         system("cls");
		        afficherListePH(*LPH);
				break;
            case 2:
                node=recherchepatient_CIN(LD);
		        Rechercher_patient_hopital(*LPH,node->data);
		        getch();
				break;
            case 3:
                 system("cls");
                box();
                gotoxy(39,3);
                printf("Donner le nom.");
                scanf("%s", &nom);
		        E=rechercherhopitaldansHP(*LPH,nom);
		        supprimerpatienthopital(LPH, E);
				break;
            case 4:
				menu_utilisateur();
				break;
			default:
			    gotoxy(50,25);
			    printf("Requete invalide");}
				}
	return EXIT_SUCCESS;}
