/* 
 * File:   main.c
 * Author: def
 *
 * Created on 24 de abril de 2019, 15:13
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[50];
} estrucProduc;

int main(int argc, char** argv) {
    estrucProduc productos[5];
    int opcion;
    FILE *archivo;
    //do{
       printf("Menu de opciones:\n\t"
               "1. Ingresar producto\n\t"
               "2. Buscar producto\n\t"
               "3. Eliminar producto\n\t"
               "4. Listar todos los productos\n\t"
               "0. SALIR\n ");
       scanf("%d",&opcion);
       
    //}while(opcion!=0);
    
    guardarDatosProductos(archivo,productos[5]);
    
   // guardaFichero(productos);
    
    return (EXIT_SUCCESS);
}
void guardarDatosProductos(FILE *archivo ,estrucProduc productos[]){
    for(int i=0;i <= strlen(productos);i++ ){
        printf("introduce productos %i ", i+1);
        fgets(productos[i].nombre,30,stdin);
        productos[i].id=i+1;
    }
    archivo=fopen("datos","w");
    if(archivo){
        fwrite(productos,sizeof(estrucProduc),5,archivo);
        fclose(archivo);
    }
    
    
    
    
}
void guardaFichero(struct estrucProduc *productos){
       FILE *archivo=fopen("productos","a");
       
       
      fclose(archivo);
}
int leerFichero(estrucProduc prod[])
{
	int i=0;
	FILE*f1=fopen("productos","r");
	if(f1==NULL)
	{
		printf("Error al abrir el archivo\n");
		
	}
	else
	{
		while(!feof(f1))
		{
			fscanf(f1,"%d %s\n",prod[i].id,prod[i].nombre);
			i++;
		}
	}
	fclose(f1);
	return i;
}