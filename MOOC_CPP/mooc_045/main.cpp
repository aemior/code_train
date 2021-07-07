#include <bits/stdc++.h>

using namespace std;

map<string, int> InitialHPs = {{"dragon", 0},
								{"ninja", 0},
								{"iceman", 0},
								{"lion", 0},
								{"wolf", 0}};
map<string, int> Powers = {{"dragon", 0},
								{"ninja", 0},
								{"iceman", 0},
								{"lion", 0},
								{"wolf", 0}};
map<string, int> warrID = {{"dragon", 0},
							{"ninja", 1},
							{"iceman", 2},
							{"lion", 3},
							{"wolf", 4}};

map<string, int> weaponID = {
	{"sword", 0},
	{"bomb", 1},
	{"arrow", 2}
};

class Weapon{
	public:
		Weapon(){};
		Weapon(const string &type):Type(type) {}
		virtual WeaponEnd Attack(int power, Warrior *target);
		string getType();
		Warrior *holder;
		friend WeaponEnd;
	private:
		string Type;
};

string Weapon::getType(){
	return Type;
}

class sword:public Weapon{
	public:
		sword():Weapon::Weapon("sword"){}
		WeaponEnd Attack(int power, Warrior *target) {
			target->hurt(int(power*0.2));
			return WeaponEnd(holder, this, false);
		}
};
class bomb:public Weapon{
	public:
		bomb():Weapon::Weapon("bomb"){}
		WeaponEnd Attack(int power, Warrior *target) {
			target->hurt(int(power*0.2));
			Weapon::holder->hurt(int(power*0.4)/2);
			return WeaponEnd(holder, this, true);
		}
};
class arrow:public Weapon{
	private:
		int use = 2;
	public:
		arrow():Weapon::Weapon("arrow"){}
		WeaponEnd Attack(int power, Warrior *target) {
			target->hurt(int(power*0.3));
			--use;
			return WeaponEnd(holder, this, use==0);
		}
};




class Warrior{
public:
	Warrior(const string &type, int idget, int wpnum):Type(type), HP(InitialHPs[type]),
	ID(idget), WpNum(wpnum) {
		number++;
	};
	~Warrior(){
		number--;
		for(int i=0; i<weapon.size(); ++i){
			delete weapon[i];
		}
	};
	string getType();
	int getHP();
	int getID();
	void hurt(int);
	void newWeapon(int wpid);
	Weapon* wp(int idx){return weapon[idx];}
	virtual void showINFO(){};
	friend WeaponEnd;
private:
	static int number;
	int ID;
	int HP;
	int WpNum;
	string Type;
	vector<Weapon*> weapon;
};

string Warrior::getType(){
return Type;
}

int Warrior::getHP(){
return HP;
}

int Warrior::getID(){
	return ID;
}

void Warrior::hurt(int dm) {
	HP -= dm;
}

void Warrior::newWeapon(int wpid){
	Weapon *tmp;
	switch (wpid)
	{
	case 0:
		tmp = new sword;
		break;
	case 1:
		tmp = new bomb;
		break;
	case 2:
		tmp = new arrow;
		break;
	default:
		break;
	}
	weapon.push_back(tmp);
}

class dragon:public Warrior{
private:
	static int number;
	float morale;
public:
	dragon(int idget, int hm):Warrior("dragon", idget, 1){
		morale = float(hm) / float(InitialHPs["dragon"]);
		Warrior::newWeapon(idget%3);
		number++;
	}
	~dragon(){
		number--;
	}
	void showINFO(){
		cout << "It has a " << wp(0)->getType() 
		<< ",and it's morale is " << fixed << setprecision(2) << morale << endl;
	}
};

class ninja:public Warrior{
private:
        static int number;
    public:
        ninja(int idget):Warrior("ninja", idget, 2){
			Warrior::newWeapon(idget%3);
			Warrior::newWeapon((idget+1)%3);
			number++;
		}
        ~ninja(){number--;}
	void showINFO(){
		cout << "It has a " << wp(0)->getType() << " and a "
		<< wp(1)->getType() << endl;
	}
};

class iceman:public Warrior{
    private:
        static int number;
    public:
        iceman(int idget):Warrior("iceman", idget, 1){
			Warrior::newWeapon(idget%3);
			number++;
		}
        ~iceman(){number--;}
	void showINFO(){
		cout << "It has a " << wp(0)->getType() << endl;
	}
};

class lion:public Warrior{
    private:
        static int number;
		int loyalty;
    public:
        lion(int idget, int hm):Warrior("lion", idget, 0){
			loyalty = hm; 
			number++;
		}
        ~lion(){number--;}
	void showINFO(){
		cout << "It's loyalty is " << loyalty << endl;
	}

};

class wolf:public Warrior{
    private:
        static int number;
    public:
        wolf(int idget):Warrior("wolf", idget, 0){number++;}
        ~wolf(){number--;}
	void showINFO(){
		return;
	};
};


class WeaponEnd{
	private:
		Warrior *H;
		Weapon *W;
		bool E;
	public:
		WeaponEnd(Warrior *h, Weapon *w, bool e):H(h), W(w), E(e){}
		void operator ()(){
			if (E) {
				for (auto it = H->weapon.begin(); it != H->weapon.end(); ++it) {
					if (*it == W) {
						H->weapon.erase(it);
						delete W;
						return;
					}
				}
			}
		}
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
	int newID = warriors.size() + 1;
	if (M >= InitialHPs[type_get]) {
		M = M - InitialHPs[type_get];
		switch (warrID[type_get])
		{
		case 0:
			return new dragon(newID, M);
			break;
		case 1:
			return new ninja(newID);
			break;
		case 2:
			return new iceman(newID);
			break;
		case 3:
			return new lion(newID, M);
			break;
		case 4:
			return new wolf(newID);
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
			tmp->showINFO();
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




int main () {

	return 0;
}