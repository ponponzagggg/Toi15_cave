/*C++ tasks: toi15_cave
  # tasks from Thailand Olympiad in Informatics 15th (TOI15th)
  # coded by Thanapon Maiseaumsook
  # for entering Junior Digital Ambassadors(JDA)
*/
//declare the library
#include<bits/stdc++.h>
using namespace std;
// declare the variable
long long n,m,st,ed,u_i,v_i,w_i,u,v,y,cost,q,h;
priority_queue<tuple<long long,long long,long long> > pq;
long long w,d[1005][1005],mn,arr[1005],kmp;
vector<pair<long long,long long> > g[1005];
vector<pair<long long,long long> > p;
int main()
{
	// input the data
	scanf("%lld%lld%lld%lld",&n,&st,&ed,&m);
	// construct the graph
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u_i,&v_i,&w_i);
		g[u_i].push_back(make_pair(v_i,w_i));
	}
	//set value of the shortest path variable maximum
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			d[i][j]=1e18;
		}
	}
	//start to do dijkstra shortest path algorithm
	pq.push(make_tuple(0,0,st));
	d[st][0]=0;
	//do dijsktra shortest path algorithm
	while(!pq.empty())
	{
		w=-get<0>(pq.top());
		v=-get<1>(pq.top());
		u=get<2>(pq.top());
		pq.pop();
		if(w!=d[u][v])
		{
			continue;
		}
		for(int i=0;i<g[u].size();i++)
		{
			y=g[u][i].first;
			cost=g[u][i].second;
			if(v+1<=1001)
			{
				if(d[u][v]+cost<d[y][v+1])
				{
					d[y][v+1]=d[u][v]+(long long)cost;
					pq.push(make_tuple(-d[y][v+1],-v-1,y));
				}	
			}
		}
	}
	kmp=d[ed][1];
	p.push_back(make_pair(kmp,1));
	for(int i=2;i<=1000;i++)
	{
		if(d[ed][i]<kmp)
		{
			kmp=d[ed][i];
			p.push_back(make_pair(kmp,i));
		}
	}
	// input the queries and output the answer
	scanf("%lld",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld",&h);
		mn=1e15;
		for(int j=0;j<p.size();j++)
		{
			if(p[j].first+h*(p[j].second-1)<mn)
			{
				mn=p[j].first+h*(p[j].second-1);
			}
		}
		printf("%lld ",mn);
	}
}
