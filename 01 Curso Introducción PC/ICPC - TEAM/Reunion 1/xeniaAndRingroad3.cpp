#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m;
	cin>>n>>m;
	int actual = 1;
	long long time = 0;

	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		if(x-actual>=0){
			time+=x-actual;
			 actual=x;
		}
		else {
			time+=x-actual+n;
			actual=x;
		}
	}
	cout<<time;   
}