#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

/*
    «‰« ⁄‰œÌ ›Ìﬂ Ê— »Ì«Œœ ”ÿ— ”ÿ—  „«„
    ⁄«Ì“ «Œœ „‰ ﬂ· ”ÿ— ﬂ·„…
    Ê«ﬁ«—‰ «·ﬂ·„… œÌ »«·ﬂ·„… «·Ì ﬁœ«„Â« ›Ì «·›Ìﬂ Ê— «· «‰Ì
    Õ—› Õ—›
   Êﬂ„«‰ ÌﬂÊ‰ ⁄‰œÌ —ﬁ„ «Ê· ”ÿ— „‘ „ ”«ÊÌ
*/

using namespace std;

void loadFile(vector<string> &text, ifstream &file){
    char srcFileName[100], word[101];
    cout << "Enter File Name: ";
    cin >> srcFileName;
    file.open(strcat(srcFileName, ".txt"));
    if (file.fail()){
        cout << "File not found !" << endl;
    }
    else{
        cout << "File found " << endl;
        while(!file.eof()){
            file.getline(word, 100, '.');
            text.push_back(strcat(word, "."));
        }
    }
}

int main()
{
    ifstream file1;
    ifstream file2;
    string line, firstDifferentWord, word1, word2;
    bool identical = true;
    int unidentical_LineNumber, answer;
    vector<string> file1_Data;
    vector<string> file2_Data;
    loadFile(file1_Data, file1);
    loadFile(file2_Data, file2);
    cout << "How Would You Like The Process of Comparison Go? By Words(1)/Characters(2): ";
    cin >> answer;
    if (answer == 2){
        for (int i = 0; i < file1_Data.size(); i++){
            if(!identical){
                unidentical_LineNumber = i;
                break;
            }
            line = "";
            for (int j = 0; j < file1_Data[i].length(); j++){
                if (file1_Data[i][j] != file2_Data[i][j]){
                    identical = false;
                    if (file1_Data[i][j] != '.'){
                        line += file1_Data[i][j];
                    }
                    else{
                        break;
                    }
                }
            }
        }
        if (!identical){
            cout << "The Two Files Are Not Identical Beginning of The Line Number: " << unidentical_LineNumber << " in the first file and it contains: "
            << line << "." << endl;
        }
        else{
            cout << "The Two Files Are Identical" << endl;
        }
    }
    else if (answer == 1){
        for (int i = 0; i < file1_Data.size(); i++){
            if(!identical){
                break;
                }
            for (int j = 0; j < file1_Data[i].length(); j++){
                if (file1_Data[i][j] != ' '){
                    word1 += file1_Data[i][j];
                }
                if (file2_Data[i][j] != ' '){
                    word2 += file2_Data[i][j];
                }
                if ((word1.compare(word2) < 0 || word1.compare(word2) > 0) && file1_Data[i][j] == ' ' && identical){
                    identical = false;
                    firstDifferentWord = word1;
                    line += word1;
                    line += ' ';
                    word1 = "";
                    word2 = "";
                }
                else if (word1.compare(word2) == 0 && file1_Data[i][j] == ' '){
                    word1 = "";
                    word2 = "";
                }
                else if (!identical && file1_Data[i][j] != '.'){
                    line += file1_Data[i][j];
                    if (file1_Data[i][j] == '.'){
                        break;
                    }
                }
            }
        }
        if (!identical){
            cout << "The Two Files Are Not Identical Beginning of The Word: '" << firstDifferentWord << "' in The First File and The Line Contains: '"
            << line << ".'" << endl;
        }
        else{
            cout << "The Two Files Are Identical" << endl;
        }
    }
    return 0;
}
