#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int opcao,i,ok,j;
char busca[50];

typedef struct{
    char nome[50];
    char rg[50];
    char empresa[50];
    char numerocracha[50];
    char tempodeacesso[50];
}cadastro;

cadastro cad[50];

void menu(void);
void cadastrocracha(void);
void buscarcracha(void);
//void listarcracha()
//void finalizar crachas()

int main() {
    setlocale(LC_ALL, "Portuguese");

    do {
        menu();
        switch (opcao) {
            case 1:
                cadastrocracha();
                break;
            case 2:
                buscarcracha();
                break;
            case 3:
                printf("\n\nSISTEMA EM DESENVOLVIMENT0\n\n");
                break;
            case 4:
                printf("\n\nSISTEMA EM DESENVOLVIMENT0\n\n");
                break;
            default:
        }

    }while (opcao != 5);
}

void menu(){
    printf("   MENU INICIAL                     \n");
    printf("1- Cadastrar Cracha\n");
    printf("2- Buscar Cracha\n");
    printf("3- Listar Crachas Cadastrados\n");
    printf("4- Finalizar crachas\n");
    printf("5- Sair\n\n");
    printf("Digite uma opção:");
    scanf("%d",&opcao);

    system("cls");
}

void cadastrocracha(){

    i=i+1;

    fflush(stdin);
    printf("Digite seu nome:\n");
    gets(cad[i].nome);
    fflush(stdin);

    printf("\nDigite o RG:\n");
    gets(cad[i].rg);
    fflush(stdin);

    printf("\nDigite o nome da empresa:\n");
    gets(cad[i].empresa);
    fflush(stdin);

    printf("digite o tempo de acesso:\n");
    gets(cad[i].tempodeacesso);

    printf("\nDigite o numero do cracha:\n");
    gets(cad[i].numerocracha);
    fflush(stdin);

    printf("\nAtendimento cadastrado!\n");
    system("Pause");
    system("cls");
}

void buscarcracha() {
    j=0;
    fflush(stdin);
    printf("Digite o numero do cracha desejado:\n");
    gets(busca);
    fflush(stdin);

    for (j = 0; j <= i; j++) {


        ok = strcmp(busca, cad[j].numerocracha);
        if (ok == 0) {
            printf("\n\nNome:%s\n", cad[j].nome);
            printf("RG:%s\n", cad[j].rg);
            printf("Empresa:%s\n", cad[j].empresa);
            printf("Tempo de acesso:%s\n",cad[j].tempodeacesso);

            j=i;
            ok=0;

            system("pause");
            system("cls");
        }

    }
    if(ok != 0){
        printf("Nehum cracha encontrado!\n\n");
        system("pause");
        system("cls");
    }
}