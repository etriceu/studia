#include <vector>
#include <map>
#include <algorithm>

template <typename T>
class MyVector : public std::vector <T>
{
public:
	T min()
	{
		return *std::min_element(this->begin(), this->end());
	}
	
	T max()
	{
		return *std::max_element(this->begin(), this->end());
	}
	
	double avg()
	{
		T sum = 0;
		for(T n : *this)
			sum += n;
		
		return sum/(this->size()+0.);
	}
	
	double median()
	{
		size_t s = this->size();
		return s%2 ? this->at(s/2) : (this->at(s/2-1)+this->at(s/2))/2.;
	}
	
	std::vector <T> mode()
	{
		std::map <T, size_t> count;
		std::vector <T> ret;
		
		for(T n : *this)
		{
			auto it = count.find(n);
			if(it == count.end()) count[n] = 1;
			else it->second++;
		}
		
		size_t max = count.begin()->second;
		for(auto n : count)
			if(max < n.second)
			{
				max = n.second;
				ret.clear();
				ret.push_back(n.first);
			}
			else if(max == n.second)
				ret.push_back(n.first);
		
		return ret;
	}
};

#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));
	MyVector <int> test;
	
	for(int n = 0; n < 20; n++)
	{
		test.push_back(rand()%10);
		cout<<test.back()<<" ";
	}
	
	cout<<endl<<test.min()<<endl;
	cout<<test.max()<<endl;
	cout<<test.avg()<<endl;
	cout<<test.median()<<endl<<endl;
	
	vector <int> tmp = test.mode();
	for(int n : tmp)
		cout<<n<<endl;
	
	return 0;
}
