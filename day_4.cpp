#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

void problem5(){


    //iterate through until X is found, from there create a grid around the X and search for M, once M is found, follow that direction
    //to try to find A and S.


    ifstream myFileStream("day4Input.txt");
    ifstream myFileStream2("day4Input.txt");

    if(!myFileStream.is_open()){
        cout<<"file failed to open"<<endl;
        //return 0;
    }
    string line;
    string text;

    int linelength;
    int lineNumber = 0;
    int lineNumber2 = 0;
    int total = 0;
    //storing text from file in memory, this should make handling easier
    while(getline(myFileStream,line)){
        text.append(line);

        lineNumber++;
        linelength = line.length();

        
    }
    vector<vector<char>> arr(lineNumber, vector<char>(linelength));


    //convert string to 2D array.
    while(getline(myFileStream2,line)){

        for (size_t i = 0; i < line.length(); ++i) {
            char c = line[i];
            arr[lineNumber2][i] = c;
        }

        lineNumber2++;
    }

    int x[]={-1,-1,-1, 0, 0, 1, 1, 1};
    int y[]={-1, 0, 1,-1, 1,-1, 0, 1};


    //find X, then search for M, then A in the same direction, and finally S in the same direction
    for(int i = 0; i < lineNumber; i++) {
    for(int j = 0; j < linelength; j++) {
        std::cout << "Checking position (" << i << ", " << j << "): " << arr[i][j] << std::endl;
    
        if(arr[i][j] == 'X') {
            std::cout << "  Found 'X' at (" << i << ", " << j << ")" << std::endl;

            int x0 = i;
            int y0 = j;
            if (x0 < 0 || x0 >= lineNumber || y0 < 0 || y0 >= linelength) {
                    std::cout << "Skipping out-of-bounds check at (" << x0 << ", " << y0 << ")" << std::endl;
                    continue;
                }
            for(int k = 0; k < 8; k++) {
                int nx = x0 + x[k];
                int ny = y0 + y[k];
                std::cout << "    Checking direction k=" << k << " at (" << x0 + x[k] << ", " << y0 + y[k] << ")" << std::endl;
                    if (nx < 0 || nx >= lineNumber || ny < 0 || ny >= linelength) {
                        std::cout << "Skipping out-of-bounds check at (" << nx << ", " << ny << ")" << std::endl;
                        continue;
                    }
                if(arr[nx][ny] == 'M') {
                    std::cout << "      Found 'M' at (" << x0 + x[k] << ", " << y0 + y[k] << ")" << std::endl;

                    int x1 = x0 + x[k];
                    int y1 = y0 + y[k];
                    if (x1 < 0 || x1 >= lineNumber || y1 < 0 || y1 >= linelength) {
                        std::cout << "      Skipping out-of-bounds check at (" << x1 << ", " << y1 << ")" << std::endl;
                        continue;
                    }

                    int dx = x1 - x0;
                    int dy = y1 - y0;

                    std::cout << "        Direction vector (dx, dy): (" << dx << ", " << dy << ")" << std::endl;

                    int x2 = x1 + dx;
                    int y2 = y1 + dy;
                        
                    if (x2 < 0 || x2 >= lineNumber || y2 < 0 || y2 >= linelength) {
                        std::cout << "      Skipping out-of-bounds check at (" << x2 << ", " << y2 << ")" << std::endl;
                        continue;
                    }
                    if(arr[x2][y2] == 'A') {

                        std::cout << "          Found 'A' at (" << x2 << ", " << y2 << ")" << std::endl;


                    int x3 = x2 + dx;
                    int y3 = y2 + dy;
                    if (x3 < 0 || x3 >= lineNumber || y3 < 0 || y3 >= linelength) {
                        std::cout << "Skipping out-of-bounds check at (" << x3 << ", " << y3 << ")" << std::endl;
                        continue;
                        }

                        if(arr[x3][y3] == 'S') {
                            std::cout << "            Found 'S' at (" << x2 + dx << ", " << y2 + dy << ")" << std::endl;
                            std::cout << "              ==> XMAS FOUND!" << std::endl;
                            total++;
                            cout << "the total amount of times mentioned is " << total << endl;
                        } else {
                            std::cout << "            No 'S' at (" << x2 + dx << ", " << y2 + dy << ")" << std::endl;
                        }
                    } else {
                        std::cout << "          No 'A' at (" << x1 + dx << ", " << y1 + dy << ")" << std::endl;
                    }
                } else {
                    std::cout << "      No 'M' at (" << x0 + x[k] << ", " << y0 + y[k] << ")" << std::endl;
                }
            }
        }
    }
    }


    
}