#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "archivo.dat";
const char *temp ="temporal.dat";
struct Empleado{
	int codigo;
	char nombre[50];
	char apellido[50];
	int sueldo, bonificacion;
};
 void ingresar_empleado();
void abrir_empleado();
 void modificar_empleado();
 void eliminar_empleado();
 void eliminar_empleado();
int main (){
	abrir_empleado();
 ingresar_empleado();
	modificar_empleado();
	eliminar_empleado();
	eliminar_empleado();
	return 0;	
}
void buscar_codigo(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	Empleado empleado;
	
	fread ( &empleado, sizeof(Empleado), 1, archivo );
		
		do{
			
			if (empleado.codigo == cod){
			pos = indice;
			}
	
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );

    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Sueldo: " << empleado.sueldo << endl;
        cout << "Bonificacion: " << empleado.bonificacion << endl;
        cout << endl;
	
	fclose(archivo);
	system("PAUSE");
}


void buscar_indice(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
	
	Empleado empleado;
	
    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Sueldo: " << empleado.sueldo << endl;
        cout << "Bonificacion: " << empleado.bonificacion << endl;
        cout << endl;
	
	fclose(archivo);

	
}


void abrir_empleado(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(Empleado), 1, archivo );
	cout<<"_____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" | "<<"APELLIDO"<<" | "<<"SUELDO"<<" | "<<"BONIFICACION"<<"|"<<"TOTAL"<<" "<<endl;	
		do{
		cout<<"_____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< empleado.codigo <<" | "<< empleado.nombre<<" | "<<empleado.apellido<<"   |   "<<empleado.sueldo<<" | "<<empleado.bonificacion<<" | "<<(empleado.bonificacion+empleado.sueldo)<<endl;
        
        
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_empleado(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		Empleado empleado;
		 string nombre,apellido;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Sueldo:";
		cin>>empleado.sueldo;
		cin.ignore();
		
		cout<<"Ingrese la Bonificacion:";
		cin>>empleado.bonificacion;
		cin.ignore();		
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_empleado();	
	buscar_codigo();
}
void modificar_empleado(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido;	
    	Empleado empleado;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Empleado), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Sueldo:";
		cin>>empleado.sueldo;
		cin.ignore();
		
		cout<<"Ingrese la Bonificacion:";
		cin>>empleado.bonificacion;
		cin.ignore();
				
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
	fclose(archivo);
	abrir_empleado();
		system("PAUSE");
}
///eliminar 
void eliminar_empleado(){
    FILE *archivo =fopen(nombe_archivo,"r+b");
    FILE * temporal =fopen(temp, "wb");
    if (archivo==NULL || temporal == NULL){
    	cout<<"ERROR uno de los archivos no ha sido encontrado."<<endl;
	}
    cout<<"Ingrese codigo a eliminar:";
    int id;
    cin>>id;
    char continuar;
    cout<<"Desea continuar con la eliminacion del empleado?"<<endl;
    fflush(stdin);
    cin>>continuar;
    if ((continuar=='s') || (continuar=='S') );{
    	Empleado empleado;
    	fread(&empleado, sizeof(Empleado),1, archivo);
        while(!feof(archivo))
	    {
	        if (empleado.codigo != id){
	        if (empleado.codigo != id){
	        	fwrite(&empleado, sizeof(Empleado), 1,archivo);
	        	fwrite(&empleado, sizeof(Empleado), 1, temporal);
			}
	    }
	}
	cout<<"Empleado eliminado"<<endl;
	fclose(archivo);
	fclose(temporal);
	remove("archivo.dat");
	rename("temporal.dat", "archivo.dat");
	abrir_empleado();
	

}
}
