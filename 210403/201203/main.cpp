#include <bits/stdc++.h>

using namespace std;

typedef struct F_NODE{
    int type;
    string name;
    F_NODE *father;
    vector<F_NODE*> sons;
    int size;
    int D;
    int R;
    int LD;
    int LR;
    F_NODE(string Name="/",
           int Type=0) {
        name = Name;
        type = Type;
    }
} File;

File ROOT;
File *root = &ROOT;




vector<string> path2vec(string path) {
    vector<string> res;
    int l=1;
    bool flg = false;
    for (int i=1; i<path.size(); ++i) {
        if (flg) {
            l = i;
            flg = false;
        }
        if (path[i] == '/') {
            res.push_back(path.substr(l, i-l));
            flg = true;
        }
    }
    if (!flg) {
        res.push_back(path.substr(l, path.size()-l));
    }
    return res;
}

F_NODE *find_by_name(string name, F_NODE *dir) {
    for (int i=0; i<dir->sons.size(); ++i) {
        if (dir->sons[i]->name == name) return dir->sons[i];
    }
    return NULL;
}

bool mkfile(F_NODE *dir, string name, int size=0) {
    F_NODE *f_res = find_by_name(name, dir);
    if (f_res) {
        if (f_res.type == 2) f_res.size = size;
        else if (f_res.type == 1) return false;
    } else {


    }
}

bool mkdir(F_NODE *dir, string name) {
    F_NODE *f_res = find_by_name(name, dir);
    if (f_res) return false;
    else {
        f_res = new F_NODE(name, 1);
        f_res.father = dir;
        return true;
    }
}

bool careat_file(string path, int f_size=0) {
    vector<string> paths = path2vec(path);
    bool flg = true;
    F_NODE *tmp = root;
    for (int i=0; i<paths.size()-1; ++i) {
        if (F_NODE *f_res = find_by_name(paths[i], tmp)) {
            if (f_res->type == 0 || f_res->type == 1) {
                tmp = f_res;
                continue;
            } else {
                flg = false;
                break;
            }
        } else if (mkdir(tmp, paths[i])){
            tmp = f_res;
            continue;
        } else {
            flg = false;
            break;
        }
    }
    if (flg) {
        if (f_size) mkfile(tmp, path[path.size()-1]);
        else {
            mkdir(tmp, path[path.size()-1]);
        }
    }

}



int main()
{
    freopen("test.txt", "r", stdin);
    string test_path;
    cin >> test_path;
    vector<string> test = path2vec(test_path);
    cout << "Hello world!" << endl;
    return 0;
}
