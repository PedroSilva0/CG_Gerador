#define _USE_MATH_DEFINES   //vhjbnvbnvbnm
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

void areaPlana(float altura, float comprimento,char* filename){
	ofstream file;
	file.open(filename, ios::ate);
	
	//triangulo 1

	file << -comprimento / 2 << " " << altura / 2 << " " << 0 << "\n" ;
	file << -comprimento / 2 << " " << -altura / 2 << " " << 0 << "\n";
	file << comprimento / 2 << " " << altura / 2 << " " << 0 << "\n";

	//tri�ngulo 2
	file << comprimento / 2 << " " << altura / 2 << " " << 0 << "\n";
	file << -comprimento / 2 << " " << -altura / 2 << " " << 0 << "\n";
	file << comprimento / 2 << " " << -altura / 2 << " " << 0 << "\n";
	file.close();
}

void paralelipipedo(float altura, float comprimento, float largura, char* filename){
	ofstream file;
	file.open(filename, ios::ate);
	//face frontal

	//triangulo 1

	file << -comprimento / 2 << " " << altura / 2 << " " << largura / 2 << "\n";
	file << -comprimento / 2 << " " << -altura / 2 << " " << largura / 2 << "\n";
	file << comprimento / 2 << " " << altura / 2 << " " << largura / 2 << "\n";

	//tri�ngulo 2
	file << comprimento / 2 << " " << altura / 2 << " " << largura / 2 << "\n";
	file << -comprimento / 2 << " " << -altura / 2 << " " << largura / 2 << "\n";
	file << comprimento / 2 << " " << -altura / 2 << " " << largura / 2 << "\n";

	//face traseira
	//triangulo 3

	file << -comprimento / 2 << " " << altura / 2 << " " << -largura / 2 << "\n";
	file << comprimento / 2 << " " << altura / 2 << " " << -largura / 2 << "\n";
	file << -comprimento / 2 << " " << -altura / 2 << " " << -largura / 2 << "\n";

	//tri�ngulo 4
	file << comprimento / 2 << " " << altura / 2 << " " << -largura / 2 << "\n";
	file << comprimento / 2 << " " << -altura / 2 << " " << -largura / 2 << "\n";
	file << -comprimento / 2 << " " << -altura / 2 << " " << -largura / 2 << "\n";

	//face superior
	//triangulo 5

	file << -comprimento / 2 << " " << altura / 2 << " " << largura / 2 << "\n";
	file << comprimento / 2 << " " << altura / 2 << " " << largura / 2 << "\n";
	file << comprimento / 2 << " " << altura / 2 << " " << -largura / 2 << "\n";

	//tri�ngulo 6
	file << comprimento / 2 << " " << altura / 2 << " " << -largura / 2 << "\n";
	file << -comprimento / 2 << " " << altura / 2 << " " << -largura / 2 << "\n";
	file << -comprimento / 2 << " " << altura / 2 << " " << largura / 2 << "\n";

	//face inferior
	//triangulo 7

	file << -comprimento / 2 << " " << -altura / 2 << " " << largura / 2 << "\n";
	file << -comprimento / 2 << " " << -altura / 2 << " " << -largura / 2 << "\n";
	file << comprimento / 2 << " " << -altura / 2 << " " << -largura / 2 << "\n";

	//tri�ngulo 8
	file << comprimento / 2 << " " << -altura / 2 << " " << -largura / 2 << "\n";
	file << comprimento / 2 << " " << -altura / 2 << " " << largura / 2 << "\n";
	file << -comprimento / 2 << " " << -altura / 2 << " " << largura / 2 << "\n";

	//face direita
	//triangulo 9

	file << comprimento / 2 << " " << -altura / 2 << " " << largura / 2 << "\n";
	file << comprimento / 2 << " " << -altura / 2 << " " << -largura / 2 << "\n";
	file << comprimento / 2 << " " << altura / 2 << " " << -largura / 2 << "\n";

	//tri�ngulo 10
	file << comprimento / 2 << " " << altura / 2 << " " << -largura / 2 << "\n";
	file << comprimento / 2 << " " << altura / 2 << " " << largura / 2 << "\n";
	file << comprimento / 2 << " " << -altura / 2 << " " << largura / 2 << "\n";

	//face esquerda
	//triangulo 11

	file << -comprimento / 2 << " " << -altura / 2 << " " << largura / 2 << "\n";
	file << -comprimento / 2 << " " << altura / 2 << " " << largura / 2 << "\n";
	file << -comprimento / 2 << " " << altura / 2 << " " << -largura / 2 << "\n";

	//tri�ngulo 12
	file << -comprimento / 2 << " " << altura / 2 << " " << -largura / 2 << "\n";
	file << -comprimento / 2 << " " << -altura / 2 << " " << -largura / 2 << "\n";
	file << -comprimento / 2 << " " << -altura / 2 << " " << largura / 2 << "\n";



	file.close();
}

void cone(float raio, float altura, int fatias, int camadas, char* filename){
	float salto = altura / camadas;
	int camaux = 1;
	float aux;
	float alpha1 = 0;
	float raioCam = ((altura - salto)*raio) / altura;
	float alturaCam = (-altura / 2) + salto;
	float alturaCam2 = -altura / 2;

	ofstream file;
	file.open(filename, ios::ate);
	
	//imprimir camadas
	while (camaux <= camadas){
		//imprimir fatias
		for (aux = 0; aux <= fatias; aux++){
			file << raioCam * sin(alpha1) << " " << alturaCam << " " << raioCam* cos(alpha1) << "\n";
			file << raio* sin(alpha1) << " " << alturaCam2 << " " << raio* cos(alpha1) << "\n";
			file << raioCam*sin(alpha1 + ((2 * M_PI) / fatias)) << " " << alturaCam << " " << raioCam*cos(alpha1 + ((2 * M_PI) / fatias)) << "\n";
			file << raioCam*sin(alpha1 + ((2 * M_PI) / fatias)) << " " << alturaCam << " " << raioCam*cos(alpha1 + ((2 * M_PI) / fatias)) << "\n";
			file << raio* sin(alpha1) << " " << alturaCam2 << " " << raio* cos(alpha1) << "\n";
			file << raio*sin(alpha1 + ((2 * M_PI) / fatias)) << " " << alturaCam2 << " " << raio*cos(alpha1 + ((2 * M_PI) / fatias)) << "\n";
			alpha1 += (2 * M_PI) / fatias;
		}
		camaux++;
		alturaCam2 = alturaCam;
		alturaCam = alturaCam + salto;
		altura = altura - salto;
		raio = raioCam;
		raioCam = ((altura - salto)*raio) / altura;
	}
	file.close();
}

void esfera(float raio, int fatias, int camadas, char* filename){
	float raioS, raioI;
	float alpha1, betaS, betaI;
	int auxC, auxF;
	betaS = M_PI / 2;
	betaI = betaS - (M_PI / camadas);
	ofstream file;
	file.open(filename, ios::ate);
	for (auxC = 1; auxC <= camadas; auxC++){
		raioS = raio*cos(betaS);
		raioI = raio*cos(betaI);
		for (auxF = 0; auxF <= fatias; auxF++){
			file << raioS*sin(alpha1) << " " << raio*sin(betaS) << " " << raioS*cos(alpha1) << "\n";
			file << raioI*sin(alpha1) << " " << raio*sin(betaI) << " " << raioI*cos(alpha1) << "\n";
			file << raioS*sin(alpha1 + ((2 * M_PI) / fatias)) << " " << raio*sin(betaS) << " " << raioS*cos(alpha1 + ((2 * M_PI) / fatias)) << "\n";
			file << raioS*sin(alpha1 + ((2 * M_PI) / fatias)) << " " << raio*sin(betaS) << " " << raioS*cos(alpha1 + ((2 * M_PI) / fatias)) << "\n";
			file << raioI*sin(alpha1) << " " << raio*sin(betaI) << " " << raioI*cos(alpha1) << "\n";
			file << raioI*sin(alpha1 + ((2 * M_PI) / fatias)) << " " << raio*sin(betaI) << " " << raioI*cos(alpha1 + ((2 * M_PI) / fatias)) << "\n";
			alpha1 += (2 * M_PI) / fatias;
		}
		betaS = betaI;
		betaI = betaI - (M_PI / camadas);
		alpha1 = 0;
	}
	file.close();
}

int main(int argc, char **argv) {
	
	//superficie plana
	if ((strcmp(argv[1], "plane") == 0) && argc == 5){
		areaPlana(atof(argv[2]), atof(argv[3]), argv[4]);
		printf("Ficheiro criado com sucesso.");
		return 0;
	}
	/*else{
		printf("Argumentos insuficientes.");
		return 0;
	}*/
	
	//paralelipipedo
	if ((strcmp(argv[1], "box") == 0) && argc == 6){
		paralelipipedo(atof(argv[2]), atof(argv[3]), atof(argv[4]),argv[5]);
		printf("Ficheiro criado com sucesso.");
		return 0;
	}
	/*else{
		printf("Argumentos insuficientes.");
		return 0;
	}*/

	//Cone
	if ((strcmp(argv[1], "cone") == 0) && argc == 7){
		cone(atof(argv[2]), atof(argv[3]), atoi(argv[4]),atoi(argv[5]),argv[6]);
		printf("Ficheiro criado com sucesso.");
		return 0;
	}
	/*else{
		printf("Argumentos insuficientes.");
		return 0;
	}*/

	//esfera
	if ((strcmp(argv[1], "sphere") == 0) && argc == 6 ){
		esfera(atof(argv[2]),atoi(argv[3]), atoi(argv[4]),argv[5]);
		printf("Ficheiro criado com sucesso.");
		return 0;
	}
	/*else{
		printf("Argumentos insuficientes.");
		return 0;
	}*/

	//Objecto n�o identificado
	printf("Primitiva inixestente");
	return 0;
	}
	
