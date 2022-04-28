#include <iostream>
#include <vector>
#include <string>

#ifndef Labirinto_h
#define Labirinto_h

using namespace std;

class Labirinto {

protected:
	char labirinto;

public:

	bool posicaoValida(vector<int> p);

	vector<int> SOBE(vector<int> p);

	vector<int> DIREITA(vector<int> p);

	vector<int> DESCE(vector<int> p);

	vector<int> ESQUERDA(vector<int> p);

	bool Livre(vector<string> l, vector<int> p);

	vector<int> procuraEntrada(vector<string> labirinto);

	vector<int> retornaPara(int a, vector<int> p);

	void mostraLabirinto(vector<string> l);

	void mostraPilhaDeAcoes(vector<int> a);

	vector<string> alteraLabirinto(vector<string> l, vector<int> p, char c);
};

#endif
