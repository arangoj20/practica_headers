#pragma once
#include "cliente.h"

lista cliente::agregar_carro(int cod, inventario inven, carrito_compras carro){
  nodo*temporal=inven.inv.cabeza;
  while(temporal->value.codigo!=cod){
    temporal=temporal->siguiente;
  }
  if(temporal->value.codigo==cod){
    articulo a;
    a.codigo=temporal->value.codigo;
    a.nombre=temporal->value.nombre;
    a.precio=temporal->value.precio;
    temporal=inven.inv.cabeza;
    while(temporal->siguiente!=NULL){
      temporal=temporal->siguiente;
    }
    if(carro.car.cabeza==NULL){
      carro.car.cabeza->value=a;
    }else{
      temporal=carro.car.cabeza;
      while(temporal->siguiente!=NULL){
        temporal=temporal->siguiente;
      }
      temporal->siguiente=new nodo;
      temporal->siguiente->value=a;
    }
  }
  return carro.car;
}

void cliente::pagar(carrito_compras carro){
  cliente c;
  nodo*temporal=carro.car.cabeza;
  int total;
  bool d;
  while(temporal->siguiente!=NULL){
    total=total+temporal->value.precio;
    cout<<temporal->value.nombre<<temporal->siguiente->value.precio<<endl;
    temporal=temporal->siguiente;

    if(temporal->siguiente==NULL){
    total=total+temporal->value.precio;
    cout<<temporal->value.nombre<<temporal->siguiente->value.precio<<endl;
    }
  }
  cout<<"Total sin descuento:"<<endl;
  cout<<total<<endl;
  
  d=c.calcular_descuento(carro);
  if(d==true){
    total=(total*0.1)+total;
    cout<<"Total con descuento:"<<endl;
    cout<<total<<endl;
  }else{
    if(d==false){
      cout<<"No hay descuentos por aplicar"<<endl;
    }
  }
}
bool cliente::calcular_descuento(carrito_compras carro){
  nodo*temporal=carro.car.cabeza;
  int tipot1=carro.car.cabeza->value.tipo;
  while(temporal->siguiente!=NULL){
    int tipot2=temporal->value.tipo;
    if(tipot1==tipot2){
      return true;
      break;
    }else{
      tipot1=temporal->value.tipo;
      temporal=temporal->siguiente;
    }
    if(temporal->siguiente==NULL){
      return false;
      break;
    }
  }
}