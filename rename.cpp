#include <bits/stdc++.h>
using namespace std;
int main ()
{
  int result;
  char oldname[100];
  char newname[100];
  result= rename( oldname , newname );
  if ( result == 0 )
    puts ( "File successfully renamed" );
  else
    perror( "Error renaming file" );
  return 0;
}
