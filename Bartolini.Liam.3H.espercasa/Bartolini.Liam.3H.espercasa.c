#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define	colonne 50


void main(void)
{
	//dichiarazione di variabili
	int contP = 0, contM = 0;
	float sommaT = 0, mediaT = 0;
	int mF = 0, f = 0;
	float sommaE = 0;
	float mediaE = 0;
	int N; //numero pazienti
	char cognomeP;
	
	do
	{
		printf("Inserire il numero di pazienti \r\n");
		scanf("%d" , &N);
	}while(N > 100);

	//dichiarazione matrici
	char cognome[N] [colonne];
	char sesso[N] [colonne];
	int age[N];
	int eta;
	int temperatura[N];
	int i=0;
	
	srand(time(NULL));
	
	//input dei dati
	for(i =0; i<N; i++)
	{
		puts("Inserire il cognome: ");
		scanf("%s", cognome[i]);
		
		puts("Inserire il sesso: ");
		scanf("%s", sesso[i]);
		
		printf("Inserire l'eta':\n");
		scanf("%i", &eta);
		age[i] = eta;
		
		sommaE = sommaE + eta;
	}
	//calcolo la media dell'età dei pazienti
	mediaE = sommaE / N;
	
	printf("cognome\t sesso\t eta'\t febbre: \r\n");
	
	//stampo tutti i dati raccolti in input
	for(i =0; i<N;i++)
	{
		temperatura[i] = rand() %  5 + 36;
		printf("%s" ,cognome[i]);
		printf("\t %s" ,sesso[i]);
		printf("\t %i" ,age[i]);
		printf("\t %i \n" ,temperatura[i]);
		sommaT = sommaT + temperatura[i];
	}
	//calcolo la media della temperatura dei pazienti
	mediaT = sommaT / N;
	printf("La media dell'eta' dei pazienti e': %f \r\n", mediaE);

	//controllo chi ha la febbre
	for(i = 0; i < N; i++)
	{
		if(temperatura[i] > 37)
			printf("%s ha la febbre di %i \r\n", cognome[i], temperatura[i]);
	}
	
	
	for(i = 0; i < N; i++)
	{
		//controllo i maschi con la febbre
		if(strcmp(sesso[i], "m") == 0)
		{
			if(temperatura[i] > 37)
				mF++;	
		}
		
		//controllo le femmine senza febbre
		if(strcmp(sesso[i], "f") == 0)
		{
			if(temperatura[i] <= 37)
				f++;
		}
	}
	
	printf("Il numero di pazienti maschi con la febbre e': %i \r\n", mF);
	printf("Il numero di pazienti femmine senza febbre e': %i \r\n", f);

	int flag;
	int comp = 0;
	char cognomeCercato[50];
	//input cognome e lo cerco nella lista se non è presente lo dico
	puts("Inserire il cognome del paziente da cercare: ");
		scanf("%s", cognomeCercato);
	
	int flagR = 0;
	for(i = 0; i < N; i++)
	{
		if(strcmp(cognome[i], cognomeCercato) == 0)
		{	
			printf("anni: %i \r\ntemperatura: %i \r\n", age[i], temperatura[i]);
			flagR = 1;
		}
			
		if(temperatura[i] > mediaT)
			contP++;
		else
			contM++;
	}
	
	if(flagR == 0)
		printf("Il paziente cercato non e' stato trovato! \r\n");
			
	printf("La temperatura media e': %f \r\n", mediaT);
	printf("I pazienti con la temperatura superiore alla media sono: %i \r\n", contP);
	printf("I pazienti con la temperatura inferiore alla media sono: %i \r\n", contM);
	
	//ordinamento pazienti in ordine alfabetico in base al cognome bubble sort
	int j =0;
	char tmp[N];
    
	for(i=1;i<N;i++)
	{
    	for(j=0;j<N-i;j++)
		{
			if(strcmp(cognome[j],cognome[j+1])>0)
			{ 
       			strcpy(tmp,cognome[j]);
	   		 	strcpy(cognome[j],cognome[j+1]);
				strcpy(cognome[j+1],tmp);
			}
		}
	}
	printf("Pazienti In ordine alfabetico: \n");
	for(i=0;i<N;i++)
	{
		printf("%s\n",cognome[i]);
	}	  
}
