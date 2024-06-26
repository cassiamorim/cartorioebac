#include <stdio.h>   // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  // Biblioteca de aloca��es de texto por regi�o
#include <string.h>  // Biblioteca respons�vel por cuidar das strings

void registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
    // In�cio de cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final de cria��o de vari�veis/string

    printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
    scanf("%s", cpf); // %s refere-se a string

    strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings

    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo e o 'w' significa escrever
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(file, "%s,", cpf); // Salva o valor da vari�vel com uma v�rgula
    fclose(file); // Fecha o arquivo

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(file, "%s,", nome);
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(file, "%s,", sobrenome);
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(file, "%s", cargo);
    fclose(file);

    system("pause");
}

void consulta()
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
        return;
    }

    printf("\nEssas s�o as informa��es do usu�rio:\n");
    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("%s", conteudo);
    }
    printf("\n\n");
    fclose(file);
    system("pause");
}

void deletar()
{
    char cpf[40];
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0)
    {
        printf("Usu�rio deletado com sucesso!\n");
    }
    else
    {
        printf("Erro ao deletar o usu�rio!\n");
    }
    system("pause");
}

int main()
{
    int opcao = 0; // Definindo vari�veis
    char senhadigitada[10];
    const char senha[] = "admin";

    printf("### Cart�rio da EBAC ###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);

    if (strcmp(senhadigitada, senha) == 0)
    {
        for (;;)
        {
            system("cls"); // Respons�vel por limpar a tela

            setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

            printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu
            printf("Escolha a op��o desejada do menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n");
            printf("\t4 - Sair do sistema\n");
            printf("Op��o: "); // Fim do menu

            scanf("%d", &opcao); // Armazenando a escolha do usu�rio

            system("cls");

            switch (opcao) // In�cio da sele��o do menu
            {
            case 1:
                registro(); // Chamada de fun��es
                break;

            case 2:
                consulta();
                break;

            case 3:
                deletar();
                break;
                
            case 4:
            printf("Obrigado por utilizar o sistema!\n");
            return 0;

    

            default:
                printf("Essa op��o n�o est� dispon�vel\n");
                system("pause");
                break;
            }
        }
    }
    else
    {
        printf("Senha incorreta!\n");
    }

    return 0;
}

