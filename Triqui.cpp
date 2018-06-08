#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Funciones prototipo
void menu (void);        //menú del juego
void creditos (void);        //créditos
void instrucciones (void);   //instrucciones
void arreglo (char *);        //Vector de 9 posiciones
void juego (char *);          //Control del juego

//------------------------------------------------------------


//Funciones
//Menú principal
void menu (void)
{
	char u=233;
	printf("\n\n\t\t\t S %c P E R  T R I Q U I \n\n",u);
	printf("1.  Jugar.\n");
	printf("2.  Instrucciones.\n");
	printf("0.  Salir.");
}

//Créditos
void creditos (void)
{
	char excl=173, i=161, gn=164;
	printf("\n\n\n\n\n\n\t\t       %c G R A C I A S  P O R  J U G A R !",excl);
	printf("\n\n\n\t\t\t\t    Hecho por");
	printf("\n\t\t\t  Luis Fernando Mart%cnez Mu%coz",i,gn);
	printf("\n\n\t\t\t\t      (O.O)");
	
}

//Instrucciones
void instrucciones (void)
{
	char i=161, u=163, a=160;
	
	printf("\n\t\t\t\tINSTRUCCIONES");
	printf("\n\nTablero:");
	printf("\nTablero de 3x3 casillas vac%cas.",i);
	printf("\n\n\t\t [ ][ ][ ]");
	printf("\n\t\t [ ][ ][ ]");
	printf("\n\t\t [ ][ ][ ]");
	printf("\n\nN%cmero de jugadores:",u);
	printf("\n2 jugadores.");
	printf("\n\nReglas:");
	printf("\n-El juego es por turnos.");
	printf("\n-Cada jugador marcar%c una casilla vac%ca con su s%cmbolo 'X' o 'O'.",a,i,i);
	printf("\n-Gana el jugador que consiga marcar su s%cmbolo en 3 casillas consecutivas en \nl%cnea recta.",i,i);
	printf("\n\n\t\t [X][X][X]\t\t[X][ ][ ]\t\t[X][ ][ ]");
	printf("\n\t\t [ ][ ][ ]\t\t[X][ ][ ]\t\t[ ][X][ ]");
	printf("\n\t\t [ ][ ][ ]\t\t[X][ ][ ]\t\t[ ][ ][X]");
	printf("\n\n-Si ning%cn jugador consigue el objetivo se declara un empate.",u);
}

//Función que crea el vector que alamacenará los símbolos y/o posiciones (1-9)
void arreglo (char * arr)
{
	char pos=49;
	
	for(int i=0;i<9;i++)
	{
		arr[i]=pos;
		pos=pos+1;
	}
}

//Función que controlará el flujo del juego
void juego (char * arr)
{
	int movidas=0, jugador=1, control=0, pos;
	char uM=233, u=163, a=160, excl=173;
	
	for(int i=1;i<10;)
	{
		system("cls");
		printf("\n\n\t\t\t S %c P E R  T R I Q U I \n\n",uM);
		if(control==1)                                                     //en caso de ganar el jugador 1
		{			
       	    for(int i=0;i<=6;i=i+3)			
			printf("\n\t\t\t\t[%c][%c][%c]",arr[i],arr[i+1],arr[i+2]);
       	    printf("\n\n\t\t\t    %cJugador 1 gana!",excl);
       	    getch();
       	    break;
		}
		else if(control==2)                                               //en caso de ganar el jugador 2
		{
			for(int i=0;i<=6;i=i+3)			
			printf("\n\t\t\t\t[%c][%c][%c]",arr[i],arr[i+1],arr[i+2]);
       	    printf("\n\n\t\t\t    %cJugador 2 gana!",excl);
       	    getch();
       	    break;
		}
		else
		{	
		    for(int i=0;i<=6;i=i+3)			
			printf("\n\t\t\t\t[%c][%c][%c]",arr[i],arr[i+1],arr[i+2]);
       	  
       		printf("\nTurno jugador %d selecciona una casilla: ",jugador);
       		scanf("%d",&pos);
       		if(pos<1 || pos>9)
       		{
       			printf("\nPor favor elige solo los n%cmeros de las casillas disponibles.",u);  //evalúa que la opción que elije el usuario esté en el rango
       			getche();                                                                   //del vector
       		}
       		else if(arr[pos-1]=='X' || arr[pos-1]=='O')
       		{			   
       			printf("\nEsta casilla ya est%c marcada, por favor elige otra.",a);    //evalúa que la casilla no esté marcada
       			getche();
       		}
       		else
			{
				if(jugador==1)
				{
					arr[pos-1]='X';
					if((arr[0]=='X' && arr[1]=='X' && arr[2]=='X') || (arr[3]=='X' && arr[4]=='X' && arr[5]=='X') || (arr[6]=='X' && arr[7]=='X' && arr[8]=='X')
					|| (arr[0]=='X' && arr[3]=='X' && arr[6]=='X') || (arr[1]=='X' && arr[4]=='X' && arr[7]=='X') || (arr[0]=='X' && arr[4]=='X' && arr[8]=='X')
					|| (arr[2]=='X' && arr[4]=='X' && arr[6]=='X'))
					control=1;       //condiciones para que gane el jugador 1
					else
					{
						jugador=2;  //cambio de turno
						i=i+1;
					}
				}
				else
				{
					arr[pos-1]='O';
					if((arr[0]=='O' && arr[1]=='O' && arr[2]=='O') || (arr[3]=='O' && arr[4]=='O' && arr[5]=='O') || (arr[6]=='O' && arr[7]=='O' && arr[8]=='O')
					|| (arr[0]=='O' && arr[3]=='O' && arr[6]=='O') || (arr[1]=='O' && arr[4]=='O' && arr[7]=='O') || (arr[0]=='O' && arr[4]=='O' && arr[8]=='O')
					|| (arr[2]=='O' && arr[4]=='O' && arr[6]=='O'))
					control=2;    //condiciones para que gane el jugador 2
					else
					{
						jugador=1;  //cambio de turno
						i=i+1;
					}
				}
			}			      			
       	}     							
    }
    if(control==0)  //condición de Empate
    {
    	system("cls");
    	printf("\n\n\t\t\t S %c P E R  T R I Q U I \n\n",uM);
     	for(int i=0;i<=6;i=i+3)			
		printf("\n\t\t\t\t[%c][%c][%c]",arr[i],arr[i+1],arr[i+2]);
       	printf("\n\n\t\t\t\t %cEmpate!",excl);
       	getch();
    }
    else
    {}	      	      		      	       	
}

//---------------------------------------------------------------

//Función principal
int main (void)
{
	int opc=-1;
	char Arreglo[9], opc2=NULL, o=162;
	do{
		system("cls");
		menu();
		printf("\nIngresa la opci%cn que deseas: ",o);
		scanf("%d",&opc);
		switch(opc){
			case 1:  
			         arreglo(Arreglo);
			         do{
			         	  system("cls");
			        	  juego(Arreglo);
			        	  while(opc2!='S' || opc2!='N')
			        	  {						  
			        	  	printf("\n¿Jugar otra vez? (Si=S/No=N).");
			        	 	scanf("%s",&opc2);
			        	  	if(opc2=='S')
			        	  	{						
			        	  		arreglo(Arreglo);
			        	  		break;
			        	  	}
			        	  	else if(opc2=='N')
			        	 	break;
			        	 	else{}
			        	   }							 			        							  
			        }while(opc2!='N');			         
			         break;
			case 2:
				     system("cls");
				     instrucciones();
				     getch();
				     break;
			case 0:  
			         system("cls");
			         creditos();
			         getch();
			         break;
			default:  
			          printf("Por favor, ingresa alguna de las opciones :) .");
			          getch();
			          break;			
		}
	}while(opc!=0);
}
