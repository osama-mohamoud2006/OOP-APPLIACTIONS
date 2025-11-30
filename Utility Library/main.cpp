#include  "clsUtillity.h"

int main() {
    clsUtil::Srand();
   // cout<< clsUtil::Random(1,10 )<<endl;
    //cout<< clsUtil::GenerateRandomWord(clsUtil::mixChar,5)<<endl ;

    //cout<< clsUtil::GenerateKey();
    //clsUtil::GenerateKeys(3);
vector <string> Keys ;
    Keys = clsUtil::GenerateKeys(5,true);

    for (string &str : Keys) {
        cout<<str<<endl;
    }

}