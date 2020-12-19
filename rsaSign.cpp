//
// Created by ghost on 19.12.2020.
//

#include "rsaSign.h"

void rsaSign::opener() {
    cout<<endl;
    cout<<"\t__    __      ______ "<<endl;
    cout<<"\t| |  / /   / /______\\ \\   | | \\  / | |   | |"<<endl;
    cout<<"\t| | / /    | |      | |   | |\\ \\/ /| |   | |"<<endl;
    cout<<"\t| |/ /     | |      | |   | |  --  | |   | |"<<endl;
    cout<<"\t| |\\ \\     | |      | |   | |      | |   | |"<<endl;
    cout<<"\t| | \\ \\    | |      | |   | |      | |   | |"<<endl;
    cout<<"\t| |  \\ \\   | |______| \\   | |      | |   | |"<<endl;
    cout<<"\t| |   \\ \\  \\ \\______| \\\\  | |      | |   | |"<<endl;
    cout<<"\n\nK@mi soft\ngithub.com:kamighost1\n"<<endl;
}

void rsaSign::start(int C, char **V){
    int mode = this->testParam(C,V);
}

void rsaSign::help() {
    cout<<"help"<<endl;
}

int rsaSign::testParam(int C, char **V) {
    if(C==1){
        this->opener();
        cout<<"its program for RSA Sign. use -h for more information"<<endl;
        exit(0);
    }
    if(C==2){
        if(!strcmp(V[1],"-h")){
            this->help();
        }
        if(!strcmp(V[1],"--simple")){
            cout<<"enter Number: ";
            int num;
            cin>>num;
            bool test = this->checkSimple(num);
            if(test){
                cout<<num<<" is simple"<<endl;
                exit(0);
            }else{
                cout<<num<<" is not simple"<<endl;
                exit(0);
            }
        }
        if(!strcmp(V[1],"--gcd")){
            int a,b;
            cout<<"enter Number 1: ";
            cin>>a;
            cout<<"enter Number 2: ";
            cin>>b;
            cout<<"GSD = "<<GCD(a,b)<<endl;
        }
        if(!strcmp(V[1],"-fe")){
            int a,b;
            cout<<"enter Number 1: ";
            cin>>a;
            cout<<"enter Number 2: ";
            cin>>b;
            cout<<"function Euler = "<<fEuler(a,b)<<endl;
        }
        if(!strcmp(V[1],"-es")){
            int a;
            cout<<"enter phi: ";
            cin>>a;
            cout<<"function Es = "<<countEs(a)<<endl;
            viewEs();
        }
        if(!strcmp(V[1],"-sk")){
            generatePairKey();
        }
    }
    return -1;
}

void rsaSign::showData() {
    cout<<"PK: "<<e<<endl;
    cout<<"SK: "<<d<<endl;
    cout<<"N:  "<<mod<<endl;
}

void rsaSign::enterSimple() {
    bool simple = false;
    while (!simple){
        cout<<"Enter simple P: ";
        cin>>p;
        simple = checkSimple(p);
        if(!simple){
            cout<<"try again, its not simple"<<endl;
        }
    }
    simple = false;
    while (!simple){
        cout<<"Enter simple Q: ";
        cin>>q;
        simple = checkSimple(q);
        if(!simple){
            cout<<"try again, its not simple"<<endl;
        }
    }
}

bool rsaSign::checkSimple(int num) {
    if(num<0){
        num = abs(num);
    }
    if(num < 3){
        cout<<"Enter normal'noe num>2"<<endl;
        return false;
    }
    for(int i=2;i<num;i++){
        if(num % i == 0 && i!=num){
            return false;
        }
    }
    return true;
}

int rsaSign::GCD(int a, int b) {
    int big,small;
    if(a>b){
        big = a;
        small = b;
    }else{
        big = b;
        small = a;
    }
    for(int i = small;i>0;i--){
        if(big%i==0 && small%i==0 && i>1){
            return i;
        }
    }
    return 1;
}

int rsaSign::fEuler(int p, int q) {
    return (p-1)*(q-1);
}

int rsaSign::countEs(int PHI) {
    //int check;
    bool testSimple;
    for(int i=3;i<PHI;i++){
        testSimple = checkSimple(i);
        //check = GCD(i,PHI);
        if(testSimple){
            Es.push_back(i);
        }
    }
    return 0;
}

void rsaSign::viewEs() {
    for(int i=0;i<Es.size();i++){
        cout<<Es[i]<<endl;
    }
}

bool rsaSign::checkEsChoose(int num) {
    for(int i=0;i<Es.size();i++){
        if(num == Es[i]){
            return true;
        }
    }
    return false;
}

int rsaSign::countDs(int num, int n, int exp) {
    return (num*n)%exp;
}

void rsaSign::viewDs() {
    for(int i=0;i<Ds.size();i++){
        cout<<Ds[i]<<endl;
    }
}

bool rsaSign::checkDsChoose(int num) {
    for(int i=0;i<Ds.size();i++){
        if(num == Ds[i]){
            return true;
        }
    }
    return false;
}

int rsaSign::generateSkey(int n, int exp) {
    int check;
    for(int i = 3;i<MAX_GENERATE_D;i++){
        check = countDs(i,n,exp);
        if(check==1){
            Ds.push_back(i);
        }
    }
    return 0;
}

int rsaSign::generatePairKey() {
    bool ChooseEs = false;
    enterSimple();
    mod = p*q;
    phi = this->fEuler(p,q);
    countEs(phi);
    while(!ChooseEs){
        viewEs();
        cout<<"choose 1 from list and enter: ";
        cin>>e;
        ChooseEs = checkEsChoose(e);
    }
#ifdef debag_main
    cout<<mod<<" "<<phi<<endl;
#endif
    generateSkey(e,phi);
    ChooseEs = false;
    while(!ChooseEs){
        viewDs();
        cout<<"choose 1 from list and enter: ";
        cin>>d;
        ChooseEs = checkDsChoose(d);
    }
    showData();
    return 0;
}