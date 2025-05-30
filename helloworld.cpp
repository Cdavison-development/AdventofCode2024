#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int problem1()
{

    ifstream myFileStream("input1.txt");

    if(!myFileStream.is_open()){
        cout<<"file failed to open"<<endl;
        return 0;
    }


    int total = 0;
    vector<int> list1 = {};
    vector<int> list2 = {};

    string myString;
    string line;
    while(getline(myFileStream,line)){
        stringstream ss(line);
        int number1, number2;

        ss >> number1 >> number2;

        list1.push_back(number1);
        list2.push_back(number2);
        //total += abs(number1-number2);
    }

    stable_sort(list1.begin(), list1.end());
    stable_sort(list2.begin(), list2.end());



    for(int i=0; i < list1.size(); i++){
        total += abs(list1[i]-list2[i]);
    }
    cout << total << endl;
    return total;
}

int problem2(){
    
    ifstream myFileStream("input1.txt");

    if(!myFileStream.is_open()){
        cout<<"file failed to open"<<endl;
        //return 0;
    }


    int total = 0;
    vector<int> list1 = {};
    vector<int> list2 = {};

    string myString;
    string line;
    while(getline(myFileStream,line)){
        stringstream ss(line);
        int number1, number2;

        ss >> number1 >> number2;

        list1.push_back(number1);
        list2.push_back(number2);
        //total += abs(number1-number2);
    }

    //stable_sort(list1.begin(), list1.end());
    //stable_sort(list2.begin(), list2.end());
    map<int,int> GnomeList = {};

    for(int i = 0; i < list1.size(); i++){
        GnomeList[list1[i]] = 0;
        for(int j = 0; j < list2.size(); j++){
            if(list1[i] == list2[j]){
                GnomeList[list1[i]] += 1;
            }
        }
    }

    for (const auto& [key, value] : GnomeList) {
        //cout << "Key: " << key << ", Value: " << value << endl;
        total += (key*value);
    }

    cout << total << endl;
    return total;
}

bool comp(int a, int b) {
    return a > b;
}

bool isArraySorted(vector<int> values){
    bool isSorted;
            if (is_sorted(values.begin(), values.end()) || is_sorted(values.begin(), values.end(), comp)){
                isSorted = true;
                //cout << line << "  is Sorted" << endl;
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

//need to be able to take the vectors that do not pass the initial test and attempt to remove single bad level to make it safe

//most likely will bruteforce

bool isVectorRedeemable(vector<int> values){
    //easy way: iterate through the vector, remove vector[i] and run isAdjacent and IsSorted tests. costly

    // this might mess with the vector.size() function in isAdjacent, be sure to handle correctly.

    // use a temporary vector that will store all values other than i and check for correctness
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
                //isRedeemable = true; 
                cout << " This one is redeemable " << endl; 
                //break;
            }else{
                //cout << " This one is not redeemable " << endl;
                //isRedeemable = false;
                continue;
            }
            //isRedeemable = false;
        }
       // return false;
    }
    return false;
}


void problem3(){

    ifstream myFileStream("matrix.txt");

    if(!myFileStream.is_open()){
        cout<<"file failed to open"<<endl;
        //return 0;
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
            //question 3 extension 
            if(isVectorRedeemable(values)){
                total++;
            }
        }

        cout << total << endl;
    }
}


int main(){
    problem3();
}