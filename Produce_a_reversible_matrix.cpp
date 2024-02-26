#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
void printMatrix(vector< vector<int> > matrix){
	for(int i=0;i<matrix.size();i++){
		cout<<"|";
		for(int j=0;j<matrix.size();j++){
			printf("%4d",matrix[i][j]);
		}
		cout<<"|\n";
	}
}
void swapMatrix(vector< vector<int> > &matrix){
	int n=matrix.size();
	int a=rand()%n,b=rand()%n,arr[n];
	for(int i=0;i<n;i++){
		arr[i]=matrix[a][i];
	}
	for(int i=0;i<n;i++){
		matrix[a][i]=matrix[b][i];
	}
	for(int i=0;i<n;i++){
		matrix[b][i]=arr[i];
	}
	cout<<"row"<<a+1<<" <-> row"<<b+1<<endl;
}
void rowCombination(vector< vector<int> > &matrix){
	int n=matrix.size();
	int a=rand()%n,b=rand()%n,c=5-rand()%11;
	for(int i=0;i<n;i++){
		matrix[a][i]+=matrix[b][i]*c;
	}
	cout<<"row"<<a+1<<":+"<<c<<"row"<<b+1<<endl;
}
void scaleMatrix(vector< vector<int> > &matrix){
	int n=matrix.size();
	int a=rand()%n,b=5-rand()%11;
	for(int i=0;i<n;i++){
		matrix[a][i]*=b;
	}
	cout<<"row"<<a+1<<":x"<<b<<endl;
}
int main()
{
	srand(time(NULL));
	int sizeOfMatrix;
  	cout << "input the size of matrix:" << endl;
  	cin>>sizeOfMatrix;
  	vector<vector<int> > identity(sizeOfMatrix, vector<int>(sizeOfMatrix));
  	for(int i=0;i<sizeOfMatrix;i++){
  		for(int j=0;j<sizeOfMatrix;j++){
  			if(j==i){
  				identity[i][j]=1;
  			}else{
  				identity[i][j]=0;
  			}
  		}
  	}
  	printMatrix(identity);
  	int steps=rand()%10 * sizeOfMatrix;
	for(int i=0;i<steps;i++){
		int process=rand()%3;
		if(process==0){
			swapMatrix(identity);
		}else if(process==1){
			scaleMatrix(identity);
		}else{
			rowCombination(identity);
		}
	}
  	printMatrix(identity);
  	return 0;
}
