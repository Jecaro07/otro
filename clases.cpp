#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

#include <fstream>
#include <sstream>

#define _USE_MATH_DEFINES

using namespace std;
 using std::vector;

template <class T>
class figgeo {
    T d;
  public:
    figgeo (T dato)
      {d=dato;}
    vector<T> circulo();
    T cuadrado();
};

template <class T>
vector<T> figgeo<T>::circulo()
{
  vector<T> retval;
  retval.resize(2);
  retval[0]=2*M_PI*d; // PERIMETRO
  retval[1]=M_PI*d*d; // AREA
  return retval;
}

template <class T>
T figgeo<T>::cuadrado()
{
  T retval;
  retval = d*4; // DEVUELVE a SI SE CUMPLE Y b EN EL CASO CONTRARIO
  return retval;
}

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int main () {
    string line; float dd; int ii_,coordenadas,n_puntos,rep;
    vector <string> words;
    vector <float> p_inicial;
    vector <vector<float>> p;
  ifstream myfile;
  myfile.open("tsp_datos.txt");
  if (myfile.is_open()){
	  
	// COORDENADAS  
   getline (myfile,line) ;
		words = split(line,' ');
		coordenadas=stoi(words[1]);
      cout << coordenadas<< '\n';  
      words.clear();
    cout<<endl;
    
    // PUNTOS_INTERMEDIOS 
    getline (myfile,line) ;
		words = split(line,' ');
		n_puntos=stoi(words[1]);
		//dd=stof(line);	
		//ii_=stoi(line);
      cout << coordenadas<< '\n';  
      words.clear();
    cout<<endl;
    
    p.resize(n_puntos+1);
    
    // PUNTO_INICIAL 
    getline (myfile,line) ;
		words = split(line,' ');
	p[0].resize(coordenadas);
	for (int j=0;j<p[0].size();j++){
	p[0][j]=stof(words[j+1]);
	cout << p[0][j]<< '\n'; 
	} 
      words.clear();// p_inicial.clear();
    cout<<endl;
    
    // PUNTO_FINAL 
    getline (myfile,line) ;
		words = split(line,' ');
	p_inicial.resize((words.size())-1);
	for (int j=0;j<p_inicial.size();j++){
	p_inicial[j]=stof(words[j+1]);
	cout << p_inicial[j]<< '\n'; 
	} 
      words.clear(); p_inicial.clear();
    cout<<endl;
  
  // PUNTOS TRAYECTORIA
  getline (myfile,line);
  
  for(int i=0;i<n_puntos;i++){	  
  getline (myfile,line) ;
		words = split(line,' ');
	p[i+1].resize(coordenadas);
	for (int j=0;j<p[i+1].size();j++){
	p[i+1][j]=stof(words[j]);
	cout << p[i+1][j]<< '\n'; 
	} 
      words.clear(); //p_inicial.clear();
    cout<<endl;
  }
  
  
  // NUMERO DE REPETICIONES  
   getline (myfile,line) ;
		words = split(line,' ');
		rep=stoi(words[1]);
      cout << rep<< '\n';  
      words.clear();
    cout<<endl;
    
    myfile.close();
  }

  else{ cout << "Unable to open file"; 
}
   
   
  return 0;
}
