// Utiliza um arquivo ja existente e organiza os numeros ordenadamente

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX2 400000    // numero maximo de numeros aleatorios

// funcoes com a logica; nao so prototipos

/*--------------------------------------------------------*/
Leitura_Dimensao_Arquivo(void) { // aceita somente dimensao valida
int dim=0;
FILE *arq;
arq = fopen("arquivo3.txt","r"); // Abrindo o arquivo
char linha[700][100];

     while(dim<700 && fgets(linha[dim], 100, arq) != NULL){ // Verificando o tamanho do arquivo
           dim++;}
    if (arq == NULL) { // Testando se o arquivo abriu
        printf("Arquivo inexistente");
    }
    if(dim>700){
        printf("Arquivo muito grande");
    }

return(dim);
} // Leitura_Dimensao_Arquivo

/*--------------------------------------------------------*/
void Associa_Valores_Arquivo(int *Ptr, int Dim) { // associa valores do arquivo ao vetor Ptr
int i = 0;   // indice para percorrer o arquivo
FILE *arq;
arq = fopen("arquivo3.txt","r");

  for ( ; i < Dim; i++) fscanf(arq,"%d\n",&Ptr[i]); // os valores presentes no arquivo

return;
} // Associando_Valores_Arquivo

/*--------------------------------------------------------*/
void Imprimindo_Valores_Arquivo(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o arquivo

 for (; i < Dim; i++)
   printf("\n[%d] = %d ",i,*(Ptr+i));
} // Imprimindo_Valores_Arquivo


/*-------------------------------------------------------*/

void InsertionSort(int *A, int n) {
    for(int i=1; i < n; i++){
        int aux = A[i];
        int j = i-1;
        while((j>=0)&&(A[j]>aux)){
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = aux;
    }
  return;
} // IsertionSort

/*-------------------------------------------------------*/

int main(void) {

int 	    n1,             // tamanho real do arquivo
	    vetor1[MAX2];   //  vetor1 para armazenar os elementos

  n1 = Leitura_Dimensao_Arquivo();
  Associa_Valores_Arquivo(vetor1,n1);
  printf("Valores no arquivo: \n");
  Imprimindo_Valores_Arquivo(vetor1,n1);

  puts("\n");
  InsertionSort(vetor1,n1);
  puts("Valores ordenados:"); // Os valores estao no arquivo criado pelo programa
  Imprimindo_Valores_Arquivo(vetor1,n1); // Funcao para criar novo arquivo e escrever os numeros ordenados
  printf("\n\nAcabei!!!!\n");

  printf("Pressione enter/return para finalizar ...");
  fflush(stdin); // esvaziando o buffer de entrada
  getchar();
  return(0);
}
