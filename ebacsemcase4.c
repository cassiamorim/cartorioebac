#include <stdio.h>   // Biblioteca de comunicação com o usuário
#include <stdlib.h>  // Biblioteca de alocação de espaço em memória
#include <locale.h>  // Biblioteca de alocações de texto por região
#include <string.h>  // Biblioteca responsável por cuidar das strings

void registro() // Função responsável por cadastrar os usuários no sistema
{
    // Início de criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final de criação de variáveis/string

    printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
    scanf("%s", cpf); // %s refere-se a string

    strcpy(arquivo, cpf); // Responsável por copiar os valores das strings

    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo e o 'w' significa escrever
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(file, "%s,", cpf); // Salva o valor da variável com uma vírgula
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
        printf("Não foi possível abrir o arquivo, não localizado!\n");
        return;
    }

    printf("\nEssas são as informações do usuário:\n");
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
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0)
    {
        printf("Usuário deletado com sucesso!\n");
    }
    else
    {
        printf("Erro ao deletar o usuário!\n");
    }
    system("pause");
}

int main()
{
    int opcao = 0; // Definindo variáveis
    char senhadigitada[10];
    const char senha[] = "admin";

    printf("### Cartório da EBAC ###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);

    if (strcmp(senhadigitada, senha) == 0)
    {
        for (;;)
        {
            system("cls"); // Responsável por limpar a tela

            setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

            printf("### Cartório da EBAC ###\n\n"); // Início do menu
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n");
            printf("\t4 - Sair do sistema\n");
            printf("Opção: "); // Fim do menu

            scanf("%d", &opcao); // Armazenando a escolha do usuário

            system("cls");

            switch (opcao) // Início da seleção do menu
            {
            case 1:
                registro(); // Chamada de funções
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
                printf("Essa opção não está disponível\n");
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

