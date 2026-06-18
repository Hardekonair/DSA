class Solution {
public:
    double angleClock(int hour, int minutes) {
        int mindegree=6;
        int hourdegree=30;
        float diff=abs(hour*hourdegree-minutes*mindegree);
        if(minutes/5>=hour){
            diff=diff-(0.5*minutes);
        }
        else 
            diff+=(0.5*minutes);
        float ans=min(diff,360-diff);
        ans=ans>0?ans:-ans;
        return ans;

    }

};