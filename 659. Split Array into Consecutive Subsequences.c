struct info {
    int val;
    int cnt;
};

int find_idx(const struct info* table, int numsSize,const int target){
    for (int i=0;i<numsSize;i++){
        if (target == table[i].val){
            return i;
        }
    }
    return numsSize;
}

bool isPossible(int* nums, int numsSize){
    struct info table[numsSize+1];
    memset(table, 0, sizeof(struct info)*(numsSize+1));
    struct info need[numsSize+1];
    memset(need, 0, sizeof(struct info)*(numsSize+1));
    int t = 0;
    int prev = nums[t];
    table[t].val = prev;
    table[t].cnt ++;
    need[t].val = prev;
    for (int i=1;i<numsSize;i++){
        
        if (prev == nums[i]){
            table[t].cnt++;
        }else {
            prev = nums[i];
            t++;
            table[t].val = prev;
            table[t].cnt ++;
            need[t].val = prev;
        }
    }
    
    for (int i=0;i<numsSize;i++){
        
        if (table[find_idx(table, numsSize, nums[i])].cnt == 0){
            continue;
        }
        table[find_idx(table, numsSize, nums[i])].cnt--;
        
        if (need[find_idx(need, numsSize, nums[i]-1)].cnt > 0){
            need[find_idx(need, numsSize, nums[i]-1)].cnt--;
            need[find_idx(need, numsSize, nums[i])].cnt++;
            need[find_idx(need, numsSize, nums[i])].val = nums[i];
        }else if ((table[find_idx(table, numsSize, nums[i]+1)].cnt > 0) && 
                    (table[find_idx(table, numsSize, nums[i]+2)].cnt > 0)){
            table[find_idx(table, numsSize, nums[i]+1)].cnt--;
            table[find_idx(table, numsSize, nums[i]+2)].cnt--;
            need[find_idx(need, numsSize, nums[i]+2)].cnt++;
            need[find_idx(need, numsSize, nums[i]+2)].val = nums[i]+2;
        }else{
            return false;
        }
    }
    return true;
}
