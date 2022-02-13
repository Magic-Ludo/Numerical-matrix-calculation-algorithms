////////////////////////////////////////////////////////////////
//	Inclusion des bibliothèques
////////////////////////////////////////////////////////////////

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <time.h>

int taille;

////////////////////////////////////////////////////////////////
//	Inclusion des fichiers
////////////////////////////////////////////////////////////////

#include "autre/affichage.c"
#include "algorithmes/gauss.c"
#include "algorithmes/cholesky.c"

////////////////////////////////////////////////////////////////
//  Main Program
////////////////////////////////////////////////////////////////

int main()
{

	printf( "\e[1;1H\e[2J" ) ;

	srand( time( NULL ) ) ; //Pour la randomisation de la matrice creuse

	int a ;
 	double **A ;
	float *b ;
	float *x ;

	printf( "Entrez la taille de votre matrice : " ) ;
	scanf( "%d", &taille ) ;

	A = Matrice() ;
 	b = (float *) malloc (sizeof (float *) * taille) ;
	x = (float *) malloc (sizeof (float *) * taille) ;

////////////////////////////////////////////////////////////////
//	Choix de la methode de résolution
////////////////////////////////////////////////////////////////

    menu( A ) ;
    afficher_systeme( A, b ) ;
		menu2( b ) ;
		afficher_systeme( A, b ) ;

    printf( "\nListe des algorithmes : \n" ) ;
    printf( "\n1 :\tPivot de Gauss \n2 :\tCholesky \n0 :\tPour sortir \n" ) ;
    printf( "\nChoisissez un algorithme : " ) ;
    scanf( "%d", &a ) ;
    printf( "\n\t-----\n\n" ) ;
	double time = 0;
	clock_t start, end;


    switch ( a )
		{
	case 1:
        
		start = clock();
        gauss( A, b, x ) ;
        end = clock();
        time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf( "Temps d'execution = %.4lf s", time ) ;
        printf( "\nSoit %.2lf ms \n", time*1000 ) ;
        printf( "\nLes valeurs de x sont egales à : \n" );
        afficher_vecteur( x ) ;
        printf( "\n" ) ;
        break;

	case 2:
        start = clock();
        afficher_systeme( cholesky( A, b ), b ) ;
		afficher_systeme( transpose( cholesky( A, b ) ), b ) ;
		end = clock();
        time = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf( "\n" ) ;
		printf( "Temps d'execution = %.4lf s", time ) ;
		printf( "\nSoit %.2lf ms \n", time*1000 ) ;
        	printf( "\n" ) ;
        break;

      case 0:
        exit(0) ;
        break;
    }
    return 0 ;
}
////////////////////////////////////////////////////////////////
