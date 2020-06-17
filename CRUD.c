
//Creating a CRUD, to praticate the memory allocation.

// Synthesis
//   Objetive: Creating  a helper for a store
//   Input: Code, Description and Value of each product.
//   Output: Product Listing.

//   Author: Caio Carvalho de Noronha.

//Library:

#include <stdio.h>
#include<string.h>
#include<locale.h>

//structType
struct tipoProdutos {
	int codigo;
	char descricao[20];
	float valor;

};

//Functions:
int menu(void);
void incluir( struct tipoProdutos produto, struct tipoProdutos produtos[], int *quantProdutos);
void listar( struct tipoProdutos produtos[], int quant);
void consultar( struct tipoProdutos produtos[], int quant);
void editar( struct tipoProdutos produto, struct tipoProdutos produtos[], int quant);
void excluir( struct tipoProdutos produtos[], int  *quantProdutos);

//Global variables:
#define TAM 1000

int main(void) {

	//Variables:
	struct tipoProdutos produtos[TAM];
	struct tipoProdutos produto;
	int opcao,quantProdutos=0;

	//Instructions:
	setlocale(LC_ALL,"portuguese");


	//Menu.
	printf("Bem vindo a loja! O que deseja fazer? \n \n" );
	do {
		opcao = menu();
		system("CLS");
		switch (opcao) {

				//Add Product.
			case 1:
				incluir(produto, produtos, &quantProdutos);
				break;

				//List.
			case 2:
				listar(produtos, quantProdutos);
				break;

				//Consult.
			case 3:
				consultar(produtos, quantProdutos);
				break;

				//Edit.
			case 4:
				editar(produto, produtos, quantProdutos);
				break;

				//Delete Product.
			case 5:
				excluir(produtos, &quantProdutos);
				break;
		}
	} while(opcao != 6);
	printf("Obrigado por usar o programa!");
	return 0;
}



// Síntese
//   Objetivo: Apresentar o Menu e ler a opção do usário.
//   Entrada: Opções do usuário.
//   Saída: Opções de Menu.
int menu(void) {

	//Vari·veis:

	int opcao;

	//InstrunÁıes:

	printf("1 - Incluir\n");
	printf("2 - Listar\n");
	printf("3 - Consultar\n");
	printf("4 - Editar\n");
	printf("5 - Excluir\n");
	printf("6 - Sair\n\n");
	scanf("%i", &opcao);
	while(opcao<1 || opcao>6) {
		puts("Código inválido! Tente Novamente!");
		scanf("%i", &opcao);
	}
	return opcao;
}


// Síntese
//   Objetivo: Adicionar novos produtos.
//   Entrada: Código, descrição e valor.
//   Saida: Novo produto.
void incluir( struct tipoProdutos produto, struct tipoProdutos produtos[], int *quantProdutos) {

	//Vari·veis:

	char opcao;

	//InstrunÁıes:
	if (*quantProdutos < TAM) {
		do {
			printf("Qual o código do produto %i?\n", *quantProdutos+1);
			scanf("%i",&produto.codigo);
			printf("Qual a Descrição do produto %i?\n", *quantProdutos+1);
			fflush(stdin);
			gets(produto.descricao);
			printf("Qual o valor do produto %i?\n", *quantProdutos+1);
			scanf("%f",&produto.valor);
			system("CLS");
			printf("Deseja confirmar o produto?(S ou N)\n\nCancelar(C)\n");

			opcao = getch();
			opcao = toupper(opcao);

			while(opcao!= 'N' && opcao!='S' && opcao!='C') {
				printf("OpÁ„o Inválida! Tente Novamente!\n");
				opcao = getch();
				opcao = toupper(opcao);
				system("CLS");
			}
		} while(opcao == 'N');

		system("CLS");

		if(opcao == 'S') {
			produtos[*quantProdutos].codigo = produto.codigo;
			strcpy(produtos[*quantProdutos].descricao, produto.descricao);
			produtos[*quantProdutos].valor = produto.valor;
			printf("Produto cadastrado com sucesso!\n");
			(*quantProdutos)++;
		} else
			printf("Produto encerrado com sucesso!\n");
	} else
		printf("Quantidade de produtos lotada!");

	system("PAUSE");
	system("CLS");
}


// Síntese
//   Objetivo: Listar todos os produtos.
//   Entrada: -
//   Saída: Todos os produtos.
void listar( struct tipoProdutos produtos[], int quant) {

	//Vari·veis:

	int i=0;

	//InstrunÁıes:

	printf("Produto		Código			Descrição		Valor\n");
	for (i=0; i<quant; i++) {
		printf("%i		%i			%s			R$%.2f\n", i+1, produtos[i].codigo, produtos[i].descricao, produtos[i].valor);
	}
	printf("\n\n");
	system("PAUSE");
	system("CLS");
}


// Síntese
//   Objetivo: Consultar produto.
//   Entrada: código do consultado.
//   Saída: Produto consultado.
void consultar( struct tipoProdutos produtos[], int quant) {

	//Vari·veis:

	int i=0, consulta, confirma=0;

	//InstrunÁıes:
	printf("Qual o código do produto que deseja consultar?\n");
	scanf("%i",&consulta);
	for(i=0; i<=quant; i++) {
		if(consulta==produtos[i].codigo) {
			printf("\n\nCódigo			Descrição		Valor\n");
			printf("%i			%s			R$%.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].valor);
			confirma=1;
		}
	}
	if(confirma==1) {
		printf("Produto encontrado!\n\n");
	} else {
		printf("Produto não encontrado!\n\n");
	}
	system("PAUSE");
	system("CLS");
}


// Síntese
//   Objetivo: Editar o produto requerido.
//   Entrada: Produto consultado.
//   Saída: Produto Editado.
void editar( struct tipoProdutos produto, struct tipoProdutos produtos[], int quant) {

	//Vari·veis:

	int i=0, consulta, confirma=0;
	char opcao;

	//InstrunÁıes:

	printf("Qual o código do produto que deseja editar?\n");
	scanf("%i",&consulta);
	for(i=0; i<=quant; i++) {
		if(consulta==produtos[i].codigo) {
			printf("\n\nCódigo			Descrição		Valor\n");
			printf("%i			%s			R$%.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].valor);
			confirma=1;
		}
	}

	if(confirma==1) {
		printf("Produto encontrado!\n\n");

		do {
			printf("Qual o novo código do produto?\n");
			scanf("%i",&produto.codigo);
			printf("Qual a nova Descrição do produto?\n");
			fflush(stdin);
			gets(produto.descricao);
			printf("Qual o novo valor do produto?\n");
			scanf("%f", &produto.valor);
			system("CLS");

			printf("Deseja confirmar a edição do produto?(S ou N)\n\nCancelar(C)\n");

			opcao = getch();
			opcao = toupper(opcao);

			while(opcao!= 'N' && opcao!='S' && opcao!='C') {
				printf("Opção Inválida! Tente Novamente!\n");
				opcao = getch();
				opcao = toupper(opcao);
				system("CLS");
			}
		} while(opcao == 'N');

		system("CLS");

		if(opcao == 'S') {
			produtos[i].codigo = produto.codigo;
			strcpy(produtos[i].descricao, produto.descricao);
			produtos[i].valor = produto.valor;
			printf("Produto editado com sucesso!\n");

		} else
			printf("Produto encerrado com sucesso!\n");
	} else
		printf("Produto não encontrado!\n\n");

	system("PAUSE");
	system("CLS");
}


// Síntese
//   Objetivo: Excluir um produto.
//   Entrada: Produto requerido.
//   Saída: Produto excluido.
void excluir( struct tipoProdutos produtos[], int  *quantProdutos) {

	//Vari·veis:

	int i=0, i2=0, consulta, confirma=0;
	char opcao;

	//InstrunÁıes:

	printf("Qual o código do produto que excluir consultar?\n");
	scanf("%i",&consulta);
	for(i=0; i<=*quantProdutos; i++) {
		if(consulta==produtos[i].codigo) {
			printf("\n\nCódigo			Descrição		Valor\n");
			printf("%i			%s			R$%.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].valor);
			confirma=1;
		}
	}
	system("CLS");

	if(confirma==1) {
		printf("Produto encontrado!\n\n");

		printf("Deseja excluir o produto?(S ou N)\n\nCancelar(C)\n");

		opcao = getch();
		opcao = toupper(opcao);

		while(opcao!= 'N' && opcao!='S' && opcao!='C') {
			printf("Opção Inválida! Tente Novamente!\n");
			opcao = getch();
			opcao = toupper(opcao);
			system("CLS");

		}

		if(opcao=='S') {
			produtos[i].codigo=0;
			strcpy(produtos[i].descricao," ");
			produtos[i].valor=0;

			(*quantProdutos)--;

			for(i2=0; i2<=*quantProdutos; i2++) {
				if(i2<=i) {
					produtos[i2-1].codigo=produtos[i2].codigo;
					strcpy(produtos[i2-1].descricao,produtos[i2].descricao);
					produtos[i2-1].valor=produtos[i2].valor;
				}

			}
		} else
			printf("Produto não excluído com sucesso!\n");
	} else
		printf("Produto não encontrado!\n\n");

	system("PAUSE");
	system("CLS");
}
