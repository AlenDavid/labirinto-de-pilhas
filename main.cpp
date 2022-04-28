#include <iostream>

#include <string>
#include "Labirinto.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
	bool parede = false;
	vector<int> posicaoAtual = {0, 0};
	vector<int> move = {4};
	vector<string> labirinto = {
		"XXXXXXXXXXXXXXXXXXXXX",
		"X     X     X     X X",
		"XX XX XXXXX X X X   X",
		"X   X       XXX XXX X",
		"X X X XXXXXXX   X   X",
		"X X   X   X X X   X X",
		"X XXXXX X X   XXXXX X",
		"X X     X XXX  X    X",
		"X X X X X   XX XX XXX",
		"X X XXX X X     X   X",
		"E X X X X XXXXX XXX X",
		"X     X X   X X X   X",
		"X XXXXX XXX X XXX X X",
		"X X       X X   X X X",
		"X   XXX X X XXX X X X",
		"XXX X X X X X X X XXX",
		"X X   X X   X   X   X",
		"X XXX XXXXXXXXX XXX X",
		"X                 X X",
		"XXXXXXXXXXXXXXXXXXXSX",
	};

  Labirinto l = Labirinto();

	posicaoAtual = l.procuraEntrada(labirinto);
	cout << "Entrada: ("<<posicaoAtual[0]<<", "<<posicaoAtual[1]<<")\n\n";
	while (!move.empty()){
		if(!l.posicaoValida(posicaoAtual)){
			cout << "Um erro inesperado ocorreu: Posição Inválida!\n";
			break;
		}
		//cout << "Posição Atual: ("<< posicaoAtual[0] <<", "<<posicaoAtual[1] << ")\n";
		//cout << "Ações: "; mostraPilhaDeAcoes(acoes);
		if(labirinto[posicaoAtual[0]].at(posicaoAtual[1]) == 'S'){
			parede = true;
			break;
		}
		labirinto = l.alteraLabirinto(labirinto, posicaoAtual, '*');	
		int &acaoAtual = move.back();
		switch (acaoAtual){
			case 4:
				if(l.Livre(labirinto, l.SOBE(posicaoAtual))){
					move.push_back(4);
					posicaoAtual = l.SOBE(posicaoAtual);
				}else{
					acaoAtual--;
				}
				break;

			case 3:
				if(l.Livre(labirinto, l.DIREITA(posicaoAtual))){
					move.push_back(4);
					posicaoAtual = l.DIREITA(posicaoAtual);
				}else{
					acaoAtual--;
				}
				break;


			case 2:
				if(l.Livre(labirinto, l.DESCE(posicaoAtual))){
					move.push_back(4);
					posicaoAtual = l.DESCE(posicaoAtual);
				}else{
					acaoAtual--;
				}
				break;

			case 1:
				if(l.Livre(labirinto, l.ESQUERDA(posicaoAtual))){
					move.push_back(4);
					posicaoAtual = l.ESQUERDA(posicaoAtual);
				}else{
					acaoAtual--;
				}
				break;
		}
		
		if(acaoAtual == 0){
			move.pop_back();
			if(move.empty()) continue;
			int &acao = move.back();
			labirinto = l.alteraLabirinto(labirinto, posicaoAtual, '!');
			posicaoAtual = l.retornaPara(acao, posicaoAtual);
			acao--;
		}
		//mostraLabirinto(labirinto);
		//cout << "Posição Nova: ("<< posicaoAtual[0] <<", "<<posicaoAtual[1] << ")\n";
		//cout << "Ações: "; mostraPilhaDeAcoes(acoes);
		//cout << "\n";
	}
	
	l.mostraLabirinto(labirinto);
		
	if(parede){
		cout << "\nSaída: ("<<posicaoAtual[0]<<", "<<posicaoAtual[1]<<")\n";
		cout << "A solução foi encontrada\n";
	
	}else{
		cout << "Não existe\n";	
	}
	return 0;
}
