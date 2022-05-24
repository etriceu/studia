#include <iostream>
#include <vector>

using namespace std;

template <class T>
class M
{
	template <typename F>
	void loop2d(M a, M &b, size_t width, size_t height, F func)
	{
		for(size_t y = 0; y < height; y++)
			for(size_t x = 0; x < width; x++)
				func(a, b, x, y);
	}
public:
	M operator+ (M a)
	{
		loop2d(*this, a, a.m.size(), a.m[0].size(), [](M a, M &b, int x, int y){b.m[x][y] = a.m[x][y] + b.m[x][y];});
		return a;
	}

	M operator- (M a)
	{
		loop2d(*this, a, a.m.size(), a.m[0].size(), [](M a, M &b, int x, int y){b.m[x][y] = a.m[x][y] - b.m[x][y];});
		return a;
	}

	M operator* (M a)
	{
		loop2d(*this, a, a.m.size(), a.m[0].size(), [](M a, M &b, int x, int y){b.m[x][y] = a.m[x][y] * b.m[x][y];});
		return a;
	}

	M operator/ (M a)
	{
		loop2d(*this, a, a.m.size(), a.m[0].size(), [](M a, M &b, int x, int y){b.m[x][y] = a.m[x][y] / b.m[x][y];});
		return a;
	}

	friend ostream& operator<<(ostream& out, const M& m)
	{
		for(size_t y = 0; y < m.m[0].size(); y++)
		{
			for(size_t x = 0; x < m.m.size(); x++)
				out<<m.m[x][y]<<" ";
			
			out<<endl;
		}
		return out;
	}
	
	vector<vector<T>> m;
};

class Point3d
{
public:
	int x, y, z;
	
	Point3d operator+ (Point3d a)
	{
		return {x+a.x, y+a.y, z+a.z};
	}
	
	Point3d operator- (Point3d a)
	{
		return {-a.x, -a.y, -a.z};
	}
	
	Point3d operator* (Point3d a)
	{
		return {x*a.x, y*a.y, z*a.z};
	}
	
	Point3d operator/ (Point3d a)
	{
		return {x/a.x, y/a.y, z/a.z};
	}
	
	friend ostream& operator<<(ostream& out, const Point3d& p)
	{
		out<<p.x<<","<<p.y<<","<<p.z;
		return out;
	}
};

int main()
{
	srand(time(NULL));
	M <int> m[2];
	M <Point3d> p[2];
	
	const int w = 3, h = 3;
	for(int n = 0; n < 2; n++)
	{
		m[n].m.resize(w);
		p[n].m.resize(w);
		for(int x = 0; x < w; x++)
			for(int y = 0; y < h; y++)
			{
				m[n].m[x].push_back(rand()%5+1);
				p[n].m[x].push_back({rand()%5+1, rand()%5+1, rand()%5+1});
			}
	}
	
	cout<<m[0]<<endl<<m[1]<<endl;
	cout<<"m1 + m2:\n"<<m[0]+m[1]<<endl;
	cout<<"m1 - m2:\n"<<m[0]-m[1]<<endl;
	cout<<"m1 * m2:\n"<<m[0]*m[1]<<endl;
	cout<<"m1 / m2:\n"<<m[0]/m[1]<<endl;
	
	cout<<p[0]<<endl<<p[1]<<endl;
	cout<<"p1 + p2:\n"<<p[0]+p[1]<<endl;
	cout<<"p1 - p2:\n"<<p[0]-p[1]<<endl;
	cout<<"p1 * p2:\n"<<p[0]*p[1]<<endl;
	cout<<"p1 / p2:\n"<<p[0]/p[1]<<endl;
}
