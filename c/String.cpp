#include<iostream>

using namespace std;

class String{
    private:
        const char* str;
        int countLength();
        int replacementSpec(char* str1, char* str2, int index, int begin, int end);
    public:
        int length;
        String(const char* str);
        String operator = (const char* str);
        int getLength();
        int frequency(String str1);
        String characterDelete(String str1);
        String replacement(String str1, String str2);
        const char* getStr();
};

String::String(const char* str)
{
    this -> str = str;
    length = countLength();
}

String String::operator = (const char* str){
    return String(str);
}

int String::frequency(String str1)
{
    int i,j;
    int count = 0;
    for(i = 0 ; i < length ; i++)
    {
        for(j = 0 ; str1.str[j] == str[i + j] ; j++)
        {
            if(j == str1.length - 1)
            {
                count++;
                break;
            }
        }
    }
    return count;
}

String String::characterDelete(String str1)
{
    int i,j,k;
    int start;
    char* tempStr = new char[length];
    for(i = 0, k = 0 ; i < length ; i++)
    {
        for(j = 0 ; str1.str[j] == str[i + j] && j < str1.length ; j++);
        if(j < str1.length)
        {
            start = i;
            i += j;
            while(start <= i)
            {
                tempStr[k] = str[start];
                k++;
                start++;
            }
        }else
        {
            i += j-1;
        }
    }
    tempStr[k] = '\0';
    return String(tempStr);
}

String String::replacement(String str1, String str2)
{
    int i,j,k;
    int start;
    char* tempStr = new char[length];
    for(i = 0, k = 0 ; i < length ; i++)
    {
        for(j = 0 ; str1.str[j] == str[i + j] && j < str1.length ; j++);
        if(j < str1.length)
        {
            start = i;
            i += j;
            k = replacementSpec(tempStr, (char*)str, k, start, i);
        }else
        {
            start = 0;
            i += j - 1;
            k = replacementSpec(tempStr, (char*)str2.str, k, start, str2.length - 1);
        }
    }
    tempStr[k] = '\0';
    return String(tempStr);
}

int String::replacementSpec(char* str1, char* str2, int index, int begin, int end)
{
    while(begin <= end)
    {
        str1[index] = str2[begin];
        begin++;
        index++;
    }
    return index;
}

int String::countLength()
{
    int index = 0;
    while(str[index] != '\0')
    {
        index++;
    }
    return index;
}

int String::getLength()
{
    return length;
}

const char* String::getStr()
{
   return str;
}

const int LENGTH = 100;

int main()
{
    cout << "Enter two String. System will give you" << endl
         << "the numbers of the given String2 in String1." << endl
         << "Ex. String1 = \"I am king. I am winer. I want.\"" << endl
         << "    Stirng2 = \"I am\", The result value is: 2" << endl;
    char* str = new char[LENGTH];
    cout << "String1 = ";
    cin.getline(str, LENGTH);
    String str1 = str;
    str = new char[LENGTH];
    cout << "String2 = ";
    cin.getline(str, LENGTH);
    String str2 = str;
    int result = str1.frequency(str2);
    cout << result << endl<<endl;

    cout << "Enter two String. System will give you" << endl
         << "a String that delete String2 in String1." << endl
         << "Ex. String1 = \"I am king. I am winer. I want.\"" << endl
         << "    String2 = \"I am\""<<endl
         << "The result is:\"  king.  winer. I want.\"" <<endl;
    str = new char[LENGTH];
    cout << "String1 = ";
    cin.getline(str, LENGTH);
    String str3 = str;
    str = new char[LENGTH];
    cout << "String2 = ";
    cin.getline(str, LENGTH);
    String str4 = str;
    String sResult1 = str3.characterDelete(str4);
    cout << sResult1.getStr() << endl<<endl;

    cout << "Enter three String. System will give you" << endl
         << "a String that replace String2 in String1 by String3" << endl
         << "Ex. String1 = \"I am handsome, I am winer.\"" << endl
         << "    String2 = \"I am\"" << endl
         << "    String3 = \"Only shit\"" << endl
         << "The result is: \"Only shit handsome, Only shit winer.\"" << endl;
    str = new char[LENGTH];
    cout << "String1 = ";
    cin.getline(str, LENGTH);
    String str5 = str;
    str = new char[LENGTH];
    cout << "String2 = ";
    cin.getline(str, LENGTH);
    String str6 = str;
    str = new char[LENGTH];
    cout << "String3 = ";
    cin.getline(str, LENGTH);
    String str7 = str;
    String sResult2 = str5.replacement(str6, str7);
    cout << sResult2.getStr() << endl<<endl;
    return 0;
}
