#include <bits/stdc++.h>

using namespace std;

class Warrior{
    public:
        //virtual Warrior(){number++; id = number;}
        virtual int getID();
        virtual string getType();
        static int InitialHP;
        virtual int getInitialHP();
    private:
        static int number;
        int id;
        string Type;
};


int Warrior::getID(){
    return this->id+1;
}

string Warrior::getType(){
    return this->Type;
}

int Warrior::getInitialHP(){
    return this->InitialHP;
}


class dragon:public Warrior{
    private:
        string Type = "dragon";
        static int number;
        int id;
    public:
        dragon(){number++; id = number;}
        ~dragon(){number--;}
        int getInitialHP();
        string getType();
        int getID();
        static int InitialHP;
};

class ninja:public Warrior{
    private:
        string Type = "ninja";
        static int number;
        int id;
    public:
        ninja(){number++; id = number;}
        ~ninja(){number--;}
        static int InitialHP;
        int getInitialHP();
        string getType();
        int getID();
};

class iceman:public Warrior{
    private:
        string Type = "iceman";
        static int number;
        int id;
    public:
        iceman(){number++; id = number;}
        ~iceman(){number--;}
        static int InitialHP;
        int getInitialHP();
        string getType();
        int getID();
};

class lion:public Warrior{
    private:
        string Type = "lion";
        static int number;
        int id;
    public:
        lion(){number++; id = number;}
        ~lion(){number--;}
        static int InitialHP;
        int getInitialHP();
        string getType();
        int getID();
};

class wolf:public Warrior{
    private:
        string Type = "wolf";
        static int number;
        int id;
    public:
        wolf(){number++; id = number;}
        ~wolf(){number--;}
        static int InitialHP;
        int getInitialHP();
        string getType();
        int getID();
};


int dragon::getID(){
    return this->id;
}
string dragon::getType(){
    return this->Type;
}
int dragon::getInitialHP(){
    return this->InitialHP;
}

int iceman::getID(){
    return this->id;
}
string iceman::getType(){
    return this->Type;
}
int iceman::getInitialHP(){
    return this->InitialHP;
}

int ninja::getID(){
    return this->id;
}
string ninja::getType(){
    return this->Type;
}
int ninja::getInitialHP(){
    return this->InitialHP;
}

int wolf::getID(){
    return this->id;
}
string wolf::getType(){
    return this->Type;
}
int wolf::getInitialHP(){
    return this->InitialHP;
}

int lion::getID(){
    return this->id;
}
string lion::getType(){
    return this->Type;
}
int lion::getInitialHP(){
    return this->InitialHP;
}


class headquarter{
    public:
        headquarter(int m_get, string side_get){
            M = m_get;
            side = side_get;
        }
        ~headquarter(){
            for(int i=0; i<warriors.size(); i++){
                delete warriors[i];
            }
        }
        string getSide();
        bool triMF();
        bool isRun();
        void setOrder(vector<string> order_get);
        int countWarrior(string type);
        static void setMthr();
    private:
        Warrior * MakeWarrior(string type_get);
        int M, curr_order=-1;
        static int Mthr;
        bool runFlag = true;
        string side;
        vector<string> order;
        vector<Warrior*> warriors;
};

string headquarter::getSide(){
    return side;
}

void headquarter::setOrder(vector<string> order_get){
    order = order_get;
}

bool headquarter::isRun(){return runFlag;}

int Warrior::InitialHP = 99;
int dragon::InitialHP;
int ninja::InitialHP;
int iceman::InitialHP;
int lion::InitialHP;
int wolf::InitialHP;
int dragon::number = 0;
int iceman::number = 0;
int ninja::number = 0;
int lion::number = 0;
int wolf::number = 0;

int headquarter::Mthr;

void headquarter::setMthr(){
    Mthr = min(dragon::InitialHP, ninja::InitialHP);
    Mthr = min(Mthr, iceman::InitialHP);
    Mthr = min(Mthr, lion::InitialHP);
    Mthr = min(Mthr, wolf::InitialHP);
}

int headquarter::countWarrior(string type){
    int res = 0;
    for(int i=0; i<warriors.size(); i++){
        if(warriors[i]->getType() == type) res++;
    }
    return res;
}

Warrior * headquarter::MakeWarrior(string type_get){
    if(type_get == "dragon" && M >= dragon::InitialHP){
        M = M - dragon::InitialHP;
        return new dragon();
    }
    else if(type_get == "ninja" && M >= ninja::InitialHP){
        M = M - ninja::InitialHP;
        return new ninja();
    }
    else if(type_get == "iceman" && M >= iceman::InitialHP){
        M = M - iceman::InitialHP;
        return new iceman();
    }
    else if(type_get == "lion" && M >= lion::InitialHP){
        M = M - lion::InitialHP;
        return new lion();
    }
    else if(type_get == "wolf" && M >= wolf::InitialHP){
        M = M - wolf::InitialHP;
        return new wolf();
    }
    else{
        return nullptr;
    }
}

bool headquarter::triMF(){
    if(M < Mthr){
        runFlag = false;
        cout << side << " headquarter stops making warriors" << endl;
        return false;
    }
    Warrior* tmp;
    while(true){
        if(curr_order == (order.size()-1)){
            curr_order = 0;
        }
        else{
            curr_order++;
        }
        tmp = MakeWarrior(order[curr_order]);
        if(tmp){
            warriors.push_back(tmp);
            cout << side << ' ' << order[curr_order]
                << ' ' << warriors.size()
                << ' ' << "born with strength "
                << tmp->getInitialHP() << ','
                << countWarrior(order[curr_order])
                << ' ' << order[curr_order] <<" in "
                << side << " headquarter" << endl;
            return true;
        }
    }

}




int main()
{
    //freopen("test.txt", "r", stdin);
    int N,M,tmp;
    cin >> N;
    for(int i=0; i<N; i++){
        cout << "Case:" << i+1 << endl;
        cin >> M;
        cin >> dragon::InitialHP
            >> ninja::InitialHP
            >> iceman::InitialHP
            >> lion::InitialHP
            >> wolf::InitialHP;
        headquarter::setMthr();
        headquarter red(M, "red"),blue(M, "blue");
        red.setOrder({"iceman", "lion", "wolf", "ninja", "dragon"});
        blue.setOrder({"lion", "dragon", "ninja", "iceman", "wolf"});
        int event=0;
        cout << setfill('0');
        while(red.isRun() || blue.isRun()){
            if(red.isRun()){
                cout << setw(3) << event << ' ';
                red.triMF();
            }
            if(blue.isRun()){
                cout << setw(3) << event << ' ';
                blue.triMF();
            }
            event++;
        }
    }
    //cout << "Hello world!" << endl;
    return 0;
}
