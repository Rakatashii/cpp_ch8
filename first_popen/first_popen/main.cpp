#include <iostream>
#include <string>
#include <vector>

// Note, if changing popen mode from "r" to "w", PATH_MAX must be changed from 100 to 1000, since all output is given at once, rather than line-by-line.
#define PATH_MAX 100

using namespace std;

vector<string> get_files(string &block, bool command = false);
string get_stdout_from_command(string cmd);

int main(int argc, const char * argv[]) {
    string dir = "~/";
    string cmd = "cd " + dir + "; ls";
    vector<string> files = get_files(cmd, true);
    
    for (int i = 0; i < files.size(); i++){
        cout << "file[" << i << "]: " << files[i] << endl;
    }
    cout << "Total of " << files.size() << " files found in directory " << dir << endl;
    
    cout << "\n";
    return 0;
}
vector<string> get_files(string &block, bool command){
    if (command){
        block = get_stdout_from_command(block);
    }
    int start = 0, end = 0;
    vector<string> files;
    
    for (int i = 0; i < block.length(); i++){
        if (i == 0 || block[i-1] == '\n'){
            start = i;
            for (int j = i+1; j < block.length(); j++){
                if (block[j] == '\n' || block[j] == '\0'){
                    end = j;
                    // Good to know that String#substr() works like this:
                    // ex. "hello"
                    // start = 0, end = 4, size = 5
                    // "hello".substr(0, (4-0));
                    // >> h (start at index 0) e l l o (increment index 4 times and add each time)
                    // So "hello".substr(0, 0), would be "h" - not empty
                    files.push_back(block.substr(start, (end-start)));
                    start = j+1;
                    j = block.length(); // end the j for loop at iteration i
                }
            }
        }
    }
    return files;
}
string get_stdout_from_command(string cmd){
    int status;
    FILE *fp;
    char path[PATH_MAX];
    string result = "";
    
    fp = popen(cmd.c_str(), "r"); // Still confused on read/write here. When "w", the output is all shown at the console at once, and result is returned empty. When "r", the output is read line-by-line, and the vector<string> helper isn't even necessary, since this cuts out whitespace for us anyways. Perhaps, "w" saves the output and allows us to continue writing shell commands, whereas "r", in a sense, freezes those commands so that fg can be read while there is no concern for future modifications. Regardless, need to research this more.
    
    while (fgets(path, PATH_MAX, fp) != NULL){
        result.append(path);
    }
    
    // pclose must be executed after the data from fp is fully read.
    if ( (status = pclose(fp)) ){
        cout << "path: " << path << endl;
        cout << "result: " << result << endl;
    }
    
    result += '\0';
    return result;
}
