//Tarefa 4 - Métodos Numéricos II

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

FILE *fp;
//Função para ler a matriz do arquivo
double **ler( char *matriz, int *dim)
{
        int  i, j;
        double **M;
        float a;
        fp = fopen(matriz,"r");
        i = fscanf(fp,"%d",dim);

        M = malloc( *dim *sizeof(double *));
        for(i=0; i<*dim; i++)
        {
                M[i]= malloc((*dim+1)*sizeof(double));
        }
        i =0;
        j = 0;

        while (fscanf(fp,"%f",&a)!= EOF)
        {
                M[i][j]=a;
                j++;
                if (j== *dim+1)
                {
                        j= 0;
                        i++;
                }
        }

        return (M);
}

//Função para imprimir as matrizes
void imprime(double **M, int dim)
{
        int i, j;
        printf("\n");
        for(i=0; i<dim; i++)
        {
                for(j=0; j<dim+1; j++)
                {
                        printf("%.3f\t", M[i][j]);
                }
                //printf("\t");
                puts("");

        }
}

void main (int argc , char **argv )
{
  double **M;
  double *raizes;
  int i, dim;

  printf("\nMatriz lida no arquivo Matriz.dat:\n");
  M=ler(argv[1] ,&dim);
  imprime(M,dim);
}
 
