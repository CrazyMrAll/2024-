int count1 = 0; // 北到南的车辆数
int count2 = 0; // 南到北车辆数
信号量 bridge = 1;
信号量 bridgecount = 5;
信号量 mutex1 = 1;
信号量 mutex2 = 1;

北到南(){
    P(mutex1);
    count1++;
    if (count1 == 1){
        P(bridge);
    }
    V(mutex1);
    
    P(bridgecount);
    北到南过桥;
    V(bridgecount);
    
    P(mutex1);
    count1--;
    if (count1 == 0){
        V(bridge);
    }
    V(mutex1);   
}

南到北(){
    P(mutex2);
    count2++;
    if (count2 == 1){
        P(bridge);
    }
    V(mutex2);
    
    P(bridgecount);
    南到北过桥;
    V(bridgecount);
    
    P(mutex2);
    count2--;
    if (count2 == 0){
        V(bridge);
    }
    V(mutex2);   
}
