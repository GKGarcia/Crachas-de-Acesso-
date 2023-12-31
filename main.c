#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int opcao,i,ok,j, op,ano;
char busca[50], novoacesso[50];

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
void buscarnome(void);
void listarcracha(void);
void menuedicao(void);
void editarcadastro(void);

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
                buscarnome();
                break;
            case 4:
                listarcracha();
                break;
            case 5:
                editarcadastro();
                break;
            case 6:
                system("cls");
                printf("\n\nSISTEMA EM DESENVOLVIMENTO\n");
                system("pause");
                break;

            default:
        }

    }while (opcao != 5);
}

void menu(){
    printf("   MENU INICIAL                     \n");
    printf("1- Cadastrar Cracha\n");
    printf("2- Buscar Cracha\n");
    printf("3- Buscar Colaborador\n");
    printf("4- Listar Crachas Cadastrados\n");
    printf("5- Editar cadastros\n");
    printf("6- Sair\n\n");
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

    printf("\nDigite o ano de nascimento:\n");
    scanf("%d",&ano);

    if(ano > 2005){

        printf("Colaborador não permitido!\n");

        system("pause");
        system("cls");

    }else {

        fflush(stdin);
        printf("\nDigite o nome da empresa:\n");
        gets(cad[i].empresa);
        fflush(stdin);

        printf("\nDigite o tempo de acesso:\n");
        gets(cad[i].tempodeacesso);

        printf("\nDigite o numero do cracha:\n");
        gets(cad[i].numerocracha);
        fflush(stdin);

        printf("\nAtendimento cadastrado!\n");
        system("Pause");
        system("cls");
    }
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

            printf("         CRACHA: %s\n",cad[j].numerocracha);
            printf("Nome:%s\n", cad[j].nome);
            printf("RG:%s\n", cad[j].rg);
            printf("Empresa:%s\n", cad[j].empresa);
            printf("Tempo de acesso:%s\n\n",cad[j].tempodeacesso);
            printf("=====================\n\n");

            j=i;
            ok=0;

            system("pause");
            system("cls");
        }
    }
    if(ok != 0){

        printf("Nenhum cracha encontrado!\n\n");
        system("pause");
        system("cls");
    }
}

void listarcracha(){
    for(j=1;j<=i;j++){

        printf("         CRACHA: %s\n", cad[j].numerocracha);
        printf("Nome:%s\n", cad[j].nome);
        printf("RG:%s\n", cad[j].rg);
        printf("Empresa:%s\n", cad[j].empresa);
        printf("Tempo de acesso:%s\n",cad[j].tempodeacesso);
        printf("=====================\n\n");
    }
    if(i==0){

        printf("\n\nNenhum cracha cadastrado!\n\n");
    }

    system("Pause");
    system("cls");
}

void buscarnome(){

    j=0;

     printf("Digite o nome do colaborador:\n");
     fflush(stdin);
     gets(busca);
     fflush(stdin);

    for (j = 0; j <= i; j++) {

        ok = strcmp(busca, cad[j].nome);

        if (ok == 0) {

            printf("         CRACHA: %s\n", cad[j].numerocracha);
            printf("Nome:%s\n", cad[j].nome);
            printf("RG:%s\n", cad[j].rg);
            printf("Empresa:%s\n", cad[j].empresa);
            printf("Tempo de acesso:%s\n\n", cad[j].tempodeacesso);
            printf("=====================\n\n");

            j = i;
            ok = 0;

            system("pause");
            system("cls");
        }
    }
}

void menuedicao(){

    printf("     QUAL OPÇÃO DESEJA?\n");
    printf("1- Atualizar tempo de acesso\n");
    printf("2- Atualizar numero cracha\n");
    printf("3- Excluir cadastro\n");
    printf("Digite uma opção:");
    scanf("%d",&op);
}

void editarcadastro() {

    menuedicao();

    switch (op) {
        case 1:
            fflush(stdin);
            printf("Digite o numero do cracha desejado:\n");
            gets(busca);
            fflush(stdin);

            for (j = 0; j <= i; j++) {

                char *ptr;
                ptr = &cad[j].tempodeacesso;

                ok = strcmp(busca, cad[j].numerocracha);

                if (ok == 0) {

                    printf("         CRACHA: %s\n", cad[j].numerocracha);
                    printf("Nome:%s\n", cad[j].nome);
                    printf("RG:%s\n", cad[j].rg);
                    printf("Empresa:%s\n", cad[j].empresa);
                    printf("Tempo de acesso:%s\n\n", cad[j].tempodeacesso);
                    printf("=====================\n\n");

                    printf("Digite o novo tempo de acesso:\n");
                    fflush(stdin);
                    gets(novoacesso);
                    fflush(stdin);

                    strcpy(ptr, novoacesso);

                    printf("Tempo de acesso atualizado!\n\n");

                    system("pause");
                    system("cls");

                    opcao = 2;
                    j = i;
                    ok = 0;
                }
            }
            if (ok != 0) {

                printf("Nenhum cracha encontrado!\n\n");
                system("pause");
                system("cls");
                break;
                case 2:

                    fflush(stdin);
                    printf("Digite o numero do cracha desejado:\n");
                    gets(busca);
                    fflush(stdin);

                for (j = 0; j <= i; j++) {

                    char *ptr;
                    ptr = &cad[j].numerocracha;

                    ok = strcmp(busca, cad[j].numerocracha);

                    if (ok == 0) {
                        printf("         CRACHA: %s\n", cad[j].numerocracha);
                        printf("Nome:%s\n", cad[j].nome);
                        printf("RG:%s\n", cad[j].rg);
                        printf("Empresa:%s\n", cad[j].empresa);
                        printf("Tempo de acesso:%s\n\n", cad[j].tempodeacesso);
                        printf("=====================\n\n");

                        printf("Digite o novo cracha de acesso:\n");
                        fflush(stdin);
                        gets(novoacesso);
                        fflush(stdin);

                        strcpy(ptr, novoacesso);

                        printf("cracha de acesso atualizado!\n\n");

                        system("pause");
                        system("cls");

                        opcao = 2;
                        j = i;
                        ok = 0;
                    }
                }

                if (ok != 0) {

                    printf("Nenhum cracha encontrado!\n\n");

                    system("pause");
                    system("cls");
                    break;
                    case 3:
                        printf("\n\n");
                        printf("!Sistema em desenvolvimento!\n");
                        system("Pause");
                        system("cls");
                        break;

                }


            }

    }

}