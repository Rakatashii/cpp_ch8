#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    string filename = "/Users/christianmeyer/cpp/ch8/fstream_exs/fstream_exs/shakespeare.txt";
    ifstream in(filename);
    int init_pos = in.tellg();
    if ( ! in ){
        cout << "Error opening input file " << filename << endl;
        return -1;
    }
    
    string firstline;
    getline(in, firstline);
    cout << "first line: " << firstline << endl;
    
    char c;
    for(int i = 0; !in.eof(); i++){
        in.get(c);
        if (c < '9' && c > '0'){
            cout << c ;
        }
    }
    cout << "\n";
    //in.seekg(0); // no point - just reopen
    in.close();
    in.open(filename);

    for(int i = 0; !in.eof(); i++){
        in.get(c);
        if (c > '9' || c < '0'){
            cout << c ;
        }
    }
    cout << in.eof();
    
    cout << "\n";
    return 0;
}
