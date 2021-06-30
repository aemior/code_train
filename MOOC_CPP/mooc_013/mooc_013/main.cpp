#include <bits/stdc++.h>

using namespace std;

map<string, int> InitialHPs = {{"dragon", 0},
								{"ninja", 0},
								{"iceman", 0},
								{"lion", 0},
								{"wolf", 0}};
map<string, int> warrID = {{"dragon", 0},
							{"ninja", 1},
							{"iceman", 2},
							{"lion", 3},
							{"wolf", 4}};

class Warrior{
public:
	Warrior(const string &type):Type(type), HP(InitialHPs[type]){}
	string getType();
	int getHP();
private:
	static int number;
	int HP;
	string Type;
};

string Warrior::getType(){
return Type;
}

int Warrior::getHP(){
return HP;
}

class dragon:public Warrior{
private:
	static int number;
public:
	dragon():Warrior("dragon"){number++;}
	~dragon(){number--;}
};

class ninja:public Warrior{
private:
        static int number;
    public:
        ninja():Warrior("ninja"){number++;}
        ~ninja(){number--;}
};

class iceman:public Warrior{
    private:
        static int number;
    public:
        iceman():Warrior("iceman"){number++;}
        ~iceman(){number--;}
};

class lion:public Warrior{
    private:
        static int number;
    public:
        lion():Warrior("lion"){number++;}
        ~lion(){number--;}
};

class wolf:public Warrior{
    private:
        static int number;
    public:
        wolf():Warrior("wolf"){number++;}
        ~wolf(){number--;}
};



class headquarter{
    public:
        headquarter(int m_get, string side_get):M(m_get), side(side_get) {}
        ~headquarter(){
            for(int i=0; i<warriors.size(); i++){
                delete warriors[i];
            }
        }
        void setOrder(vector<string> &order_get);
        static void setMthr();
        string getSide();
        bool isRun();
        int countWarrior(const string &type);
        bool triMF();
    private:
        Warrior * MakeWarrior(const string &type_get);
        int M, curr_Morder=-1;
        static int Mthr;
        bool runFlag = true;
        string side;
		map<string, int> warrCNT;
        vector<string> Morder;
        vector<Warrior*> warriors;
};

void headquarter::setOrder(vector<string> &order_get){
    Morder = order_get;
}

void headquarter::setMthr(){
	Mthr = 1 << 30;
	for (map<string, int>::iterator it=InitialHPs.begin();
		 it != InitialHPs.end(); ++it) {
		Mthr = min(Mthr, it->second);
	}
}

string headquarter::getSide(){
    return side;
}

bool headquarter::isRun(){return runFlag;}

int headquarter::countWarrior(const string &type){
	if (warrCNT.find(type) != warrCNT.end()) {
		return warrCNT[type];
	}
	else {
		return 0;
	}
};



Warrior * headquarter::MakeWarrior(const string &type_get){
	if (M >= InitialHPs[type_get]) {
		M = M - InitialHPs[type_get];
		switch (warrID[type_get])
		{
		case 0:
			return new dragon();
			break;
		case 1:
			return new ninja();
			break;
		case 2:
			return new iceman();
			break;
		case 3:
			return new lion();
			break;
		case 4:
			return new wolf();
			break;
		default:
			break;
		}
	}
	return NULL;
}

bool headquarter::triMF(){
    if(M < Mthr){
        runFlag = false;
        cout << side << " headquarter stops making warriors" << endl;
        return false;
    }
    Warrior* tmp;
    while(true){
        if(curr_Morder == (Morder.size()-1)){
            curr_Morder = 0;
        }
        else{
            curr_Morder++;
        }
        tmp = MakeWarrior(Morder[curr_Morder]);
        if(tmp){
            warriors.push_back(tmp);
			if (warrCNT.find(tmp->getType()) != warrCNT.end()) {
				warrCNT[tmp->getType()] += 1;
			}
			else {
				warrCNT[tmp->getType()] = 1;
			}
            cout << side << ' ' << Morder[curr_Morder]
                << ' ' << warriors.size()
                << ' ' << "born with strength "
                << tmp->getHP() << ','
                << countWarrior(Morder[curr_Morder])
                << ' ' << Morder[curr_Morder] <<" in "
                << side << " headquarter" << endl;
            return true;
        }
    }

}

vector<string> redOrder = {"iceman", "lion", "wolf", "ninja", "dragon"};
vector<string> blueOrder = {"lion", "dragon", "ninja", "iceman", "wolf"};

int Warrior::number = 0;
int dragon::number = 0;
int iceman::number = 0;
int ninja::number = 0;
int lion::number = 0;
int wolf::number = 0;

int headquarter::Mthr;

int main()
{
    //freopen("test.txt", "r", stdin);
    int N,M,tmp;
    cin >> N;
    for(int i=0; i<N; i++){
        cout << "Case:" << i+1 << endl;
        cin >> M;
        cin >> InitialHPs["dragon"]
            >> InitialHPs["ninja"]
            >> InitialHPs["iceman"]
            >> InitialHPs["lion"]
            >> InitialHPs["wolf"];
        headquarter::setMthr();
        headquarter red(M, "red"),blue(M, "blue");
        red.setOrder(redOrder);
        blue.setOrder(blueOrder);
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
