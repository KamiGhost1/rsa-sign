//
// Created by ghost on 19.12.2020.
//

#ifndef RSA_SIGN_RSASIGN_H
#define RSA_SIGN_RSASIGN_H
#include <string>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#define MAX_GENERATE_D 1000
//#define debag_main

using namespace std;

class rsaSign {
public:
        void start(int C, char **V);
        int GCD (int a, int b);
        int testParam(int C, char **V);
        int generatePairKey();
        int generateSkey(int PHI);
        int generatePkey(int D, int PHI);
        void opener();
        void help();
        bool checkSimple(int num);
        int fEuler(int p,int q);
        int countEs(int PHI, int num, int n);
        void viewEs();
        bool checkEsChoose(int num);
        int countDs(int PHI);
        void viewDs();
        bool checkDsChoose(int num);
        void enterSimple();
        void showData();
        void showAllData();
        void Sign();
        void CheckSign();
        int modFunc(int x, int y, int z);
        void Encrypt();
        void Decrypt();
        void EncryptFile(char *input, char *output);
        void DecryptFile(char *input, char *output);
private:
        int mod,phi,p,q,e,d, msg;
        vector<int>Es, Ds, bInt, bDig;
        vector<char> bStr;
};


#endif //RSA_SIGN_RSASIGN_H
