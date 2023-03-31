#pragma once
#include <iostream>
#include "usuario.h"
#include "inventario.h"
#include "carrito_compras.h"
using namespace std;

class cliente: public usuario{
public:
  lista agregar_carro(int cod, inventario inv, carrito_compras carro);
  void pagar(carrito_compras carro);
  bool calcular_descuento(carrito_compras carro);
};