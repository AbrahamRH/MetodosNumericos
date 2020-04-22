

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
  void reglaDelTrapecio(float a, float b, size_t iteraciones);
  void printTable(std::vector<float> x, std::vector<float> y);
  float redondear(float n){ return (int)(n * 10000.0)/10000.0; };
};

#endif
