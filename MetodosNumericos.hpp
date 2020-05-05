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
 * @version 1.7
 * @date 2020-04-22
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <optional>

#ifndef _METODOS_NUMERICOS_
#define _METODOS_NUMERICOS_

namespace MetodosNumericos{
	class Integracion
	{
	public:

		Integracion(){}

		~Integracion(){}

		/* -------------------------------*/
		/**
		 * @brief Aplicación de la regla del trapecio en funciones para su integración definida
		 *
		 * @param float	Valor inicial de la integral definida
		 * @param float Valor final de la integral definida
		 * @param size_t Número de iteraciones que se desean para calcullar su integral
		 */
		/* -------------------------------*/
		void reglaDelTrapecio(float, float, size_t);


		/* -------------------------------*/
		/**
		 * @brief Aplicación de las reglas de Simpson de tres octavos más un tercio para la integración
		 *
		 * @param float Punto inicial de la integral
		 * @param float Punto intermedio para la aplicacion de la regla a tres octavos
		 * @param float Punto final de la integral definida
		 */
		/* -------------------------------*/
		void reglasDeSimpson(float ,float ,float);
	};

	class Interpolacion
	{
	public:

		Interpolacion(){}

		~Interpolacion(){}


		/* -------------------------------*/
		/**
		 * @brief Aplicación del método de espacios iguales para interpolación (hasta polinomios de grado 4)
		 *
		 * @param std::vector Tabla de valores de la variable independiente X
		 * @param std::vector	Tabla de valores de la variable dependiente Y
		 * @param float Valor que se busca estimar para la función tabular
		 */
		/* -------------------------------*/
		void espaciosIguales(std::vector<float>, std::vector<float>, float);


		/* -------------------------------*/
		/**
		 * @brief Aplicación del método de polinomio de Newton para interpolación para polinómios de grado n
		 *
		 * @param std::vector Tabla de valores de la variable independiente X
		 * @param std::vector	Tabla de valores de la variable dependiente Y
		 * @param float Valor que se quieres estimar para la función tabular
		 */
		/* -------------------------------*/
		void polinomioNewton(std::vector<float>, std::vector<float>, float);
	};


		/*=========================================================================================
																		Funciones miceláneas
		==========================================================================================*/

		/* -------------------------------*/
		/**
		 * @brief Imprime una tabla [ x | f(x)] verticalmente a partir de 2 vectores
		 *
		 * @param std::vector primer vector con los valoes de X
		 * @param std::vector segundo vector con los valores de f(x)
		 */
		/* -------------------------------*/
		void printTable(std::vector<float>, std::vector<float>);


		/* -------------------------------*/
		/**
		 * @brief Función para redondear valores flotantes a 4 digitos despues del punto decimal
		 *
		 * @param float Número que se desea redondear
		 *
		 * @return Número redondeado
		 */
		/* -------------------------------*/
		float redondear(float);


		/* -------------------------------*/
		/**
		 * @brief Función para calcular combinaciones sin repetición con números enteros tanto flotantes
		 *
		 * @param float Elementos a tomar
		 * @param float Numeros de elemetos de la colección
		 *
		 * @return Resultado de la combinación
		 */
		/* -------------------------------*/
		float combinacion(float, float);


		/* -------------------------------*/
		/**
		 * @brief Función para obtener vectores de las diferencias finitas (Tabla de diferencias finitas)
		 *
		 * @param std::vector Tabla de X (si unicamente se pasa este parámetro), ó vector de la diferencia que se deseaobtener, haciendo obteniendo las diferencias hacia atrás.
		 * @param std::optional Vector (opcional) apartir del cual se obtendran las diferencias hacia atrás.
		 * @param std::optional Bandera (opcional) para saber si se construyen los vectores hacia adelante o atras; true: atras | false(default): hacia adelante.
		 *
		 * @return Vector con las diferencias
		 */
		/* -------------------------------*/
		std::vector<float> obtenerDiferencias(std::vector<float>,std::optional<std::vector<float>> = std::nullopt,std::optional<bool> = std::nullopt);


		/* -------------------------------*/
		/**
		 * @brief Función para imprimir las diferencias en forma de tabla
		 *
		 * @param std::vector Vector con la diferencia 1
		 * @param std::vector Vector con la diferencia 2
		 * @param std::vector Vector con la diferencia 3
		 * @param std::vector Vector con la diferencia 4
		 */
		/* -------------------------------*/
		void printDiferencias(std::vector<float> ,std::vector<float> ,std::vector<float> ,std::vector<float>);


		/* -------------------------------*/
		/**
		 * @brief Función recursiva para obtener los valoes de b de la interpolación de Newton
		 *
		 * @param std::vector& referencia al vector con los valores de x
		 * @param std::vector& referencia al vector con los valores de f(x)
		 * @param size_t Indice que apunta al valor final del rango del vector
		 * @param size_t Indice que apunta al valor inicial del rango del vector
		 *
		 * @return valor del coeficiente b
		 */
		/* -------------------------------*/
		float obtenerB(std::vector<float> &, std::vector<float> &, size_t, size_t);

}

#endif
