
int cmpfunc(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}


int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    
    int diff[costsSize];
    int sum = 0, ans = 0;
    for (int i=0;i<costsSize;i++){
        //First, count all the costs to the same city(that said a-city). 
        ans += costs[i][0];
        //Second, counting the difference between two cities from the b-city side.
        diff[i] = costs[i][1] - costs[i][0];

    }
    // for (int i=0;i<costsSize;i++){
    //     diff[i] = costs[i][0] - costs[i][1];
    //     ans += costs[i][1];
    // }
    qsort(diff, costsSize, sizeof(int), cmpfunc);
    for (int i=0;i<costsSize/2;i++){
        ans += diff[i];
    }
    return ans;
}
