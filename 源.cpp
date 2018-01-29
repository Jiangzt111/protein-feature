#include <fstream>  
#include <string>  
#include <iostream>  
using namespace std;
int Demen1[20][20]= { 0 };

int quer(char cha[800])
{
	int a = 0, b = 0, c = 0, d = 0, l = 0;
	for (int k = 6; k < 800; k++)
	{
		l++;
		a = 0; b = 0; c = 0;
		if (cha[k+1] == 0)
			break;

		a = cha[k];
		switch (a) {
		case 65:b = 0; break;
		case 67:b = 1; break;
		case 68:b = 2; break;
		case 69:b = 3; break;
		case 70:b = 4; break;
		case 71:b = 5; break;
		case 72:b = 6; break;
		case 73:b = 7; break;
		case 75:b = 8; break;
		case 76:b = 9; break;
		case 77:b = 10; break;
		case 78:b = 11; break;
		case 80:b = 12; break;
		case 81:b = 13; break;
		case 82:b = 14; break;
		case 83:b = 15; break;
		case 84:b = 16; break;
		case 86:b = 17; break;
		case 87:b = 18; break;
		case 89:b = 19; break;
		default:break;
		}
		a = cha[k+1];
		switch (a) {
		case 65:c = 0; break;//a
		case 67:c = 1; break;//c
		case 68:c = 2; break;//d
		case 69:c = 3; break;//e
		case 70:c = 4; break;//f
		case 71:c = 5; break;//g
		case 72:c = 6; break;//h
		case 73:c = 7; break;//i
		case 75:c = 8; break;//k
		case 76:c = 9; break;//l
		case 77:c = 10; break;//m
		case 78:c = 11; break;//n
		case 80:c = 12; break;//p
		case 81:c = 13; break;//q
		case 82:c = 14; break;//r
		case 83:c = 15; break;//s
		case 84:c = 16; break;//t
		case 86:c = 17; break;//v
		case 87:c = 18; break;//w
		case 89:c = 19; break;//y
		default:break;
		}
		Demen1[b][c]++;
	}
	return l;
}
int main()
{
	FILE *fp;
	ifstream in("text.txt");
	string line;fp = fopen("out.txt", "w");
	char a;
	int i = 0,j=0,k=0;
	char b[1800] = { 0 };
	if (in) // 有该文件  
	{
		while (getline(in, line)) // line中不包括每行的换行符  
		{
			a = line.at(0);
			if (a==62)
			{
				if (j != 0)
				{
				b[i] = '\0';
				i = 0;
				quer(b);
				
				for (k = 0; k<400; k++)
				{
					fprintf(fp, "%d,", Demen1[k/20][k%20]);
				}
				fprintf(fp, "\n");
				memset(Demen1,0, sizeof(int) * 20*20);
				memset(b, 0, sizeof(char) * 400);
				}
				j++;	
			}
			for ( k=0; k<line.length(); k++)
				         b[i++] = line[k];
		}
		b[i] = '\0';
		i = 0;
		quer(b);
		for (k = 0; k<400; k++)
		{
			fprintf(fp, "%d,", Demen1[k / 20][k % 20]);
		}
		fprintf(fp, "\n");
		memset(Demen1, 0, sizeof(int) * 20 * 20);
		memset(b, 0, sizeof(char) * 400);
		fclose(fp);
	}
	else // 没有该文件  
	{
		cout << "no such file" << endl; 
	}
	return 0;
}	