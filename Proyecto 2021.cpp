/* Este programa realiza la suma, producto y diagonal principal de dos matrices ingresadas por el usuario */
/* Las dimensiones de estas matrices son de nxn */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int matrizA[100][100];  /* se declaran las variables globales de modo que sean utilizadas en todas las funciones */
int matrizB[100][100];
int matrizC[100][100];
int x;

/*  Esta funcion guarda el tamaÃ±o de las matrices*/
void tamanio(){
	printf("\n");
	printf("\n Ingresa el tamanio de las matrices:");
	scanf("%d",&x); /* Guardamos el valor de las dimensiones ingresadas */
	/* Debido a que las matrices son de nxn, bastarï¿½ con leer un ï¿½nico valor */
	printf("\n");
}
/* Esta funcion se encarga de leer las matrices */
void leermatrices(int matriz[100][100]){
	int i,j; 
	/* Debido a que las matrices son de nxn, bastarï¿½ con leer un ï¿½nico valor */
	printf("\n Primera matriz\n");
	for(i=0;i<x;i++){  /* Para guardar los valores de las matrices, serï¿½ necesario guardar filas y columnas
	dependiendo de las dimensiones que ingrese el usuario */
		for(j=0;j<x;j++){ /* Para guardar estos valores, serï¿½ necesario el uso de dos ciclos for */
			printf(" Introduzca el elemento [%d] [%d]:",i,j);
			scanf("%d",&matrizA[i][j]); /* Aqui se irï¿½n guardando los valores de la primer matriz */
		}
	}
	printf("\n");  /* Se ingresan valores de la segunda matriz */
	printf("\n Segunda matriz\n"); /* Para la segunda matriz, utilizaremos el mismo ciclo for, pero guardando ahora los
	valores correspondientes a la segunda matriz */
	//y=x; /* Se agregï¿½ la variable y de modo que se puedan mostrar los valores de la segunda matriz */
	for(i=0;i<x;i++){  
		for(j=0;j<x;j++){ 
			printf(" Introduzca el elemento [%d] [%d]:",i,j);
			scanf("%d",&matrizB[i][j]); /* Aqui se irï¿½n guardando los valores de la segunda matriz */
		}
	} 
}
/* Esta funciï¿½n muestra la matriz ingresada */
void matriz_ingresada(int matriz[100][100]){	
	int i, j;
	for(i=0;i<x;i++){  /* inicia ciclo for para mostrar la matriz inicial */ 
		for(j=0;j<x;j++){
			printf("\t%d", matriz[i][j]); /* Se imprime la matriz seleccionada */
		}
		printf("\n");
	}  /* termina ciclo for para mostrar la matriz inicial */
	printf("\n");
}
/* Esta funciï¿½n se encarga de sumar las matrices */
void suma(){ 
	int i,j;
	/* Iniciamos un ciclo for para la operaciï¿½n de la suma */
	for(i=0;i<x;i++){ 
		for(j=0;j<x;j++){
			matrizC[i][j]=matrizA[i][j]+matrizB[i][j]; /* Guardamos la suma de celda en celda en la tercera matriz */
		}
	}
	printf ("\n La suma de las matrices es:\n");
	for (i=0;i<x;i++){  /* Este ciclo se encarga de mostrar los valores guardados en cada celda */
		for(j=0;j<x;j++){
			printf("%5d", matrizC[i][j]); /* Aquï¿½ se imprimen los valores uno por uno */
		}
		printf("\n");
	}
}
/* Esta funcion se encarga de multiplicar las matrices */
void producto(){
	int i,j,k;
	
	/* Se realiza multiplicacion */
	for (i=0;i<x;i++){
		for(j=0;j<x;j++){
			for(k=0;k<x;k++){ /* A diferencia de la suma, vamos a requerir un tercer ciclo for, esto se debe a que al 
			realizar la multiplicacion de celda en celda, estas se iran acumulando en en una fila de modo que se vayan
			sumando para obtener n sumas en cada fila. Por lo tanto se requiere un cilo for adicional que guarde esta
			nueva operacion */
			matrizC[i][j]=matrizC[i][j]+matrizA[i][k]*matrizB[k][j];
			}
		}
	} /* Se imprimen resultados */
	printf("\n El producto de las matrices es:\n");
	for (i=0;i<x;i++){
		for (j=0;j<x;j++){
		    printf("%5d ",matrizC[i][j]);
        }
        printf("\n");
    }
}
/* Esta funcion indica la diagonal de las funciones */
void diagonal(int matriz[100][100]){
	int i,j;
	printf("\n");
    printf("\n La diagonal principal es: \n");
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			if(i == j)
				printf("%5d",matriz[i][j]);  /* Se imprime la diagonal principal */
        }
    }
}
	

int main(void){

	int i,j,k;	
	int menu,opc,c,b;

	do{ /* Dado que el ususario tiene la libertad de seleccionar una operaciï¿½n, es necesario agregar un ciclo do while. 
	Este ciclo repetitivo serï¿½ necesario para validar las condiciones establecidas */
		system("Cls"); /* Limpiamos la pantalla para visualizar el menu principal */
		printf("\n Este programa realiza la suma, producto y diagonal principal de dos matrices \n\n"); /* Mostramos mensaje de bienvenida */
		printf("\t Menu principal \n");
		printf("\n Que operacion desea realizar? \n 1.-Suma \n 2.-Producto \n 3.-Diagonal Principal \n"); 
		scanf("%d",&opc); /* Guardamos la opcion seleccionada por el ususario */
		switch(opc){  /* Inicia switch */
			/* -----------Suma------------ */
			case 1:  /* Se ingresan valores de la primer matriz */
			    tamanio(); /* Se llama la funcion que lee el tamaño de las matrices */
				leermatrices(matrizC); /* Se llama la funcion que lee los datos de las matrices */
				printf("\n");
				printf("Primera matriz:\n");
				matriz_ingresada(matrizA); /* Se llama la funcion que muestra la matriz ingresada */
				printf("Segunda matriz:\n");
				matriz_ingresada(matrizB); /* Se llama la funcion que muestra la matriz ingresada */
				suma(); /* Se llama la funcion que muestra la suma de matrices */
		
		    break;
		    /* ----------Multiplicacion----------- */
		    case 2:  /* Se ingresan valores de la primer matriz */
		        tamanio(); /* Se llama la funcion que lee el tamaño de las matrices */
			    leermatrices(matrizC); /* Se llama la funcion que lee los datos de las matrices */
				printf("\n");
				printf("Primera matriz:\n");
				matriz_ingresada(matrizA); /* Se llama la funcion que muestra la matriz ingresada */
				printf("Segunda matriz:\n");
				matriz_ingresada(matrizB); /* Se llama la funcion que muestra la matriz ingresada */
			    producto(); /* Se llama la funcion que muestra el producto de matrices */
		    break;
            /* ----------Diagonal Principal----------- */
			case 3:  /* Para  el caso de la diagonal se va a requerir un nuevo switch, esto se hace para que
			el usuaio tenga la opcion de elegir cual matriz desea calcular. Las opciones son tres */
			printf("\n Que matriz deseas calcular: \n1.-Matriz 1 \n2.-Matriz 2 \n3.-Matriz resultante\n");
			scanf("%d",&b); /* Guardamos la matriz seleccionada para calcular su respectiva diagonal */
			switch(b){ /* Inicia el segundo switch */
				case 1: /* Diagonal de la primera matriz */
				printf("\n Primera matriz:\n");  /* Para que el usuario pueda corroborar la informacion mas facilmente se 
				incluyeron dos ciclos for para mostrar la matriz inicial seleccionada */
				matriz_ingresada(matrizA); /* Se llama la funcion que muestra la matriz ingresada */
				diagonal(matrizA);
                break;
                case 2: /* Diagonal de la segunda matriz */
                printf("\n Segunda matriz:\n");  /* Para que el usuario pueda corroborar la informacion mas facilmente se 
				incluyeron dos ciclos for para mostrar la matriz inicial seleccionada */
				matriz_ingresada(matrizB); /* Se llama la funcion que muestra la matriz ingresada */
				diagonal(matrizB);
                break;
                case 3: /* Diagonal de la tercera matriz */
                printf("\n Matriz resultante: \n");  /* Para que el usuario pueda corroborar la informacion mas facilmente se 
				incluyeron dos ciclos for para mostrar la matriz inicial seleccionada */
				matriz_ingresada(matrizC); /* Se llama la funcion que muestra la matriz resultante */
				diagonal(matrizC); /* Se llama la funcion que muestra la diagonal de la matriz seleccionada */
                break;
			}  /* termina el segundo switch */
			break;
		default:  /* Si el ususario ingresa un valor fuera del menu se le dara un mensaje de error */
   		printf("\n");
		printf("\n No hay mas opciones que mostrar \n");
		    
		} /* Termina switch */
	printf("\n");
	printf("\n Deseas volver al menu?:\n1.-Si \n2.-No \n");
	scanf("%d",&menu);	

	}  while(menu==1); /* fin ciclo do while */
	return 0;
}
