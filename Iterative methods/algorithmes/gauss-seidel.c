////////////////////////////////////////////////////////////////
//  Algorithme de Gauss-Siedel
////////////////////////////////////////////////////////////////
float vabGS(float a) { // Fonction de valeur absolue
	if (a < 0) {
		return -a;
	}
	else {
		return a;
	}
}

void diagstrictdomGS(double **A) { // Fonction de vérification de diagonale strictement domiante
	int i, j;
	for (i = 0; i < taille; i++) {
		float som = 0;
		
		for (j = 0; j < taille; j++) {
			som += vabGS(A[i][j]);
		}
		
		if (vabGS(A[i][i]) < som - vabGS(A[i][i])) {
			printf("La matrice n'est pas à diagonale strictement dominante \n");
			exit(EXIT_FAILURE);
		}
	}
}

void gauss_seidel(double ** A, float *b, float *x, float E, int maxiter) {
	int i, j;
	int iter = 0;
	float *y = calloc(taille, sizeof(float));
	float somme1, somme2;
	diagstrictdomGS(A);
	for (i = 0; i < taille; i++)
	{
		y[i] = x[i];
		x[i] = y[i] + (2 * E);
	}
	while ((norme(A, x, b) > E) && (iter < maxiter)) // Vérification de la précision et critères d'arret
	{
		for (i = 0; i < taille; i++)
		{
			x[i] = y[i];
		}
		for (i = 0; i < taille; i++)
		{
			somme1 = 0;
			somme2 = 0;
			for (j = 0; j < i; j++)
			{
				somme1 += A[i][j] * y[j];
			}
			for (j = i + 1; j < taille; j++)
			{
				somme2 += A[i][j] * x[j];
			}
			y[i] = (b[i] - somme1 - somme2) / A[i][i];
		}
		iter++;
	}
	printf("Le nombre d'iteration est de %d\n",iter);
}
////////////////////////////////////////////////////////////////
