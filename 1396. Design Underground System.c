
typedef struct {
    int id;
    int startTime;
    int endTime;
    char startStation[11];
    char endStation[11];
}info;


typedef struct {
    info data[20001];
    int customers;
    
} UndergroundSystem;


UndergroundSystem* undergroundSystemCreate() {
    UndergroundSystem *obj = malloc(sizeof(UndergroundSystem));
    memset(obj, 0, sizeof(info)*20001);
    obj->customers = 0;
    return obj;
}

void undergroundSystemCheckIn(UndergroundSystem* obj, int id, char * stationName, int t) {
    obj->data[obj->customers].id= id;
    obj->data[obj->customers].startTime = t;
    strcpy(obj->data[obj->customers].startStation, stationName);
    obj->data[obj->customers].endTime = 0;
    obj->customers++;
}

void undergroundSystemCheckOut(UndergroundSystem* obj, int id, char * stationName, int t) {
    for (int i=0;i<obj->customers;i++){
        if (obj->data[i].id == id && obj->data[i].endTime == 0){
            obj->data[i].endTime = t;
            strcpy(obj->data[i].endStation, stationName);
            break;
        }
    }
}

double undergroundSystemGetAverageTime(UndergroundSystem* obj, char * startStation, char * endStation) {
    int sum = 0, cnt = 0;
    for (int i=0;i<obj->customers;i++){
        if (!strcmp(obj->data[i].startStation, startStation) && !strcmp(obj->data[i].endStation, endStation)){
            sum += (obj->data[i].endTime - obj->data[i].startTime);
            cnt++;
        }
    }
    return (double)sum/cnt;
}

void undergroundSystemFree(UndergroundSystem* obj) {
    free(obj);
}

/**
 * Your UndergroundSystem struct will be instantiated and called as such:
 * UndergroundSystem* obj = undergroundSystemCreate();
 * undergroundSystemCheckIn(obj, id, stationName, t);
 
 * undergroundSystemCheckOut(obj, id, stationName, t);
 
 * double param_3 = undergroundSystemGetAverageTime(obj, startStation, endStation);
 
 * undergroundSystemFree(obj);
*/
