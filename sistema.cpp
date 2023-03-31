#include "sistema.h"

void sistema::iniciar(){
   while(true){
    int opcion;
    cout<<"Ingresa que tipo de usuario es"<<endl;
    cout<<"1. Cliente"<<endl;
    cout<<"2. Coordinador"<<endl;
    cout<<"3. Salir"<<endl;
    cin>>opcion;
     if(opcion==1){
       menu m;
       m.menu_cliente();
       break;
     }else{
      if(opcion==2){
        menu m;
        m.menu_coordinador();
        break;
      }else{
        if(opcion==3){
          abort();
        }else{
          printf("Opcion incorrecta");
        }
      }
   }
}