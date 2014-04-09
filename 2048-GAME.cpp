#include "stdafx.h"

#define random_2_4 (rand()%5==4 ? 4:2)
#define random_x(x) (rand()%x)
using namespace std;

const int MAX = 4;
const int MAXMAX = MAX*MAX;
const int INIT_SIZE = 2;
int _matrix[MAX][MAX];
int current[MAX];
int _count;
string ch;
int score;
string chara;


char arduino(char a);
char t=' ';
void print();
void help();
void start();
void init();
bool random_data_one();

bool b_up();
bool b_left();
bool b_down();
bool b_right();

void _up();
void _left();
void _down();
void _right();
Serial* SP = new Serial("\\\\.\\COM5");    

int main()
{
	
 
    while(1){
             bool fail=true;
             //start();
	         init();
	         print();
	         while (b_up() || b_left() || b_down() || b_right())
                                                                {
		                                                        //help();
																ch[0]=arduino(t);
																if(ch[0]!='1'/*=='w'||ch[0]=='a'||ch[0]=='s'||ch[0]=='d'||ch[0]=='W'||ch[0]=='A'||ch[0]=='S'||ch[0]=='D'*/){
		                                                        switch (ch[0])
		                                                                      {
		                                                                      case 'w':
			                                                                           _up();
	                                                                                   break;
                                                                              case 'W':
			                                                                           _up();
	                                                                                   break;         
		                                                                      case 'a':
		                                                                      	       _left();
			                                                                           break;
                                                                              case 'A':
		                                                                      	       _left();
			                                                                           break;
                                                                              case 's':
			                                                                           _down();
                                                                                       break;
                                                                              case 'S':
			                                                                           _down();
                                                                                       break;
                                                                              case 'd':
			                                                                           _right();
			                                                                           break;
                                                                              case 'D':
			                                                                           _right();
			                                                                           break;
                                                                              /*case '`':
              		                                                                   for(int p=0;p<MAX;p++){
                                                                                                              for(int q=0;q<MAX;q++){
                                                                                                                                     _matrix[p][q]=512;
                                                                                                                                     }
                                                                                                              }
                                                                                       break;*/
                                                                           
                                                                               }
                                                                print();
																}
		                                                        bool k=0;
		                                                        for(int p=0;p<MAX;p++){
                                                                                       for(int q=0;q<MAX;q++){
                                                                                                              k=(_matrix[p][q]>=2048);
                                                                                                              }
                                                                                       }
                                                                if(k){
                                                                      cout << " YOUWIN :) " << endl;
	                                                                  cout << "最终得分Socre -> " << score << endl;
	                                                                  cout<<"重新开始请按R，退出请按E"<<endl;
                                                                      for( chara[0]='d';(chara[0]!='r')&&(chara[0]!='R')&&(chara[0]!='e')&&(chara[0]!='E');chara[0]=_getch()){
                                                                                                                                                            }
                                                                       
                                                                      if((chara[0]!='r')||(chara[0]!='R')){
                                                                                                     fail=false;
                                                                                                     break;
                                                                                                     }
                                                                      else if((chara[0]!='e')||(chara[0]!='E')){
                                                                                                    system("pause");
                                                                                                    return 0;
                                                                                                     }
                                                                      }       
                                                                }  
                        
             if(fail){
                      cout << " Game Over !! :(" << endl;
                      cout << "最终得分Socre -> " << score << endl;
                      cout<<"重新开始请按R，退出请按E"<<endl;
                      for( chara[0]='d';((chara[0]!='r')&&(chara[0]!='R')&&(chara[0]!='e')&&(chara[0]!='E'));chara[0]=_getch() ){
                                                                                                              }
                                                                       
                      if((chara[0]!='r')||(chara[0]!='R')){
                                                     
                                                     }
                      else if((chara[0]!='e')||(chara[0]!='E')){
                      system("pause");
                      return 0;
                      }                      
                      }
             }

}
void print()
{
     system("cls");
	cout << "------------------------------------------" << endl;
	cout << "得分Socre => " << score << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (_matrix[i][j])
				cout << setw(5) << _matrix[i][j] << " |";
			else
				cout << setw(7) << " |";
		}
		cout << endl;
	}
	cout << "-------------------------------------" << endl << endl;
    cout<<"版权没有，拷贝随意";
	
}
void start(){
     system("cls");
     cout<<"操作："<<endl<<"方向：所有数向所按方向上移动，有如下特殊情况："<<endl;
     cout<<"   2->      2"<<"->   4" <<endl;
     cout<<"   4->      4"<<"->   8" <<endl;
     cout<<"......"<<endl;
     cout<<"1024->   1024"<<"->2048" <<endl;
     cout<<"目标："<<endl<<"达到2048"<<endl; 
     cout<<"开始请按r"<<endl;
     for(char cha='d';((cha!='r')&&(cha!='R'));cha=_getch() ){
                }
                }
void help()
{
	cout << "wasd => 上左下右" << endl;
	cout << "请输入: ";
	ch[0]=_getch();
}
void init()
{   	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
	     _matrix[i][j]=0;
		}
	}
	_count = 0;
	score = 0;
	srand((int)time(0));
	for (int i = 0; i < INIT_SIZE; i++)
		random_data_one();
}
bool random_data_one()
{
	if (_count == MAXMAX)
		return false;
	int left = MAXMAX - _count;
	int tmp = random_x(left);
	int num = random_2_4;
	int k = 0;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (_matrix[i][j] == 0)
			{
				if (k++ == tmp)
				{
					_matrix[i][j] = num;
					break;
				}
			}
		}
	}
	++_count;
	return true;
}
bool b_up()
{
	for (int k = 0; k < MAX; k++)
	{
		bool flag = false;
		for (int i = 0; i < MAX - 1; i++)
		{
			if (_matrix[i][k] == 0)
				flag = true;
			else
			{
				int j = i + 1;
				while (j < MAX)
				{
					if (_matrix[j][k])
					{
						if (_matrix[i][k] == _matrix[j][k])
							return true;
						else
							break;
					}
					else{
						++j;
					}
				}
			}
		}
		if (flag)
		{
			int i = 0, j = MAX - 1;
			while (i < MAX)
			{
				if (_matrix[i][k])
					++i;
				else
					break;
			}
			while (j >= 0)
			{
				if (_matrix[j][k] == 0)
					--j;
				else
					break;
			}
			if (i < j)
				return true;
		}
	}
	return false;
}
bool b_left()
{
	for (int k = 0; k < MAX; k++)
	{
		
		bool flag = false;
		for (int i = 0; i < MAX - 1; i++)
		{
			if (_matrix[k][i] == 0)
				flag = true;
			else
			{
				int j = i + 1;
				while (j < MAX)
				{
					if (_matrix[k][j])
					{
						if (_matrix[k][i] == _matrix[k][j])
							return true;
						else
							break;
					}
					else{
						++j;
					}
				}
			}
		}
		if (flag)
		{
			int i = 0, j = MAX - 1;
			while (i < MAX)
			{
				if (_matrix[k][i])
					++i;
				else
					break;
			}
			while (j >= 0)
			{
				if (_matrix[k][j] == 0)
					--j;
				else
					break;
			}
			if (i < j)
				return true;
		}
	}
	return false;
}
bool b_down()
{
	for (int k = 0; k < MAX; k++)
	{
		bool flag = false;
		for (int i = MAX - 1; i > 0; i--)
		{
			if (_matrix[i][k] == 0)
				flag = true;
			else
			{
				int j = i - 1;
				while (j >= 0)
				{
					if (_matrix[j][k])
					{
						if (_matrix[i][k] == _matrix[j][k])
							return true;
						else
							break;
					}
					else{
						--j;
					}
				}
			}
		}
		if (flag)
		{
			int i = 0, j = MAX - 1;
			while (i < MAX)
			{
				if (_matrix[i][k] == 0)
					++i;
				else
					break;
			}
			while (j >= 0)
			{
				if (_matrix[j][k])
					--j;
				else
					break;
			}
			if (i < j)
				return true;
		}
	}
	return false;
}
bool b_right()
{
	for (int k = 0; k < MAX; k++)
	{
		bool flag = false;
		for (int i = MAX - 1; i > 0; i--)
		{
			if (_matrix[k][i] == 0)
				flag = true;
			else
			{
				int j = i - 1;
				while (j >= 0)
				{
					if (_matrix[k][j])
					{
						if (_matrix[k][i] == _matrix[k][j])
							return true;
						else
							break;
					}
					else{
						--j;
					}
				}
			}
		}
		if (flag)
		{
			int i = 0, j = MAX - 1;
			while (i < MAX)
			{
				if (_matrix[k][i] == 0)
					++i;
				else
					break;
			}
			while (j >= 0)
			{
				if (_matrix[k][j])
					--j;
				else
					break;
			}
			if (i < j)
				return true;
		}
	}
	return false;
}
void _up()
{
	if (b_up())
	{
		for (int i = 0; i < MAX; i++)
		{
			memset(current, 0, sizeof(int)*MAX);
			int ii = 0;
			for (int j = 0; j < MAX; j++)
			{
				if (_matrix[j][i])
					current[ii++] = _matrix[j][i];
			}
			for (int k = 0; k < ii - 1; k++)
			{
				if (current[k] == current[k + 1])
				{
					current[k] *= 2;
					score += current[k];
					current[k + 1] = 0;
					++k;
					--_count;
				}
			}
			ii = 0;
			for (int j = 0; j < MAX; j++)
			{
				if (current[j])
					_matrix[ii++][i] = current[j];
			}
			for (; ii < MAX; ii++)
				_matrix[ii][i] = 0;
		}
		random_data_one();
	}
	else{
	}
}
void _left()
{
	if (b_left())
	{
		for (int i = 0; i < MAX; i++)
		{
			memset(current, 0, sizeof(int)*MAX);
			int ii = 0;
			for (int j = 0; j < MAX; j++)
			{
				if (_matrix[i][j])
					current[ii++] = _matrix[i][j];
			}
			for (int k = 0; k < ii - 1; k++)
			{
				if (current[k] == current[k + 1])
				{
					current[k] *= 2;
					score += current[k];
					current[k + 1] = 0;
					++k;
					--_count;
				}
			}
			ii = 0;
			for (int j = 0; j < MAX; j++)
			{
				if (current[j])
					_matrix[i][ii++] = current[j];
			}
			for (; ii < MAX; ii++)
				_matrix[i][ii] = 0;
		}
		random_data_one();
	}
	else{
	}
}
void _down()
{
	if (b_down())
	{
		for (int i = 0; i < MAX; i++)
		{
			memset(current, 0, sizeof(int)*MAX);
			int ii = 0;
			for (int j = MAX - 1; j >= 0; j--)
			{
				if (_matrix[j][i])
					current[ii++] = _matrix[j][i];
			}
			for (int k = 0; k < ii - 1; k++)
			{
				if (current[k] == current[k + 1])
				{
					current[k] *= 2;
					score += current[k];
					current[k + 1] = 0;
					++k;
					--_count;
				}
			}
			ii = MAX - 1;
			for (int j = 0; j < MAX; j++)
			{
				if (current[j])
					_matrix[ii--][i] = current[j];
			}
			for (; ii >= 0; ii--)
				_matrix[ii][i] = 0;
		}
		random_data_one();
	}
	else{
	}
}
void _right()
{
	if (b_right())
	{
		for (int i = 0; i < MAX; i++)
		{
			memset(current, 0, sizeof(int)*MAX);
			int ii = 0;
			for (int j = MAX - 1; j >= 0; j--)
			{
				if (_matrix[i][j])
					current[ii++] = _matrix[i][j];
			}
			for (int k = 0; k < ii - 1; k++)
			{
				if (current[k] == current[k + 1])
				{
					current[k] *= 2;
					score += current[k];
					current[k + 1] = 0;
					++k;
					--_count;
				}
			}
			ii = MAX - 1;
			for (int j = 0; j < MAX; j++)
			{
				if (current[j])
					_matrix[i][ii--] = current[j];
			}
			for (; ii >= 0; ii--)
				_matrix[i][ii] = 0;
		}
		random_data_one();
	}
	else{
	}
}
char arduino(char a){// adjust as needed
	
	char incomingData[256]="1";

	int dataLength = 256;
	int readResult = 0;
	readResult = SP->ReadData(incomingData,dataLength);
	a=incomingData[0];
	std::string test(incomingData);

	return a;
}