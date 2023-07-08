class MedianFinder {
public:
    priority_queue<int>s;//first containner to store smaller half elements
    priority_queue<int,vector<int>,greater<int>>g;//this is our second congtainer to store greater half elements
    int size;
    MedianFinder() {
        size=0;
    }
    
    void addNum(int num) {
        //we maintain extra element in our first container
        if(size==0)
        {
            s.push(num);
            size++;
        }
        else if(s.size()>g.size())
        {
            //we need to add element to the second container
            if(num<s.top())
            {
                g.push(s.top());
                s.pop();
                s.push(num);
            }
            else
            {
                g.push(num);
            }
        }
        else
        {
      
           if(num>g.top())
           {
                s.push(g.top());
                g.pop();
                g.push(num);
           }
           else
           {
               s.push(num);
           }
        }
    }
    
    double findMedian() {
        if(s.size()>g.size())
        {
            return s.top();
        }
        else
        {
            return (s.top()+g.top())/2.0;

        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
