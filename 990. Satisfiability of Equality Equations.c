static int union_find[26];


int find_root(int x){
    while (x != union_find[x]){
        union_find[x] = union_find[union_find[x]];
        x = union_find[x];
    }
    return x;
}

void union_nodes(int node1, int node2){
    int root1 = find_root(node1);
    int root2 = find_root(node2);
    union_find[root1] = root2;
}

bool check(int node1, int node2){
    return find_root(node1) == find_root(node2);
}

bool equationsPossible(char ** equations, int equationsSize){
    
    for (int i=0;i<26;i++){
        union_find[i] = i; //自己的根結點是自己
    }
    for (int i=0;i<equationsSize;i++){
        if (equations[i][1] == '='){
            int idx1 = equations[i][0] - 'a';
            int idx2 = equations[i][3] - 'a';
            union_nodes(idx1, idx2);
        }
    }
    for (int i=0;i<equationsSize;i++){
        if (equations[i][1] == '!'){
            int idx1 = equations[i][0] - 'a';
            int idx2 = equations[i][3] - 'a';
            if (check(idx1, idx2)){
                return false;
            }
        }
    }
    return true;
}
