#include <iostream>
#include "Stack.h"
#include <fstream>
#include <cctype>
using namespace std;

#define INPUT_FILE "test.txt"
int main() {

    ifstream f(INPUT_FILE);
    string tmp;
    bool failed = false;
    char item;


    if(!f.good()){
        cout << "Invalid file" << endl;
        exit(-1);
    }


    while(true){
        getline(f, tmp);

        if (f.eof())
            return 0;

        failed = false;
        int nl = atoi(tmp.c_str());


        Stack<string> tmpstack(nl);

        while(nl--){

            getline(f, tmp);
            char op = tmp[0];

            string word = tmp.substr(2);

            if(op == 'i'){
                tmpstack.push(word);

            }else{

                string s;
                if(!tmpstack.isEmpty()){

                    tmpstack.pop(s);

                    if(s != word){
                        failed = true;
                    }

                }

            }
        }

        if (!tmpstack.isEmpty()){
            failed = true;
        }

        if(!failed){
            cout << "stack" << endl;
        }else{
            cout << "not stack" << endl;
        }
    }
    return 0;
}