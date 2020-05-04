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
 * @file driverProgram.cpp
 * @brief Driver Program para los metodos numéricos
 * @author AbrahamRH
 * @version 1.6
 * @date 2020-04-22
 */

#include "MetodosNumericos.hpp"

using namespace MetodosNumericos;

int main()
{
	/* Integracion integral;
	integral.reglaDelTrapecio(.5,3,10);
	integral.reglasDeSimpson(.5,1.25,3); */

	Interpolacion metodos;
	metodos.espaciosIguales({0,1,2},{1,3,12},1.5);
	metodos.polinomioNewton({.1,.4,.7,1},{1.105,1.492,2.014,2.718},1);
	return 0;
}

