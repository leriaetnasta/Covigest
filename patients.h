#ifndef PATIENTS_H_INCLUDED
#define PATIENTS_H_INCLUDED
typedef struct{

  char nom[25];
 struct maladie*next;

 }maladie;

typedef struct
 {

 maladie*top;

 }L;

typedef struct
 {

char nom[25];
char prenom[25];
struct contact*next;

 }contact;

typedef struct
{

contact*top;

 }C;

typedef struct
{
char adresse[100];
char commune[25];
char ville[10];
int codepostal;

}Adresse;

typedef struct
{

char nom[15];
char prenom[15];
bool genre;
char CIN[25];
Adresse Adresse;
int age;
L L;
C C;
SYSTEMTIME consultation;
bool contintroduite ;
bool etat;

 }patient;

typedef struct
{

patient data;
struct NodeP*next;
struct NodeP*prev;

 }NodeP;

typedef struct{

NodeP*head;

}LDC;


#endif // PATIENTS_H_INCLUDED
