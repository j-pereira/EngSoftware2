#ifndef GERARDISCURSO_H
#include <iostream>
#include <string>

using namespace std;

class GerarDiscurso{
	private: 
		string c1[10], c2[10], c3[10], c4[10];
	public:
		GerarDiscurso();
		void criar(int num);
		void exibir(string discurso);
		int salvar();
		int apagarTmp();
		int listarSalvos();
		int consultar(int i);
};

#endif