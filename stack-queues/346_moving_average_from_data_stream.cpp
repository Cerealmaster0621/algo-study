/*
leetcode 346 easy
class implementation, queue
when there is a parameter in class initializer,
follow this implementation
Example 1
Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]
*/

class MovingAverage {
public:
    int size; //MovingAverage member var
    double sum = 0;
    queue<int> q;
    MovingAverage(int size) {
        this->size = size;//initialize with pointer bc it called as pointer in Main func
    }
    
    double next(int val) {
        q.push(val);
        sum+=val;
        if(!q.empty()&&q.size()>size){
            sum-=q.front();
            q.pop();
        }
        return sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */