////////////////////////////////////////////////////////////////
//  Algorithme de Cholesky
////////////////////////////////////////////////////////////////


double** cholesky( double **A, float *b ) {
  int i, j, k ;
  double s, tmp, somme = 0 ;

  double **r = Matrice() ;

  for( i = 0 ; i < taille ; i++ )
  {
    for ( j = 0 ; j < taille ; j++ )
    {
      if ( fabs(A[i][j] - A[j][i]) > 0.0001 )
      {
        printf("La matrice n'est pas symétrique\n");
        exit(EXIT_FAILURE);
      }
    }

    for( j = 0 ; j <= i-1 ; j++)
    {
      somme += r[j][i] * r[j][i];
    }
    s = A[i][i] - somme;
    if (s == 0)
    {
      printf("La matrice n'est pas définie positive\n");
      exit(EXIT_FAILURE);
    }

    else
    {
        r[i][i] = sqrt(s);
        for( j = i+1 ; j < taille ; j++)
        {
          tmp = .0;
          for( k = 0 ; k <= i-1 ; k++)
          {
            tmp += r[k][i] * r[k][i];
          }
          r[i][j] = ( A[i][j] - tmp ) / r[i][i];
        }
      }
   }
  return r ;
}
///////////////////////////////////////////////////////////////        		
        	

	


















