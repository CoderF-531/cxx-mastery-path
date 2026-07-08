#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

    struct Comper{
        bool operator()(const std::pair<std::string,int>& x,const std::pair<std::string,int>& y)
        { 
            //按照出现次数，如果相同按字典序
           if (x.second != y.second) {
                return x.second > y.second;
            }
            return x.first < y.first;
        }
    };

int main()
{
    std::string str;

    std::map<std::string,int> M;
    getline(std::cin,str); //读取一段字符串
    std::string word;
    //循环读入字符串
    for(auto e: str)
    {
        //如果该字符是 字母或者数字 word就尾插
        if (std::isalnum(static_cast<unsigned char>(e)))
        {
            word += static_cast<char>(std::tolower(static_cast<unsigned char>(e))); //统一转小写方便计算
        }
        else
        {
            if(!word.empty())
            {
                //添加进map
                M[word]++;
                word.clear();
            }
        }
    }
    //处理最后一个单词
       if(!word.empty())
            {
                //添加进map
                M[word]++;
                word.clear();
            }
    
    std::vector<std::pair<std::string,int>> words(M.begin(),M.end());
    //自排序
    std::sort(words.begin(),words.end(),Comper());


    //输出map
    for(int i = 0;i<words.size()&&i<3;i++)
    {
        std::cout<<words[i].first<<" "<<words[i].second<<std::endl;
    }

    return 0;
}