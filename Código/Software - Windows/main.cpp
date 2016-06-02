#include <iostream>
#include <stdio.h>
#include <string>
#include <locale.h> 	//Biblioteca para configurações regionais
#include <stdlib.h>
#include "GerarDiscurso.cpp"

using namespace std; 

void exibirMenu (){
	int opc=-1;
	int n = 0, m = 0, res = 0;
	char back, cn, copc;
	GerarDiscurso discurso;
	
	setlocale(LC_ALL,"");	
	system("clear");

	printf("\n\tSoftware de Produção de Discursos\n\n");
	printf("Digite o número correspondente a opção desejada.\n");
	printf("1. Gerar Discurso\n");
	printf("2. Consultar discursos armazenados em histórico\n");
	printf("0. Sair\n");
	printf("Opção: ");
	scanf("%c", &copc);
	opc = copc - '0';

	switch (opc){
		case 1: 
			system("clear");
			printf("\n\tGerar Discurso\n\n");
			printf("Informe o número de parágrafos \n0. Voltar\n\nValor: ");
			scanf("%d", &n);
			if(n == 0){
				exibirMenu ();
				break;
			}else if((n > 200) || (n < 0)){
				printf("Valor inválido. O sistema possui o limite de 200 parágrafos por discurso.\n");
				printf("Pressione qualquer tecla para voltar ao menu: ");
				getchar();
				scanf("%c", &back);
				exibirMenu ();
				break;
			}
			printf("\n\n");
			discurso.criar(n);
			
			printf("Deseja armazenar este discurso em histórico?\n1. Sim\n2. Não\nOpção: ");
			getchar();
			scanf("%c", &cn);
			n = cn - '0';
			
			switch (n){
				case 1:
					res = discurso.salvar();
					if(res == 0)
						printf("Discurso salvo com sucesso! Para consultá-lo, acesse o ítem 2 no menu.\n\n");
					else
						printf("Erro ao salvar o discurso.\n");
					printf("Pressione qualquer tecla para voltar ao menu: ");
					getchar();
					scanf("%c", &cn);
					exibirMenu ();
					break;
				case 2:
					res = discurso.apagarTmp();
					if(res != 0)
						printf("Erro ao apagar arquivo temporário.\n");
					printf("Pressione qualquer tecla para voltar ao menu: ");
					getchar();
					scanf("%c", &cn);
					exibirMenu ();
					break;
				default:
					printf("Valor inválido. Arquivo temporário gerado será apagado.\n");
					res = discurso.apagarTmp();
					if(res != 0)
						printf("Erro ao apagar arquivo temporário.\n");
					printf("Pressione qualquer tecla para voltar ao menu: ");
					getchar();
					scanf("%c", &cn);
					exibirMenu ();
					break;
			}
			break;

		case 2:
			system("clear");
			printf("\n\tHistórico de Discursos\n\n");
			printf("Digite o número correspondente ao discurso que deseja consultar:\n");
			discurso.listarSalvos();
			printf("\n0. Voltar\n");
		
			printf("Opção: ");
			getchar();
			scanf("%c", &back);
			m = back - '0';
			if(m == 0){
				exibirMenu ();
				break;
			}
			printf("\n");
			res = discurso.consultar(m);
			if(res != 0)
				printf("Discurso não existe em histórico. Verifique se o valor digitado é um número válido.\n\n");
			printf("Pressione qualquer tecla para voltar ao menu: ");
			getchar();
			scanf("%c", &back);
			exibirMenu ();
			break;

		case 0:
			printf("Tem certeza que deseja sair do programa?\n[N]. Não, voltar ao menu\n[S]. Sim\nOpção: ");
			getchar();
			scanf("%c", &back);
			if ((back == 'S') || (back == 's'))
				exit(0);
			else
				exibirMenu();
		default:
			//getchar();
			printf("Valor digitado não corresponde a nenhum ítem do menu.\n");
			//printf("Pressione qualquer tecla para voltar: ");
			//getchar();
			//scanf("%c", &back);
			exibirMenu ();
			break;
	}
}


int main() {

	exibirMenu();
	return 0;
	system("pause");
}

