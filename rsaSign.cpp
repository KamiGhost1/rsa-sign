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
    if(mode==0){
        this->generatePairKey();
    }
    if(mode==1){
        this->Sign();
    }
    if(mode==2){
        this->CheckSign();
    }
    if(mode == 3){
        this->Encrypt();
    }
    if(mode == 4){
        this->Decrypt();
    }
    if(mode == 5){
        this->EncryptFile(V[3],V[5]);
    }
    if(mode == 6){
        this->DecryptFile(V[3],V[5]);
    }
}

void rsaSign::help() {
    cout<<"\thelp"<<endl;
    cout<<"./e -sk - generate pair keys"<<endl;
    cout<<"./e --sign - sign msg"<<endl;
    cout<<"./e --check-sign - check signed msg"<<endl;
    cout<<""<<endl;
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
            exit(0);
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
        if(!strcmp(V[1],"-es1")){
            int a,b,c;
            cout<<"enter i: ";
            cin>>a;
            cout<<"enter d: ";
            cin>>b;
            cout<<"enter phi: ";
            cin>>c;
            cout<<"function Es = "<<countEs(a,b,c)<<endl;
        }
        if(!strcmp(V[1],"-sk")){
            return 0;
        }
        if(!strcmp(V[1],"--sign")){
            return 1;
        }
        if(!strcmp(V[1],"--check-sign")){
            return 2;
        }
        if(!strcmp(V[1],"-e")){
            return 3;
        }
        if(!strcmp(V[1],"-d")){
            return 4;
        }
        if(!strcmp(V[1],"--mod")){
            int a,b,c;
            cout<<"enter x: ";
            cin>>a;
            cout<<"enter y: ";
            cin>>b;
            cout<<"enter z: ";
            cin>>c;
            this->modFunc(a,b,c);
        }
    }
    if(C == 6){
        if(!strcmp(V[1],"-e") && !strcmp(V[2],"-i") && !strcmp(V[4],"-o")){
            return 5;
        }
        if(!strcmp(V[1],"-d") && !strcmp(V[2],"-i") && !strcmp(V[4],"-o")){
            return 6;
        }
    }
    cout<<"use -h for help"<<endl;
    exit(0);
}

void rsaSign::showData() {
    cout<<"PK: "<<e<<endl;
    cout<<"SK: "<<d<<endl;
    cout<<"N:  "<<mod<<endl;
}

void rsaSign::showAllData() {
    cout<<"PK: "<<e<<endl;
    cout<<"SK: "<<d<<endl;
    cout<<"N:  "<<mod<<endl;
    cout<<"phi: "<<phi<<endl;
    cout<<"P: "<<p<<endl;
    cout<<"Q: "<<q<<endl;
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

int rsaSign::countEs(int num, int n, int PHI) {
    return (num*n)%PHI;
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


int rsaSign::countDs(int PHI) {
    bool testSimple = 1;
    int check;
    for(int i=3;i<PHI;i++){
        //testSimple = checkSimple(i);
        check = GCD(i,PHI);
        if(testSimple && check==1){
            Ds.push_back(i);
        }
    }
    return 0;
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


int rsaSign::generateSkey(int PHI) {
   countDs(PHI);
    return 0;
}

int rsaSign::generatePkey(int D, int PHI) {
    int check;
    for(int i = 3;i<MAX_GENERATE_D;i++){
        check = countEs(i,D,PHI);
        if(check==1){
            Es.push_back(i);
        }
    }
    return 0;
}

int rsaSign::generatePairKey() {
    bool ChooseEs = false;
    enterSimple();
    mod = p*q;
    phi = this->fEuler(p,q);
#ifdef debag_main
    cout<<mod<<" "<<phi<<endl;
#endif
    generateSkey(phi);
    while(!ChooseEs){
        viewDs();
        cout<<"choose 1 from list and enter: ";
        cin>>d;
        ChooseEs = checkDsChoose(d);
    }
    generatePkey(d,phi);
    ChooseEs = 0;
    while(!ChooseEs){
        viewEs();
        cout<<"choose 1 from list and enter: ";
        cin>>e;
        ChooseEs = checkEsChoose(e);
    }
    showData();
    return 0;
}

int rsaSign::modFunc(int x, int y, int z){
    int buf = x;
    for(int i = 1;i<y;i++){
        buf*=x;
        buf%=z;
    }
#ifdef debag_main
    cout<<buf<<endl;
#endif
    return buf;
}

void rsaSign::Sign() {
    cout<<"Enter message: ";
    cin>>msg;
    cout<<"Enter SK: ";
    cin>>d;
    cout<<"Enter N: ";
    cin>>mod;
    int eMsg = modFunc(msg, d, mod);
    cout<<"Signed msg = "<<eMsg<<endl;
}

void rsaSign::CheckSign() {
    cout<<"Enter signed message: ";
    cin>>msg;
    cout<<"Enter PK: ";
    cin>>e;
    cout<<"Enter N: ";
    cin>>mod;
    int dMsg = modFunc(msg, e, mod);
    cout<<"Msg = "<<dMsg<<endl;
}

void rsaSign::Encrypt() {
    cout<<"Enter message: ";
    cin>>msg;
    cout<<"Enter PK: ";
    cin>>e;
    cout<<"Enter N: ";
    cin>>mod;
    int dMsg = modFunc(msg, e, mod);
    cout<<"encrypt msg = "<<dMsg<<endl;
}

void rsaSign::Decrypt() {
    cout<<"Enter encrypt message: ";
    cin>>msg;
    cout<<"Enter SK: ";
    cin>>d;
    cout<<"Enter N: ";
    cin>>mod;
    int eMsg = modFunc(msg, d, mod);
    cout<<"Decrypt msg = "<<eMsg<<endl;
}

void rsaSign::EncryptFile(char *input, char *output) {
    FILE *fin=fopen(input,"r");
    if(!fin){
        cout<<"file not found!!"<<endl;
        exit(2);
    }
    FILE *fout=fopen(output,"w");
    cout<<"Enter PK: ";
    cin>>e;
    cout<<"Enter N: ";
    cin>>mod;
    char ch;
    int symb;
    while((ch=fgetc(fin)) != EOF){
        symb = (int)ch;
        cout<<symb<<" ";
        symb = modFunc(symb,e,mod);
        cout<<symb<<" ";
        ch = (char)symb;
        cout<<ch<<" "<<(int)ch<<endl;
        fwrite(&symb, sizeof(char),1,fout);
    }
    fcloseall();
    cout<<"the file "<<input<<" was encrypted and saved in "<<output<<endl;
}
void rsaSign::DecryptFile(char *input, char *output) {
    FILE *fin=fopen(input,"r");
    if(!fin){
        cout<<"file not found!!"<<endl;
        exit(2);
    }
    FILE *fout=fopen(output,"w");
    cout<<"Enter SK: ";
    cin>>d;
    cout<<"Enter N: ";
    cin>>mod;
    char ch;
    int symb;
    while((ch=fgetc(fin)) != EOF){
        symb = (int)ch;
        cout<<symb<<" ";
        symb = modFunc(symb,d,mod);
        cout<<symb<<" ";
        ch = (char)symb;
        cout<<ch<<" "<<(int)ch<<endl;
        fwrite(&symb, sizeof(char),1,fout);
    }
    fcloseall();
    cout<<"the file "<<input<<" was decrypted and saved in "<<output<<endl;
}