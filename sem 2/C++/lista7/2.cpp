#include <vector>
#include <map>
#include <algorithm>
#include <ctime>

class MyVector
{
public:
    static std::vector <int> tab;
	static int min()
	{
		return *std::min_element(tab.begin(), tab.end());
	}

	static int max()
	{
		return *std::max_element(tab.begin(), tab.end());
	}

	static double avg()
	{
		int sum = 0;
		for(int n : tab)
			sum += n;

		return sum/(tab.size()+0.);
	}

	static double median()
	{
		size_t s = tab.size();
		return s%2 ? tab.at(s/2) : (tab.at(s/2-1)+tab.at(s/2))/2.;
	}

	static std::vector <int> mode()
	{
		std::map <int, size_t> count;
		std::vector <int> ret;

		for(int n : tab)
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

std::vector <int> MyVector::tab;

#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));

	for(int n = 0; n < 20; n++)
	{
		MyVector::tab.push_back(rand()%10);
		cout<<MyVector::tab.back()<<" ";
	}

	cout<<endl<<"min: "<<MyVector::min()<<endl;
	cout<<"max: "<<MyVector::max()<<endl;
	cout<<"srednia: "<<MyVector::avg()<<endl;
	cout<<"mediana: "<<MyVector::median()<<endl;
    cout<<"dominujace: ";
	vector <int> tmp = MyVector::mode();
	for(int n : tmp)
		cout<<n<<" ";

    cout<<endl;
	return 0;
}
