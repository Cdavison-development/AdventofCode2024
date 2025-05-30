#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


bool comp(int a, int b) {
    return a > b;
}

bool isArraySorted(vector<int> values){
    bool isSorted;
            if (is_sorted(values.begin(), values.end()) || is_sorted(values.begin(), values.end(), comp)){
                isSorted = true;
            }else{
                isSorted = false;
            }
            return isSorted;
}

bool isArrayAdjacent(vector<int> values){
    bool isAdjacent;
        for(int i = 0;i < values.size()-1;i++){
                if(((abs(values[i] - values[i+1]) <= 3) && (abs(values[i] - values[i+1]) != 0))){
                    isAdjacent = true;               
                }else{  
                    isAdjacent = false;
                    break;
                }
            }
    return isAdjacent;
}


bool isVectorRedeemable(vector<int> values){
    vector<int> tempValues;
    bool isRedeemable;
    for(int i = 0; i < values.size();i++){
        //for each i, initialise the temp Values vector as equal to the values vector, only not including i
        tempValues = values;
        tempValues.erase(tempValues.begin()+i);

    std::cout << "tempValues after removing index " << i << ": ";
    for (const auto& val : tempValues) {
    std::cout << val << " ";
    }
    std::cout << std::endl;

        for(int j = 0; j < tempValues.size()-1;j++){
            bool isAdjacent = isArrayAdjacent(tempValues);
            bool isSorted = isArraySorted(tempValues);
            
            if(isAdjacent  && isSorted){ 
                return true; 
                cout << " This one is redeemable " << endl; 
            }else{

                continue;
            }
        }
    }
    return false;
}


void problem3(){

    ifstream myFileStream("matrix.txt");

    if(!myFileStream.is_open()){
        cout<<"file failed to open"<<endl;
        
    }

    int total = 0;
    string line;
    while(getline(myFileStream,line)){
        vector<int> values;

        stringstream ss(line);
        int currentNumber;

        while (ss >> currentNumber){
            values.push_back(currentNumber);
        }

        bool isSorted = isArraySorted(values);
        bool isAdjacent = isArrayAdjacent(values);
        
        if(isAdjacent == true && isSorted == true){    
            total++;      
             
        }else{
            if(isVectorRedeemable(values)){
                total++;
            }
        }

        cout << total << endl;
    }
}