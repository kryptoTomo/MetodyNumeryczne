
/* Dyrektywy dla Taurusa (nie wymagaja kopiowania plikow, ale Taurus musi dzialac...) */
#include<stdio.h>
#include"include/nrutil.h"
#include"include/nrutil.c"
#include"include/gaussj.c"

#include<math.h>
#define N 200 // rozmiar macierzy M: NxN


int main(void)
{
	float **M,**b;
  float v_0= 0,A= 1,h= 0.1,w =1;

	//	Alokacja macierzy
	M = matrix(1, N, 1, N);
  b = matrix(1, N, 1, 1);
	// 	Wypelnienie macierzy M 
	for (int i = 1; i <= N; i++)
	{ 
			M[i][i] = 1;
      if(i>1)
        M[i][i-1] = pow(w*h,2)-2;
      if(i>2)
        M[i][i-2] = 1;      
	}
  
  M[2][1] = -1;
  // Wypelnienie wektora b
  b[1][1]= A;
  b[2][1] = v_0*h;

	//	Rozwiazanie ukladu rownan Mx=b - wywolanie procedury:
	gaussj(M, N, b, 1);

	//	Wypisanie rozwiazania, ktore procedura gaussj(M, N, b, 1); zapisala w wektorze b.
  
	for (int i = 1; i <= N; ++i)
		printf("%g, %g\n", h*(i-1), b[i][1]);

	//	Zwolnienie pamieci
	free_matrix(M, 1, N, 1, N);
	free_matrix(b, 1, N, 1, 1);

	return 0;
}