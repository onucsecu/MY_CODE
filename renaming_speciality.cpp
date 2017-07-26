#include <Windows.h>
#include<bits/stdc++.h>
using namespace std;
vector<string> GetFileNamesInDirectory(string directory) {  /**http://www.dreamincode.net/forums/topic/367121-List-all-file-names-in-a-directory/**/
    vector<string> files;
    WIN32_FIND_DATA fileData;
    HANDLE hFind;
    if ( !((hFind = FindFirstFile(directory.c_str(), &fileData)) == INVALID_HANDLE_VALUE) ) {
        while(FindNextFile(hFind, &fileData)) {
            files.push_back(fileData.cFileName);
        }
    }
    FindClose(hFind);

    return files;

}



int main() {

    vector<string> vFileNames = GetFileNamesInDirectory("*");
    char ptr[100];
    scanf("%s",ptr);
    for (int i = 0; i < vFileNames.size(); i++) {
            char str[1000];
            strcpy(str, vFileNames[i].c_str());
            char *pch;
            pch = strstr (str,ptr);
            if(pch!=NULL){
                    int n;
                    char digi[5000];
                    digi[0]='#';
                    n=strlen(str)-strlen(pch)+strlen(ptr);
                    int i,j;
                    for(i=n,j=1;i<=n+5;i++){
                        if(isdigit(str[i])){
                            digi[j]=str[i];
                            j++;
                        }
                    }
                    digi[j]='\0';
                    strcat(digi,str);
                    int res;
                    res= rename( str , digi );
                    if ( res == 0 )
                        cout<<str<<" ==Done"<<endl;
                    else{
                        cout<<vFileNames[i];
                        perror( " Error renaming file\n");
                    }

            }

    }

    return 0;

}
