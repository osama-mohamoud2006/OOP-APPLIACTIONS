#include  "clsUtillity.h"

int main() {
    clsUtil::Srand();
   // cout<< clsUtil::Random(1,10 )<<endl;
    //cout<< clsUtil::GenerateRandomWord(clsUtil::mixChar,5)<<endl ;

    //cout<< clsUtil::GenerateKey();
    //clsUtil::GenerateKeys(3);
// vector <string> Keys ;
//     Keys = clsUtil::GenerateKeys(5,true);
//
//     for (string &str : Keys) {
//         cout<<str<<endl;
//     }

// string  arr[5];
//     clsUtil::FillArrayWithRandomKey(arr,5,clsUtil::mixChar,7);
//     for (int i=0; i<5; i++) {
//         cout<<arr[i]<<endl;
//     }

    // string arr[3]={"ahmed" , "mohammed","osama"};
    // clsUtil::ShuffleArray(arr,3);
    //  for (int i=0; i<3; i++) {
    //      cout<<arr[i]<<endl;
    //  }
// clsDate d1(1,2,2022);
//     clsDate d2(10,12,2025);
//
//     clsUtil::Swap(d1,d2);
//     cout<<clsDate::PrintFullDateForStatic(d1)<<endl ;
//     cout<<clsDate::PrintFullDateForStatic(d2)<<endl;

    // cout<<clsUtil::Tabs(5)<<"HI"<<clsUtil::Tabs(5)<<endl;

string text = "abc";
    clsUtil::EncryptText(text,5);
    cout<<text<<endl;
    clsUtil::DecryptText(text,5);
    cout<<text<<endl;
}