// Example program
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char* stringReverse( char* str );
int multiply( int a, int b );
void findSubString( char* str , char* substr, int& startLoc, int& endLoc);

int main()
{

    int startLocation = 0, endLocation = 0;
    
    char substr[] = "man";
    
    char* str = new char[20];
    
    char* name = new char[10];

    char* reversedName = NULL;
    
    strcpy(name, "Brandon");
    
    strcpy(str, "cavemackmazmackmanmack");
    
    cout << name << endl;
    
    reversedName = stringReverse( name );
    
    cout << reversedName << endl;
    
    cout << multiply( 29, 443 ) << endl;
    
    findSubString( str, substr, startLocation,  endLocation );
    
    cout << startLocation << "  " << endLocation << endl;
    
    
    delete [] str; str = NULL;    

    delete [] name; name = NULL;

    
}


char* stringReverse( char* str )
{

	char* head = str;
	
	char* tail = str + strlen(str) - 1;

	char temp;
	
	for(int i = 0; i < strlen(str) / 2; i++ )
	{
		temp = *head;
		*head = *tail;
		*tail = temp;
		head++;
		tail--;	
	}

	return str;
}


void findSubString( char* str , char* substr, int& startLoc, int& endLoc)
{
    int count = 0;
    startLoc = -1;   
    char* substrFront = substr;
    
    while( *str != '\0' && *substr != '\0' )
    {
        if( *str == *substr )
        {   
            if( startLoc == -1 )
            {
                startLoc = count;   
            }    
            
            substr++;    
        }
        
        else
        {
            substr = substrFront;
            startLoc = -1;
            endLoc = -1;
        }
        
        str++;       
        count++;
    }
    
    endLoc = count - 1;
}


int multiply( int a, int b )
{
	if( b == 0 )
	{
		return 0;
	}
	
	return a + multiply( a, b - 1 );
	
}



