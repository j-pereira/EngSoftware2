#include "GerarDiscurso.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

GerarDiscurso::GerarDiscurso(){
	c1[0] = "Caros colegas, ";
	c1[1] = "Por outro lado, ";
	c1[2] = "Não podemos esquecer que ";
	c1[3] = "Do mesmo modo, ";
	c1[4] = "A prática mostra que ";
	c1[5] = "Nunca é demais insistir que ";
	c1[6] = "A experiência mostra que ";
	c1[7] = "É fundamental resaltar que ";
	c1[8] = "O incentivo ao avanço tecnológico, assim como ";
	c1[9] = "Assim mesmo, ";

	c2[0] = "a execução deste projeto ";
	c2[1] = "a complexidade dos estudos efetuados ";
	c2[2] = "a atual estrutura de organização ";	
	c2[3] = "o novo modelo estrutural aqui preconizado ";
	c2[4] = "o desenvolvimento de formas distintas de atuação ";
	c2[5] = "a constante divulgação das informações ";
	c2[6] = "a consolidação das estruturas ";
	c2[7] = "a análise dos diversos resultados ";
	c2[8] = "o início do programa de formação de atitudes ";
	c2[9] = "a expansão de nossa atividade ";

	c3[0] = "nos obriga a análise ";
	c3[1] = "cumpre um papel essencial na formulação ";
	c3[2] = "auxilia a preparação e a estruturação ";
	c3[3] = "contribui para a correta determinação ";
	c3[4] = "assume importantes posições na definição ";
	c3[5] = "facilita a definição ";
	c3[6] = "prejudica a percepção da importância ";
	c3[7] = "oferece uma boa oportunidade de verificação ";
	c3[8] = "acarreta um processo de reformulação ";
	c3[9] = "exige precisão e definição ";
	
	c4[0] = "das nossas ações de desenvolvimento futuro. ";
	c4[1] = "das nossas metas financeiras e administrativas. ";
	c4[2] = "das atitudes e das atribuições da diretoria. ";
	c4[3] = "das novas proposições. ";
	c4[4] = "das opções básicas para o sucesso do programa. ";
	c4[5] = "do nosso sistema de formação de quadros. ";
	c4[6] = "das condições apropriadas para os negócios. ";
	c4[7] = "dos índices pretendidos. ";
	c4[8] = "das formas de ação. ";
	c4[9] = "dos conceitos de participação geral. ";
}


void GerarDiscurso :: criar(int num){
	int i=0, j=0;
	int r1=0, r2=0, r3=0, r4=0, frasesP=0;
	string discurso = "";
	const char *dtemp;
	FILE *tmp;

	tmp = fopen("tmp.txt", "w");

	while(i < num){
		frasesP = rand() % 3 + 3;

		while(j < frasesP){
			r1 = rand() % 9;
			r2 = rand() % 9;
			r3 = rand() % 9;
			r4 = rand() % 9;

			discurso += c1[r1] + c2[r2] + c3[r3] + c4[r4];
			j++;
		}

		discurso += "\n\n";
		j=0;
		i++;
	}
	dtemp = discurso.c_str();
	fputs(dtemp, tmp);
	fclose(tmp);
	exibir(discurso);
}


void GerarDiscurso :: exibir(string discurso){
	cout << discurso << endl;
}


int GerarDiscurso :: salvar(){
	FILE *arq;
	int i=1;
	string path = "", c;
	const char *caminho;

	while(1){
		ostringstream convert;
		convert << i;
		c = convert.str();
		path += "Discursos/";
		path += c;
		path += ".txt";
		caminho = path.c_str();

		cout << caminho << endl;

		arq = fopen(caminho, "r");
		if(arq == NULL)
			break;
		fclose(arq);
		path = "";
		i++;
	}
	
	return (rename("tmp.txt", caminho));
}



int GerarDiscurso :: apagarTmp(){
	return (remove("tmp.txt"));
}


void GerarDiscurso :: listarSalvos(){
	FILE *arq;
	int i=1;
	string path = "", c;
	const char *caminho;

	while(1){
		ostringstream convert;
		convert << i;
		c = convert.str();
		path += "Discursos/";
		path += c;
		path += ".txt";
		caminho = path.c_str();

		arq = fopen(caminho, "r");
		if(arq == NULL)
			break;

		cout << i << ". " << caminho << endl;
		fclose(arq);
		path = "";
		i++;
	}
}


int GerarDiscurso :: consultar(int i){
	FILE *arq;
	string path = "", c;
	char cadeia[250];
	const char *caminho;

	ostringstream convert;
	convert << i;
	c = convert.str();
	path += "Discursos/";
	path += c;
	path += ".txt";
	caminho = path.c_str();

	arq = fopen(caminho, "r");
	if(arq == NULL){
		return 1;
	}else{
		while(feof(arq) == 0){
			fgets(cadeia, 250, arq);
			cout << cadeia;
		}
	}
	
}