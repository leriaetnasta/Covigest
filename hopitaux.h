#ifndef HOPITAUX_H_INCLUDED
#define HOPITAUX_H_INCLUDED
#include <stdbool.h>
#include<windows.h>
#include"patients.h"
#include"hotels.h"
#include"personnesQ.h"

typedef struct
{

char nom[10];
Adresse Adresse;
int nombre_pole;
int nombre_unite;
int nombre_salles;
int nombre_med;
int litsrea_dispo;
int litsnormal_dispo;

}hopital;


typedef struct
{
 hopital data;
 struct Node_H*next;
 struct Node_H*prev;

 }Node_H;

 typedef struct
 {

 Node_H*head;

 }LDCH;
 typedef struct
{

 char nompatient[15];
 char prenompatient[15];
 char nomhopital[15];

 }patienthopital;

typedef struct
{

 patienthopital data;
 struct Element*next;
 struct Element*prev;

 }Element;

 typedef struct
 {

Element*head;

}PH;


 LDC* initialiserLDCP();
 L* initialiserLmd();
 void ajouterFin(L*LD);
 void afficherLDC(L LD);
 C* initialiserLContact();
 void ajouterCONTACTFin(C*LC);
 patient* Nouveaupatient();
 void afficherLContact(C LC);
 void Afficherpatient(patient p, int i);
 void ajouterFinLDC(LDC*LD);
 void afficherLDCP(LDC LD);
void menu_recherche_patient();
void menu();
void menu_patient();
void menu_recherche_quarantaine();
void menu_PersonneQ();
void menu_hopital();
void menu_hotel();
#endif // HOPITAUX_H_INCLUDED
