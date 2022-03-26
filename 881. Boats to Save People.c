int cmpfunc(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int numRescueBoats(int* people, int peopleSize, int limit){
    //Two Sum problem
    int boats = 0;
    int L = 0, R = peopleSize -1 ;
    qsort(people, peopleSize, sizeof(int), cmpfunc);
    
    while (L<=R){
        if (people[R] >= limit){
            R--;
            boats++;
        }else{
            if (people[L]+people[R]<=limit){
                L++;
                R--;
                boats++;
            }else {
                R--;
                boats++;
            }
        }
    }
    return boats;
}
