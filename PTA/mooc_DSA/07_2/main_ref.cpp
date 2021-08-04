#include <bits/stdc++.h>

using namespace std;

typedef int vertex; 

#define MaxNodes 101 // 不考虑岸的情况下，图中有101个顶点：岛和100只鳄鱼 （岸是隐藏顶点） 
#define distance 42.5 //岛的边缘到岸上的距离 
#define radius 7.5  //岛半径 
#define Null -1
#define source 0 
 
struct node
{
	int x;
	int y;
}a[MaxNodes];

int FirstDistance[MaxNodes];  // If there are many shortest paths, just output the one with the minimum first jump . 据此，需要将100只鳄鱼 到 岛的距离，按从小到大排序。若第一跳无法到达，输出Null
int dist[MaxNodes];
int path[MaxNodes]; 

int NodesNumber,BondJumpDist; 

bool jump(int New,int Old);
bool isSave(int n);

int BFS(int n); //Breadth First Search

void GetNodesFirstDistance(); //获取各顶点的第一跳距离，并按从小到大排序，Null代表第一跳不可达 
void initialize(); //初始化dist path FirstDistance数组 
bool CompareFirstJump(vertex a,vertex b);
int firstjump(vertex n);
void PrintResult(vertex currentNode);
void BFS();

int main()
{
	freopen("test.txt", "r", stdin);
	int x,y;
	
	cin>>NodesNumber>>BondJumpDist; 
	
	for(int i=1;i<=NodesNumber;i++) //无论是否愿意，所有的输入数据必须先接收 . i=0代表岛，也就是源点 
	{
		cin>>x>>y;	
		a[i].x=x; 
		a[i].y=y;
	}
	
	if(BondJumpDist>=distance) //Bond天纵奇才，从小岛到岸边，一跳结束战斗 
	{
		cout<<'1';
		return 0;
	}
	
	initialize(); //初始化dist path  FirstDistance 三个数组 
	
	GetNodesFirstDistance();//获取各顶点的第一跳距离，使得FirstDistance数组 从小到大排序，Null代表第一跳不可达
	
	BFS();
	
	return 0;
}

void BFS()
{
	vertex Node,currentNode;
	queue<vertex> q;
	q.push(source);
	currentNode=q.front();
	q.pop();
	dist[currentNode]=0;
	path[currentNode]=Null;
	 
	for(int i=1;i<=NodesNumber;i++) //将第一跳可达的顶点，按从近到远的距离压入队列 
	{
		Node=FirstDistance[i];
		if(firstjump(Node)==Null) continue; //第一跳为Null，说明不可达
		else
		{
			q.push(Node);
			dist[Node]=dist[currentNode]+1;
			path[Node]=currentNode;
		}	 
	}
	
	while(!q.empty()) 
	{
		currentNode=q.front();
		q.pop();
		
		if(isSave(currentNode)) 
		{
			PrintResult(currentNode);//满足登岸要求后执行打印
			return ;
		}
		for(int i=1;i<=NodesNumber;i++)//不满足继续循环
		{
			if(jump(i,currentNode) && dist[i]==Null)
			{
				q.push(i);
				dist[i]=dist[currentNode]+1;
				path[i]=currentNode;
			}
		}	
	}
	
	cout<<"0"<<endl;
}

void PrintResult(vertex currentNode)
{
	int top;
	stack<vertex> s;
	cout<<dist[currentNode]+1<<endl; //从鳄鱼到岸还要跳一次，所以+1
	
	while(true)
	{
		s.push(currentNode);
		currentNode=path[currentNode];
		if(currentNode==source) break;
	}
	
	while(!s.empty())
	{
		top=s.top();
		s.pop();
		cout<<a[top].x<<" "<<a[top].y<<endl;
	}
	return;
}

bool jump(int New,int Old)
{
	int dist, james_jump;
	dist=(a[New].x-a[Old].x)*(a[New].x-a[Old].x) + \
	 (a[New].y-a[Old].y)*(a[New].y-a[Old].y);
	james_jump=BondJumpDist*BondJumpDist;
	if(james_jump>=dist) return true;
	else return false;
}

bool isSave(int n)
{
	if(a[n].x+BondJumpDist >= 50 || a[n].x-BondJumpDist <= -50 || \
	a[n].y+BondJumpDist >=50 || a[n].y-BondJumpDist <= -50 ) 
		return true;
	else return false;
}


void initialize()
{
	for(int i=0;i<=NodesNumber;i++)
	{
		dist[i]=Null;
		path[i]=Null;
		FirstDistance[i]=i; // i=1 代表顶点1，也就是录入数据中第一只鳄鱼的坐标 
	}
}

void GetNodesFirstDistance()
{
	sort(FirstDistance+1,FirstDistance+NodesNumber+1,CompareFirstJump); //sort
} 

bool CompareFirstJump(vertex a,vertex b)
{
	return  firstjump(a) < firstjump(b); 
} 

int firstjump(vertex n)
{
	int dist, james_jump;
	dist=(a[n].x*a[n].x) + (a[n].y*a[n].y);
	james_jump=(radius+BondJumpDist)*(radius+BondJumpDist); //第一跳有岛的加成 
	if(james_jump>=dist) 
		return dist;
	else 
		return Null;
}