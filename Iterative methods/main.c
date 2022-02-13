////////////////////////////////////////////////////////////////
//	Inclusion des bibliothèques
////////////////////////////////////////////////////////////////

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

int taille;

////////////////////////////////////////////////////////////////
//	Inclusion des fichiers
////////////////////////////////////////////////////////////////

#include "autre/affichage.c"
#include "algorithmes/jacobi.c"
#include "algorithmes/gauss-seidel.c"

////////////////////////////////////////////////////////////////
//  Main Program
////////////////////////////////////////////////////////////////


int main() {

	printf( "\e[1;1H\e[2J" );

	srand( time( NULL ) ) ; //Pour la randomisation de la matrice creuse

	int a ;
 	double **A ;
	float *b ;
	float *x ;

	printf( "Entrez la taille de votre matrice : " ) ;
	scanf( "%d", &taille );

	A = Matrice() ;
 	b = (float *) malloc (sizeof (float *) * taille) ; // Allocation dynamique de la matrice b
	x = (float *) malloc (sizeof (float *) * taille) ; // Allocation dynamique de la matrice x

////////////////////////////////////////////////////////////////
//	Choix de la methode de résolution
////////////////////////////////////////////////////////////////

    	menu( A ) ;
    	afficher_systeme( A, b ) ;
	menu2( b ) ;
	afficher_systeme( A, b ) ;

    	printf( "\nListe des algorithmes : \n" ) ;
    	printf( "\n1 :\tJacobi \n2 :\tGauss-Seidel \n0 :\tPour sortir \n" ) ;
    	printf( "\nChoisissez un algorithme : " ) ;
	scanf( "%d", &a ) ;
    	printf( "\n\t-----\n\n" ) ;
    	double time = 0;
	clock_t start, end; // Déclaration des variable du temps

    switch ( a )
		{
      case 1:
        	start = clock();
        	jacobi( A, b, x, 0.0001, 500000 ) ; // Méthode itérative de Jacobi
        	end = clock() ;
        	time = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf( "\nLes valeurs de x sont egales à : \n" );
        	afficher_vecteur( x ) ;
        	printf( "\n" ) ;
		printf( "Temps d'execution = %.4lf s", time ) ;
        	printf( "\nSoit %.2lf ms \n", time*1000 ) ;
        	printf( "\n" ) ;
       	break;

	case 2:
		start = clock();
		gauss_seidel( A, b, x, 0.0001, 500000 ) ; // Méthode itérative de Gauss_Seidel
		end = clock() ;
        	time = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf( "\nLes valeurs de x sont egales à : \n" );
		afficher_vecteur( x ) ;
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
