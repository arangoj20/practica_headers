#pragma once
#include "coordinador.h"

articulo coordinador::crear_producto(int cod, string nom, int pre, int t){
  articulo art;
  lista l;
  if(t==1){
    articulo_deportivo artdep;
    artdep.codigo=cod;
    artdep.nombre=nom;
    artdep.precio=pre;
    artdep.tipo=t;
    art=artdep;
  }else{
    if(t==2){
      articulo_tecnologico arttec;
      arttec.codigo=cod;
      arttec.nombre=nom;
      arttec.precio=pre;
      arttec.tipo=t;
      art=arttec;
    }else{
      if(t==3){
        float imp;
        articulo_extranjero artex;
        artex.codigo=cod;
        artex.nombre=nom;
        imp=pre*artex.impuesto;
        artex.precio=pre+imp;
        artex.tipo=t;
        art=artex;
      }
    }
  }
  return art;
}

lista coordinador::crear_lista(articulo a){
  lista l1;
  if(l1.cabeza->siguiente==NULL){
    l1.cabeza=new nodo;
    l1.cabeza->value=a;
  }else{
    añadir(l1,a);
  }
  inventario i;
  i.inv=l1;
  return i.inv;
}

lista coordinador::añadir(lista l,articulo a){
    nodo*temporal=l.cabeza;
    while(temporal->siguiente!=NULL){
      temporal=temporal->siguiente;
    }
    temporal->siguiente=new nodo;
    temporal->siguiente->value=a;
    return l;
}

lista coordinador::modificar_nombre(lista l, int cod,string nom){
  nodo*temporal=l.cabeza;
  while(temporal->value.codigo!=cod){
    temporal=temporal->siguiente;
  }
  if(temporal->value.codigo==cod){
    temporal->value.nombre=nom;
  }else{
    printf("Código incorrecto");
  }
  return l;
}

lista coordinador::modificar_precio(lista l, int cod,int pre){
  nodo*temporal=l.cabeza;
  while(temporal->value.codigo!=cod){
    temporal=temporal->siguiente;
  }
  if(temporal->value.codigo==cod){
    temporal->value.precio=pre;
  }else{
    printf("Código incorrecto");
  }
  return l;
}

lista coordinador::modificar_ambas(lista l, int cod, string nom, int pre){
  nodo*temporal=l.cabeza;
  while(temporal->value.codigo!=cod){
    temporal=temporal->siguiente;
  }
  if(temporal->value.codigo==cod){
    temporal->value.nombre=nom;
    temporal->value.precio=pre;
  }else{
    printf("Código incorrecto");
  }
  return l;
}

lista coordinador::eliminar(lista l, int cod){
  nodo*temporal=l.cabeza;
  while(temporal->siguiente->value.codigo!=cod){
    temporal=temporal->siguiente;
  }

  if(temporal->siguiente->value.codigo==cod){
    if(temporal->siguiente->siguiente!=NULL){
      temporal->siguiente=temporal->siguiente->siguiente;
    }else{
      if(temporal->siguiente->siguiente==NULL){
        temporal->siguiente=NULL;
      }
    }
  }
  return l;
}

lista coordinador::ver_lista(lista l){
  nodo*temporal=l.cabeza;
  while(temporal!=NULL){
    cout<<temporal->value.codigo<<endl;
    cout<<temporal->value.nombre<<endl;
    cout<<temporal->value.precio<<endl;
    temporal=temporal->siguiente;
  }
  return l;
}