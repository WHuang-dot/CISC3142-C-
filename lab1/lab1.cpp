// This file shows basic functions of reading in a CSV file using C++98
// Please add your name to your code! 

/* Homework Objective: fix this program to match the requirements listed: 
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category 
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.
All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(
*/

/* 
Name : Wong Chi Kung Huang Liu
EmplID : 23680237
*/


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std; 

//helper function for removing vector duplicates
void remove(std::vector<string> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
 
    v.erase(end, v.end());
}

int main() {

  // define variables
  string sku, brand, category, year, price; 
  vector<int>vSKU;
  vector<string>vBrand;
  vector<string>vCategory;
  vector<int>vYear;
  vector<float>vPrice;

  ifstream in_stream;
  in_stream.open("lab1/data.csv"); //opening the file.

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

  //create a vector that stores uniqueBrands

  vector<string>uniqueBrand;
  uniqueBrand = vBrand;
  
  remove(uniqueBrand);
  //loop through unique brands
  for(int i = 0; i < uniqueBrand.size(); i++){
    // initializes values for average calculation
    double sum = 0;
    int count = 0;
    double average = 0;

    for(int j = 0; j < vBrand.size(); j++){ //loop through all brands to get their price
      if(vBrand[j] == uniqueBrand[i]){ // if the brand is equal to the current unique brand the price is added to the sum
        sum += vPrice[j];
        count++;
      }
    }

    average = sum/count; // calculate the average
    cout << uniqueBrand[i] + ": " << average << endl;
  }

  //Average price per SKU
  cout << "Average price per SKU" << endl;

  //create a vector that stores uniqueSKUs
  vector<int>uniqueSKU;
  uniqueSKU = vSKU;
  uniqueSKU.erase( unique( uniqueSKU.begin(), uniqueSKU.end() ), uniqueSKU.end() );

  //loop through unique SkUs
  for(int i = 0; i < uniqueSKU.size(); i++){
    // initializes values for average calculation
    double sum = 0;
    int count = 0;
    double average = 0;

    for(int j = 0; j < vSKU.size(); j++){
      if(vSKU[j] == uniqueSKU[i]){ // if the brand is equal to the current unique sku the price is added to the sum
        sum += vPrice[j];
        count++;
      }
    }
    average = sum/count; //calculat the average
    cout << uniqueSKU[i] << ": " << average << endl;
  }

  //SKUs for each unique years
  cout << "SKUs for each unique years" << endl;

  //create a vector that stores uniqueSKUs
  vector<int>uniqueYear;
  uniqueYear = vYear;
  uniqueYear.erase( unique( uniqueYear.begin(), uniqueYear.end() ), uniqueYear.end() );

  //loop through unique Years
  for(int i = 0; i<uniqueYear.size(); i++){
    vector<int> skuOfYear; // vector to store the Sku/s of the year
    int count = 0; // to keep track amount of SKUs

    // loop through all SKUs to get the SKU of the corresponding year
    for(int j = 0; j < vSKU.size(); j++){
      if(vYear[j] == uniqueYear[i]){
        count++;
        skuOfYear.push_back(vSKU[j]);
      }
    }

    cout << uniqueYear[i] << "(" << count << ")" << ": ";

    // outputs all the SKU recorded for the year
    for(int i = 0; i<skuOfYear.size();i++){
      if(i == skuOfYear.size() - 1){
        cout << skuOfYear[i]; // no comma for the last SKU
      }else{
        cout << skuOfYear[i] << ", ";
      }
    }

    cout << "\n" << flush; // end the output
  }

  

}