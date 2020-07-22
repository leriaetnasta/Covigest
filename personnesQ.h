#ifndef PERSONNESQ_H_INCLUDED
#define PERSONNESQ_H_INCLUDED
#include"patients.h"


typedef struct
{

int numq;
char nom[25];
char prenom[25];
bool genre;
Adresse Adresse;
int age;
char CIN[10];
L L;
C C;
SYSTEMTIME debut;
SYSTEMTIME FIN;
bool contintroduite ;

}personneQ;

typedef struct
{

personneQ data;
struct NodeQ*next;
struct NodeQ*prev;

 }NodeQ;

 typedef struct
 {

 NodeQ*head;

 }LDCQ;

typedef struct
{
 char nom[15];
 char prenom[15];
 char hotel[15];

 }personnehotel;

typedef struct
{

 personnehotel data;
 struct ElementPQH*next;
 struct ElementPQH*prev;

 }ElementPQH;

 typedef struct
 {

 ElementPQH*head;

 }PQH;
#endif // PERSONNESQ_H_INCLUDED
