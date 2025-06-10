#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <map>
using namespace std;


bool CheckCommon(std::vector<int> const& inVectorA, std::vector<int> const& nVectorB)
{
    auto it = std::find_first_of(inVectorA.begin(), inVectorA.end(),
                                 nVectorB.begin(), nVectorB.end());

    if (it != inVectorA.end()) {
        std::cout << "First common element: " << *it << std::endl;
        return true;
    } else {
        std::cout << "No common element found." << std::endl;
        return false;
    }
}

vector<int> reorderVectors(std::vector<int> const& inVectorA, std::vector<int> const& nVectorB){

    //find the spot in the vector where the common element is found, as this is the spot the error has occured
    
    //first instinct is to bruteforce check, since it seems that you need to search the entire vector for the correct spot





/*
    for (const std::vector<int>& row : inVectorA)
    {
        vector<int> gap;
            for (int s : row) {
                    gap.push_back(s);
                    //std::cout << "Current val from gap: " << s << std::endl;
                
                    std::cout << "Contents of rules[" << s << "]: " << endl;
                    for (int number : rules[s]) {
                        std::cout << number << " ";
                    }
                    std::cout << std::endl;

                    std::cout << "contents of gap vector: "  << std::endl;
                    for (int x: gap){
                        std::cout << x << ' ';
                    }

                    if(CheckCommon(gap,rules[s])){
                        gap.clear();
                        break;
                    }else{
                        continue;
                    }

            }
    }
    */

}

void problem6(){
    
    //ifstream myFileStream("day_5_input_test.txt");
    ifstream myFileStream("day5Input.txt");
        if(!myFileStream.is_open()){
        cout<<"file failed to open"<<endl;
        //return 0;
    }


    string line;
    std::map<int, std::vector<int>> rules;
    vector<vector<int>> updateNumbers;
    
    //could differentiate csv from | values by searching for if the line contains "," or "|"

    //split with regex

    std::regex pattern("^(\\d+)\\|(\\d+)$");
    std::smatch match;

    while(getline(myFileStream,line)){
        stringstream ss(line);
        int itmp;
        vector<int>update {};

        if(std::regex_match(line,match,pattern)){
            int left = std::stoi(match[1].str());
            int right = std::stoi(match[2].str());
            rules[left].push_back(right);
        }
        // rules map populated successfully.

        // read and write comma separated fields to the 2d vector updateNumbers
        while (ss >> itmp) {            /* read integer value from ss */
            std::string stmp {};        /* temporary string to hold delim */
            update.push_back(itmp);          /* add to vector */
            getline (ss, stmp, ',');  /* read delimiter */
        }

        updateNumbers.push_back(update);
    }
    /*
    for each vector
        for each value in vector
            find the equal key in the map
                check if the value comes before all of the values on the value side of the key:value pair 
                    if yes:
                        continue
                    if not:
                        break    

    */

   int total = 0;
   
    for (const std::vector<int>& row : updateNumbers)
    {
        vector<int> gap;
        bool commonFound = false;
            for (int s : row) {
                    gap.push_back(s);
                    //std::cout << "Current val from gap: " << s << std::endl;
                
                    std::cout << "Contents of rules[" << s << "]: " << endl;
                    for (int number : rules[s]) {
                        std::cout << number << " ";
                    }
                    std::cout << std::endl;

                    std::cout << "contents of gap vector: "  << std::endl;
                    for (int x: gap){
                        std::cout << x << ' ';
                    }

                    if(CheckCommon(gap,rules[s])){
                        //gap.clear();
                        commonFound = true;
                        break;        
                    }else{
                        continue;
                    }

            }
            //we see an error where gap vector will be added, where there is only 1 value. work around
            // because i dont know why it does that.
            if(gap.size() > 1 && commonFound == false){
                int middleValue = gap[gap.size()/2];
                total += middleValue;
                cout << "The adding middle value :" << gap[gap.size()/2] << endl;
                cout << "total : " << total << endl;
            }
        }
        //cout << "total : " << total << endl;
}