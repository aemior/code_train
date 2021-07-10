#include <bits/stdc++.h>

using namespace std;


//======================================================

class Weapon;
class weaponEnd;
class Warrior;
class warriorEnd;
class City;
bool cmpweapon(Weapon *w1, Weapon *w2);
bool cmpwarrior(Warrior *w1, Warrior *w2);
void printTime();

//======================================================

int now;
int tnum,M,N,K,T;

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

vector<string> redOrder = {"iceman", "lion", "wolf", "ninja", "dragon"};
vector<string> blueOrder = {"lion", "dragon", "ninja", "iceman", "wolf"};

//======================================================


class Weapon{
	public:
		Weapon(){};
		Weapon(const string &type):Type(type) {}
		virtual weaponEnd Attack(int power, Warrior *target);
		string getType();
		Warrior *holder;
		friend class weaponEnd;
		int use=0;
	private:
		string Type;
};

class Warrior{
	public:
		Warrior(const string &type, int idget, int wpnum, string side):Type(type), HP(InitialHPs[type]),
		ID(idget), WpNum(wpnum), Side(side) {
			number++;
		};
		~Warrior(){
			number--;
			for(int i=0; i<weapon.size(); ++i){
				delete weapon[i];
			}
		};
		vector<Weapon*> weapon;
		string getType();
		int getHP();
		int getID();
		string getSide();
		City * getpos();
		void hurt(int);
		void newWeapon(int wpid);
		virtual void showINFO(){};
		friend class weaponEnd;
		void sortWeapon();
		bool useWeapon(Warrior *target);
		virtual void marchTo(City *tar);
		void report();
	private:
		static int number;
		int ID;
		int HP;
		int WpNum;
		int WpIdx = 0;
		string Side;
		string Type;
		City *pos;
};


class City{
	public:
		static int number;
		vector<Warrior*> warriors;
		int ID;
		City(){
			ID = ++number;
		}
		void waReport();
};

class weaponEnd {
	private:
		bool isEnd;
		Weapon *weapon;
		Warrior *warrior;
	public:
		weaponEnd(Weapon *we, Warrior *wa, bool e):weapon(we), warrior(wa), isEnd(e) {}
		void operator()(){
			if (isEnd) {
				for (auto it=warrior->weapon.begin(); it != warrior->weapon.end(); ++it) {
					if (*it == weapon) {
						warrior->weapon.erase(it);
						delete weapon;
						return;
					}
				}
			}
		}
};

class warriorEnd{
	private:
		bool isEnd;
		Warrior *warrior;
		City *city;
	public:
		warriorEnd(Warrior *wa, City *ci, bool e):warrior(wa), city(ci), isEnd(e){}
		void operator()(){
			if (isEnd) {
				for (auto it=city->warriors.begin(); it != city->warriors.end(); ++it) {
					if (*it == warrior) {
						city->warriors.erase(it);
						delete warrior;
						return;
					}
				}
			}
		}
};

//======================================================

string Weapon::getType(){
	return Type;
}

class sword:public Weapon{
	public:
		sword():Weapon::Weapon("sword"){}
		weaponEnd Attack(int power, Warrior *target) {
			target->hurt(int(power*0.2));
			++use;
			return weaponEnd(this, Weapon::holder, false);
		}
};
class bomb:public Weapon{
	public:
		bomb():Weapon::Weapon("bomb"){}
		weaponEnd Attack(int power, Warrior *target) {
			target->hurt(int(power*0.2));
			Weapon::holder->hurt(int(power*0.4)/2);
			++use;
			return weaponEnd(this, Weapon::holder, true);
		}
};
class arrow:public Weapon{
	public:
		arrow():Weapon::Weapon("arrow"){}
		weaponEnd Attack(int power, Warrior *target) {
			target->hurt(int(power*0.3));
			++use;
			return weaponEnd(this, Weapon::holder, use==2);
		}
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

string Warrior::getSide(){
	return Side;
}

City * Warrior::getpos() {
	return pos;
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

void Warrior::sortWeapon(){
	sort(weapon.begin(), weapon.end(), cmpweapon);
}

bool Warrior::useWeapon(Warrior *t) {
	if (weapon.empty()) return false;
	else {
		(weapon[WpIdx++]->Attack(Powers[this->Type], t))();
		if (WpIdx >= weapon.size()) {
			WpIdx = 0;
		}
		return true;
	}
}

void Warrior::marchTo(City *tar) {
	pos = tar;
	pos->warriors.push_back(this);
	printTime();
	cout << Side << ' ' << Type <<  ' ' << ID << " marched to city "
	<< tar->ID << " with " << HP << " elements and force " << Powers[Type] << endl;
}

void Warrior::report() {
	int a=0,b=0,c=0;
	printTime();
	cout << Side << ' ' << Type << ' ' << ID << " has "
	a << " sword " << b << " bomb " << c << " arrow and " << HP << " elements" << endl; 
}

class dragon:public Warrior{
private:
	static int number;
	float morale;
public:
	dragon(int idget, int hm, string side):Warrior("dragon", idget, 1, side){
		morale = float(hm) / float(InitialHPs["dragon"]);
		Warrior::newWeapon(idget%3);
		number++;
	}
	~dragon(){
		number--;
	}
	void showINFO(){
		cout << "It has a " << weapon[0]->getType() 
		<< ",and it's morale is " << fixed << setprecision(2) << morale << endl;
	}
};

class ninja:public Warrior{
private:
        static int number;
    public:
        ninja(int idget, string side):Warrior("ninja", idget, 2, side){
			Warrior::newWeapon(idget%3);
			Warrior::newWeapon((idget+1)%3);
			number++;
		}
        ~ninja(){number--;}
	void showINFO(){
		cout << "It has a " << weapon[0]->getType() << " and a "
		<< weapon[1]->getType() << endl;
	}
};

class iceman:public Warrior{
    private:
        static int number;
    public:
        iceman(int idget, string side):Warrior("iceman", idget, 1, side){
			Warrior::newWeapon(idget%3);
			number++;
		}
        ~iceman(){number--;}
		void showINFO(){
			cout << "It has a " << weapon[0]->getType() << endl;
		}
		void marchTo()
};

class lion:public Warrior{
    private:
        static int number;
		int loyalty;
    public:
        lion(int idget, int hm, string side):Warrior("lion", idget, 0, side){
			loyalty = hm; 
			number++;
		}
        ~lion(){number--;}
		void showINFO(){
			cout << "It's loyalty is " << loyalty << endl;
		}
		warriorEnd run() {
			if (loyalty <= 0) {
				printTime();
				cout << Warrior::getSide() << " lion " << Warrior::getID() << "ran away" << endl; 
			}
			return warriorEnd(this, Warrior::getpos(), loyalty <= 0);
		}
};

class wolf:public Warrior{
    private:
        static int number;
    public:
        wolf(int idget, string side):Warrior("wolf", idget, 0, side){number++;}
        ~wolf(){number--;}
		void Rob(Warrior *tar) {
			if (tar->getType() ==  "wolf" || tar->weapon.empty() || weapon.size() == 10) return;
			int minID = weaponID[tar->weapon[0]->getType()];
			int CNT=0;
			if (minID == 2) {
				auto it = tar->weapon.begin();
				for(;it != tar->weapon.end();++it) {
					if (weaponID[(*it)->getType()] != 2) break;
				}
				--it;
				while (it >= tar->weapon.begin() && weapon.size() < 10) {
					++CNT;
					weapon.push_back(*it);
					tar->weapon.erase(it);
					--it;
				}
			} else {
				auto it = tar->weapon.begin();
				while (it != tar->weapon.end() && weapon.size() < 10) {
					++CNT;
					weapon.push_back(*it);
					tar->weapon.erase(it);
					++it;
				}
			}
			printTime();
			cout << getSide() << " wolf " << getID() << " took " << CNT << " bomb from "
			<< tar->getSide() << ' ' << tar->getType() << " in city " << getpos()->ID << endl;
		}
	void showINFO(){
		return;
	};
};

void City::waReport(){
	sort(warriors.begin(), warriors.end(), cmpwarrior);
	for (auto it = warriors.begin(); it != warriors.end()) {
		(*it)->report();
	}
}

class headquarter:public City{
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
		int getM(){return M;}
    private:
        Warrior * MakeWarrior(const string &type_get);
        int M, curr_Morder=-1;
		int newID = 0;
        static int Mthr;
        bool runFlag = true;
        string side;
		map<string, int> warrCNT;
        vector<string> Morder;
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
	newID++;
	if (M >= InitialHPs[type_get]) {
		M = M - InitialHPs[type_get];
		switch (warrID[type_get])
		{
		case 0:
			return new dragon(newID, M, side);
			break;
		case 1:
			return new ninja(newID, side);
			break;
		case 2:
			return new iceman(newID, side);
			break;
		case 3:
			return new lion(newID, M, side);
			break;
		case 4:
			return new wolf(newID, side);
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
			printTime();
            cout << side << ' ' << Morder[curr_Morder]
                << ' ' << newID << " born" << endl;
			tmp->showINFO();
            return true;
        }
    }
}

bool cmpweapon(Weapon *w1, Weapon *w2) {
	if (w1->getType() == "arrow" && w2->getType() == "arrow") {
		return w1->use < w2->use;
	} else {
		return weaponID[w1->getType()] < weaponID[w2->getType()];
	}
}
bool cmpwarrior(Warrior *w1, Warrior *w1) {
	if (w1->getType() == "red") retrun true;
	return false;
}

int Warrior::number = 0;
int dragon::number = 0;
int iceman::number = 0;
int ninja::number = 0;
int lion::number = 0;
int wolf::number = 0;

int headquarter::Mthr;			

headquarter *RedHQ, *BlueHQ;
City *citys;

void printTime() {
	printf("%03d:%02d ", now/60, now%60);
}

void newWarrios(){
	if (RedHQ->isRun()) {
		printTime();
		RedHQ->triMF();
	}
	if (BlueHQ->isRun()) {
		printTime();
		BlueHQ->triMF();
	}
}

void lionRun(){
	for (int i=0; i<RedHQ->warriors.size(); ++i) {
		if (RedHQ->warriors[i]->getType() == "lion") {
			lion *p = (lion*)(RedHQ->warriors[i]);
			(p->run())();
		}
	}
}

void warriorsMarch() {
	for (auto it=RedHQ->warriors.begin(); it != RedHQ->warriors.end(); ++it) {
		if ((*it)->getSide() == "red") {
			(*it)->marchTo(citys);
			RedHQ->warriors.erase(it);
		}
	}
	for (auto it=BlueHQ->warriors.begin(); it != BlueHQ->warriors.end(); ++it) {
		if ((*it)->getSide() == "blue") {
			(*it)->marchTo(citys+(N-1));
			BlueHQ->warriors.erase(it);
		}
	}
	for (int i=0; i<N; ++i) {
		for (auto it=(citys+i)->warriors.begin(); it != (citys+i)->warriors.end(); ++it) {
			if ((*it)->getSide() == "red") {
				if (i = (N-1)) {
					(*it)->marchTo(BlueHQ);
					printTime();
					cout << "blue headquarter was taken" << endl;
				}
				else
					(*it)->marchTo(citys+i+1);
			} else {
				if (i = 0) {
					(*it)->marchTo(RedHQ);
					printTime();
					cout << "red headquarter was taken" << endl;
				}
				else
					(*it)->marchTo(citys+i-1);
			}
			(citys+i)->warriors.erase(it);
		}
	}
}

void wolfRob() {
	for (int i=0; i<N; ++i) {
		for (auto it=(citys+i)->warriors.begin(); it != (citys+i)->warriors.end(); ++it) {
			if ((*it)->getType() == "wolf") {
				for (int j=0; j<(citys+i)->warriors.size(); ++j) {
					if ((citys+i)->warriors[j]->getSide() != (*it)->getSide()) {
						((wolf*)(*it))->Rob((citys+i)->warriors[j]);
					}
				}
			}
		}
	}
}

void warriorFight(Warrior *wr, Warrior *wb) {
	for (int i=0; i<20; ++i) {
		wr->useWeapon(wb);
		if (wr->getHP() <=0 || wb->getHP() <=0) break;
		wb->useWeapon(wr);
		if (wr->getHP() <=0 || wb->getHP() <=0) break;
	}
	printTime();
	if (wr->getHP() <=0 && wb->getHP() <=0) {
		cout << "both red " << wr->getType() << ' ' << wr->getID() << " and blue "
		<< wb->getType() << ' ' << wb->getID() << " died in city " << wb->getpos()->ID << endl;
	} else if (wr->getHP() >=0 && wb->getHP() >=0) {
		cout << "both red " << wr->getType() << ' ' << wr->getID() << " and blue "
		<< wb->getType() << ' ' << wb->getID() << " were alive in city " << wb->getpos()->ID << endl;
	} else if (wr->getHP() >=0) {
		cout << "red " << wr->getType() << ' ' << wr->getID() << " killed blue " << wb->getType()
		<< ' ' << wb->getID() << " in city " << wr->getpos()->ID << " remaining " << wr->getHP()
		<< " elements" << endl;
	} else {
		cout << "blue " << wb->getType() << ' ' << wb->getID() << " killed red " << wr->getType()
		<< ' ' << wr->getID() << " in city " << wb->getpos()->ID << " remaining " << wb->getHP()
		<< " elements" << endl;
	}
	warriorEnd(wr, wr->getpos(), wr->getHP() <= 0)();
	warriorEnd(wb, wb->getpos(), wb->getHP() <= 0)();
}

void warriorsFight(){
	for (int i=0; i<N; ++i) {
		if ((citys+i)->warriors.size() > 1) {
			if ((citys+i)->warriors[0]->getSide() == "red") {
				warriorFight((citys+i)->warriors[0], (citys+i)->warriors[1]);
			} else {
				warriorFight((citys+i)->warriors[1], (citys+i)->warriors[0]);
			}
		}
	}
}

void HQreport(){
	printTime();
	cout << RedHQ->getM() << " elements in red headquarter" << endl;
	printTime();
	cout << BlueHQ->getM() << " elements in blue headquarter" << endl;
}

void warriorReport() {
	RedHQ->waReport();
	for (int i=0; i<N; ++i) {
		(citys+i)->waReport();
	}
	BlueHQ->waReport();
}


int main () {
	cin >> tnum;
	for (int i=0; i<tnum; ++i) {
		cout << "Case " << i+1 << ':' << endl;
		cin >> M >> N >> K >> T;
		citys = new City[N];
        cin >> InitialHPs["dragon"]
            >> InitialHPs["ninja"]
            >> InitialHPs["iceman"]
            >> InitialHPs["lion"]
            >> InitialHPs["wolf"];
        cin >> Powers["dragon"]
            >> Powers["ninja"]
            >> Powers["iceman"]
            >> Powers["lion"]
            >> Powers["wolf"];
        headquarter::setMthr();
		RedHQ = new headquarter(M, "red");
		BlueHQ = new headquarter(M, "blue");
        RedHQ->setOrder(redOrder);
        BlueHQ->setOrder(blueOrder);
        int event=0;
        cout << setfill('0');
		now = 0;
		while (now <= T) {
			switch (now%60)
			{
			case 0:
				now += 5;
				RedHQ->triMF();
				BlueHQ->triMF();
				break;
			case 5:
				now += 5;
				lionRun();
				break;
			case 10:
				now += 25;
				warriorsMarch();
				break;
			case 35:
				now += 5;
				wolfRob();
				break;
			case 40:
				now += 10;
				warriorsFight();
				break;
			case 50:
				now += 5;
				HQreport();
				break;
			case 55:
				now += 5;
				warriorReport();
				break;
			default:
				break;
			}
		}
		if (N) delete []citys;
		delete BlueHQ;
		delete RedHQ;
	}


	return 0;
}
