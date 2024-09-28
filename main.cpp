#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

 
int main ()
{
    vector<string> inputs;
    vector<string> results;
    
   vector<string> datas;
   string data;
 
   // 以读模式打开文件
   ifstream infile; 
   infile.open("../input.txt"); 
 
   cout << "Reading from the file" << endl;

   while(infile >> data)
   {
        inputs.push_back(data);
   }


   for(int i = 0; i < inputs.size(); i++)
   {
        cout << inputs[i] << endl;
   }
 
   // 关闭打开的文件
   infile.close();

   for(int i = 0; i < inputs[0].size(); i++)
   {
        for(int j = 0; j < inputs[1].size(); j++)
        {
            for(int k = 0; k < inputs[2].size(); k++)
            {
                for(int l = 0; l < inputs[3].size(); l++)
                {
                    string res;
                    res = res + inputs[0][i] + inputs[1][j] + inputs[2][k] + inputs[3][l];
                    results.push_back(res);
                }
            }
        }
   }

    // 以写模式打开文件
   ofstream outfile;
   outfile.open("output.txt");
 
   // 向文件写入用户输入的数据
   for(int i = 0; i < results.size(); i++)
   {
        outfile << results[i] << endl;
   }
   
   // 关闭打开的文件
   outfile.close();
 
   return 0;
}