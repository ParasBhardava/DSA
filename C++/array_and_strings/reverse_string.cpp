#include<bits/stdc++.h>

int main()
{
    std::string str = "My name is Paras.";
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string word;

    while(getline(ss, word, ' '))
    {
        tokens.push_back(word);
    }

    for(int i=0; i<tokens.size(); i++)
    {
        std::cout<<tokens[i]<<std::endl;
    }

    return 0;
}