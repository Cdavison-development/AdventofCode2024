#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;


// could remove all characters not in the "mul(x,y)" format, and go from there.


// for the second problem, I could try to get all the text under do(), and then pass that to the multiplication functions

//The other way would be to iterate with multiplication functions as I have been doing, but stop the summing of multiples
//after dont has been found, and begin summing of multiples when do() is found

// I think method 1 will be easier but method 2 is more efficient.

int Multiplications(string text){

    int total = 0;

    std::regex multiplication_pattern(R"(mul\((-?\d+),\s*(-?\d+)\))");

    std::sregex_iterator iter(text.begin(), text.end(), multiplication_pattern);
    std::sregex_iterator end;

    while(iter != end)
    {
        std::cout << "size: " << iter->size() << std::endl;

        for(unsigned i = 0; i < iter->size(); ++i)
        {
            std::cout << "the " << i + 1 << "th match" << ": " << (*iter)[i] << std::endl;
            if(i == 2){
                int x = std::stoi((*iter)[1].str());
                int y = std::stoi((*iter)[2].str());
                cout << x << " * " << y << " = " << (x*y) << endl;
                total += (x*y);
            }
        }
        ++iter;
    }


    return total;
    //problem 1 total should be 178538786

}

void problem4(){


    ifstream myFileStream("day4Text.txt");

    if(!myFileStream.is_open()){
        cout<<"file failed to open"<<endl;
        //return 0;
    }

    std::regex ExtractionPattern(R"(do\(\)|don't\(\))");
    bool isExtracting = false;
    std::string line;
    std::string text;
    std::string correctedText;
    int startingIdx = -1;
    int closingIdx = -1;

    
    while (std::getline(myFileStream, line)) {
        text.append(line);
    }


    std::sregex_iterator iter(text.begin(), text.end(), ExtractionPattern);
    std::sregex_iterator end;

    while(iter != end)
    {
        std::string matchStr = (*iter).str();

        if (matchStr == "do()") {
            isExtracting = true;
            startingIdx = (*iter).position() + (*iter).length();
            std::cout << "Starting index is " << startingIdx << std::endl;
        }
        else if (matchStr == "don't()") {
            if (isExtracting && startingIdx >= 0) {
                closingIdx = (*iter).position();
                std::cout << "Closing index is " << closingIdx << std::endl;

                if (closingIdx > startingIdx) {
                    correctedText += text.substr(startingIdx, closingIdx - startingIdx);
                }

                // Reset flags after extraction
                isExtracting = false;
                startingIdx = -1;
                closingIdx = -1;
            }
        }
        ++iter;
    }


    //std::cout << correctedText << std::endl;

    int total = Multiplications(correctedText);
    cout << total << endl;
}