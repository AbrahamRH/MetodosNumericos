/* Copyright (C)
 * 2020 - AbrahamRH
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

/**
 * @file MetodosNumericos.cpp
 * @brief Implementación de metodos numéricos en c++
 * @author AbrahamRH
 * @version 1.4
 * @date 2020-04-20
 */

#include "MetodosNumericos.hpp"

namespace MetodosNumericos{

	void Integracion::reglaDelTrapecio(float a, float b, size_t iteraciones)
	{
		//Definimos una constante con el valor real de la integral obtenida previamente
		const float INTEGRAL = 9.566;

		//Valor de la integral inmediata anterior para obtener el error aproximado
		float anterior = 0;

		//Repetimos el método el numero de iteraciones dadas
		for (size_t n = 1; n <= iteraciones ; ++n){
			std::vector<float> X;
			std::vector<float> Y;
			float h = (b - a)/n;
			float integral;
			float suma = 0;
			float eRel, eAbs, eAprox;

			/*
				LLenamos las tablas para Xa a Xb con incremento de h,
				y aplicamos f(x) para obtener y
			*/
			for(float x = a; x <= b + .1 ; x+=h){
				X.push_back(redondear(x));
				/*Funcion (1/raiz(2*pi))*e^(-0.5*x²) */
				Y.push_back(redondear(sqrtf(1+x*x*x*x)));
			}

			for(size_t i = 1; i < Y.size()-1 ; ++i){
				suma += Y[i];
			}

			integral = redondear((b - a)*( Y[0] + 2*suma + Y[Y.size()-1])/(2*n));


			//Obtenemos los diferentes tipos de errores para cada iteración
			eRel = redondear(fabsf(100*(INTEGRAL - integral)/INTEGRAL));
			eAbs = fabsf(redondear(INTEGRAL - integral));
			eAprox = fabsf(redondear(integral - anterior));

			anterior = integral;

			std::cout << "=====================================" << std::endl;
			std::cout << "Integral n = " << n << std::endl << std::endl;
			std::cout << "I = " << integral << std::endl << std::endl;
			std::cout << "h = " << redondear(h) << std::endl << std::endl;
			std::cout << "Error relativo = " << eRel << "%" << std::endl << std::endl;
			std::cout << "Error absoluto = " << eAbs << std::endl << std::endl;

			if ( n != 1 ){
				std::cout << "Error Aproximado = " << eAprox << std::endl << std::endl;
			}

			printTable(X,Y);
		}
	}

	void Integracion::reglasDeSimpson(float a, float b, float c)
	{
		//Definimos una constante con el valor real de la integral obtenida previamente
		const float INTEGRAL = 9.566;

		//Integral total, tres octavos (h1) y un tercio (h2)
		float integral, I3_8, I1_3;
		float h1 = (b-a)/3;	//n = 3
		float h2 = (c-b)/2; //n = 2

		float eRel;
		float eAbs;

		std::vector<float> X;
		std::vector<float> Y;

		//Llenamos el vector de a hasta b con paso de h1
		for(float x = a; x <= b ; x+=h1){
				X.push_back(redondear(x));
				Y.push_back(redondear(sqrtf(1+x*x*x*x)));
		}
		I3_8 = (b-a)*(Y[0] + 3*(Y[1] + Y[2]) + Y[3])/8;


		//Llenamos el vector de b hasta c con paso de h2
		for(float x = b; x <= c ; x+=h2){
				X.push_back(redondear(x));
				Y.push_back(redondear(sqrtf(1+x*x*x*x)));
		}

		I1_3 = (c-b)*(Y[4] + 4*Y[5] + Y[6])/6;

		integral = I1_3 + I3_8;

		eRel = redondear(fabsf(100*(INTEGRAL - integral)/INTEGRAL));
		eAbs = fabsf(redondear(INTEGRAL - integral));

		std::cout << "=====================================" << std::endl;
		std::cout << "I = " << integral << std::endl << std::endl;
		std::cout << "h (a - b)= " << redondear(h1) << std::endl << std::endl;
		std::cout << "h (b - c)= " << redondear(h2) << std::endl << std::endl;
		std::cout << "Error relativo = " << eRel << "%" << std::endl << std::endl;
		std::cout << "Error absoluto = " << eAbs << std::endl << std::endl;

		printTable(X,Y);
	}

	void Interpolacion::espaciosIguales(std::vector<float> X , std::vector<float> Y, float xk)
	{
		float h = fabsf(X[1] - X[0]);
		float grado = X.size() - 1;
		float k;

		std::vector<float> Dif_1;
		std::vector<float> Dif_2;
		std::vector<float> Dif_3;
		std::vector<float> Dif_4;

		for(size_t i = 0; (xk < X[i] and xk > X[i-1]); ++i){
			k = (xk-X[i-1])/h;
		}

		//Obtenemos la primer parte de las diferencias finitas hacia delante
		Dif_1 = obtenerDiferencias(Y);
		Dif_2 = obtenerDiferencias(Dif_1);
		Dif_3 = obtenerDiferencias(Dif_2);
		Dif_4 = obtenerDiferencias(Dif_3);

		//Obtenemos la segunda parte de las diferencias finitas hacia atras
		for(size_t i = 0; i < Dif_1.size(); ++i){ Dif_4.push_back(Dif_4[0]); }
		Dif_3 = obtenerDiferencias(Dif_3,Dif_4,true);
		Dif_2 = obtenerDiferencias(Dif_2,Dif_3,true);
		Dif_1 = obtenerDiferencias(Dif_1,Dif_2,true);

		printDiferencias(Dif_1,Dif_2,Dif_3,Dif_4);





	}

	float combinacion(float k, float j)
	{
		if(j == 0)
			return (k)*tgamma(k)/(tgamma(j+1)*(k-j)*tgamma(k-j));
		else
			return (k)*tgamma(k)/(j*tgamma(j)*(k-j)*tgamma(k-j));
	}

	void printTable(std::vector<float> x, std::vector<float> y)
	{
		std::cout << " x	 |   f(x)       " << std::endl;
		for ( size_t i = 0; i <  x.size(); ++i){
			if(x[i] < 0 )
				std::cout << std::fixed << std::setprecision(4) << x[i] << "  |" << y[i] << std::endl;
			else
				std::cout << std::fixed << std::setprecision(4) << " " << x[i] << "  | " << y[i] << std::endl;
		}
	}

	void printDiferencias(std::vector<float> Dif_1,std::vector<float> Dif_2, std::vector<float> Dif_3, std::vector<float> Dif_4)
	{
		std::cout << "Tabla de diferencias" << std::endl << std::endl;

		std::cout << " Y1	| Y2	 |  Y3	 | Y4  " << std::endl;
		for ( size_t i = 0; i <  Dif_1.size(); i++){
			if(Dif_1[i] < 0 )
				std::cout << std::fixed << std::setprecision(4) << Dif_1[i] << " | " << Dif_2[i] << " | " << Dif_3[i] << " | " << Dif_4[i] << std::endl;
			else
				std::cout << std::fixed << std::setprecision(4) << " " << Dif_1[i] << " | " << Dif_2[i] << " | " << Dif_3[i] << " | " << Dif_4[i] << std::endl;
		}
		std::cout << "==========================================" << std::endl << std::endl;
	}

	float redondear(float n){ return (int)(n * 10000.0)/10000.0; };

	std::vector<float> obtenerDiferencias(std::vector<float> diferencia1, std::optional<std::vector<float>> diferencia2,std::optional<bool> bandera)
	{
		if(bandera.value_or(false)){
			/*Para obtener los valores finales de la tabla de diferencias con los valores anteriores*/
			while(diferencia1.size() !=  diferencia2.value().size()){
				diferencia1.push_back(diferencia2.value()[diferencia1.size()-1]+diferencia1[diferencia1.size()-1]);
			}
			return diferencia1;
		}else{
			/*Obtenemos la primer parte de la tabla de diferencias finitas*/
			std::vector<float> diferencia;
			for(size_t i = 0; i < diferencia1.size()- 1; ++i){
				diferencia.push_back(diferencia1[i+1]-diferencia1[i]);
			}
			return diferencia;
		}
	}
}
