#pragma once
#include <iostream>
#include "articulo.h"
using namespace std;

class nodo{
public:
  articulo value;
  nodo* siguiente=NULL;
};