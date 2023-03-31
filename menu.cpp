#pragma once
#include "menu.h"
void menu::menu_cliente(inventario i,carrito_compras carro){
  cliente cl;
  while(true){
    int opcion;
    cout<<"Ingresa lo que deseas hacer"<<endl;
    cout<<"1. Ver lista de productos"<<endl;
    cout<<"2. Comprar productos"<<endl;
    cout<<"3. Salir"<<endl;
    cin>>opcion;
    if(opcion==1){
      coordinador c;
      c.ver_lista(i.inv);
      break;
    }else{
      if(opcion==2){
        int cod;
        cout<<"Ingrese el codigo del producto"<<endl;
        cin>>cod;
        carro.car=cl.agregar_carro(cod, i, carro);
        break;
      }else{
        if(opcion==3){
          abort();
        }else{
          printf("Opción incorrecta");
        }
      }
    }
  }
}

void menu::menu_coordinador(inventario i){
  coordinador c;
  while(true){
    int opcion;
    cout<<"Ingresa lo que deseas hacer"<<endl;
    cout<<"1. Ver inventario"<<endl;
    cout<<"2. Agregar producto"<<endl;
    cout<<"3. Modificar producto"<<endl;
    cout<<"4. Eliminar producto"<<endl;
    cout<<"5. Salir"<<endl;
    cin>>opcion;

    if(opcion==1){
      c.ver_lista(i.inv);
      break;
    }else{
      if(opcion==2){
        articulo a;
        lista i;
        int cod;
        string nom;
        int pre;
        int t;
        cout<<"Ingresa el codigo"<<endl;
        cin>>cod;
        cout<<"Ingresa el nombre"<<endl;
        cin>>nom;
        cout<<"Ingresa el precio"<<endl;
        cin>>pre;
        while(true){
          cout<<"Ingresa el tipo"<<endl;
          cout<<"1 si es tecnologico"<<endl;
          cout<<"2 si es deportivo"<<endl;
          cout<<"3 si es extranjero"<<endl;
          cin>>t;
          if((t=!1)&&(t!=2)&&(t!=3)){
            printf("Codigo incorrecto");
          }else{
            if((t==1)||(t==2)){
              break;
            }
          }
        }
        a=c.crear_producto(cod, nom, pre,t);
        i=c.crear_lista(a);
        i=c.añadir(i,a);
        break;
      }else{
        if(opcion==3){
          while(true){
            cout<<"Ingresa lo que deseas hacer"<<endl;
            cout<<"1. Modificar precio"<<endl;
            cout<<"2. Modificar nombre"<<endl;
            cout<<"3. Modificar ambas"<<endl;
            cout<<"4. Salir"<<endl;
            cin>>opcion;
            if(opcion==1){
              break;
            }else{
              if(opcion==2){
                break;
              }else{
                if(opcion==3){
                  break;
                }else{
                  if(opcion==4){
                  break;
                }else{
                  printf("Opción incorrecta");
                }
              }
            }
          }
          }
          break;
        }else{
          if(opcion==4){
            break;
          }else{
            if(opcion==5){
              abort();
            }else{
              printf("Opción incorrecta");
            }
          }
        }
      }
    }
  }
}