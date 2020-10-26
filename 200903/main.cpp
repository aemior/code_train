#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <set>


class gate{
public:
    gate(std::string FUNC, int number,std::vector<std::string> input);
    void set_out(int out_get);
private:
    int num;
    std::string func;
    std::vector<string> all_input;
    std::vector<int> all_output;
    bool is_buff;
    bool buff;
};

gate::gate(std::string FUNC, int number; std::vector<std::string> input){
    func = FUNC;
    all_input = input;
    is_buff = false;
    num = number;
}

gate::set_out(int out_get){
    all_output.push_back(out_get);
}

class Net{
public:
    Net(std::vector<gate> gates);
    void Set(std::vector<bool> inputs);
    bool get_out(int I);
    bool check_loop();
    bool Net::check_back(std::set<int> &chain, int check_num);
private:
    bool set_input;
    std::vector<bool> all_input;
    std::vector<gate> all_gates;
};

Net::Net(std::vector<gate> gates){
    set_input = false;
    all_gates = gates;
}
void Net::Set(std::vector<bool> inputs){
    all_input = inputs;
}
bool Net::check_loop(){
    for(int i=0; i<all_gates.size(); i++){
        for(int j=0; j<all_gates[i].all_input.size(); j++){
            if(all_gates[i].all_input[j][0] == 'O'){
                all_gates[std::stoi(all_gates[i].all_output[j].substr(1))].set_out(i);
            }
        }
    }
    for(int i=0; i<all_gates.size(); i++){
        std::set<int> all_chains;
        if(check_back(all_chains, i))
            return true;
    }
    return false;
}
bool Net::check_back(std::set<int> &chain, int check_num){
    if(chain.count(check_num))
        return true;
    else
        chain.insert(check_num);
    for(int i=0; i<all_gates[check_num].all_output.size(); i++){
        if(chain.count(all_gates[check_num].all_output[i]) == 1)
            return true;
        else if(check_back(chain, i))
            return true;
    }
    return false;
}

bool Net::get_out(int I){
    std::vector<bool> tmp_input;
    for(int i=0; i< all_gates[I].all_input.size(); i++){
            if(all_gates[I].all_input[i][0] == 'I'){
                tmp_input.push_back(all_input[])
            }

    }

}



int main()
{
    freopen("test.txt", "r", stdin);
    std::cin >> Q;
    for(int i=0; i<Q; i++){
        int M,N;
        std::cin >> M >> N;
        for(int j=0; j<N; j++){

        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
