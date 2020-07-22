#ifndef HOTELS_H_INCLUDED
#define HOTELS_H_INCLUDED
#include"hopitaux.h"
typedef struct
{
char nom[10];
Adresse Adresse;
int nombre_chambre_dispo;

}hotel;
typedef struct
{
 hotel data;
 struct NodeH*next;
 struct NodeH*prev;

 }NodeH;

typedef struct
{

NodeH*head;

}H;

#endif // HOTELS_H_INCLUDED
