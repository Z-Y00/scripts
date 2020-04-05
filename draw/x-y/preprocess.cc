#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int main(int argc, char ** argv) {
	std::string input = argv[1];
    std::string output = input+".plot";
    uint32_t a,b;
    uint32_t a_,b_;
    double counter=0;
    ifstream fin(input);
    ofstream fout(output);
    bool init = false;
    while (true) {
		if (fin.eof()) break;
        fin >> a >> b;
        counter++;
        if(!init){
            a_=a;
            b_=b;
            init = true;
        }
        if((a!=a_)||(b!=b_)){//next one
                //fout<<a_<<" "<<b_<<" "<<sqrt(counter)/40<<"\n";//usually consider log/sqrt
                fout<<a_<<" "<<b_<<" "<<sqrt(counter)<<"\n";
                counter = 0;
                a_=a;
                b_=b;
            }
		}
		fin.close();
        fout.close();
    return 0;
}
