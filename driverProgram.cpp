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
 * @version 1.0
 * @date 2020-04-22
 */

#include "MetodosNumericos.hpp"

using namespace MetodosNumericos;

int main(){
	/* Integracion integral;
	integral.reglaDelTrapecio(-3,3,4);

	std::cout << std::endl <<"Metodo Simpson" << std::endl;
	integral.reglasDeSimpson(-3,0,3); */

	std::cout << combinacion(.5,0) << std::endl;

	return 0;
}

