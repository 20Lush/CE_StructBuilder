#include <iostream>
#include <fstream>

using namespace std;

string buildLine(string TYPE, string NAME, string OFFSET){
    cout << "building line" << endl;
    string spacerSmall;
    string spacerBig = "                                                ";

    if (TYPE == "BYTE" || TYPE == "INT8" || TYPE == "CHAR")
        spacerSmall = "    "; // 4 spaces
    if (TYPE == "INT32" || TYPE == "FLOAT")
        spacerSmall = "   "; // 3 spaces
    if (TYPE == "POINT3D")
        spacerSmall = " "; // 1 space

    int diff;
    diff = NAME.size() - 4;
    if(diff > 0)
        for(int i = 0; i < diff; i++) spacerBig.pop_back();
    if(diff < 0)
        for(int i = 0; i > diff; i--) spacerBig.append(" ");

    string rtn = TYPE + spacerSmall + NAME + ";" + spacerBig + "// +0x" + OFFSET;
    return rtn;
}


int main(){

    fstream myFile;
    fstream values;
    myFile.open("structBuilder.txt", ios::out);
    values.open("da-values.txt", ios::in);
    
    for(string line; getline(values, line);){

        string type; 
        string name;
        string offset;

        offset = line.substr(1, 4);
        name = line.substr(7, 31);
        name.resize(name.find(" "));

        cout << "Enter TYPE for " << name << " :: ";
        cin >> type;

        myFile << buildLine(type,name,offset) << endl;
        type.clear();
        name.clear();
        offset.clear();
    }

    system("pause > nul");
    return 0;
}