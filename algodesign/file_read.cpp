#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("list.txt");
    ofstream outFile;
    outFile.open("list_output.txt");
    if(inFile.fail())
    {
        cerr<<"error"<<endl;
        exit(1);
    }
    string line;
    while(getline(inFile,line))
{
    std::stringstream   linestream(line);
    std::string         value;
    string temp[2];
    int i=0;
    while(getline(linestream,value,','))
    {
        std::cout << "Value(" << value << ")\n";
        temp[i]=value;
        i++;
        if(i==2)
        {
            outFile<<temp[0]<<","<<temp[1]<<endl;
            i=0;
        }
    }
}
    std::cout << "Line Finished" << std::endl;
    inFile.close();
    outFile.close();
}

