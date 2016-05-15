#include <iostream>
#include <stdio.h>
#include <string>
#include <locale.h> 	//Biblioteca para configurações regionais
#include "GerarDiscurso.cpp"

using namespace std; 

void exibirMenu (){
	printf("\n\tSoftware de Produção de Discursos\n\n");
	printf("Digite o número correspondente a opção desejada.\n");
	printf("1. Gerar Discurso\n");
	printf("2. Consultar discursos armazenados em histórico\n");
	printf("0. Sair\n");
	printf("Opção: ");
}


int main() {
	int opc=-1;
	int n = 0, m = 0, res = 0;
	GerarDiscurso discurso;
	setlocale(LC_ALL,"");
	
	exibirMenu();
	scanf("%d", &opc);
	
	switch (opc){
		case 1: 
			printf("\n\tGerar Discurso\n\n");
			printf("Informe o número de parágrafos: ");
			scanf("%d", &n);
			if(n > 200){
				printf("Valor inválido. O sistema possui o limite de 200 parágrafos por discurso. ");
				break; //voltar aqui
			}
			discurso.criar(n);
			
			printf("Deseja armazenar este discurso em histórico?\n1. Sim\n2. Não\nOpção: ");
			scanf("%d", &n);

			switch (n){
				case 1:
					res = discurso.salvar();
					if(res == 0)
						printf("Discurso salvo com sucesso! Para consultá-lo, acesse o ítem 2 no menu\n");
					else
						printf("Erro ao salvar o discurso.\n");
					printf("Retornar ao menu.\n");
					break;
				case 2:
					res = discurso.apagarTmp();
					if(res != 0)
						printf("Erro ao apagar arquivo temporário.\n");
					printf("Retornar ao menu.\n");
					break;
				default:
					printf("Número inválido.\n");
					break;
			}
			break;

		case 2:
			printf("\n\tHistórico de Discursos\n\n");
			printf("Digite o número correspondente ao discurso que deseja consultar:\n");
			discurso.listarSalvos();
			printf("Opção: ");
			scanf("%d", &m);
			res = discurso.consultar(m);
			if(res != 0)
				printf("Erro ao acessar discurso.\n");
			printf("Retornar ao menu.\n");
			break;

		case 0:
			return 0;
		default:
			printf("Número inválido.\n");
			break;
	}

	
	//system("pause");
}

