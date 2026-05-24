#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/arvore.h"
#include "include/fila.h"
#include "include/lista.h"
#include "include/livro.h"


void menu(Arvore* arvore, Fila* fila, Lista* lista);
void menuLivro(Arvore* arvore, Fila* fila, Lista* lista);
void limparBuffer();
void telaCadastrarLivro(Arvore* arvore);
void telaBuscaLivro(Arvore* arvore);
void telaRealizarEmprestimo(Arvore* arvore, Fila* fila, Lista* lista);
void telaDevolverLivro(Arvore* arvore, Fila* fila, Lista* lista);



int main() {
    Arvore* arvore = criarArvore();
    Fila* fila = criarFila();
    Lista* lista = criarLista();
    menu(arvore, fila, lista);

    return 0;
}

void menu(Arvore* arvore, Fila* fila, Lista* lista) {
    int opcao;

    do {
        printf("\n=========================================\n");
        printf("    SISTEMA DE GERENCIAMENTO DE BIBLIOTECA\n");
        printf("=========================================\n");
        printf("1. Gerenciamento de Livros\n");
        printf("2. Exibir fila de reservas\n");
        printf("3. Exibir historico de emprestimos\n");
        printf("4. Exibir quantidade de livros cadastrados\n");
        printf("5. Exibir altura da arvore\n");
        printf("0. Sair\n");
        printf("=========================================\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Digite um número. \n");
            limparBuffer();
            opcao = -1;
            continue;
        }

        switch (opcao)
        {
            case 1:
                menuLivro(arvore, fila, lista);
                break;
            case 2:
                printf("\n--- Fila de Reservas ---\n");
                exibirReservas(fila);
                break;
            case 3:
                printf("\n--- Histórico de Empréstimos ---\n");
                listarEmprestimos(lista);
                break;
            case 4:
                printf("\nQuantidade de livros cadastrados: %d\n", contarLivros(arvore));
                break;
            case 5:
                printf("\nAltura da árvore: %d\n", calcularAlturaArvore(arvore));
                break;
            case -1:
                break;
            case 0:
                printf("Encerrando o sistema de biblioteca...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
    
}

void menuLivro(Arvore* arvore, Fila* fila, Lista* lista)
{
    int opcao;
    do {
        
        printf("\n=========================================\n");
        printf("    GERENCIAMENTO DE LIVROS\n");
        printf("=========================================\n");
        printf("1. Cadastrar novo livro\n");
        printf("2. Buscar livro por codigo\n");
        printf("3. Listar livros em ordem crescente de codigo\n");
        printf("4. Listar livros em pre-ordem\n");
        printf("5. Listar livros em pos-ordem\n");
        printf("6. Realizar emprestimo de livro\n");
        printf("7. Devolver livro\n");
        printf("0. Voltar\n");
        printf("=========================================\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Digite um número. \n");
            limparBuffer();
            opcao = -1;
            continue;
        }
        
        switch (opcao)
        {
            case 1:
                telaCadastrarLivro(arvore);
                break;
            
            case 2:
                telaBuscaLivro(arvore);
                break;
            case 3:
                printf("\n--- Livros em Ordem Crescente ---\n");
                listarLivrosEmOrdem(arvore);
                break;
            case 4:
                printf("\n--- Livros em Pré-Ordem");
                listarLivrosPreOrdem(arvore);
                break;
            case 5:
                printf("\n--- Livros em Pós-Ordem ---");
                listarLivrosPosOrdem(arvore);
                break;
            case 6:
                telaRealizarEmprestimo(arvore, fila, lista);
                break;
            case 7:
                telaDevolverLivro(arvore, fila, lista);
                break;
            case -1:
                break;
            case 0:
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void telaCadastrarLivro(Arvore* arvore) {
    int codigo, ano, qtd;
    char titulo[100], autor[100];

    printf("\n--- Cadastro de Novo Livro ---\n");
    printf("Código: ");
    scanf("%d", &codigo);
    limparBuffer();

    if (buscarLivroArvore(arvore, codigo) != NULL) {
        printf("Erro: Já existe um livro cadastrado com o código %d!\n", codigo);
        return;
    }

    printf("Título: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';

    printf("Author: ");
    fgets(autor, sizeof(autor), stdin);
    autor[strcspn(autor, "\n")] = '\0';

    printf("Ano de Publicação: ");
    scanf("%d", &ano);
    printf("Quantidade Total de Exemplares: ");
    scanf("%d", &qtd);
    limparBuffer();

    Livro* novo = criarLivro(codigo, titulo, autor, ano, qtd);
    if (novo != NULL) {
        inserirLivroArvore(arvore, novo);
        printf("Livro cadastrado e inserido na árvore com sucesso!\n");
    }
}

void telaBuscaLivro(Arvore* arvore) {
    int codigo;
    printf("\nDigire o código do livro para busca: ");
    scanf("%d", &codigo);
    limparBuffer();

    Livro* livro = buscarLivroArvore(arvore, codigo);
    if (livro != NULL) {
        printf("\n--- Livro Encontrado ---\n");
        exibirLivro(livro);
    } else {
        printf("Erro: Livro com código %d não foi encontrado. \n", codigo);
    }
}

void telaRealizarEmprestimo(Arvore* arvore, Fila* fila, Lista* lista) {
    int codigo;
    char nomeUsuario[100];

    printf("\n--- Realizar Empréstimo ---\n");
    printf("Nome do usuário: ");
    limparBuffer();
    fgets(nomeUsuario, sizeof(nomeUsuario), stdin);
    nomeUsuario[strcspn(nomeUsuario, "\n")] = '\0';

    printf("Código do livro: ");
    scanf("%d",&codigo);
    limparBuffer();

    Livro* livro = buscarLivroArvore(arvore, codigo);
    if (livro == NULL) {
        printf("Erro: Livro inexistente no acervo. \n");
        return;
    }

    if (obterQuantidadeDisponivel(livro) > 0) {
        emprestarExemplar(livro);

        Emprestimo emp;
        strcpy(emp.nomeUsuario, nomeUsuario);
        emp.codigoLivro = codigo;
        strcpy(emp.tituloLivro, livro -> titulo);

        inserirEmprestimo(lista, emp);
        printf("Empréstimo realizado com sucesso para %s!\n", nomeUsuario);
    } else {
        char opcaoReserva;
        printf("Não há exemplares disponíveis. Deseja entrar na fila de reserva? (S/N): ");
        scanf("%c", &opcaoReserva);
        limparBuffer();

        if (opcaoReserva == 'S' || opcaoReserva == 's') {
            Reserva res;
            strcpy(res.nomeUsuario, nomeUsuario);
            res.codigoLivro = codigo;
            enfileirarReserva(fila, res);
            printf("Usuário adicionado à fila de reservas com sucesso.\n");
        }
    }
}

void telaDevolverLivro(Arvore* arvore, Fila* fila, Lista* lista) {
    int codigo;
    printf("\nDigite o código do livro para devolução: ");
    scanf("%d", &codigo);
    limparBuffer();

    Livro* livro = buscarLivroArvore(arvore, codigo);
    if (livro == NULL) {
        printf("Erro: Livro não pertence ao acervo desta biblioteca.\n");
        return;
    }
    
    devolverExemplar(livro);
    printf("Exemplar devolvido ao acervo. Quantidade atualizada.\n");
    
    int qtdOriginal = fila -> quantidade;
    int atendeu = 0;

    for (int i = 0; i < qtdOriginal; i++) {
        Reserva reservaRemovida = desenfileirarReserva(fila);

        if (reservaRemovida.codigoLivro == livro -> codigo && atendeu == 0) {       

            emprestarExemplar(livro);
            Emprestimo emp;
            strcpy(emp.nomeUsuario, reservaRemovida.nomeUsuario);
            emp.codigoLivro = reservaRemovida.codigoLivro;
            strcpy(emp.tituloLivro, livro -> titulo);
            inserirEmprestimo(lista, emp);

            printf("O usuário %s saiu da fila de espera com o livro %s", reservaRemovida.nomeUsuario, livro->titulo);
            atendeu = 1;
        } else {
            enfileirarReserva(fila, reservaRemovida);
        }
    }
}