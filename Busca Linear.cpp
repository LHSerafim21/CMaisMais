// Realizando a busca num arquivo ja existente e com chave definida pelo usuario

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX1 500000  // numero max de componentes do arquivo

typedef enum boleano {falso, verdadeiro} Boleano;
// Boleano eh o sinonimo para o tipo enumeravel

Boleano Busca_Linear(int *Ptr, int Dim, int Chave);

int Leitura_Dimensao_Arquivo(void);

// as funcoes a seguir usam passagem de parametro por referencia
// int *Ptr
void Associa_Valores_Arquivo(int *Ptr, int Dim);
void Imprimindo_Valores_Arquivo(int *Ptr, int Dim);
int Maior_Elemento_Arquivo(int *Ptr, int Dim);

/*--------------------------------------------------------*/
Boleano Busca_Linear(int *Ptr, int Dim, int Chave) {
int i=0;   // indice para percorrer o array

 for (; i < Dim; i++)
      if ( *(Ptr+i) == Chave ) return(verdadeiro);  // elemento localizado (USO DO ENUM BOLEANO)

 return(falso);  // elemento nao pertence ao arquivo (USO DO ENUM BOLEANO)
}  // Busca_Linear

/*--------------------------------------------------------*/
Leitura_Dimensao_Arquivo(void) { // aceita somente dimensao valida
int dim=0;
FILE *arq;
arq = fopen("arquivo.txt","r"); // Abrindo o arquivo
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
arq = fopen("arquivo.txt","r");

  for ( ; i < Dim; i++) fscanf(arq,"%d\n",&Ptr[i]);

return;
} // Associando_Valores_Arquivo


/*--------------------------------------------------------*/
void Imprimindo_Valores_Arquivo(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o arquivo

 for (; i < Dim; i++)
   printf("\n [%d] = %d ",i,*(Ptr+i));  // ~ Prt[i]
} // Imprimindo_Valores_Arquivo

/*--------------------------------------------------------*/

int Maior_Elemento_Arquivo(int *Ptr, int Dim) {
int i = 1, maior1;

  maior1 = *(Ptr);  // inicializando maior1 com o primeiro elemento do arquivo

  for ( ; i < Dim; i++)	// a partir do segundo elemento - posicao 1
    if ( *(Ptr+i) > maior1 )
	   maior1 = *(Ptr+i);

return(maior1);
}   // Maior_Elemento_Arquivo

/*--------------------------------------------------------*/

int main(void) {

int 	 n1,             // tamanho real do arquivo
      vetor1[MAX1],   // vetor1 para armazenar os elementos
      chave;          // chave a ser pesquisada
FILE *arq;
arq = fopen("arquivo.txt","a");

  n1 = Leitura_Dimensao_Arquivo();
  Associa_Valores_Arquivo(vetor1,n1);

// imprimindo os valores presentes no arquivo

  printf("\n\nValores no arquivo:\n");
  Imprimindo_Valores_Arquivo(vetor1,n1);

// Encontrando o maior elemento

 printf("\n\nO maior elemento do arquivo e o valor: << %d >> ", Maior_Elemento_Arquivo(vetor1,n1) );

  printf("\nDigite o valor que deseja buscar: ");
  scanf("%d",&chave); // Ao inves de determinar a chave automaticamente, o usuario pode definir o que quer pesquisar
 // chave = vetor1[n1-1];  // valor presente no vetor


  printf("\n\nRealizando uma busca linear ... ");

  if ( Busca_Linear(&vetor1[0],n1,chave) ){
     printf("\n\nO elemento %d PERTENCE ao arquivo.\n\n ",chave); //resposta no executavel
     fprintf(arq, "\nO elemento %d pertence ao arquivo",chave);}// resposta no arquivo
     else {
     printf("\n\nO elemento %d NAO PERTENCE ao arquivo.\n\n",chave);// resposta no executavel
     fprintf(arq, "\nO elemento %d nao pertence ao arquivo",chave);}// resposta no arquivo

  printf("Pressione enter/return para finalizar ...");
  fflush(stdin); // esvaziando o buffer de entrada
  getchar();
  return(0);
}
