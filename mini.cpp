#include<iostream>
using namespace std;
int main()
{
	int edge[8][10]={{1,1,1,1,1,1,1,1,1,1},{1,0,1,1,1,0,1,1,1,1},{1,1,0,1,0,1,1,1,1,1},{1,0,1,0,0,0,0,0,1,1},{1,0,1,1,1,0,1,1,1,1},{1,1,0,0,1,1,0,0,0,1},{1,0,1,1,0,0,1,1,0,1},{1,1,1,1,1,1,1,1,1,1}};
	string miGong(int edge[][10]);
	cout<<miGong(edge)<<endl;
}
struct Node
{
	int x;
	int y;
	int prex;
	int prey;
	string direction;
};
string miGong(int edge[][10])
{
	int dir[8][2]={{0,-1},{-1,0},{0,1},{1,0},{-1,-1},{-1,1},{1,1},{1,-1}};
	string dir1[8]={"¡û","¡ü","¡ú","¡ý","¨I","¨J","¨K","¨L"}; 
	Node head;
	head.x=1;head.y=1;head.prex=0;head.prey=0;head.direction="";
	Node Queue[50];
	int font=-1,rear=-1;
	Node stack[50];
	int top=-1;
	int visit[8][10]={0};
	string s="";
	Queue[++rear]=head;
	while(font!=rear)
	{
		Node node=Queue[++font];
		stack[++top]=node;
		visit[node.x][node.y]=1;
		for(int i=0;i<8;i++)
		{
			int x=node.x+dir[i][0];
			int y=node.y+dir[i][1];
			if(x==6&&y==8)
			{
				Node work=stack[top--];
				s.append(dir1[i]);
				s.append(node.direction);
				while(top!=-1)
				{
					Node work1=stack[top--];
					if(work.prex==work1.x&&work.prey==work1.y)
					{
						s.append(work1.direction);
						work=work1;
					}
				}
				return s;
			}
			if(edge[x][y]==0&&visit[x][y]==0)
			{
				head.x=x;head.y=y;head.prex=node.x;head.prey=node.y;head.direction=dir1[i];
				Queue[++rear]=head;
			}
		}
	}
}
