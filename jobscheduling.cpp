#include<iostream>
using namespace std;
class CircularQueue{

	public:
		int *arr, size, front, rear;
		CircularQueue(int s)
		{
			size = s;
			front = rear = -1;
			arr = new int[s];
			//t = 0;
		}
		bool isEmpty()
		{
			return (front==-1 && rear==-1);
		}

		bool isFull()
		{
			return ((rear==size-1 && front==0)||(rear==front-1));
		}
		int get_front()
		{
			if(isEmpty())
			{
				//cout<<"Empty front\n";
				return -1;
			}
			return arr[front];
		}
		void addTask(int serviceTime)	
		{
			if(isFull())	
			{
				cout<<"queue full\n";
				return;
			}
			else if(isEmpty())
			{
				front = rear = 0;
				arr[rear] = serviceTime;
				return;
			}
			else if(rear==size-1 && front!=0)
			{
				rear = 0;
				arr[rear] = serviceTime;
				return;
			}
			rear++;
			arr[rear] = serviceTime;
		}
		void removeTask()	
		{
			if(isEmpty())
            {
				cout<<"no tasks\n";
				return;
			}
			else if(front==rear)
			{
				front = rear = -1;
				return;
			}
			else if(front==size-1)
            {
                front = 0;
                return;
            }
			front++;
		}
};

int main(){
	int s, n, calls_served = 0, t = 120;
	cout<<"Enter size of queue: ";
	cin>>s;
	CircularQueue job(s);
	cout<<"Enter number of calls: ";
	cin>>n;
	int arrival[n], service[n];

	cout<<"Enter Arrival and Service time:\n";
	cin>>arrival[0]>>service[0];
	job.addTask(service[0]);
	int k = 1, r = -1, temp;
	int sum = service[0];
	int idleT = arrival[0]-1;
	sum+=idleT;
	t-=idleT;
	//cout<<"waiting time of call 1 is 0\n";
	while((t - job.get_front())>=0)
    {
        //cout<<"enter while1\n";
		while(!job.isFull() && k!=n){
            //cout<<"enter while2\n";
			cout<<"Enter Arrival and Service time:\n";
			cin>>arrival[k]>>service[k];
			if((sum+1)<arrival[k])
            {
                idleT+=(arrival[k]-sum)-1;
                sum+=idleT;
                t-=idleT;
                //cout<<"value of t inside at end"<<t<<endl;

            }
            sum+=service[k];
			job.addTask(service[k]);
			k++;
		}
		if(job.isFull())
		{
		    cout<<"Waiting for space....\n";
        }

		temp = job.get_front();
		//cout<<"trm is "<<temp<<endl;

		job.removeTask();
		r++;
		calls_served++;
        //cout<<calls_served<<endl;
        if(t+arrival[r]<121)
        {
            cout<<"Waiting time for call "<<r+1<<" is "<<121 - (t + arrival[r])<<endl;

        }
        else
        {
            cout<<"Waiting time for call "<<r+1<<" is "<<0<<endl;

        }

		t = t-temp;
		//cout<<"value of t at end"<<t<<endl;

		if(calls_served == n)
        {
            break;
        }

	}
	cout<<"...................\n";
	cout<<"number of calls served: "<<calls_served<<endl;
	cout<<"Idle time is: "<<idleT+t<<endl;
	return 0;
}


