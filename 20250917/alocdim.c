#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 256
#define MAX_NOME 50
#define NUM_NOTAS 3
char read='r', write='w';
typedef struct
{
    char nome [MAX_NOME];
    float notas[NUM_NOTAS];
    float media;
} aluno;

void testfile (char *filename, char fopenmode);

int main()
{
    FILE *arquivo;
    char linha[MAX_LINHA];
    int j, quantidadeAlunos = 0;

    arquivo = fopen("fnotas.csv","r");
    testfile("arquivo","mode");
   /* if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo. \n");
        return 1;
    }
    */
    while (fgets(linha, MAX_LINHA, arquivo) != NULL)
    {
        quantidadeAlunos++;
    }
    fclose(arquivo);

    aluno *alunos = (aluno *) malloc(quantidadeAlunos * sizeof(aluno));
    if (alunos == NULL)
    {
        printf ("Erro ao aloca memoria. \n");
        return 1;
    }
    arquivo = fopen("notas.csv", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo. \n");
        return 1;
    }
    int i = 0;
    float somaTurma = 0.0;

    while (fgets(linha, MAX_LINHA, arquivo) !=NULL && i <quantidadeAlunos)
    {
        char *token = strtok(linha, ",");
        if (token != NULL)
        {
            strncpy(alunos[i].nome, token, MAX_NOME);
            alunos[i].nome[MAX_NOME - 1]= '\0';
        }
        float somaNotas = 0.0;
        int j;
        for (j = 0; j<NUM_NOTAS; j++)
        {
            token = strtok(NULL, ",");
            if (token != NULL)
            {
                alunos[i].notas[j] = atof(token);
                somaNotas += alunos[i].notas[j];
            }
        }
        alunos[i].media = somaNotas / NUM_NOTAS;
        somaTurma += alunos[i].media;

        i++;

    }

    fclose(arquivo);

    printf("\n ===== Relatorio de Notas ====\n");
    int k;
    for (k = 0; k<quantidadeAlunos; k++)
    {
        printf("Aluno %s\n", alunos[k].nome);
        printf ("Notas: ");
        for (j = 0; j < NUM_NOTAS; j++)
        {
            printf("%.2f ", alunos[k].notas[j]);
        }
        printf("\nMedia: %.2f\n\n", alunos[k].media);
    }
    printf("Media global da turma: %.2f\n", somaTurma / quantidadeAlunos);

    free(alunos);
}

void testfile (char *filename, char *fopenmode){
   if (filename == NULL)
    {
        printf("Erro ao abrir o arquivo. \n");
        return 5;
    }
}
