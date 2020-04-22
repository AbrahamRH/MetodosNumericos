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
 * @version 1.2
 * @date 2020-04-20
 */

#include "MetodosNumericos.hpp"

void MetodosNumericos::reglaDelTrapecio(float a, float b, size_t iteraciones)
{ 
  //Definimos una constante con el valor real de la integral obtenida previamente
  const float INTEGRAL = .2376;

  MetodosNumericos print, rnd;

  //Valor de la integral inmediata anterior para obtener el error aproximado
  float anterior = 0;

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
    for(float x = a; x <= b ; x+=h){
      X.push_back(rnd.redondear(x));
      /*Funcion Sen(x)/x*/
      Y.push_back(rnd.redondear(sin(x)/x));
    } 

    for(size_t i = 1; i < Y.size()-1 ; ++i){
      suma += Y[i];
    }   
    
    /*
      Aplicamos la formula del metodo de integración
      I = (b-a)(Ya + 2*Suma(Ya+1, Yb-1) + Yb)/2*n
    */
    integral = rnd.redondear((b - a)*( Y[0] + 2*suma + Y[Y.size()-1])/(2*n));


    //Obtenemos los diferentes tipos de errores para cada iteración 
    eRel = rnd.redondear(fabsf(100*(INTEGRAL - integral)/INTEGRAL));
    eAbs = fabsf(rnd.redondear(INTEGRAL - integral));
    eAprox = fabsf(rnd.redondear(integral - anterior));

    anterior = integral;

    std::cout << "=====================================" << std::endl;
    std::cout << "Integral n = " << n << std::endl << std::endl;
    std::cout << "I = " << integral << std::endl << std::endl;
    std::cout << "Error relativo = " << eRel << "%" << std::endl << std::endl;
    std::cout << "Error absoluto = " << eAbs << std::endl << std::endl;

    if ( n != 1 ){
      std::cout << "Error relativo = " << eAprox << std::endl << std::endl;
    }

    print.printTable(X,Y);
  }
}

void MetodosNumericos::printTable(std::vector<float> x, std::vector<float> y){
  std::cout << " x	|   f(x)       " << std::endl;
  for ( size_t i = 0; i <  x.size(); ++i){
    std::cout << x[i] << "  |" << y[i] << std::endl;
  }
}

