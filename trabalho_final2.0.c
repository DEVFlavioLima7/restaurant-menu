#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

// Variáveis globais
int numero_do_lanche[100];
char nome[100][50];
float preco[100];
int quantidade_lanches, total = 0; // Quantidade atual de lanches no cardápio
int ultima_informacao = 0;         // Código do último lanche inserido
int quantidade_definida=0;

// Protótipos das funções
int verificaNumero(const char numero[]);
int verificaNumeroReal(const char numero[]);
void definirQuantidadeLanches();
void inserirLanche();
void mostrarLanches();
void relatorioPorPalavraChave();
void atualizarLanche();
void mostrarQuantidadeLanches();

int main() {
    int opcao;
    char blin;

    do {
        // Menu de opções
        printf("\n==== Cardapio de Lanchonete ====\n");
        printf("\nDigite a opcao desejada: \n");
        printf("1 - Definir quantidade de lanches\n");
        printf("2 - Inserir lanche\n");
        printf("3 - Mostrar lanches\n");
        printf("4 - Gerar relatorio por palavra-chave\n");
        printf("5 - Atualizar lanche\n");
        printf("6 - Mostrar quantidade de lanches\n");
        printf("7 - Finalizar aplicacao\n");

        do{
            blin = getche();
            if(isdigit(blin) == 0){ 
                printf("Digite um numero\n");
            }
        }while(isdigit(blin) == 0);

        //Esse & é para pegar o endereço da variavel blin(Coloquei isso pois não estava rodando, por conta que é caractere unico)
        opcao = atoi(&blin);
        printf("\n");  

        switch (opcao) {
            case 1:
                definirQuantidadeLanches();
                system("PAUSE");
                system("cls");
                break;
            case 2:
                inserirLanche();
                system("PAUSE");
                system("cls");
                break;
            case 3:
                mostrarLanches();
                system("PAUSE");
                system("cls");
                break;
            case 4:
                relatorioPorPalavraChave();
                system("PAUSE");
                system("cls");
                break;
            case 5:
                atualizarLanche();
                system("PAUSE");
                system("cls");
                break;
            case 6:
                mostrarQuantidadeLanches();
                system("PAUSE");
                system("cls");
                break;
            case 7:
                printf("Aplicacao finalizada.\n");
                system("PAUSE");
                system("cls");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                system("PAUSE");
                system("cls");
        }
    } while (opcao != 7);

    return 0;
}

// Função para definir a quantidade de lanches no cardápio
void definirQuantidadeLanches() {
    char blin[3];
    printf("Digite a quantidade de lanches a serem inseridos: ");
    do{
        gets(blin);

        if(verificaNumero(blin) != 1){

             printf("Digite so numeros\n");

        }


    }while(verificaNumero(blin) != 1);

    quantidade_lanches = atoi(blin);

    if(quantidade_lanches>100){
        printf("a quantidade maxima e 100 lanches.");
        quantidade_lanches=100;
    }

    total += quantidade_lanches;
    quantidade_definida=1;

    
    
}

// Função para inserir um novo lanche no cardápio
void inserirLanche() {
    char blin[100];

    if (!quantidade_definida) {
        printf("A quantidade de lanches ainda nao foi definida.\n");
        return;
    }

    if (quantidade_lanches >= 100) {
        printf("Nao e possível adicionar mais lanches.\n");
        return;
    }
    do{

        printf("--------------------------------------------------------------\n");
        printf("Digite as informacoes do lanche %d:\n", ultima_informacao + 1);
        numero_do_lanche[ultima_informacao] = ultima_informacao;

        printf("Digite o nome do lanche: ");
        fgets(nome[ultima_informacao], 50, stdin);

        int len = strlen(nome[ultima_informacao]);
        if (len <= 1 || (len == 2 && nome[ultima_informacao][0] == '\n')) {
            printf("Nome do lanche nao pode ser vazio. Digite novamente.\n");
            continue; // Volta ao início do loop para pedir o nome novamente
        }

        printf("Digite o preco do lanche: ");
        do{
            gets(blin);
            if(verificaNumeroReal(blin) != 1){
            
            printf("Digite numeros");
            }

        }while(verificaNumeroReal(blin) != 1);

        preco[ultima_informacao] = atof(blin);

        ultima_informacao++;

        printf("Lanche adicionado com sucesso.\n");

        printf("----------------------------------------------------------------\n");

    }while(ultima_informacao<total);

}

// Função para mostrar todos os lanches do cardápio
void mostrarLanches() {
    if (quantidade_lanches == 0) {
        printf("Nao ha lanches cadastrados no cardapio.\n");
        return;
    }

    printf("\n==== Lanches do Cardapio ====\n");
    for (int i = 0; i < ultima_informacao; i++) {
        printf("Codigo: %d\n", numero_do_lanche[i] + 1);
        printf("Nome: %s", nome[i]);
        printf("Preco: R$ %.2f\n", preco[i]);
    }
}

// Função para gerar um relatório de lanches por palavra-chave na descrição
void relatorioPorPalavraChave() {
    char blin;

    if (quantidade_lanches == 0) {
        printf("Nao ha lanches cadastrados no cardápio.\n");
        return;
    }else{
        printf("\n==== Relatorio de Lanches por Palavra-chave ====\n");

        int opcao, n;
        printf("Digite 1 para mostrar o lanche mais caro ou 2 para mostrar o lanche mais barato: ");
        do{
            blin = getch();

            if(isdigit(blin) == 0){
                printf("Digite um numero\n");
            }
        }while(isdigit(blin) == 0);

        //Esse & é para pegar o endereço da variavel blin(Coloquei isso pois não estava rodando, por conta que é caractere unico)
        opcao = atoi(&blin);

        switch (opcao) {
            case 1: {
                float maior_preco =-1;
                for (int i = 0; i < ultima_informacao; i++) {
                    if (preco[i] > maior_preco) {
                        maior_preco = preco[i];
                    }
                }
                if (maior_preco != -1) {
                    printf("Lanche mais caro:\n");
                    for (int i = 0; i < ultima_informacao; i++) {
                        if (preco[i] == maior_preco) {
                            printf("Codigo: %d\n", numero_do_lanche[i] + 1);
                            printf("Nome: %s", nome[i]);
                            printf("Preco: R$ %.2f\n", preco[i]);
                        }
                    }
                } else {
                    printf("Nenhum lanche encontrado com a palavra-chave fornecida.\n");
                }
                break;
            }
            case 2: {
                float menor_preco = preco[0];
                for (int i = 0; i < ultima_informacao; i++) {
                    if (preco[i] <= menor_preco) {
                        menor_preco = preco[i];
                        n = i;
                    }
                }

                printf("Lanche mais barato:\n");
                printf("Codigo: %d\n", numero_do_lanche[n] + 1);
                printf("Nome: %s", nome[n]);
                printf("Preco: R$ %.2f\n", preco[n]);
                break;
            }
            default:
                printf("Opcao invalida.\n");
        }
    }
}

// Função para atualizar os dados de um lanche
void atualizarLanche() {
    char blin[100];
    if (quantidade_lanches == 0) {
        printf("Nao ha lanches cadastrados no cardapio.\n");
        return;
    }

    mostrarLanches();

    int numero_do_lanche;
    printf("\nDigite o numero do lanche que deseja atualizar: ");
    scanf("%d", &numero_do_lanche);

    for (int i = 0; i < quantidade_lanches; i++) {
        if (numero_do_lanche-1 == i) {
            printf("\nDigite o nome do lanche: ");
            getchar();
            fgets(nome[i], 50, stdin);

            printf("\nDigite o preco do lanche: ");
            do{
                gets(blin);
                if(verificaNumeroReal(blin) != 1) printf("Digite numeros");
            }while(verificaNumeroReal(blin) != 1);

            preco[i] = atof(blin);

            printf("Lanche atualizado com sucesso.\n");
            return;
        }
    }

    printf("Lanche com o numero %d nao encontrado.\n", numero_do_lanche + 1);
}

// Função para mostrar a quantidade de lanches armazenados
void mostrarQuantidadeLanches() {
    printf("Quantidade de lanches armazenados: %d\n", quantidade_lanches);
}

int verificaNumero(const char numero[]){
    int i=0;

    while (numero[i]) {
        if(isdigit(numero[i]) == 0) return 0;
        i++;
    }

    return 1;
}

int verificaNumeroReal(const char numero[]){
    int i=0;

    while (numero[i]) {
        if(isdigit(numero[i]) == 0 && numero[i] != 46) return 0;
        i++;
    }

    return 1;
}