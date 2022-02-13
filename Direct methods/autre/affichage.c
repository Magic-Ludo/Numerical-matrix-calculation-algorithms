////////////////////////////////////////////////////////////////
// Affichage
////////////////////////////////////////////////////////////////

#include "matrices.c"

//Fonction Afficher
void afficher_systeme( double **A, float *b )
{
	int i , j ;
	for( i = 0 ; i < taille ; i++ )
	{
		printf( "(" ) ;
		for( j = 0 ; j < taille ; j++ )
		{
			printf( " %.6lf ", A[i][j] ) ;
		}
		printf( ") (X%d) = ", i + 1 ) ;
		printf( "%.6f", b[i] ) ;
		printf( "\n\n" ) ;
	}
}

void afficher_cholesky( double **A, double **B, float *b )
{
	int i , j ;
	for( i = 0 ; i < taille ; i++ )
	{
		printf( "(" ) ;
		for( j = 0 ; j < taille ; j++ )
		{
			printf( " %.6f ", A[i][j] ) ;
		}
		printf(") (");
		for( j = 0 ; j < taille ; j++ )
		{
			printf( " %.6f ", B[i][j] ) ;
		}
		printf( ") (X%d) = ", i + 1 );
		printf( "%.6f", b[i] ) ;
		printf( "\n\n" ) ;
	}
}

//Fonction afficher vecteur
void afficher_vecteur( float *A )
{
	int i;
	for( i = 0 ; i < taille ; i++ )
	{
    printf( "(x%d) = ", i + 1 ) ;
		printf( "%.7f", A[i] ) ;
		printf( "\n\n" ) ;
	}
}

//Fonction d'affichage du menu
void menu( double **A)
{
	double p;
	int x;

	printf("\n\n\t\t####  MENU  ####\t\t\n\n");
	printf("\nListe des matrices : \n");
	printf("\n0 :\tBord Carre\n1 :\tDing Dong\n2 :\tFranc\n3 :\tHilbert v1\n4 :\tHilbert v2\n5 :\tKMS\n6 :\tLotkin\n7 :\tLehmer\n8 :\tMoler\n9 :\tMatrice creuse - 70%% de valeurs nulles\n10 :\tSaisie manuelle\n");
	printf("\nChoisissez la matrice : ");
	scanf("%d", &x);

	printf("\e[1;1H\e[2J");

	printf("\n\n\t\t####  MENU  ####\t\t\n\n");;
	printf("\n\n = %d\n\n",taille);

	switch (x) {
		case 0:
			printf("Bordcarre :\n\n");
			Bordcarre( A );
			break;
		case 1:
			printf("DingDong :\n\n");
			DingDong( A);
			break;
		case 2:
			printf("Franc :\n\n");
			Franc( A );
			break;
		case 3:
			printf("Hilbert v1 :\n\n");
			HilbertM( A );
			break;
		case 4:
			printf("Hilbert v2 :\n\n");
			HilbertP( A );
			break;
		case 5:
			printf("KMS :\n\n");
		  printf("Rentrez une valeur de p entre 0 et 1: ");
		  scanf("%lf",&p);
			kms( A, p );
			break;
		case 6:
			printf("Lotkin :\n\n");
			Lotkin( A );
			break;
		case 7:
			printf("Lehmer :\n\n");
			Lehmer( A );
			break;
		case 8:
			printf("Moler :\n\n");
			Moler( A );
			break;
		case 9:
			printf("Matrice creuse - 70%% de valeurs nulles :\n\n");
			Creuse( A );
			break;
		case 10:
			printf("Saisie manuelle :\n\n");
			Saisieman( A );
			break;
		}
	}


////////////////////////////////////////////////////////////////
//	Choix de b
////////////////////////////////////////////////////////////////
void menu2( float *b ){
			int i, choix ;

			printf( "Génération de la matrice b :\n" ) ;
			printf( "\n\n\t\t####  MENU  ####\t\t\n\n" ) ;
			printf( "\n1 :\tRemplissage manuel de la matrice b\n2 :\tRemplissage aléatoire (entre 0 et 100) de la matrice b\n0 :\tSortir\n" ) ;
			printf( "\nChoisissez une méthode : " ) ;

			scanf( "%d", &choix ) ;

			switch ( choix )
			{
			 	case 0:
			 		exit( 0 ) ;
			    break;
				case 1:
					printf( "Entrez les valeurs de b telles que Ax = b :\n\n" ) ;
					for (i=0; i < taille; i++) {
					printf("b[%d] = ",i+1);
					scanf("%f", &b[i]);
				}
					break;
				case 2:
					printf( "Remplissage aléatoire en cours...\n" ) ;
					for ( i = 0 ; i < taille ; i++ )
					{
						b[i] = alea2();
					}
					break;
			}
			printf("\e[1;1H\e[2J");
}
////////////////////////////////////////////////////////////////
