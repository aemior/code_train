#include <iostream>
//#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <set>


class gate{
public:
    gate(std::string FUNC, int number,std::vector<std::string> input);
    void set_out(int out_get);
    void clean();
    std::vector<std::string> all_input;
    std::set<int> all_output;
    std::string func;
    int num;
    bool buff;
    bool is_buff;
};

gate::gate(std::string FUNC, int number, std::vector<std::string> input){
    func = FUNC;
    all_input = input;
    is_buff = false;
    num = number;
}

void gate::set_out(int out_get){
    all_output.insert(out_get);
}

void gate::clean(){
    is_buff = false;
}

bool dfs(std::vector<gate>& all_gates, std::vector<int> &check_flg, std::set<int> &father, int tar){
    for(std::set<int>::iterator j = all_gates[tar].all_output.begin(); j != all_gates[tar].all_output.end(); j++){
        if(!check_flg[*j])
            if(father.count(*j)) return true;
            else{
                int n_tar = *j;
                father.insert(n_tar);
                bool res = dfs(all_gates, check_flg, father, n_tar);
                if(res) return true;
            }
        check_flg[*j] = true;
    }
    father.insert(tar);
    check_flg[tar] = true;
    return false;
}

bool check_loop(std::vector<gate>& all_gates){
    for(int i=0; i<all_gates.size(); i++){
        for(int j=0; j<all_gates[i].all_input.size(); j++){
            if(all_gates[i].all_input[j][0] == 'O'){
                all_gates[atoi(all_gates[i].all_input[j].substr(1).c_str())-1].set_out(i);
            }
        }
    }
    //debug
    /*
    for(int i=0; i<all_gates.size(); i++){
            std::cout << "#DEBUG gates:" << i << ':';
        for(std::set<int>::iterator j = all_gates[i].all_output.begin(); j != all_gates[i].all_output.end(); j++){
            std::cout << ' ' << *j;
        }
        std::cout << std::endl;
    }
    */

    std::vector<int> check_flg(all_gates.size(), false);
    for(int i=0; i<check_flg.size(); i++){
        if(!check_flg[i]){
            std::set<int> father;
            father.insert(i);
            bool res = dfs(all_gates, check_flg, father, i);
            if(res) return true;
            check_flg[i] = true;
        }
    }
    return false;
    std:: cout << "PASS";
}


void clean_all(std::vector<gate> &all_gates){
    for(int i=0; i<all_gates.size(); i++){
        all_gates[i].clean();
    }
}

bool get_output(std::vector<gate>& all_gates, std::vector<bool> &all_inputs, int tar){
    if(!all_gates[tar].is_buff){
        //std::cout << "##DEBUG" << all_gates[tar].func << ' ' << tar << std::endl;
        if(all_gates[tar].func == "NOT"){
            if(all_gates[tar].all_input[0][0] == 'I'){
                all_gates[tar].buff = !all_inputs[atoi(all_gates[tar].all_input[0].substr(1).c_str())-1];

            }
            else all_gates[tar].buff = !get_output(all_gates, all_inputs, atoi(all_gates[tar].all_input[0].substr(1).c_str())-1);
        }
        else if(all_gates[tar].func == "AND"){
            all_gates[tar].buff = true;
            for(int i=0;i<all_gates[tar].all_input.size();i++){
                if(all_gates[tar].all_input[i][0] == 'I'){
                    if(!all_inputs[atoi(all_gates[tar].all_input[i].substr(1).c_str())-1]){
                        all_gates[tar].buff = false;
                        break;
                    }
                }
                else{
                    if(!get_output(all_gates, all_inputs, atoi(all_gates[tar].all_input[i].substr(1).c_str())-1)){
                        all_gates[tar].buff = false;
                        break;
                    }
                }
            }
        }
        else if(all_gates[tar].func == "OR"){
            all_gates[tar].buff = false;
            for(int i=0;i<all_gates[tar].all_input.size();i++){
                if(all_gates[tar].all_input[i][0] == 'I'){
                    if(all_inputs[atoi(all_gates[tar].all_input[i].substr(1).c_str())-1]){
                        all_gates[tar].buff = true;
                        break;
                    }
                }
                else{
                    if(get_output(all_gates, all_inputs, atoi(all_gates[tar].all_input[i].substr(1).c_str())-1)){
                        all_gates[tar].buff = true;
                        break;
                    }
                }
            }
        }
        else if(all_gates[tar].func == "XOR"){
            all_gates[tar].buff = false;
            bool first;
            if(all_gates[tar].all_input[0][0] == 'I'){
                first = !all_inputs[atoi(all_gates[tar].all_input[0].substr(1).c_str())-1];

            }
            else first = !get_output(all_gates, all_inputs, atoi(all_gates[tar].all_input[0].substr(1).c_str())-1);
            for(int i=1;i<all_gates[tar].all_input.size();i++){
                if(all_gates[tar].all_input[i][0] == 'I'){
                    if(all_inputs[atoi(all_gates[tar].all_input[i].substr(1).c_str())-1] == first){
                        all_gates[tar].buff = true;
                        break;
                    }
                }
                else{
                    if(get_output(all_gates, all_inputs, atoi(all_gates[tar].all_input[i].substr(1).c_str())-1) == first){
                        all_gates[tar].buff = true;
                        break;
                    }
                }
            }
        }
        else if(all_gates[tar].func == "NAND"){
            all_gates[tar].buff = true;
            for(int i=0;i<all_gates[tar].all_input.size();i++){
                if(all_gates[tar].all_input[i][0] == 'I'){
                    if(!all_inputs[atoi(all_gates[tar].all_input[i].substr(1).c_str())-1]){
                        all_gates[tar].buff = false;
                        break;
                    }
                }
                else{
                    if(!get_output(all_gates, all_inputs, atoi(all_gates[tar].all_input[i].substr(1).c_str())-1)){
                        all_gates[tar].buff = false;
                        break;
                    }
                }
            }
            all_gates[tar].buff = !all_gates[tar].buff;
        }
        else if(all_gates[tar].func == "NOR"){
            all_gates[tar].buff = false;
            for(int i=0;i<all_gates[tar].all_input.size();i++){
                if(all_gates[tar].all_input[i][0] == 'I'){
                    if(all_inputs[atoi(all_gates[tar].all_input[i].substr(1).c_str())-1]){
                        all_gates[tar].buff = true;
                        break;
                    }
                }
                else{
                    if(get_output(all_gates, all_inputs, atoi(all_gates[tar].all_input[i].substr(1).c_str())-1)){
                        all_gates[tar].buff = true;
                        break;
                    }
                }
            }
            all_gates[tar].buff = !all_gates[tar].buff;
        }
    }
    all_gates[tar].is_buff = true;
    //std::cout << all_gates[tar].buff << "<<\n";
    return all_gates[tar].buff;
}



int main()
{
    //freopen("test2.txt", "r", stdin);
    int Q;
    std::cin >> Q;
    for(int i=0; i<Q; i++){
        int M,N,S;
        std::cin >> M >> N;
        std::vector<gate> all_gates;
        for(int j=0; j<N; j++){
                std::string func, tmp_input;
                int k;
                std::vector<std::string> inputs;
                std::cin >> func >> k;
                for(int m=0; m<k; m++){
                        std::cin >> tmp_input;
                        inputs.push_back(tmp_input);
                }
                gate tmp_gate(func, k, inputs);
                all_gates.push_back(tmp_gate);
        }
        //debug
        /*
        for(int j=0;j<all_gates.size();j++){
            std::cout << all_gates[j].func << std::endl;
            for(int k=0; k<all_gates[j].all_input.size();k++){
                std::cout << ' ' << all_gates[j].all_input[k] << ' ' << atoi(all_gates[j].all_input[k].substr(1).c_str());
            }
            std::cout << std::endl;
        }
        */
        std::vector<std::vector<bool> > s_inputs;
        std::cin >> S;
        bool tmp_single;
        for(int j=0;j<S;j++){
                std::vector<bool> tmp_inputs;
                for(int k=0;k<M;k++){
                    std::cin >> tmp_single;
                    tmp_inputs.push_back(tmp_single);
                }
                s_inputs.push_back(tmp_inputs);
        }
        bool qus_flg = true;
        if(check_loop(all_gates)){
            qus_flg = false;
            std::cout << "LOOP" << std::endl;
            int o_p,pas;
            for(int j=0; j<S; j++){
                std::cin >> o_p;
                for(int k=0; k<o_p; k++) std::cin >> pas;
            }
        }
        else{
            int o_p,curr;
            for(int j=0; j<S; j++){
                clean_all(all_gates);
                std::cin >> o_p;
                for(int k=0; k<o_p; k++){
                    std::cin >> curr;
                    bool debug_res  = get_output(all_gates, s_inputs[j], curr-1);
                    if(debug_res) std::cout << "1 ";
                    else std::cout << "0 ";
                }
                std::cout << std::endl;

            }
        }

    }
    /*
    Net min_net(all_gates);
    if(min_net.check_loop()){
        std::cout << "LOOP" << std::endl;
    }
    else{
        std::cout << "NEXT" << std::endl;
    }
    */
    return 0;
}

