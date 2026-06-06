# Sistema de Gerenciamento de Biblioteca

## Descrição

Este projeto foi desenvolvido para a disciplina de Estrutura de Dados e tem como objetivo implementar um Sistema de Gerenciamento de Biblioteca utilizando a linguagem C. O sistema permite o cadastro, consulta, listagem, empréstimo, devolução e reserva de livros, aplicando conceitos fundamentais de Tipos Abstratos de Dados (TADs), estruturas lineares e estruturas não lineares.

Todas as estruturas de dados foram implementadas manualmente, sem o uso de bibliotecas prontas para armazenamento dinâmico.

## Objetivos

* Aplicar os conceitos de TADs em um sistema real.
* Utilizar estruturas lineares e não lineares para resolver problemas de gerenciamento.
* Desenvolver operações de cadastro, busca e controle de empréstimos de livros.
* Praticar manipulação dinâmica de memória em linguagem C.

## Estruturas de Dados Utilizadas

### Árvore Binária de Busca (ABB)

A ABB é a estrutura principal do sistema e é responsável pelo armazenamento e organização dos livros cadastrados. Cada livro possui um código identificador único utilizado como chave para inserção e busca na árvore.

Operações realizadas:

* Inserção de livros;
* Busca de livros por código;
* Remoção de livros;
* Listagem ordenada dos livros.

### Fila

A fila é utilizada para controlar as reservas de livros que já se encontram emprestados.

Operações realizadas:

* Inserção de reservas;
* Atendimento das reservas em ordem de chegada;
* Consulta da fila de espera.

### Lista Encadeada

A lista encadeada é utilizada para armazenar o histórico de empréstimos realizados no sistema.

Informações registradas:

* Livro emprestado;
* Usuário;
* Data do empréstimo;
* Data de devolução.

## Funcionalidades

* Cadastro de livros;
* Consulta de livros;
* Listagem de livros cadastrados;
* Empréstimo de livros;
* Devolução de livros;
* Reserva de livros indisponíveis;
* Registro do histórico de empréstimos.

## Estrutura do Projeto

```text
Projeto/
│
├── README.md
│
├── data/
│   └── Arquivos de armazenamento da biblioteca
│
└── src/
    ├── include/
    │   ├── biblioteca.h
    │   ├── livro.h
    │   ├── fila.h
    │   ├── lista.h
    │   └── arvore.h
    │
    ├── biblioteca.c
    ├── livro.c
    ├── fila.c
    ├── lista.c
    ├── arvore.c
    └── main.c
```

## Tecnologias Utilizadas

* Linguagem C
* GCC
* Estruturas de Dados:

  * Árvore Binária de Busca (ABB)
  * Fila
  * Lista Encadeada

## Como Compilar

```bash
gcc src/*.c -I src/include -o app
```

## Como Executar

```bash
./app
```

## Equipe

* Cauã Maciel
* Pedro Henrique
* Ramon Venâncio

