// CS20B1107, SRIRAM REDDY CHEERLA
// CD Lab - 5

#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Creating object of fstream classs
    ifstream f;
    // Reading file
    f.open("input5.txt");
    string line;
    vector<vector<string> > ans;

    // Reading text file until end of file
    while (f)
    {
        // Gets each line of text file
        // for each run
        getline(f, line);
        string a = "";
        vector<string> aa;
        
        // From the line read by traversing
        // through each character and when i 
        // encounter space or end of line 
        // appending that to vector as a string
        // at end appending that vector to vector of vectors
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ' ')
            {
                if(!a.empty()){
                    aa.push_back(a);
                }
                a = "";
            }
            else {
                a = a + line[i];
                if (i == line.length()-1)
                {
                    aa.push_back(a);
                    a = "";
                }
            }
        }

        ans.push_back(aa);
    }

    string sa, sd = "";

    vector<string> s1;
    vector<string> s2;

    // Here aa, stores each line without spaces
    // and each line in one row
    // From that, this loop reads
    // int, float, char and variables related to them
    // and stores in vector s1 and s2
    for (int i = 0; i < ans.size();i++)
    {
        for (int j = 0; j < ans[i].size();j++)
        {
            if (ans[i][j] == "int" || ans[i][j] == "char" || ans[i][j] == "float")
            {
                j++;
                sa = "";
                sd = "";
                for (int k = j; k < ans[i].size(); k++)
                {
                    if(ans[i][k].size() > 0)
                    {
                        sa = ans[i][k];
                        for (int q = 0; q < sa.length();q++)
                        {
                            if (sa[q] != ',' && sa[q] != ';')
                                sd += sa[q];
                            else{
                                s1.push_back(ans[i][j - 1]);
                                s2.push_back(sd);
                                sd = "";
                            }
                        }
                    }
                }
            }
        }
    }


    // Vector s3 of size s3, since all could not
    // be defined
    vector<string> s3(s1.size(), "");

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            if (ans[i][j] == "int" || ans[i][j] == "char" || ans[i][j] == "float")
            {
                continue;
            }
            else
            {
                sa = ans[i][j];
                string temp;
                temp = sa[0];

                if(temp == s2[0])
                {
                    for (int j = 1; j < sa.size(); j++)
                    {
                        if(sa[j] == '=')
                        {
                            string k="";
                            for (j = j + 1; j < sa.size(); j++)
                            {
                                if (sa[j] != ';')
                                {
                                    k += sa[j];
                                }
                            }
                            s3[0] = k;
                        }

                    }
                }
                else if(temp == s2[2])
                {
                    for (int j = 1; j < sa.size(); j++)
                    {
                        if (sa[j] == '=')
                        {
                            string k = "";
                            for (j = j + 1; j < sa.size(); j++)
                            {
                                if (sa[j] != ';')
                                {
                                    k += sa[j];
                                }
                            }
                            s3[2] = k;
                        }
                        
                    }
                }
                else if(temp == s2[4])
                {
                    for (int j = 1; j < sa.size(); j++)
                    {
                        if (sa[j] == '=')
                        {
                            string k = "";
                            for (j = j + 1; j < sa.size(); j++)
                            {
                                if (sa[j] != ';')
                                {
                                    k += sa[j];
                                }
                            }
                            s3[4] = k;
                        }
                    }
                }
            }
        }
    }

    // Finally printing all the vectors as a table
    cout<<"Token"<<"\t"<<"Attr.-1"<<"\t"<<"Attr. 2"<<"\n";
    for (int i = 0; i < s1.size();i++)
    {
        cout << s2[i] << "\t" << s1[i]<<"\t"<<s3[i]<<'\n';
    }

    f.close();
}