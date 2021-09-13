#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;


int count_coma(string file) {
    char symbol;
    int count_coma = 0;
     for ( std::string::iterator it=file.begin(); it!=file.end(); ++it)
    {
        
        if(*it == ',')count_coma ++;
        if(*it ==']') break;
    }
    cout<<"count coma: "<< count_coma;
return count_coma;
}

int main()
{
    //==========Open the File=============
    fstream file;
    string word, filename;

    filename = "binance-min.txt";
    file.open(filename.c_str());
    file >> word;
        
    int count = count_coma(word);
    int size = count + 1;
    
    string arr[size];

    int i = 0;
    stringstream ssin(word);
    string segment;
    
    while(getline(ssin, segment, ','))
{
    arr[i] = segment;
    i++;
}
    //delete []
    arr[0].erase(0, 1);
    arr[size - 1].erase(5, 6);

    //=============Adding to int array=============
    float arr2[size];
    for(int i = 0; i < size; i++) 
    {
       arr2[i] = stof(arr[i]);
    // cout<<"new_arr: "<< arr2[i]<<"\n";
    } 
    //=======Create Array2=============
    int cols;
    cout<< "Please input how many elements in collumns you prefere"<< "\n";
    cin>> cols;
    int rows = size /cols;
    cout<<"rows"<<rows<<"\n";

    float **arr3 = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
       arr3[i] = new float[cols];
    }
    //=============Divide===============
    int chunk = 0;
    for (int i = 0; i < rows; i++)
    {
      
      for (int j = 0; j < cols; j++)
    {
       arr3[i][j] = arr2[j + chunk];
       cout<<arr3[i][j]<<"\t";
    }
    chunk += cols;
    cout<<endl;
    }

    file.close();
    return 0;
}