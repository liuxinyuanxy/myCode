#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct node{
	int id, reachtime, time, level;
	friend bool operator > (const node& x, const node& y)
	{
		return x.level == y.level ? x.reachtime > y.reachtime : x.level > y.level;
	}
}run, pro, temp;
priority_queue<node, vector<node>, greater<node> > wait;
int runtime;
int main()
{
	while (scanf ("%d%d%d%d", &pro.id, &pro.reachtime, &pro.time, &pro.level) != EOF)
	{
		while (runtime < pro.reachtime)
		{
			if (!run.id)
			{
				runtime = pro.reachtime;
				break;
			}
			if (pro.reachtime - runtime >= run.time)
			{
				runtime += run.time;
				printf("%d %d\n", run.id, runtime);
				if (wait.empty())
				{
					runtime = pro.reachtime;
					run.id = 0;
					break;
				}
				run = wait.top();
				wait.pop();
			}
			else
			{
				run.time -= pro.reachtime - runtime;
				runtime = pro.reachtime;
			}
		}
		if (run.id != 0 && pro > run)
			wait.push(pro);
		else
		{
			if (run.id)
				wait.push(run);
			run = pro;
		}
	}
	return 0;
}

