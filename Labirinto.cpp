#include <iostream>
#include <vector>
#include <string>
#include "Labirinto.h"

using namespace std;

bool Labirinto::posicaoValida(vector<int> p) {
	if (p[0] < 0 || p[0] > 19) return false;
	if (p[1] < 0 || p[1] > 20) return false;
	return true;
}

vector<int>  Labirinto::SOBE(vector<int> p) {
	vector<int> r = { p[0] - 1,p[1] };
	return r;
}

vector<int>  Labirinto::DIREITA(vector<int> p) {
	vector<int> r = { p[0],p[1] + 1 };
	return r;
}

vector<int>  Labirinto::DESCE(vector<int> p) {
	vector<int> r = { p[0] + 1,p[1] };
	return r;
}

vector<int>  Labirinto::ESQUERDA(vector<int> p) {
	vector<int> r = { p[0],p[1] - 1 };
	return r;
}

bool  Labirinto::Livre(vector<string> l, vector<int> p) {
	if (posicaoValida(p) && (l[p[0]].at(p[1]) == ' ' || l[p[0]].at(p[1]) == 'S')) return true;
	return false;
}

vector<int>  Labirinto::procuraEntrada(vector<string> labirinto) {
	vector<int> pos = { 0, 0 };
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 21; j++) {
			if (labirinto[i].at(j) == 'E') {
				pos[0] = i;
				pos[1] = j;
				break;
			}
		}
	}
	return pos;
}

vector<int>  Labirinto::retornaPara(int a, vector<int> p) {
	vector<int> r = { 0, 0 };
	if (a == 4) 	return DESCE(p);
	else if (a == 3)	return ESQUERDA(p);
	else if (a == 2)	return SOBE(p);
	else 		return DIREITA(p);

}

void  Labirinto::mostraLabirinto(vector<string> l) {
	for (int i = 0; i < 20; i++)
		cout << l[i] << "\n";
}

void  Labirinto::mostraPilhaDeAcoes(vector<int> a) {
	if (!a.empty()) {
		for (int i = 0; i < a.size(); i++) {
			cout << a[i];
			if (i != a.size() - 1) cout << ", ";
		}
	}
	cout << "\n";
}

vector<string>  Labirinto::alteraLabirinto(vector<string> l, vector<int> p, char c) {
	string alterada = l[p[0]];
	alterada[p[1]] = c;
	l[p[0]] = alterada;
	return l;
}
