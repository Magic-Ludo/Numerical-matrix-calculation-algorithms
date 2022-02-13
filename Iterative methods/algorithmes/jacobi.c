////////////////////////////////////////////////////////////////
//	Algorithme de Jacobi
////////////////////////////////////////////////////////////////
float vabJ(float a) { // Fonction de valeur absolue
	if (a < 0) {
		return -a;
	}
	else {
		return a;
	}
}

void diagstrictdom(double **A) { // Fonction de vérification de diagonale strictement domiante
	int i, j;
	for (i = 0; i < taille; i++) {
		float som = 0;
		
		for (j = 0; j < taille; j++) {
			som += vabJ(A[i][j]);
		}
		
		if (vabJ(A[i][i]) < som - vabJ(A[i][i])) {
			printf("La matrice n'est pas à diagonale strictement dominante \n");
			exit(EXIT_FAILURE);
		}
	}
}


void jacobi(double **A, float *b, float *x, double E, int maxiter){
	int i, j;
	int iter = 0;
	float somme = 0;
	float *y =  calloc(taille, sizeof(float));
	diagstrictdom(A);
	while ((norme(A, x, b) > E) && (iter < maxiter)){ // Vérification de la précision et critères d'arret
		for (i = 0; i < taille; i++){
			somme = 0;
			for (j = 0; j < taille; j++){
				if (j != i) {
					somme += A[i][j] * x[j];
				}
			}
			y[i] = (b[i] - somme) / A[i][i];
		}
		for (i = 0; i < taille; i++){
			x[i] = y[i];
			//printf("x[%d] = %f\n", i, x[i]);
		}
		iter++;
	}
	printf("Le nombre d'iteration est de %d\n", iter);
	
	
}
////////////////////////////////////////////////////////////////
