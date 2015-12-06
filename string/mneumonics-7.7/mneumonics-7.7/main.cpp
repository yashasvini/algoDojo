//
//  main.cpp
//  mneumonics-7.7
//
//  Created by yashasvi on 11/22/15.
//  Copyright (c) 2015 yashasvi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <array>
using namespace std;

void findPneunomicHelper(string phoneNumber,vector<string> *pneumonics,int digit,string *partial_pneumonic );

vector<string> phonePneumonics(const string&s){
    vector<string> pneumonics;
    string partial_pneumonic(s.size(),0);
     findPneunomicHelper(s,&pneumonics,0,&partial_pneumonic);
    return pneumonics;
}

const int numOfDigits=10;
const array<string,numOfDigits> M={"0","1","ABC","DEF","GHI","JKL","MNO","PQR","TUV","WXYZ"};


void findPneunomicHelper(string phoneNumber,vector<string> *pneumonics,int digit,string *partial_pneumonic ){
    if(digit==phoneNumber.size()){
            pneumonics->emplace_back(*partial_pneumonic);
    }
    else{
        for(char c:M[phoneNumber[digit]-'0']){
            (*partial_pneumonic)[digit]=c;
            findPneunomicHelper(phoneNumber,pneumonics,digit+1,partial_pneumonic);
        }
    }
}


void PhoneMnemonicHelper(const string&, int, string*, vector<string>*);

// @include
vector<string> PhoneMnemonic(const string& phone_number) {
    string partial_mnemonic(phone_number.size(), 0);
    vector<string> mnemonics;
    PhoneMnemonicHelper(phone_number, 0, &partial_mnemonic, &mnemonics);
    return mnemonics;
}

const int kNumTelDigits = 10;


void PhoneMnemonicHelper(const string& phone_number, int digit,
                         string* partial_mnemonic, vector<string>* mnemonics) {
    if (digit == phone_number.size()) {
        // All digits are processed, so add partial_mnemonic to mnemonics.
        // (We add a copy since subsequent calls modify partial_mnemonic.)
        cout<<*partial_mnemonic<<endl;
        mnemonics->emplace_back(*partial_mnemonic);
    } else {
        // Try all possible characters for this digit.
        for (char c : M[phone_number[digit] - '0']) {
            (*partial_mnemonic)[digit] = c;
            PhoneMnemonicHelper(phone_number, digit + 1, partial_mnemonic,
                                mnemonics);
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s="9741";
    vector<string> result;
   result = phonePneumonics(s);
    for(string item:result){
        cout<<"item is:";
        cout<<item;
    }
    vector<string> result1;
    cout<<endl<<endl<<"WTFWTF"<<endl<<endl;
    result1 = PhoneMnemonic(s);
    for(string item:result1){
        cout<<"item is";
        cout<<item;
    }
    return 0;
}
