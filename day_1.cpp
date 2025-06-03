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


    //int size_t = list1.size();
    for(std::size_t i=0; i < list1.size(); i++){
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