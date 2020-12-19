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
#define MAX_GENERATE_D 100
//#define debag_main

using namespace std;

class rsaSign {
public:
        void start(int C, char **V);
        int GCD (int a, int b);
        int testParam(int C, char **V);
        int generatePairKey();
        int generateSkey( int n, int exp);
        void opener();
        void help();
        bool checkSimple(int num);
        int fEuler(int p,int q);
        int countEs(int PHI);
        void viewEs();
        bool checkEsChoose(int num);
        int countDs(int num, int n, int exp);
        void viewDs();
        bool checkDsChoose(int num);
        void enterSimple();
        void showData();
private:
        int mod,phi,p,q,e,d;
        vector<int>Es, Ds;
};


#endif //RSA_SIGN_RSASIGN_H
