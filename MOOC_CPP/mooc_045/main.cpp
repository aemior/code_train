#include <bits/stdc++.h>

using namespace std;

//======================================================

template<class T1>
void modeVector(vector<T1> &v, bool(*p)(T1)){
	bool FLG = true;
	while (FLG) {
		FLG = false;
		for (auto it = v.begin(); it != v.end(); ++it) {
			if (p(*it)) {
				v.erase(it);
				FLG = true;
				break;
			}
		}
	}
}

bool equ2(int i) {
	return i==2;
}

//======================================================

class Weapon;
class weaponEnd;
class Warrior;
class warriorEnd;
class City;
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
		~Weapon(){}
		Weapon(const string &type, Warrior *h):Type(type), holder(h){}
		virtual weaponEnd Attack(int power, Warrior *target) = 0;
		string getType();
		Warrior *holder;
		friend class weaponEnd;
		int use=0;
	private:
		string Type;
};

class Warrior{
	public:
		Warrior(const string &type, int idget, int wpnum, string side, City *ipos):Type(type), HP(InitialHPs[type]),
		ID(idget), WpNum(wpnum), Side(side), pos(ipos) {
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
		void captureWeapons(Warrior *tar);
		void lostWeapon(Weapon *tar);
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

bool cmpweapon(Weapon *w1, Weapon *w2);
bool cmpwarrior(Warrior *w1, Warrior *w2);


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
		sword(Warrior *h):Weapon::Weapon("sword", h){}
		~sword(){}
		weaponEnd Attack(int power, Warrior *target) {
			target->hurt(int(power*0.2));
			++use;
			return weaponEnd(this, Weapon::holder, false);
		}
};
class bomb:public Weapon{
	public:
		bomb(Warrior *h):Weapon::Weapon("bomb", h){}
		~bomb(){}
		weaponEnd Attack(int power, Warrior *target) {
			target->hurt(int(power*0.4));
			if (holder->getType() != "ninja")
				Weapon::holder->hurt(int(power*0.4)/2);
			++use;
			return weaponEnd(this, Weapon::holder, true);
		}
};
class arrow:public Weapon{
	public:
		arrow(Warrior *h):Weapon::Weapon("arrow", h){}
		~arrow(){}
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
		tmp = new sword(this);
		break;
	case 1:
		tmp = new bomb(this);
		break;
	case 2:
		tmp = new arrow(this);
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
	for (auto it=pos->warriors.begin(); it != pos->warriors.end(); ++it) {
		if ((*it) == this) {
			pos->warriors.erase(it);
			break;
		}
	}
	sortWeapon();
	pos = tar;
	pos->warriors.push_back(this);
	printTime();
	cout << Side << ' ' << Type <<  ' ' << ID << " marched to city "
	<< tar->ID << " with " << HP << " elements and force " << Powers[Type] << endl;
}

void Warrior::report() {
	int a=0,b=0,c=0;
	for (auto it = weapon.begin(); it != weapon.end(); ++it) {
		if ((*it)->getType() == "sword") {
			++a;
		} else if ((*it)->getType() == "bomb") {
			++b;
		} else {
			++c;
		}
	}
	printTime();
	cout << Side << ' ' << Type << ' ' << ID << " has " <<
	a << " sword " << b << " bomb " << c << " arrow and " << HP << " elements" << endl; 
}

void Warrior::lostWeapon(Weapon *tar) {
	for (auto it=weapon.begin(); it != weapon.end(); ++it) {
		if (*it == tar) {
			weapon.erase(it);
			return;
		}
	}
}

void Warrior::captureWeapons(Warrior *tar) {
	set<Weapon*> weaponTrans;
	int totalWeapon = weapon.size();
	for (auto it=tar->weapon.begin(); it != tar->weapon.end(); ++it) {
		if (totalWeapon < 10) {
			if ((*it)->getType() == "arrow") {
				if (((arrow*)(*it))->use > 1) {
					weaponTrans.insert(*it);
					++totalWeapon;
				}
			} else {
				weaponTrans.insert(*it);
				++totalWeapon;
			}
		}
	}
	for (auto it=tar->weapon.begin(); it != tar->weapon.end(); ++it) {
		if (totalWeapon < 10) {
			++totalWeapon;
			weaponTrans.insert(*it);
		}
	}
	for (auto it=weaponTrans.begin(); it !=weaponTrans.end(); ++it) {
		tar->lostWeapon(*it);
		(*it)->holder = this;
		weapon.push_back(*it);
	}
}

class dragon:public Warrior{
private:
	static int number;
	float morale;
public:
	dragon(int idget, int hm, string side, City *ipos):Warrior("dragon", idget, 1, side, ipos){
		morale = float(hm) / float(InitialHPs["dragon"]);
		Warrior::newWeapon(idget%3);
		number++;
	}
	~dragon(){
		number--;
	}
	void yelled(){
		printTime();
		cout << Warrior::getSide() << " dragon " << Warrior::getID() << " yelled in city "
		<< (getpos())->ID << endl;
	}
};

class ninja:public Warrior{
private:
        static int number;
    public:
        ninja(int idget, string side, City *ipos):Warrior("ninja", idget, 2, side, ipos){
			Warrior::newWeapon(idget%3);
			Warrior::newWeapon((idget+1)%3);
			number++;
		}
        ~ninja(){number--;}
	/*
	void showINFO(){
		cout << "It has a " << weapon[0]->getType() << " and a "
		<< weapon[1]->getType() << endl;
	}
	*/
};

class iceman:public Warrior{
    private:
        static int number;
    public:
        iceman(int idget, string side, City *ipos):Warrior("iceman", idget, 1, side, ipos){
			Warrior::newWeapon(idget%3);
			number++;
		}
        ~iceman(){number--;}
		/*
		void showINFO(){
			cout << "It has a " << weapon[0]->getType() << endl;
		}
		*/
		void marchTo(City *tar){
			hurt(getHP()*0.1);
			Warrior::marchTo(tar);
		}
};

class lion:public Warrior{
    private:
        static int number;
		int loyalty;
    public:
        lion(int idget, int hm, string side, City *ipos):Warrior("lion", idget, 0, side, ipos){
			Warrior::newWeapon(idget%3);
			loyalty = hm; 
			number++;
		}
        ~lion(){number--;}
		void showINFO(){
			cout << "Its loyalty is " << loyalty << endl;
		}
		void marchTo(City *tar) {
			Warrior::marchTo(tar);
			loyalty -= K;
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
        wolf(int idget, string side, City *ipos):Warrior("wolf", idget, 0, side, ipos){number++;}
        ~wolf(){number--;}
		void Rob(Warrior *tar) {
			if (tar->getType() ==  "wolf" || tar->weapon.empty() || weapon.size() >= 10) return;
			int totalWeapons = weapon.size(), CNT=0;
			string robType = tar->weapon[0]->getType();
			set<Weapon*> Trans;
			for (auto it=tar->weapon.begin(); it!=tar->weapon.end(); ++it) {
				if ((*it)->getType() == robType && totalWeapons < 10) {
					if ((*it)->getType() == "arrow") {
						if ((*it)->use < 1) {
							Trans.insert(*it);
							++totalWeapons;
							++CNT;
						}
					} else {
						++totalWeapons;
						Trans.insert(*it);
					}
				}
			}
			for (auto it=tar->weapon.begin(); it!=tar->weapon.end(); ++it) {
				if ((*it)->getType() == robType && totalWeapons < 10) {
					Trans.insert(*it);
					++totalWeapons;
					++CNT;
				}
			}
			for (auto it=Trans.begin(); it !=Trans.end(); ++it) {
				weapon.push_back(*it);
				tar->lostWeapon(*it);
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
	for (auto it = warriors.begin(); it != warriors.end(); ++it) {
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
			return new dragon(newID, M, side, this);
			break;
		case 1:
			return new ninja(newID, side, this);
			break;
		case 2:
			return new iceman(newID, side, this);
			break;
		case 3:
			return new lion(newID, M, side, this);
			break;
		case 4:
			return new wolf(newID, side, this);
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
        } else {
			runFlag = false;
			return false;
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
bool cmpwarrior(Warrior *w1, Warrior *w2) {
	if (w1->getType() == "red") return true;
	return false;
}

int Warrior::number = 0;
int dragon::number = 0;
int iceman::number = 0;
int ninja::number = 0;
int lion::number = 0;
int wolf::number = 0;
int City::number = 0;

int headquarter::Mthr;			

headquarter *RedHQ, *BlueHQ;
City *citys;

void printTime() {
	printf("%03d:%02d ", now/60, now%60);
}

void newWarrios(){
	if (RedHQ->isRun()) {
		RedHQ->triMF();
	}
	if (BlueHQ->isRun()) {
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
	for (int j=0; j<N; ++j) {
		for (int i=0; i<(citys+j)->warriors.size(); ++i) {
			if ((citys+j)->warriors[i]->getType() == "lion") {
				lion *p = (lion*)((citys+j)->warriors[i]);
				(p->run())();
			}
		}
	}
	for (int i=0; i<BlueHQ->warriors.size(); ++i) {
		if (BlueHQ->warriors[i]->getType() == "lion") {
			lion *p = (lion*)(BlueHQ->warriors[i]);
			(p->run())();
		}
	}
}

class marchEvent{
	private:
		Warrior *W;
		City *C;
	public:
		int P;
		marchEvent(Warrior *w, City *c, int p):W(w), C(c), P(p){}
		void operator()()const {
			W->marchTo(C);
		}
};

struct cmpMarchEvent{
	bool operator()(const marchEvent &m1, const marchEvent &m2)const {
		return m1.P > m2.P;
	}
};

bool warriorsMarch() {
	bool flg = false;
	priority_queue<marchEvent, vector<marchEvent>,cmpMarchEvent> q;
	for (int i=0; i<RedHQ->warriors.size(); ++i) {
		if (RedHQ->warriors[i]->getSide() == "red") {
			q.push(marchEvent(RedHQ->warriors[i], citys, 0));
		}
	}
	for (int i=N-1; i>=0; --i) {
		for (int j=0; j<(citys+i)->warriors.size(); ++j){
			if ((citys+i)->warriors[j]->getSide() == "red") {
				if (i == (N-1)) {
					q.push(marchEvent((citys+i)->warriors[j], BlueHQ, (N+1)*10));
					printTime();
					cout << "blue headquarter was taken" << endl;
					flg = true;
				} else {
					q.push(marchEvent((citys+i)->warriors[j], citys+i+1, (i+2)*10));
				}
			} else {
				if (i == 0) {
					q.push(marchEvent((citys+i)->warriors[j], RedHQ, 1));
					printTime();
					cout << "red headquarter was taken" << endl;
					flg = true;
				} else {
					q.push(marchEvent((citys+i)->warriors[j], citys+i-1, i*10+1));
				}
			}
		}
	}
	for (int i=0; i<BlueHQ->warriors.size(); ++i) {
		if (BlueHQ->warriors[i]->getSide() == "blue") {
			q.push(marchEvent(BlueHQ->warriors[i], citys+N-1, N*10+1));
		}
	}
	while (q.size()) {
		(q.top())();
		q.pop();
	}
	return flg;
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
	if (wr->getpos()->ID % 2 || wr->getpos()->ID == 1) {
		for (int i=0; i<20; ++i) {
			wr->useWeapon(wb);
			if (wr->getHP() <=0 || wb->getHP() <=0) break;
			wb->useWeapon(wr);
			if (wr->getHP() <=0 || wb->getHP() <=0) break;
		}
	} else {
		for (int i=0; i<20; ++i) {
			wb->useWeapon(wr);
			if (wr->getHP() <=0 || wb->getHP() <=0) break;
			wr->useWeapon(wb);
			if (wr->getHP() <=0 || wb->getHP() <=0) break;
		}
	}
	printTime();
	if (wr->getHP() <=0 && wb->getHP() <=0) {
		cout << "both red " << wr->getType() << ' ' << wr->getID() << " and blue "
		<< wb->getType() << ' ' << wb->getID() << " died in city " << wb->getpos()->ID << endl;
	} else if (wr->getHP() >0 && wb->getHP() >0) {
		cout << "both red " << wr->getType() << ' ' << wr->getID() << " and blue "
		<< wb->getType() << ' ' << wb->getID() << " were alive in city " << wb->getpos()->ID << endl;
	} else if (wr->getHP() >0) {
		cout << "red " << wr->getType() << ' ' << wr->getID() << " killed blue " << wb->getType()
		<< ' ' << wb->getID() << " in city " << wr->getpos()->ID << " remaining " << wr->getHP()
		<< " elements" << endl;
		wr->captureWeapons(wb);
	} else {
		cout << "blue " << wb->getType() << ' ' << wb->getID() << " killed red " << wr->getType()
		<< ' ' << wr->getID() << " in city " << wb->getpos()->ID << " remaining " << wb->getHP()
		<< " elements" << endl;
		wb->captureWeapons(wr);
	}
	if (wr->getType() == "dragon" && wr->getHP() > 0) {
		((dragon*)wr)->yelled();
	}
	if (wb->getType() == "dragon" && wb->getHP() > 0) {
		((dragon*)wb)->yelled();
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
	//freopen("datapub.in", "r", stdin);
	freopen("case_1_in.txt", "r", stdin);
	freopen("case_1_out.txt", "w", stdout);
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
				newWarrios();
				now += 5;
				break;
			case 5:
				lionRun();
				now += 5;
				break;
			case 10:
				warriorsMarch();
				now += 25;
				break;
			case 35:
				wolfRob();
				now += 5;
				break;
			case 40:
				warriorsFight();
				now += 10;
				break;
			case 50:
				HQreport();
				now += 5;
				break;
			case 55:
				warriorReport();
				now += 5;
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
