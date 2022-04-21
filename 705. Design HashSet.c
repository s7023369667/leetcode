typedef struct {
    int *arr;
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* obj=malloc(sizeof(MyHashSet));
    obj->arr=malloc(sizeof(int)*(1e6+1));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->arr[key]=1;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->arr[key]=0;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    if(obj->arr[key]==1){
        return true;
    }else{
        return false;
    }
}

void myHashSetFree(MyHashSet* obj) {
	free(obj->arr);
    free(obj);
} 
