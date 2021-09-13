#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main() {

srand(time(NULL));
//=======Open the File============
    ifstream ifs("binance-min.txt");
    char symbol;
    int count_coma = 0;
    while(!ifs.eof())
    {
        ifs.get(symbol);
        if(symbol == ',')count_coma ++;
        if(symbol ==']') break;
    }
    cout<<"count_coma: "<< count_coma<<endl;
    int okr = 10;
    int si = (count_coma + 1) / okr;
    cout<<"si"<< si << endl;
    int *arr3 = new int[si];
    



    //     ifs.seekg(0, ios::beg);
	//     ifs.clear();
    // int temp;
    // for(int i = 0; i<si; i++) {

    //     ifs.get(symbol);
    //      if(symbol != ',' && symbol != '[' && symbol != ']') {
    //          for(int j = 0; j < 5; j++) {
    //              ifs >> temp;
    //             //  cout<<"temp:"<< temp;
    //          }
    //      }
    //      arr3[i] = temp;
    //     //  cout<<"======="<<arr3[i];
    // }
  
    ifs.close();

//=======Create Array==============
int size = 15;

int *arr = new int[size];

cout<<"First array: \t";
for (int i = 0; i < size; i++)
{
    arr[i] = rand()%100;
    cout<<arr[i]<<"\t";
}
cout<<endl;
//=======Create Array2=============
int rows = 3;
int cols = size/rows;

int **arr2 = new int* [rows];
for (int i = 0; i < rows; i++)
    {
       arr2[i] = new int[cols];
    }
//=============Divide===============
int chunk = 0;
for (int i = 0; i < rows; i++)
    {
      
      for (int j = 0; j < cols; j++)
    {
       arr2[i][j] = arr[j + chunk];
       cout<<arr2[i][j]<<"\t";
    }
    chunk += 5;
    cout<<endl;
    }


}