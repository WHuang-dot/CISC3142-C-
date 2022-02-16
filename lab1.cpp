// This file shows basic functions of reading in a CSV file using C++98
// Please add your name to your code! 

/* Homework Objective: fix this program to match the requirements listed: 
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category 
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.
All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std; 

int main() {

  // define variables
  string sku, brand, category, year, price; 
  vector<int>vSKU;
  vector<string>vBrand;
  vector<string>vCategory;
  vector<int>vYear;
  vector<float>vPrice;

  ifstream in_stream;
  in_stream.open("data.csv"); //opening the file.

  if (!in_stream.fail()) { //if the file is open

    string line;

    while (getline(in_stream, line)) { //while the end of file is NOT reached

     // Fields: sku,brand,category,year,price

     getline(in_stream, sku, ',');
     stringstream ssku(sku); 
     int iSKU = 0;
     ssku >> iSKU;
     vSKU.push_back(iSKU);

     getline(in_stream, brand, ',');
     vBrand.push_back(brand);

     getline(in_stream, category, ',');
     vCategory.push_back(category);

     getline(in_stream, year, ','); 
     stringstream syear(year);
     int iYear;
     syear >> iYear;
     vYear.push_back(iYear);

     getline(in_stream, price, '\n'); 
     stringstream sprice(price);
     float fPrice;
     sprice >> fPrice;
     vPrice.push_back(fPrice);
     
    }

    in_stream.close(); //closing the file cout << "Number of entries: " << i-1 << endl;

   } else {
    cout << "Unable to open file"; 
   }
 
  //output values 
  cout << "SKU" << "\t" << "Brand" << "\t" << "Year" << "\t" << "Price" << endl; 

  for (int j = 0; j < vSKU.size(); j++) {
    cout << vSKU[j] << "\t" << vBrand[j] << "\t" << vYear[j] << "\t" << vPrice[j] << endl;
  }

  //Averages

  //Average price per brand
  cout << "Average price per brand" << endl;
  vector<string>uniqueBrand;
  uniqueBrand = vBrand;
  uniqueBrand.erase( unique( uniqueBrand.begin(), uniqueBrand.end() ), uniqueBrand.end() );
  for(int i = 0; i < uniqueBrand.size(); i++){
    double sum = 0;
    int count = 0;
    double average = 0;
    for(int j = 0; j < vBrand.size(); j++){
      if(vBrand[j] == uniqueBrand[i]){
        sum += vPrice[j];
        count++;
      }
    }
    average = sum/count;
    cout << uniqueBrand[i] + ": " << average << endl;
  }

  //Average price per SKU
  cout << "Average price per SKU" << endl;
  vector<int>uniqueSKU;
  uniqueSKU = vSKU;
  uniqueSKU.erase( unique( uniqueSKU.begin(), uniqueSKU.end() ), uniqueSKU.end() );
  for(int i = 0; i < uniqueSKU.size(); i++){
    double sum = 0;
    int count = 0;
    double average = 0;
    for(int j = 0; j < vSKU.size(); j++){
      if(vSKU[j] == uniqueSKU[i]){
        sum += vPrice[j];
        count++;
      }
    }
    average = sum/count;
    cout << uniqueSKU[i] << ": " << average << endl;
  }

  //SKUs for each unique years
  cout << "SKUs for each unique years" << endl;
  vector<int>uniqueYear;
  uniqueYear = vYear;
  uniqueYear.erase( unique( uniqueYear.begin(), uniqueYear.end() ), uniqueYear.end() );

  for(int i = 0; i<uniqueYear.size(); i++){
    vector<int> skuOfYear;
    int count = 0;
    for(int j = 0; j < vSKU.size(); j++){
      if(vYear[j] == uniqueYear[i]){
        count++;
        skuOfYear.push_back(vSKU[j]);
      }
    }

    cout << uniqueYear[i] << "(" << count << ")" << ": ";
    for(int i = 0; i<skuOfYear.size();i++){
      if(i == skuOfYear.size() - 1){
        cout << skuOfYear[i];
      }else{
        cout << skuOfYear[i] << ", ";
      }
    }

    cout << "\n" << flush;
  }

  

}