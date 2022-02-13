////////////////////////////////////////////////////////////////
//	Matrice Aléatoires
////////////////////////////////////////////////////////////////

int alea() {
	int result;
	const int MAX = 100, MIN = 0;
	int n = (rand() % (MAX - MIN + 1)) + MIN;
	if (n < 70){
		result = 0;
	}
	else{
		result = (rand() % (MAX - MIN + 1)) + MIN;
	}
	return result;
}

int alea2() {
	int result;
	const int MAX = 100, MIN = 0;
	result = (rand() % (MAX - MIN + 1)) + MIN;
	return result;
}

////////////////////////////////////////////////////////////////
//	Allocution dynamique matrice taille n
////////////////////////////////////////////////////////////////

double **Matrice() {
	double **matrice = malloc(sizeof(*matrice)*taille);
	for (int i = 0; i < taille; i++) {
		matrice[i] = malloc(sizeof(**matrice)*taille);
	}
	return matrice;
}

////////////////////////////////////////////////////////////////
//	Jeu d'essaie
////////////////////////////////////////////////////////////////

//Fonction pour Transposée
double **transpose( double** A ) {
  int i,j;

  double **res = Matrice(taille);
	printf("Transposée :\n\n");
  for( i = 0 ; i < taille ; i++)
  {
    for( j = 0 ; j < taille ; j++)
    {
      res[i][j] =  A[j][i];
    }
  }
	return res;
}

//Fonction Bord Carrée
void Bordcarre( double **A ) {
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
			if (i == j) {
				A[i][j] = 1;
			}
			else {
				if (i == 0) {
					A[i][j] = pow(2, 1 - (j+1));
				}
				else if (j == 0) {
					A[i][j] = pow(2, 1 - (i+1));
				}
			}
		}
	}
}

//Fonction Ding Dong
void DingDong( double **A ) {
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
			A[i][j] = 1.0 / (2 * (taille - (i+1) - (j+1) + 1.5));
		}
	}
}

//Fonction Franc
void Franc( double **A ) {
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
			if (i >= j + 2) {
				A[i][j] = 0;
			}
			else if (i <= j) {
				A[i][j] = i + 1.0;
			}
			else if (j < i) {
				A[i][j] = j + 1.0;
			}
		}
	}
}

//Fonction de Hilbert
void HilbertM( double **A ) {
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
			A[i][j] = 1.0 / ((i + 1) + (j + 1) - 1);
		}
	}
}

void HilbertP( double **A ) {
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
			A[i][j] = 1.0 / ((i + 1) + (j + 1) + 1);
		}
	}
}

//Fonction KMS
void kms( double **A, double p ) {
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
			A[i][j] = pow(p, i - j);
		}
	}
}

//Fonction de Lehmer
void Lehmer( double **A ) {
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
			if (i <= j) {
				A[i][j] = ((i + 1.0) / (j + 1.0));
			}
			else {
				A[i][j] = ((j + 1.0) / (i + 1.0));
			}
		}
	}
}

//Fonction de Lotkin
void Lotkin( double **A ) {
	for (int i = 1; i <= taille; i++) {
		for (int j = 1; j <= taille; j++) {
			if (i == 1) {
				A[i - 1][j - 1] = 1;
			}
			else {
				A[i - 1][j - 1] = 1.0 / (i + j - 1);
			}
		}
	}
}

//Fonction de Moler
void Moler( double **A ) {
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
			if (i == j) {
				A[i][j] = i + 1.0;
			}
			else if (i < j) {
				A[i][j] = (i + 1.0) - 2;
			}
			else if (j < i) {
				A[i][j] = (j + 1.0) - 2;
			}
		}
	}
}

//Fonction matrices Creuses aléatoires avec plus de 70% de valeurs nulles
void Creuse( double **A ) {
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
			A[i][j] = alea();
		}
	}
}
////////////////////////////////////////////////////////////////
//	Saisie manuelle
///////////////////////////////////////////////////////////////
void Saisieman( double **A ) { 
     printf("Saisie de la matrice : \n");
     
     for(int i = 0; i < taille; i++)
     {
        for(int j = 0; j < taille; j++)
        {
           printf("A[%d][%d] = ",i+1,j+1);
           scanf("%lf",&A[i][j]);
        }
     printf("\n");
     }
}












