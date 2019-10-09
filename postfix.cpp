#include<iostream>
using namespace std;

class stack
{
	private:
		int st[100],top;
	public:
		stack()
		{
			top=-1;
		}
		void push(int n)
		{
			top++;
			st[top]=n;
		}
		int pop()
		{
			top--;
			return st[top+1];
		}
};
int main()
{
	char arr[100];
	stack st1;
	int a,b=0;
	cout<<"enter postfix equation:\n";
	cin.getline(arr,100);
	for(int i=0;arr[i]!='\0';i++)
	{	
		switch(arr[i])
		{
			case ' ':
				//st1.push(int(arr[i-1]));
				break;
			case '*':
				a=st1.pop();
				b=st1.pop();
				b=b*a;
				st1.push(b);
				break;
			case '/':
				a=st1.pop();
				b=st1.pop();
				b=b/a;
				st1.push(b);
				break;
			case '+':
				a=st1.pop();
				b=st1.pop();
				b=b+a;
				st1.push(b);
				break;
			case '-':
				a=st1.pop();
				b=st1.pop();
				b=b-a;
				st1.push(b);
				break;
			default:
				st1.push(int(arr[i])-48);
				break;
		}
	}
	cout<<"answer is: "<<b<<endl;
	return 0;
}
			
			
			
			
			
