class Robot {
public:
    int w,h;
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}}; // EAST, NORTH, WEST, SOUTH
    int x=0,y=0;
    int i=0;
    Robot(int width, int height) {
        this->w=width;
        this->h=height;
    }
    
    void step(int num) {
        int cycle=2*(w+h-2);
        num=num%cycle;
        if(num==0 && cycle>0)
            num=cycle;
        for(int k=0;k<num;k++){
            while(x+dir[i][0]<0 || x+dir[i][0]>=w || y+dir[i][1]<0 || y+dir[i][1]>=h){
                i=(i+1)%4;
            }
            x=x+dir[i][0];
            y=y+dir[i][1];
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(i==0){return "East";}
        else if(i==1)   return "North";
        else if(i==2)   return "West";
        else    return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */