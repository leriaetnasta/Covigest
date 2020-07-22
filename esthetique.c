#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
COORD coord = {0, 0};// fixe les coordonnées à 0,0
int i,j;

void gotoxy(int x, int y){
 COORD coord;
 coord.X = x;
 coord.Y = y;// Coordonnées X et Y
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);// on se déplace vers les coordonnées
}
void main_border(){

    gotoxy(95,6);//Nord Est
	printf("%c",187);
	gotoxy(15,37);//Sub Ouest
	printf("%c",200);
	gotoxy(15,6);//Nord Ouest
	printf("%c",201);
	gotoxy(95,37);// Sud Est
	printf("%c",188);
	for(i=1;i<80;i++)//Nord
	{
		gotoxy(15+i,6);
		printf("%c",205);
	}



	for(i=5;i<35;i++) // Ouest
	{
		gotoxy(15,2+i);
		printf("%c",186);
	}

	for(i=1;i<80;i++) //sud
	{
		gotoxy(15+i,37);
		printf("%c",205);
	}


	for(i=5;i<35;i++)//Est
	{
		gotoxy(95,2+i);
		printf("%c",186);
	}
}
void Covigest_border(){

    gotoxy(81,9);//Nord Est
	printf("%c",187);
	gotoxy(38,15);//Sub Ouest
	printf("%c",200);
	gotoxy(38,9);//Nord Ouest
	printf("%c",201);
	gotoxy(81,15);// Sud Est
	printf("%c",188);
	for(i=1;i<43;i++)//Nord
	{
		gotoxy(38+i,9);
		printf("%c",205);
	}



	for(i=5;i<10;i++) // Ouest
	{
		gotoxy(38,5+i);
		printf("%c",186);
	}

	for(i=1;i<43;i++) //sud
	{
		gotoxy(38+i,15);
		printf("%c",205);
	}


	for(i=5;i<10;i++)//Est
	{
		gotoxy(81,5+i);
		printf("%c",186);
	}
}
void box_I(){

	gotoxy(25,16);
	printf("%c",201);
	gotoxy(45,16);
	printf("%c",187);
	gotoxy(25,19);
	printf("%c",200);
	gotoxy(45,19);
	printf("%c",188);
	for(i=26;i<45;i++) //Nord
	{
		gotoxy(i,16);
		printf("%c",205);
	}

	for(i=6;i<8;i++)//ouest
	{
		gotoxy(25,i+11);
		printf("%c",186);
	}

	for(i=26;i<45;i++)//sud
	{
		gotoxy(i,19);
		printf("%c",205);
	}

	for(i=6;i<8;i++)//Est
	{
		gotoxy(45,i+11);
		printf("%c",186);
	}

}
void box_II(){

	gotoxy(75,16);
	printf("%c",201);
	gotoxy(95,16);
	printf("%c",187);
	gotoxy(75,19);
	printf("%c",200);
	gotoxy(95,19);
	printf("%c",188);
	for(i=26;i<45;i++) //Nord
	{
		gotoxy(i+50,16);
		printf("%c",205);
	}

	for(i=6;i<8;i++)//ouest
	{
		gotoxy(75,i+11);
		printf("%c",186);
	}

	for(i=26;i<45;i++)//sud
	{
		gotoxy(i+50,19);
		printf("%c",205);
	}

	for(i=6;i<8;i++)//Est
	{
		gotoxy(95,i+11);
		printf("%c",186);
	}

}
void box_III(){

	gotoxy(37,2);
	printf("%c",201);
	gotoxy(55,2);
	printf("%c",187);
	gotoxy(37,5);
	printf("%c",200);
	gotoxy(55,5);
	printf("%c",188);
	for(i=38;i<55;i++)//NORD
	{
		gotoxy(i,2);
		printf("%c",205);
	}
	for(i=2;i<4;i++)//OUEST
	{
		gotoxy(37,i+1);
		printf("%c",186);
	}

	for(i=38;i<55;i++)//SUD
	{
		gotoxy(i,5);
		printf("%c",205);
	}

	for(i=2;i<4;i++)//EST
	{
		gotoxy(55,i+1);
		printf("%c",186);
	}

}
void box_IV(){

	gotoxy(54,2);
	printf("%c",201);
	gotoxy(72,2);
	printf("%c",187);
	gotoxy(54,5);
	printf("%c",200);
	gotoxy(72,5);
	printf("%c",188);
	for(i=55;i<72;i++)//NORD
	{
		gotoxy(i,2);
		printf("%c",205);
	}
	for(i=2;i<4;i++)//OUEST
	{
		gotoxy(54,i+1);
		printf("%c",186);
	}

	for(i=55;i<72;i++)//SUD
	{
		gotoxy(i,5);
		printf("%c",205);
	}

	for(i=2;i<4;i++)//EST
	{
		gotoxy(72,i+1);
		printf("%c",186);
	}

}
void box(){
   for(i=3;i<=100;i++) 	//This 'FOR' loop will print a combination of
	{
		gotoxy(i,0);    //the 79th column is reached.
		printf("%c",219);
		gotoxy(i,45);
		printf("%c",219);
	}

	for(i=0;i<=45;i++)      //This 'FOR' loop will print asterisks 'I'
	{                       //vertically till the 3th row is reached.
		gotoxy(2,i);
		printf("%c",219);
		gotoxy(100,i);
		printf("%c",219);
	}
}
void I_box(){
   for(i=3;i<=118;i++) 	//This 'FOR' loop will print a combination of
	{
		gotoxy(i,0);    //the 79th column is reached.
		printf("%c",219);
		gotoxy(i,45);
		printf("%c",219);
	}

	for(i=0;i<=45;i++)      //This 'FOR' loop will print asterisks 'I'
	{                       //vertically till the 3th row is reached.
		gotoxy(2,i);
		printf("%c",219);
		gotoxy(118,i);
		printf("%c",219);
	}
}
int alert_requete_invalide(){
        MessageBeep(MB_ICONINFORMATION);
        MessageBox(0,"Requete Invalide.","Erreur!",0);
        EXIT_SUCCESS;
}




