#include <iostream>

using namespace std;

int main()
{
	cout<<"N: ";
	int n;
	cin>>n;

	int matrix[n][n];
	for(int y = 0; y < n; y++)
		for(int x = 0; x < n; x++)
			cin>>matrix[x][y];
	
	cout<<"a) suma ponizej przekatnej\n"
			<<"b) suma powyzej przekatnej\n"
			<<"c) suma kolumny\n"
			<<"d) suma wiersza\n"
			<<"e) exit\n";
	
	char odp;
	do
	{
		cin>>odp;
		int sum = 0;
		if(odp == 'a')
			for(int y = 0; y < n; y++)
				for(int x = 0; x < y; x++)
					sum += matrix[x][y];
		else if(odp == 'b')
			for(int y = 0; y < n; y++)
				for(int x = y+1; x < n; x++)
					sum += matrix[x][y];
		else if(odp == 'c')
		{
			cout<<"kolumna: ";
			int col;
			cin>>col;
			for(int a = 0; a < n; a++)
				sum += matrix[col][a];
		}
		else if(odp == 'd')
		{
			cout<<"wiersz: ";
			int row;
			cin>>row;
			for(int a = 0; a < n; a++)
				sum += matrix[a][row];
		}
		
		if(odp != 'e')
		{
			for(int y = 0; y < n; y++, cout<<endl)
				for(int x = 0; x < n; x++)
					cout<<matrix[x][y]<<" ";
			
			cout<<"Suma: "<<sum<<endl;
		}
	}while(odp != 'e');
}
