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
 * @file MetodosNumericos.hpp
 * @brief Fichero de cabecera para el archivo de métodos numéricos
 * @author AbrahamRH
 * @version 1.0
 * @date 2020-04-22
 */

#include <iostream>
#include <cmath>
#include <vector>

#ifndef METODOSNUMERICOS
#define METODOSNUMERICOS

class MetodosNumericos
{
private:
public:

	/* -------------------------------*/
	/**
	 * @brief Aplicación de la regla del trapecio en funciones para su integración definida
	 *
	 * @param float	Valor inicial de la integral definida (a)
	 * @param float Valor final de la integral definida	(b)
	 * @param size_t Número de iteraciones que se desean para calcullar su integral
	 */
	/* -------------------------------*/
  void reglaDelTrapecio(float, float, size_t);


	/* -------------------------------*/
	/**
	 * @brief Imprime una tabla [ x | f(x)] verticalmente a partir de 2 vectores
	 *
	 * @param std::vector primer vector con los valoes de X
	 * @param std::vector segudon vector con los valores de f(x)
	 */
	/* -------------------------------*/
  void printTable(std::vector<float>, std::vector<float>);


	/* -------------------------------*/
	/**
	 * @brief Función para redondear valores flotantes a 4 digitos despues del punto decimal
	 *
	 * @param n Número que se desea redondear
	 *
	 * @return Número redondeado
	 */
	/* -------------------------------*/
  float redondear(float n){ return (int)(n * 10000.0)/10000.0; };
};

#endif