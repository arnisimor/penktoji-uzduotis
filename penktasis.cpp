#include <iostream>
#include <fstream>
#include <locale>
#include <set>
#include <iterator>
#include <regex>
#include <streambuf>
#include <string>

int main()
{
std::ifstream fd("duomenys.txt");
std::ofstream fr("url.txt");
std::multiset<std::string> list = std::multiset<std::string>( std::istream_iterator<std::string>(fd), std::istream_iterator<std::string>());
fd.close();
fr<<"url: "<<std::endl;
 for(auto zodis = list.begin(); zodis != list.end(); zodis=list.upper_bound(*zodis))
{
    std::string word=*zodis;
 if(word.rfind("www.",0)==0||word.rfind("http://",0)==0||word.rfind("https://",0)==0||word.rfind("ftp://",0)==0||word.rfind("localhost:",0)==0)
    {
        fr << *zodis <<std::endl;
        fr<< " url kiekis: " << list.count(*zodis) << std::endl;
    }
}
fr.close();

std::ofstream isveda("zodziai.txt",std::ios::app);
std::ifstream t("duomenys.txt");
std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
str.resize(remove_if(str.begin(), str.end(),[](char x){return !isalnum(x) && !isspace(x);})-str.begin());
t.close();
std::ofstream output("duomenys.txt");
output<<str;
output.close();
std::ifstream input("duomenys.txt");
std::multiset<std::string> listas = std::multiset<std::string>( std::istream_iterator<std::string>(input),std::istream_iterator<std::string>());
input.close();
isveda<<"besikartojantys zodziai:"<<std::endl;
 for(auto zodis = listas.begin(); zodis != listas.end(); zodis=listas.upper_bound(*zodis))
{
std::ifstream in("duomenys.txt");
if(listas.count(*zodis)>=2){
std::string eilute;
std::string word;
std::vector<int> line;
int kartai=0;
int eile = 1;
in.clear();
    while (std::getline(in, eilute))
    {
        std::stringstream abc(eilute);
        while (!abc.eof())
        {
          abc>>word;
          if(kartai>eile)
          {

          }
          else if(word==*zodis)
          {
            kartai=eile;
             kartai++;

             line.push_back(eile);
          }

        }
        eile++;

    }

  isveda << *zodis << "  pasikartoja: " << listas.count(*zodis) <<" kartus "<< "ir jis pasikartoja ";
      for(size_t i=0;i<line.size();i++)
{
  isveda<<line[i]<<" ";
}
isveda<<"teksto eilutese.";
  isveda<<std::endl;
  }
  in.clear();
}
isveda.close();
    return 0;
}
