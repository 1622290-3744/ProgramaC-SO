#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int tamanoArchivo(char *name){
        FILE *archivo;
        int contador = 0;

        archivo = fopen(name,"rb");

        while(fgetc(archivo) != EOF){ 

                contador++;
        }

        fclose(archivo);        
  
        return contador;        
}

int main (int argc, char *argv[]){

        char *lista[200];
        int narch=0;

        DIR *directorio;

		unsigned char tipo;

        struct dirent *dir;

        if(argc!=2){
                printf("Debes especificar una ruta de directorio.\n");
                return 1;
        }

        directorio=opendir(argv[1]);

        if (directorio == NULL){
                printf("No se puede abrir el directorio. \n");
                return 1;
        }
	printf("Estudiante_1: 201622290\nEstudiante_2: 201627015\n");
        while ((dir = readdir(directorio)) !=NULL){
				tipo=dir->d_type;				
				if (tipo==DT_REG){				
					narch++;
					
						/*if ((strcmp(dir->d_name,".")!= 0)&&(strcmp(dir->d_name, "..")!= 0)){
					

                        FILE*comprobacion;
                        comprobacion=fopen(dir->d_name,"r");

                 
                                //lista[narch]=(char *)malloc(sizeof(char) *strlen(dir->d_name));
                                //strcpy(lista[narch],dir->d_name);
								q=tamanoArchivo(char *lista[narch]);
								
					}*/
               
				}
        }
    
	printf("Total archivos:%i \n",narch);
	printf("Total Bytes:%d \n",tamanoArchivo(argv[0]));

	closedir(directorio);

        return 0;
}

