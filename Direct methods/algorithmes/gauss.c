////////////////////////////////////////////////////////////////
//  Algorithme de Gauss
////////////////////////////////////////////////////////////////
void gauss( double **A, float *b, float *x )
{
     int i, j, k ;
     int min ;
     float p ;
     float somme, valeur_min, y, z;
		 double **C = Matrice();
		 for (int i = 0; i < taille; i++) {
 			for (int j = 0; j < taille; j++) {
 				C[i][j] = A[i][j];
 			}
 		}
     for(k = 0 ; k < taille-1 ; k++){
        valeur_min = C[k][k] ; min = k ;
        for(i = k+1 ; i < taille ; i++){
           if (valeur_min != 0){
              if (abs(C[i][k]) < abs(valeur_min) && C[i][k] != 0){
                 valeur_min = C[i][k] ;
                 min = i ;
              }
           }
           else {
                 valeur_min = C[i][k] ;
                 min = i ;
           }
        }
				if (C[taille - 1][taille - 1] == 0){
					printf("Pas de solution\n");
				}
        for(j = 0 ; j < taille ; j++){
           y = C[min][j] ;
           C[min][j] = C[k][j] ;
           C[k][j] = y ;
        }
        z = b[min] ;
        b[min] = b[k] ;
        b[k] = z ;
        for(i = k+1 ; i < taille ; i++){
           p = C[i][k]/C[k][k] ;
           for(j = 0 ; j < taille ; j++){
              C[i][j] = C[i][j] - p*C[k][j] ;
           }
           b[i] = b[i] - p*b[k] ;
        }
     }

		 if (C[taille - 1][taille - 1] == 0){
 			printf("Pas de solution\n");
 	   }
     x[taille-1] = b[taille-1]/C[taille-1][taille-1] ;
     for(i = taille-2 ; i > -1 ; i--){
           somme = 0 ;
           for(j = taille-1 ; j > i ; j--){
              somme += C[i][j]*x[j] ;
           }
           x[i] = (b[i] - somme)/C[i][i] ;
     }
}
///////////////////////////////////////////////////////////////
