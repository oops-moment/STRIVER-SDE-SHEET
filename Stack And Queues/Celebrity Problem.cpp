#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	 stack<int>stck;
	 for(int i=0;i<n;i++)
	 {
		 stck.push(i);
	 }
	 while(stck.size()>1)
	 {
		 int A=stck.top();
		 stck.pop();
		 int B=stck.top();
		 stck.pop();
		 if(knows(A,B))
		 {
			 stck.push(B);
		 }
		 else
		 {
			 stck.push(A);
		 }
	 }
	 int C=stck.top();
	 stck.pop();
	 for(int i=0;i<n;i++)
	 {
		 if(i!=C)
		 {
			 if(knows(i,C)==0)
			 {
				 return -1;
			 }
			 if(knows(C,i))
			 {
				 return -1;
			 }
		 }
	 }
	 return C;
}
